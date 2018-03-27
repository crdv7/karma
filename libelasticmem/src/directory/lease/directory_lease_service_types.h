/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef directory_lease_service_TYPES_H
#define directory_lease_service_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>


namespace elasticmem { namespace directory {

class rpc_lease_update;

class rpc_lease_ack;

class directory_lease_service_exception;


class rpc_lease_update {
 public:

  rpc_lease_update(const rpc_lease_update&);
  rpc_lease_update& operator=(const rpc_lease_update&);
  rpc_lease_update() {
  }

  virtual ~rpc_lease_update() throw();
  std::vector<std::string>  to_renew;
  std::vector<std::string>  to_flush;
  std::vector<std::string>  to_remove;

  void __set_to_renew(const std::vector<std::string> & val);

  void __set_to_flush(const std::vector<std::string> & val);

  void __set_to_remove(const std::vector<std::string> & val);

  bool operator == (const rpc_lease_update & rhs) const
  {
    if (!(to_renew == rhs.to_renew))
      return false;
    if (!(to_flush == rhs.to_flush))
      return false;
    if (!(to_remove == rhs.to_remove))
      return false;
    return true;
  }
  bool operator != (const rpc_lease_update &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const rpc_lease_update & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(rpc_lease_update &a, rpc_lease_update &b);

std::ostream& operator<<(std::ostream& out, const rpc_lease_update& obj);


class rpc_lease_ack {
 public:

  rpc_lease_ack(const rpc_lease_ack&);
  rpc_lease_ack& operator=(const rpc_lease_ack&);
  rpc_lease_ack() : renewed(0), flushed(0), removed(0) {
  }

  virtual ~rpc_lease_ack() throw();
  int64_t renewed;
  int64_t flushed;
  int64_t removed;

  void __set_renewed(const int64_t val);

  void __set_flushed(const int64_t val);

  void __set_removed(const int64_t val);

  bool operator == (const rpc_lease_ack & rhs) const
  {
    if (!(renewed == rhs.renewed))
      return false;
    if (!(flushed == rhs.flushed))
      return false;
    if (!(removed == rhs.removed))
      return false;
    return true;
  }
  bool operator != (const rpc_lease_ack &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const rpc_lease_ack & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(rpc_lease_ack &a, rpc_lease_ack &b);

std::ostream& operator<<(std::ostream& out, const rpc_lease_ack& obj);

typedef struct _directory_lease_service_exception__isset {
  _directory_lease_service_exception__isset() : msg(false) {}
  bool msg :1;
} _directory_lease_service_exception__isset;

class directory_lease_service_exception : public ::apache::thrift::TException {
 public:

  directory_lease_service_exception(const directory_lease_service_exception&);
  directory_lease_service_exception& operator=(const directory_lease_service_exception&);
  directory_lease_service_exception() : msg() {
  }

  virtual ~directory_lease_service_exception() throw();
  std::string msg;

  _directory_lease_service_exception__isset __isset;

  void __set_msg(const std::string& val);

  bool operator == (const directory_lease_service_exception & rhs) const
  {
    if (!(msg == rhs.msg))
      return false;
    return true;
  }
  bool operator != (const directory_lease_service_exception &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const directory_lease_service_exception & ) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
  mutable std::string thriftTExceptionMessageHolder_;
  const char* what() const throw();
};

void swap(directory_lease_service_exception &a, directory_lease_service_exception &b);

std::ostream& operator<<(std::ostream& out, const directory_lease_service_exception& obj);

}} // namespace

#include "directory_lease_service_types.tcc"

#endif