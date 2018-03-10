/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef kv_management_rpc_service_H
#define kv_management_rpc_service_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "kv_service_types.h"

namespace elasticmem { namespace kv {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class kv_management_rpc_serviceIf {
 public:
  virtual ~kv_management_rpc_serviceIf() {}
  virtual void flush(const int32_t block_id, const std::string& path) = 0;
  virtual void load(const int32_t block_id, const std::string& path) = 0;
  virtual void clear(const int32_t block_id) = 0;
  virtual int64_t storage_capacity(const int32_t block_id) = 0;
  virtual int64_t storage_size(const int32_t block_id) = 0;
};

class kv_management_rpc_serviceIfFactory {
 public:
  typedef kv_management_rpc_serviceIf Handler;

  virtual ~kv_management_rpc_serviceIfFactory() {}

  virtual kv_management_rpc_serviceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(kv_management_rpc_serviceIf* /* handler */) = 0;
};

class kv_management_rpc_serviceIfSingletonFactory : virtual public kv_management_rpc_serviceIfFactory {
 public:
  kv_management_rpc_serviceIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<kv_management_rpc_serviceIf>& iface) : iface_(iface) {}
  virtual ~kv_management_rpc_serviceIfSingletonFactory() {}

  virtual kv_management_rpc_serviceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(kv_management_rpc_serviceIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<kv_management_rpc_serviceIf> iface_;
};

class kv_management_rpc_serviceNull : virtual public kv_management_rpc_serviceIf {
 public:
  virtual ~kv_management_rpc_serviceNull() {}
  void flush(const int32_t /* block_id */, const std::string& /* path */) {
    return;
  }
  void load(const int32_t /* block_id */, const std::string& /* path */) {
    return;
  }
  void clear(const int32_t /* block_id */) {
    return;
  }
  int64_t storage_capacity(const int32_t /* block_id */) {
    int64_t _return = 0;
    return _return;
  }
  int64_t storage_size(const int32_t /* block_id */) {
    int64_t _return = 0;
    return _return;
  }
};

typedef struct _kv_management_rpc_service_flush_args__isset {
  _kv_management_rpc_service_flush_args__isset() : block_id(false), path(false) {}
  bool block_id :1;
  bool path :1;
} _kv_management_rpc_service_flush_args__isset;

class kv_management_rpc_service_flush_args {
 public:

  kv_management_rpc_service_flush_args(const kv_management_rpc_service_flush_args&);
  kv_management_rpc_service_flush_args& operator=(const kv_management_rpc_service_flush_args&);
  kv_management_rpc_service_flush_args() : block_id(0), path() {
  }

  virtual ~kv_management_rpc_service_flush_args() throw();
  int32_t block_id;
  std::string path;

  _kv_management_rpc_service_flush_args__isset __isset;

  void __set_block_id(const int32_t val);

  void __set_path(const std::string& val);

  bool operator == (const kv_management_rpc_service_flush_args & rhs) const
  {
    if (!(block_id == rhs.block_id))
      return false;
    if (!(path == rhs.path))
      return false;
    return true;
  }
  bool operator != (const kv_management_rpc_service_flush_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const kv_management_rpc_service_flush_args & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};


class kv_management_rpc_service_flush_pargs {
 public:


  virtual ~kv_management_rpc_service_flush_pargs() throw();
  const int32_t* block_id;
  const std::string* path;

  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};

typedef struct _kv_management_rpc_service_flush_result__isset {
  _kv_management_rpc_service_flush_result__isset() : ex(false) {}
  bool ex :1;
} _kv_management_rpc_service_flush_result__isset;

class kv_management_rpc_service_flush_result {
 public:

  kv_management_rpc_service_flush_result(const kv_management_rpc_service_flush_result&);
  kv_management_rpc_service_flush_result& operator=(const kv_management_rpc_service_flush_result&);
  kv_management_rpc_service_flush_result() {
  }

  virtual ~kv_management_rpc_service_flush_result() throw();
  kv_management_rpc_exception ex;

  _kv_management_rpc_service_flush_result__isset __isset;

  void __set_ex(const kv_management_rpc_exception& val);

  bool operator == (const kv_management_rpc_service_flush_result & rhs) const
  {
    if (!(ex == rhs.ex))
      return false;
    return true;
  }
  bool operator != (const kv_management_rpc_service_flush_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const kv_management_rpc_service_flush_result & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};

typedef struct _kv_management_rpc_service_flush_presult__isset {
  _kv_management_rpc_service_flush_presult__isset() : ex(false) {}
  bool ex :1;
} _kv_management_rpc_service_flush_presult__isset;

class kv_management_rpc_service_flush_presult {
 public:


  virtual ~kv_management_rpc_service_flush_presult() throw();
  kv_management_rpc_exception ex;

  _kv_management_rpc_service_flush_presult__isset __isset;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);

};

typedef struct _kv_management_rpc_service_load_args__isset {
  _kv_management_rpc_service_load_args__isset() : block_id(false), path(false) {}
  bool block_id :1;
  bool path :1;
} _kv_management_rpc_service_load_args__isset;

class kv_management_rpc_service_load_args {
 public:

  kv_management_rpc_service_load_args(const kv_management_rpc_service_load_args&);
  kv_management_rpc_service_load_args& operator=(const kv_management_rpc_service_load_args&);
  kv_management_rpc_service_load_args() : block_id(0), path() {
  }

  virtual ~kv_management_rpc_service_load_args() throw();
  int32_t block_id;
  std::string path;

  _kv_management_rpc_service_load_args__isset __isset;

  void __set_block_id(const int32_t val);

  void __set_path(const std::string& val);

  bool operator == (const kv_management_rpc_service_load_args & rhs) const
  {
    if (!(block_id == rhs.block_id))
      return false;
    if (!(path == rhs.path))
      return false;
    return true;
  }
  bool operator != (const kv_management_rpc_service_load_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const kv_management_rpc_service_load_args & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};


class kv_management_rpc_service_load_pargs {
 public:


  virtual ~kv_management_rpc_service_load_pargs() throw();
  const int32_t* block_id;
  const std::string* path;

  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};

typedef struct _kv_management_rpc_service_load_result__isset {
  _kv_management_rpc_service_load_result__isset() : ex(false) {}
  bool ex :1;
} _kv_management_rpc_service_load_result__isset;

class kv_management_rpc_service_load_result {
 public:

  kv_management_rpc_service_load_result(const kv_management_rpc_service_load_result&);
  kv_management_rpc_service_load_result& operator=(const kv_management_rpc_service_load_result&);
  kv_management_rpc_service_load_result() {
  }

  virtual ~kv_management_rpc_service_load_result() throw();
  kv_management_rpc_exception ex;

  _kv_management_rpc_service_load_result__isset __isset;

  void __set_ex(const kv_management_rpc_exception& val);

  bool operator == (const kv_management_rpc_service_load_result & rhs) const
  {
    if (!(ex == rhs.ex))
      return false;
    return true;
  }
  bool operator != (const kv_management_rpc_service_load_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const kv_management_rpc_service_load_result & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};

typedef struct _kv_management_rpc_service_load_presult__isset {
  _kv_management_rpc_service_load_presult__isset() : ex(false) {}
  bool ex :1;
} _kv_management_rpc_service_load_presult__isset;

class kv_management_rpc_service_load_presult {
 public:


  virtual ~kv_management_rpc_service_load_presult() throw();
  kv_management_rpc_exception ex;

  _kv_management_rpc_service_load_presult__isset __isset;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);

};

typedef struct _kv_management_rpc_service_clear_args__isset {
  _kv_management_rpc_service_clear_args__isset() : block_id(false) {}
  bool block_id :1;
} _kv_management_rpc_service_clear_args__isset;

class kv_management_rpc_service_clear_args {
 public:

  kv_management_rpc_service_clear_args(const kv_management_rpc_service_clear_args&);
  kv_management_rpc_service_clear_args& operator=(const kv_management_rpc_service_clear_args&);
  kv_management_rpc_service_clear_args() : block_id(0) {
  }

  virtual ~kv_management_rpc_service_clear_args() throw();
  int32_t block_id;

  _kv_management_rpc_service_clear_args__isset __isset;

  void __set_block_id(const int32_t val);

  bool operator == (const kv_management_rpc_service_clear_args & rhs) const
  {
    if (!(block_id == rhs.block_id))
      return false;
    return true;
  }
  bool operator != (const kv_management_rpc_service_clear_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const kv_management_rpc_service_clear_args & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};


class kv_management_rpc_service_clear_pargs {
 public:


  virtual ~kv_management_rpc_service_clear_pargs() throw();
  const int32_t* block_id;

  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};

typedef struct _kv_management_rpc_service_clear_result__isset {
  _kv_management_rpc_service_clear_result__isset() : ex(false) {}
  bool ex :1;
} _kv_management_rpc_service_clear_result__isset;

class kv_management_rpc_service_clear_result {
 public:

  kv_management_rpc_service_clear_result(const kv_management_rpc_service_clear_result&);
  kv_management_rpc_service_clear_result& operator=(const kv_management_rpc_service_clear_result&);
  kv_management_rpc_service_clear_result() {
  }

  virtual ~kv_management_rpc_service_clear_result() throw();
  kv_management_rpc_exception ex;

  _kv_management_rpc_service_clear_result__isset __isset;

  void __set_ex(const kv_management_rpc_exception& val);

  bool operator == (const kv_management_rpc_service_clear_result & rhs) const
  {
    if (!(ex == rhs.ex))
      return false;
    return true;
  }
  bool operator != (const kv_management_rpc_service_clear_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const kv_management_rpc_service_clear_result & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};

typedef struct _kv_management_rpc_service_clear_presult__isset {
  _kv_management_rpc_service_clear_presult__isset() : ex(false) {}
  bool ex :1;
} _kv_management_rpc_service_clear_presult__isset;

class kv_management_rpc_service_clear_presult {
 public:


  virtual ~kv_management_rpc_service_clear_presult() throw();
  kv_management_rpc_exception ex;

  _kv_management_rpc_service_clear_presult__isset __isset;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);

};

typedef struct _kv_management_rpc_service_storage_capacity_args__isset {
  _kv_management_rpc_service_storage_capacity_args__isset() : block_id(false) {}
  bool block_id :1;
} _kv_management_rpc_service_storage_capacity_args__isset;

class kv_management_rpc_service_storage_capacity_args {
 public:

  kv_management_rpc_service_storage_capacity_args(const kv_management_rpc_service_storage_capacity_args&);
  kv_management_rpc_service_storage_capacity_args& operator=(const kv_management_rpc_service_storage_capacity_args&);
  kv_management_rpc_service_storage_capacity_args() : block_id(0) {
  }

  virtual ~kv_management_rpc_service_storage_capacity_args() throw();
  int32_t block_id;

  _kv_management_rpc_service_storage_capacity_args__isset __isset;

  void __set_block_id(const int32_t val);

  bool operator == (const kv_management_rpc_service_storage_capacity_args & rhs) const
  {
    if (!(block_id == rhs.block_id))
      return false;
    return true;
  }
  bool operator != (const kv_management_rpc_service_storage_capacity_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const kv_management_rpc_service_storage_capacity_args & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};


class kv_management_rpc_service_storage_capacity_pargs {
 public:


  virtual ~kv_management_rpc_service_storage_capacity_pargs() throw();
  const int32_t* block_id;

  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};

typedef struct _kv_management_rpc_service_storage_capacity_result__isset {
  _kv_management_rpc_service_storage_capacity_result__isset() : success(false), ex(false) {}
  bool success :1;
  bool ex :1;
} _kv_management_rpc_service_storage_capacity_result__isset;

class kv_management_rpc_service_storage_capacity_result {
 public:

  kv_management_rpc_service_storage_capacity_result(const kv_management_rpc_service_storage_capacity_result&);
  kv_management_rpc_service_storage_capacity_result& operator=(const kv_management_rpc_service_storage_capacity_result&);
  kv_management_rpc_service_storage_capacity_result() : success(0) {
  }

  virtual ~kv_management_rpc_service_storage_capacity_result() throw();
  int64_t success;
  kv_management_rpc_exception ex;

  _kv_management_rpc_service_storage_capacity_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_ex(const kv_management_rpc_exception& val);

  bool operator == (const kv_management_rpc_service_storage_capacity_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(ex == rhs.ex))
      return false;
    return true;
  }
  bool operator != (const kv_management_rpc_service_storage_capacity_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const kv_management_rpc_service_storage_capacity_result & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};

typedef struct _kv_management_rpc_service_storage_capacity_presult__isset {
  _kv_management_rpc_service_storage_capacity_presult__isset() : success(false), ex(false) {}
  bool success :1;
  bool ex :1;
} _kv_management_rpc_service_storage_capacity_presult__isset;

class kv_management_rpc_service_storage_capacity_presult {
 public:


  virtual ~kv_management_rpc_service_storage_capacity_presult() throw();
  int64_t* success;
  kv_management_rpc_exception ex;

  _kv_management_rpc_service_storage_capacity_presult__isset __isset;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);

};

typedef struct _kv_management_rpc_service_storage_size_args__isset {
  _kv_management_rpc_service_storage_size_args__isset() : block_id(false) {}
  bool block_id :1;
} _kv_management_rpc_service_storage_size_args__isset;

class kv_management_rpc_service_storage_size_args {
 public:

  kv_management_rpc_service_storage_size_args(const kv_management_rpc_service_storage_size_args&);
  kv_management_rpc_service_storage_size_args& operator=(const kv_management_rpc_service_storage_size_args&);
  kv_management_rpc_service_storage_size_args() : block_id(0) {
  }

  virtual ~kv_management_rpc_service_storage_size_args() throw();
  int32_t block_id;

  _kv_management_rpc_service_storage_size_args__isset __isset;

  void __set_block_id(const int32_t val);

  bool operator == (const kv_management_rpc_service_storage_size_args & rhs) const
  {
    if (!(block_id == rhs.block_id))
      return false;
    return true;
  }
  bool operator != (const kv_management_rpc_service_storage_size_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const kv_management_rpc_service_storage_size_args & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};


class kv_management_rpc_service_storage_size_pargs {
 public:


  virtual ~kv_management_rpc_service_storage_size_pargs() throw();
  const int32_t* block_id;

  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};

typedef struct _kv_management_rpc_service_storage_size_result__isset {
  _kv_management_rpc_service_storage_size_result__isset() : success(false), ex(false) {}
  bool success :1;
  bool ex :1;
} _kv_management_rpc_service_storage_size_result__isset;

class kv_management_rpc_service_storage_size_result {
 public:

  kv_management_rpc_service_storage_size_result(const kv_management_rpc_service_storage_size_result&);
  kv_management_rpc_service_storage_size_result& operator=(const kv_management_rpc_service_storage_size_result&);
  kv_management_rpc_service_storage_size_result() : success(0) {
  }

  virtual ~kv_management_rpc_service_storage_size_result() throw();
  int64_t success;
  kv_management_rpc_exception ex;

  _kv_management_rpc_service_storage_size_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_ex(const kv_management_rpc_exception& val);

  bool operator == (const kv_management_rpc_service_storage_size_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(ex == rhs.ex))
      return false;
    return true;
  }
  bool operator != (const kv_management_rpc_service_storage_size_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const kv_management_rpc_service_storage_size_result & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

};

typedef struct _kv_management_rpc_service_storage_size_presult__isset {
  _kv_management_rpc_service_storage_size_presult__isset() : success(false), ex(false) {}
  bool success :1;
  bool ex :1;
} _kv_management_rpc_service_storage_size_presult__isset;

class kv_management_rpc_service_storage_size_presult {
 public:


  virtual ~kv_management_rpc_service_storage_size_presult() throw();
  int64_t* success;
  kv_management_rpc_exception ex;

  _kv_management_rpc_service_storage_size_presult__isset __isset;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);

};

template <class Protocol_>
class kv_management_rpc_serviceClientT : virtual public kv_management_rpc_serviceIf {
 public:
  kv_management_rpc_serviceClientT(apache::thrift::stdcxx::shared_ptr< Protocol_> prot) {
    setProtocolT(prot);
  }
  kv_management_rpc_serviceClientT(apache::thrift::stdcxx::shared_ptr< Protocol_> iprot, apache::thrift::stdcxx::shared_ptr< Protocol_> oprot) {
    setProtocolT(iprot,oprot);
  }
 private:
  void setProtocolT(apache::thrift::stdcxx::shared_ptr< Protocol_> prot) {
  setProtocolT(prot,prot);
  }
  void setProtocolT(apache::thrift::stdcxx::shared_ptr< Protocol_> iprot, apache::thrift::stdcxx::shared_ptr< Protocol_> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return this->piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return this->poprot_;
  }
  void flush(const int32_t block_id, const std::string& path);
  void send_flush(const int32_t block_id, const std::string& path);
  void recv_flush();
  void load(const int32_t block_id, const std::string& path);
  void send_load(const int32_t block_id, const std::string& path);
  void recv_load();
  void clear(const int32_t block_id);
  void send_clear(const int32_t block_id);
  void recv_clear();
  int64_t storage_capacity(const int32_t block_id);
  void send_storage_capacity(const int32_t block_id);
  int64_t recv_storage_capacity();
  int64_t storage_size(const int32_t block_id);
  void send_storage_size(const int32_t block_id);
  int64_t recv_storage_size();
 protected:
  apache::thrift::stdcxx::shared_ptr< Protocol_> piprot_;
  apache::thrift::stdcxx::shared_ptr< Protocol_> poprot_;
  Protocol_* iprot_;
  Protocol_* oprot_;
};

typedef kv_management_rpc_serviceClientT< ::apache::thrift::protocol::TProtocol> kv_management_rpc_serviceClient;

template <class Protocol_>
class kv_management_rpc_serviceProcessorT : public ::apache::thrift::TDispatchProcessorT<Protocol_> {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<kv_management_rpc_serviceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
  virtual bool dispatchCallTemplated(Protocol_* iprot, Protocol_* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (kv_management_rpc_serviceProcessorT::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef void (kv_management_rpc_serviceProcessorT::*SpecializedProcessFunction)(int32_t, Protocol_*, Protocol_*, void*);
  struct ProcessFunctions {
    ProcessFunction generic;
    SpecializedProcessFunction specialized;
    ProcessFunctions(ProcessFunction g, SpecializedProcessFunction s) :
      generic(g),
      specialized(s) {}
    ProcessFunctions() : generic(NULL), specialized(NULL) {}
  };
  typedef std::map<std::string, ProcessFunctions> ProcessMap;
  ProcessMap processMap_;
  void process_flush(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_flush(int32_t seqid, Protocol_* iprot, Protocol_* oprot, void* callContext);
  void process_load(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_load(int32_t seqid, Protocol_* iprot, Protocol_* oprot, void* callContext);
  void process_clear(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_clear(int32_t seqid, Protocol_* iprot, Protocol_* oprot, void* callContext);
  void process_storage_capacity(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_storage_capacity(int32_t seqid, Protocol_* iprot, Protocol_* oprot, void* callContext);
  void process_storage_size(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_storage_size(int32_t seqid, Protocol_* iprot, Protocol_* oprot, void* callContext);
 public:
  kv_management_rpc_serviceProcessorT(::apache::thrift::stdcxx::shared_ptr<kv_management_rpc_serviceIf> iface) :
    iface_(iface) {
    processMap_["flush"] = ProcessFunctions(
      &kv_management_rpc_serviceProcessorT::process_flush,
      &kv_management_rpc_serviceProcessorT::process_flush);
    processMap_["load"] = ProcessFunctions(
      &kv_management_rpc_serviceProcessorT::process_load,
      &kv_management_rpc_serviceProcessorT::process_load);
    processMap_["clear"] = ProcessFunctions(
      &kv_management_rpc_serviceProcessorT::process_clear,
      &kv_management_rpc_serviceProcessorT::process_clear);
    processMap_["storage_capacity"] = ProcessFunctions(
      &kv_management_rpc_serviceProcessorT::process_storage_capacity,
      &kv_management_rpc_serviceProcessorT::process_storage_capacity);
    processMap_["storage_size"] = ProcessFunctions(
      &kv_management_rpc_serviceProcessorT::process_storage_size,
      &kv_management_rpc_serviceProcessorT::process_storage_size);
  }

  virtual ~kv_management_rpc_serviceProcessorT() {}
};

typedef kv_management_rpc_serviceProcessorT< ::apache::thrift::protocol::TDummyProtocol > kv_management_rpc_serviceProcessor;

template <class Protocol_>
class kv_management_rpc_serviceProcessorFactoryT : public ::apache::thrift::TProcessorFactory {
 public:
  kv_management_rpc_serviceProcessorFactoryT(const ::apache::thrift::stdcxx::shared_ptr< kv_management_rpc_serviceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< kv_management_rpc_serviceIfFactory > handlerFactory_;
};

typedef kv_management_rpc_serviceProcessorFactoryT< ::apache::thrift::protocol::TDummyProtocol > kv_management_rpc_serviceProcessorFactory;

class kv_management_rpc_serviceMultiface : virtual public kv_management_rpc_serviceIf {
 public:
  kv_management_rpc_serviceMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<kv_management_rpc_serviceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~kv_management_rpc_serviceMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<kv_management_rpc_serviceIf> > ifaces_;
  kv_management_rpc_serviceMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<kv_management_rpc_serviceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void flush(const int32_t block_id, const std::string& path) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->flush(block_id, path);
    }
    ifaces_[i]->flush(block_id, path);
  }

  void load(const int32_t block_id, const std::string& path) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->load(block_id, path);
    }
    ifaces_[i]->load(block_id, path);
  }

  void clear(const int32_t block_id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->clear(block_id);
    }
    ifaces_[i]->clear(block_id);
  }

  int64_t storage_capacity(const int32_t block_id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->storage_capacity(block_id);
    }
    return ifaces_[i]->storage_capacity(block_id);
  }

  int64_t storage_size(const int32_t block_id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->storage_size(block_id);
    }
    return ifaces_[i]->storage_size(block_id);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
template <class Protocol_>
class kv_management_rpc_serviceConcurrentClientT : virtual public kv_management_rpc_serviceIf {
 public:
  kv_management_rpc_serviceConcurrentClientT(apache::thrift::stdcxx::shared_ptr< Protocol_> prot) {
    setProtocolT(prot);
  }
  kv_management_rpc_serviceConcurrentClientT(apache::thrift::stdcxx::shared_ptr< Protocol_> iprot, apache::thrift::stdcxx::shared_ptr< Protocol_> oprot) {
    setProtocolT(iprot,oprot);
  }
 private:
  void setProtocolT(apache::thrift::stdcxx::shared_ptr< Protocol_> prot) {
  setProtocolT(prot,prot);
  }
  void setProtocolT(apache::thrift::stdcxx::shared_ptr< Protocol_> iprot, apache::thrift::stdcxx::shared_ptr< Protocol_> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return this->piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return this->poprot_;
  }
  void flush(const int32_t block_id, const std::string& path);
  int32_t send_flush(const int32_t block_id, const std::string& path);
  void recv_flush(const int32_t seqid);
  void load(const int32_t block_id, const std::string& path);
  int32_t send_load(const int32_t block_id, const std::string& path);
  void recv_load(const int32_t seqid);
  void clear(const int32_t block_id);
  int32_t send_clear(const int32_t block_id);
  void recv_clear(const int32_t seqid);
  int64_t storage_capacity(const int32_t block_id);
  int32_t send_storage_capacity(const int32_t block_id);
  int64_t recv_storage_capacity(const int32_t seqid);
  int64_t storage_size(const int32_t block_id);
  int32_t send_storage_size(const int32_t block_id);
  int64_t recv_storage_size(const int32_t seqid);
 protected:
  apache::thrift::stdcxx::shared_ptr< Protocol_> piprot_;
  apache::thrift::stdcxx::shared_ptr< Protocol_> poprot_;
  Protocol_* iprot_;
  Protocol_* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

typedef kv_management_rpc_serviceConcurrentClientT< ::apache::thrift::protocol::TProtocol> kv_management_rpc_serviceConcurrentClient;

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

}} // namespace

#include "kv_management_rpc_service.tcc"
#include "kv_service_types.tcc"

#endif
