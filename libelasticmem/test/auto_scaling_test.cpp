#include "catch.hpp"

#include <thrift/transport/TTransportException.h>
#include <thread>
#include "../src/storage/manager/storage_management_server.h"
#include "../src/storage/manager/storage_management_client.h"
#include "../src/storage/manager/storage_manager.h"
#include "../src/storage/kv/kv_block.h"
#include "test_utils.h"
#include "../src/storage/service/block_server.h"
#include "../src/storage/kv/hash_slot.h"
#include "../src/directory/fs/directory_tree.h"
#include "../src/directory/fs/directory_server.h"

using namespace ::elasticmem::storage;
using namespace ::elasticmem::directory;
using namespace ::apache::thrift::transport;

#define NUM_BLOCKS 1
#define HOST "127.0.0.1"
#define DIRECTORY_SERVICE_PORT 9090
#define STORAGE_SERVICE_PORT 9091
#define STORAGE_MANAGEMENT_PORT 9092

TEST_CASE("scale_block_split_test", "[setup_block][path][slot_range]") {
  auto alloc = std::make_shared<sequential_block_allocator>();
  auto block_names = test_utils::init_block_names(2, STORAGE_SERVICE_PORT, STORAGE_MANAGEMENT_PORT, 0, 0);
  alloc->add_blocks(block_names);
  auto blocks = test_utils::init_kv_blocks(block_names);

  auto storage_server = block_server::create(blocks, HOST, STORAGE_SERVICE_PORT);
  std::thread storage_serve_thread([&storage_server] { storage_server->serve(); });
  test_utils::wait_till_server_ready(HOST, STORAGE_SERVICE_PORT);

  auto mgmt_server = storage_management_server::create(blocks, HOST, STORAGE_MANAGEMENT_PORT);
  std::thread mgmt_serve_thread([&mgmt_server] { mgmt_server->serve(); });
  test_utils::wait_till_server_ready(HOST, STORAGE_MANAGEMENT_PORT);

  auto sm = std::make_shared<storage_manager>();
  auto tree = std::make_shared<directory_tree>(alloc, sm);

  REQUIRE_NOTHROW(tree->create("/sandbox/file.txt", "/tmp", 1, 1));

  // Write some data into it
  for (std::size_t i = 0; i < 1000; ++i) {
    REQUIRE_NOTHROW(std::dynamic_pointer_cast<kv_block>(blocks[0])->put(std::to_string(i), std::to_string(i)));
  }

  REQUIRE_NOTHROW(tree->split_block("/sandbox/file.txt", 0));
  // Busy wait until number of blocks increases
  while (tree->dstatus("/sandbox/file.txt").data_blocks().size() == 1);

  for (std::size_t i = 0; i < 1000; i++) {
    std::string key = std::to_string(i);
    auto h = hash_slot::get(key);
    if (h >= 0 && h < 32768) {
      REQUIRE(std::dynamic_pointer_cast<kv_block>(blocks[0])->get(key) == key);
      REQUIRE(std::dynamic_pointer_cast<kv_block>(blocks[1])->get(key) == "!block_moved");
    } else {
      REQUIRE(std::dynamic_pointer_cast<kv_block>(blocks[0])->get(key) == "!block_moved");
      REQUIRE(std::dynamic_pointer_cast<kv_block>(blocks[1])->get(key) == key);
    }
  }

  storage_server->stop();
  if (storage_serve_thread.joinable()) {
    storage_serve_thread.join();
  }

  mgmt_server->stop();
  if (mgmt_serve_thread.joinable()) {
    mgmt_serve_thread.join();
  }
}

TEST_CASE("scale_add_block_test", "[setup_block][path][slot_range]") {
  auto alloc = std::make_shared<sequential_block_allocator>();
  auto block_names = test_utils::init_block_names(2, STORAGE_SERVICE_PORT, STORAGE_MANAGEMENT_PORT, 0, 0);
  alloc->add_blocks(block_names);
  auto blocks = test_utils::init_kv_blocks(block_names);

  auto storage_server = block_server::create(blocks, HOST, STORAGE_SERVICE_PORT);
  std::thread storage_serve_thread([&storage_server] { storage_server->serve(); });
  test_utils::wait_till_server_ready(HOST, STORAGE_SERVICE_PORT);

  auto mgmt_server = storage_management_server::create(blocks, HOST, STORAGE_MANAGEMENT_PORT);
  std::thread mgmt_serve_thread([&mgmt_server] { mgmt_server->serve(); });
  test_utils::wait_till_server_ready(HOST, STORAGE_MANAGEMENT_PORT);

  auto sm = std::make_shared<storage_manager>();
  auto tree = std::make_shared<directory_tree>(alloc, sm);

  REQUIRE_NOTHROW(tree->create("/sandbox/file.txt", "/tmp", 1, 1));

  // Write some data into it
  for (std::size_t i = 0; i < 1000; ++i) {
    REQUIRE_NOTHROW(std::dynamic_pointer_cast<kv_block>(blocks[0])->put(std::to_string(i), std::to_string(i)));
  }

  REQUIRE_NOTHROW(tree->add_block_to_file("/sandbox/file.txt"));
  // Busy wait until number of blocks increases
  while (tree->dstatus("/sandbox/file.txt").data_blocks().size() == 1);

  for (std::size_t i = 0; i < 1000; i++) {
    std::string key = std::to_string(i);
    auto h = hash_slot::get(key);
    if (h >= 0 && h < 32768) {
      REQUIRE(std::dynamic_pointer_cast<kv_block>(blocks[0])->get(key) == key);
      REQUIRE(std::dynamic_pointer_cast<kv_block>(blocks[1])->get(key) == "!block_moved");
    } else {
      REQUIRE(std::dynamic_pointer_cast<kv_block>(blocks[0])->get(key) == "!block_moved");
      REQUIRE(std::dynamic_pointer_cast<kv_block>(blocks[1])->get(key) == key);
    }
  }

  storage_server->stop();
  if (storage_serve_thread.joinable()) {
    storage_serve_thread.join();
  }

  mgmt_server->stop();
  if (mgmt_serve_thread.joinable()) {
    mgmt_serve_thread.join();
  }
}