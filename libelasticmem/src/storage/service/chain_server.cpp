#include "chain_server.h"
#include "chain_request_handler_factory.h"

#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TNonblockingServerSocket.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/server/TThreadPoolServer.h>

namespace elasticmem {
namespace storage {

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

std::shared_ptr<TServer> chain_server::create(std::vector<std::shared_ptr<chain_module>> &blocks,
                                              const std::string &address, int port, bool non_blocking) {
  std::shared_ptr<chain_request_serviceIfFactory> clone_factory(new chain_request_handler_factory(blocks));
  std::shared_ptr<chain_request_serviceProcessorFactory>
      proc_factory(new chain_request_serviceProcessorFactory(clone_factory));
  auto thread_manager = ThreadManager::newSimpleThreadManager(16);
  auto thread_factory = std::make_shared<PosixThreadFactory>();
  std::shared_ptr<TBinaryProtocolFactory> protocol_factory(new TBinaryProtocolFactory());
  thread_manager->threadFactory(thread_factory);
  thread_manager->start();
  if (non_blocking) {
    std::shared_ptr<TNonblockingServerSocket> socket(new TNonblockingServerSocket(port));
    std::shared_ptr<TServer> server(new TNonblockingServer(proc_factory, protocol_factory, socket, thread_manager));
    return server;
  } else {
    std::shared_ptr<TServerSocket> sock(new TServerSocket(address, port));
    std::shared_ptr<TFramedTransportFactory> transport_factory(new TFramedTransportFactory());
    std::shared_ptr<TServer> server(new TThreadPoolServer(proc_factory, sock, transport_factory, protocol_factory, thread_manager));
    return server;
  }
}
}
}