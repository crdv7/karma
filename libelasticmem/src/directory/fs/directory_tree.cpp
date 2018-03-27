#include "directory_tree.h"

#include <iostream>
#include "../../storage/chain_module.h"
#include "../../utils/logger.h"
#include "../../utils/retry_utils.h"

namespace elasticmem {
namespace directory {

using namespace utils;

directory_tree::directory_tree(std::shared_ptr<block_allocator> allocator,
                               std::shared_ptr<storage::storage_management_ops> storage)
    : root_(std::make_shared<ds_dir_node>(std::string("/"))),
      allocator_(std::move(allocator)),
      storage_(std::move(storage)) {}

void directory_tree::create_directory(const std::string &path) {
  std::string ptemp = path;
  std::string directory_name = directory_utils::pop_path_element(ptemp);
  auto parent = get_node_as_dir(ptemp);
  if (parent->get_child(directory_name) == nullptr) {
    parent->add_child(std::make_shared<ds_dir_node>(directory_name));
  }
}

void directory_tree::create_directories(const std::string &path) {
  std::string p_so_far(root_->name());
  std::shared_ptr<ds_dir_node> dir_node = root_;
  for (auto &name: directory_utils::path_elements(path)) {
    directory_utils::push_path_element(p_so_far, name);
    std::shared_ptr<ds_node> child = dir_node->get_child(name);
    if (child == nullptr) {
      child = std::dynamic_pointer_cast<ds_node>(std::make_shared<ds_dir_node>(name));
      dir_node->add_child(child);
      dir_node = std::dynamic_pointer_cast<ds_dir_node>(child);
    } else {
      if (child->is_directory()) {
        dir_node = std::dynamic_pointer_cast<ds_dir_node>(child);
      } else {
        throw directory_ops_exception("Cannot create directory: " + p_so_far + " is a file.");
      }
    }
  }
}

data_status directory_tree::open(const std::string &path) {
  return dstatus(path);
}

data_status directory_tree::create(const std::string &path,
                                   const std::string &persistent_store_prefix,
                                   std::size_t num_blocks,
                                   std::size_t chain_length) {
  if (num_blocks == 0) {
    throw directory_ops_exception("File cannot have zero blocks");
  }
  if (chain_length == 0) {
    throw directory_ops_exception("Chain length cannot be zero");
  }
  std::string filename = directory_utils::get_filename(path);

  if (filename == "." || filename == "/") {
    throw directory_ops_exception("Path is a directory: " + path);
  }
  std::string parent_path = directory_utils::get_parent_path(path);
  auto node = get_node_unsafe(parent_path);
  if (node == nullptr) {
    create_directories(parent_path);
    node = get_node_unsafe(parent_path);
  } else if (node->is_regular_file()) {
    throw directory_ops_exception(
        "Cannot create file in dir " + parent_path + ": " + node->name() + " is a file.");
  }

  auto parent = std::dynamic_pointer_cast<ds_dir_node>(node);

  std::vector<block_chain> blocks;
  for (std::size_t i = 0; i < num_blocks; ++i) {
    block_chain chain{allocator_->allocate(chain_length, {})};
    assert(chain.block_names.size() == chain_length);
    blocks.push_back(chain);
    using namespace storage;
    if (chain_length == 1) {
      storage_->setup_block(chain.block_names[0], path, chain_role::singleton, "nil");
    } else {
      for (std::size_t j = 0; j < chain_length; ++j) {
        std::string block_name = chain.block_names[j];
        std::string next_block_name = (j == chain_length - 1) ? "nil" : chain.block_names[j + 1];
        int32_t role = (j == 0) ? chain_role::head : (j == chain_length - 1) ? chain_role::tail : chain_role::mid;
        storage_->setup_block(block_name, path, role, next_block_name);
      }
    }
  }
  auto child =
      std::make_shared<ds_file_node>(filename, storage_mode::in_memory, persistent_store_prefix, chain_length, blocks);
  child->persistent_store_prefix(persistent_store_prefix);
  parent->add_child(child);
  return child->dstatus();
}

bool directory_tree::exists(const std::string &path) const {
  return get_node_unsafe(path) != nullptr;
}

std::uint64_t directory_tree::last_write_time(const std::string &path) const {
  return get_node(path)->last_write_time();
}

perms directory_tree::permissions(const std::string &path) {
  return get_node(path)->permissions();
}

void directory_tree::permissions(const std::string &path, const perms &prms, perm_options opts) {
  auto node = get_node(path);
  switch (opts) {
    case perm_options::replace: {
      node->permissions(prms & perms::mask);
      break;
    }
    case perm_options::add: {
      node->permissions(node->permissions() | (prms & perms::mask));
      break;
    }
    case perm_options::remove: {
      node->permissions(node->permissions() & ~(prms & perms::mask));
      break;
    }
  }
}

void directory_tree::remove(const std::string &path) {
  std::string ptemp = path;
  std::string child_name = directory_utils::pop_path_element(ptemp);
  auto parent = get_node_as_dir(ptemp);
  auto child = parent->get_child(child_name);
  if (child == nullptr) {
    throw directory_ops_exception("Path does not exist: " + path);
  }
  if (child->is_directory() && !std::dynamic_pointer_cast<ds_dir_node>(child)->empty()) {
    throw directory_ops_exception("Directory not empty: " + path);
  }
  parent->remove_child(child_name);
  clear_storage(child);
}

void directory_tree::remove_all(const std::string &path) {
  std::string ptemp = path;
  std::string child_name = directory_utils::pop_path_element(ptemp);
  auto parent = get_node_as_dir(ptemp);
  auto child = parent->get_child(child_name);
  if (child == nullptr) {
    throw directory_ops_exception("Path does not exist: " + path);
  }
  parent->remove_child(child_name);
  clear_storage(child);
}

void directory_tree::flush(const std::string &path) {
  get_node(path)->flush(path, storage_, allocator_);
}

void directory_tree::rename(const std::string &old_path, const std::string &new_path) {
  if (old_path == new_path)
    return;
  std::string ptemp = old_path;
  std::string child_name = directory_utils::pop_path_element(ptemp);
  auto old_parent = get_node_as_dir(ptemp);
  auto old_child = old_parent->get_child(child_name);
  if (old_child == nullptr) {
    throw directory_ops_exception("Path does not exist: " + old_path);
  }

  ptemp = new_path;
  child_name = directory_utils::pop_path_element(ptemp);
  auto new_parent = get_node_as_dir(ptemp);
  auto new_child = new_parent->get_child(child_name);
  if (new_child != nullptr) {
    if (new_child->is_directory())
      throw directory_ops_exception("New path is a non-empty directory: " + new_path);
    new_parent->remove_child(child_name);
  }
  old_parent->remove_child(old_child->name());
  old_child->name(child_name);
  new_parent->add_child(old_child);
}

file_status directory_tree::status(const std::string &path) const {
  return get_node(path)->status();
}

std::vector<directory_entry> directory_tree::directory_entries(const std::string &path) {
  return get_node_as_dir(path)->entries();
}

std::vector<directory_entry> directory_tree::recursive_directory_entries(const std::string &path) {
  return get_node_as_dir(path)->recursive_entries();
}

data_status directory_tree::dstatus(const std::string &path) {
  return get_node_as_file(path)->dstatus();
}

bool directory_tree::is_regular_file(const std::string &path) {
  return get_node(path)->is_regular_file();
}

bool directory_tree::is_directory(const std::string &path) {
  return get_node(path)->is_directory();
}

void directory_tree::touch(const std::string &path) {
  auto time = utils::time_utils::now_ms();
  auto node = touch_node_path(path, time);
  if (node == nullptr) {
    throw directory_ops_exception("Path does not exist: " + path);
  }
  touch(node, time);
}

block_chain directory_tree::resolve_failures(const std::string &path, const block_chain &chain) {
  // TODO: Replace block_chain argument with chain id
  std::size_t chain_length = chain.block_names.size();
  std::vector<bool> failed(chain_length);
  LOG(log_level::info) << "Resolving failures for block chain " << chain.to_string() << " @ " << path;
  bool mid_failure = false;
  std::vector<std::string> fixed_chain;
  for (std::size_t i = 0; i < chain_length; i++) {
    std::string block_name = chain.block_names[i];
    auto parsed = storage::block_name_parser::parse(block_name);
    try {
      utils::retry_utils::retry(3, [parsed]() {
        storage::block_client c;
        c.connect(parsed.host, parsed.service_port, parsed.id);
        c.disconnect();
        return true;
      });
      LOG(log_level::info) << "Block " << block_name << " is still live";
      fixed_chain.push_back(block_name);
    } catch (std::exception &) {
      LOG(log_level::warn) << "Block " << block_name << " has failed, removing it from chain";
      failed[i] = true;
      if (i > 0 && i < chain_length - 1 && failed[i] && !failed[i - 1]) {
        mid_failure = true;
      }
    }
  }

  // Re-organize chain as needed
  using namespace storage;
  if (fixed_chain.empty()) {                       // All failed
    LOG(log_level::error) << "No blocks left in chain";
    throw directory_ops_exception("All blocks in the chain have failed.");
  } else if (fixed_chain.size() == 1) {            // All but one failed
    LOG(log_level::info) << "Only one block has remained in chain; setting singleton role";
    storage_->setup_block(fixed_chain[0], path, chain_role::singleton, "nil");
  } else {                                         // More than one left
    LOG(log_level::info) << fixed_chain.size() << " blocks left in chain";
    for (std::size_t i = 0; i < fixed_chain.size(); ++i) {
      std::string block_name = fixed_chain[i];
      std::string next_block_name = (i == fixed_chain.size() - 1) ? "nil" : fixed_chain[i + 1];
      int32_t role = (i == 0) ? chain_role::head : (i == fixed_chain.size() - 1) ? chain_role::tail : chain_role::mid;
      LOG(log_level::info) << "Setting block <" << block_name << ">: path=" << path << ", role=" << role << ", next="
                           << next_block_name;
      storage_->setup_block(block_name, path, role, next_block_name);
    }
    if (mid_failure) {
      LOG(log_level::info) << "Resending pending requests to resolve mid block failure";
      storage_->resend_pending(fixed_chain[0]);
    }
  }
  return block_chain{fixed_chain};
}

block_chain directory_tree::add_node(const std::string &path, const block_chain &chain, std::size_t count) {
  // TODO: Replace block_chain argument with chain id
  if (count == 0) return chain;

  using namespace storage;
  LOG(log_level::info) << "Adding " << count << " new blocks to block chain " << chain.to_string() << " @ " << path;

  auto new_blocks = allocator_->allocate(count, chain.block_names);
  auto updated_chain = chain.block_names;
  updated_chain.insert(updated_chain.end(), new_blocks.begin(), new_blocks.end());

  // Setup forwarding path
  LOG(log_level::info) << "Setting old tail block <" << chain.block_names.back() << ">: path=" << path << ", role="
                       << chain_role::tail << ", next=" << new_blocks.front();
  storage_->setup_block(chain.block_names.back(), path, chain_role::tail, new_blocks.front());
  for (std::size_t i = chain.block_names.size(); i < updated_chain.size(); i++) {
    std::string block_name = updated_chain[i];
    std::string next_block_name = (i == updated_chain.size() - 1) ? "nil" : updated_chain[i + 1];
    int32_t role = (i == 0) ? chain_role::head : (i == updated_chain.size() - 1) ? chain_role::tail : chain_role::mid;
    LOG(log_level::info) << "Setting block <" << block_name << ">: path=" << path << ", role=" << role << ", next="
                         << next_block_name;
    storage_->setup_block(block_name, path, role, next_block_name);
  }

  storage_->forward_all(chain.block_names.back());
  storage_->setup_block(chain.block_names.back(), path, chain_role::mid, new_blocks.front());

  return block_chain{updated_chain};
}

std::shared_ptr<ds_node> directory_tree::get_node_unsafe(const std::string &path) const {
  std::shared_ptr<ds_node> node = root_;
  for (auto &name: directory_utils::path_elements(path)) {
    if (!node->is_directory()) {
      return nullptr;
    } else {
      node = std::dynamic_pointer_cast<ds_dir_node>(node)->get_child(name);
      if (node == nullptr) {
        return nullptr;
      }
    }
  }
  return node;
}

std::shared_ptr<ds_node> directory_tree::get_node(const std::string &path) const {
  auto node = get_node_unsafe(path);
  if (node == nullptr) {
    throw directory_ops_exception("Path does not exist: " + path);
  }
  return node;
}

std::shared_ptr<ds_dir_node> directory_tree::get_node_as_dir(const std::string &path) const {
  auto node = get_node(path);
  if (node->is_regular_file()) {
    throw directory_ops_exception("Path corresponds to a file: " + path);
  }
  return std::dynamic_pointer_cast<ds_dir_node>(node);
}

std::shared_ptr<ds_file_node> directory_tree::get_node_as_file(const std::string &path) const {
  auto node = get_node(path);
  if (!node->is_regular_file()) {
    throw directory_ops_exception("Path corresponds to a directory: " + path);
  }
  return std::dynamic_pointer_cast<ds_file_node>(node);
}

std::shared_ptr<ds_node> directory_tree::touch_node_path(const std::string &path, const std::uint64_t time) const {
  std::shared_ptr<ds_node> node = root_;
  for (auto &name: directory_utils::path_elements(path)) {
    if (!node->is_directory()) {
      return nullptr;
    } else {
      node = std::dynamic_pointer_cast<ds_dir_node>(node)->get_child(name);
      if (node == nullptr) {
        return nullptr;
      }
      node->last_write_time(time);
    }
  }
  return node;
}

void directory_tree::touch(std::shared_ptr<ds_node> node, std::uint64_t time) {
  node->last_write_time(time);
  if (node->is_regular_file()) {
    return;
  }
  auto dir = std::dynamic_pointer_cast<ds_dir_node>(node);
  for (const auto &child: *dir) {
    touch(child.second, time);
  }
}

void directory_tree::clear_storage(std::shared_ptr<ds_node> node) {
  if (node->is_regular_file()) {
    auto file = std::dynamic_pointer_cast<ds_file_node>(node);
    auto s = file->dstatus();
    for (const auto &block: s.data_blocks()) {
      for (const auto &block_name: block.block_names) {
        storage_->reset(block_name);
      }
      allocator_->free(block.block_names);
    }
  } else if (node->is_directory()) {
    auto dir = std::dynamic_pointer_cast<ds_dir_node>(node);
    for (auto entry: *dir) {
      clear_storage(entry.second);
    }
  }
}

}
}