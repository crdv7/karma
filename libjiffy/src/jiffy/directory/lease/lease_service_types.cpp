/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "lease_service_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace jiffy { namespace directory {


rpc_lease_ack::~rpc_lease_ack() throw() {
}


void rpc_lease_ack::__set_renewed(const int64_t val) {
  this->renewed = val;
}

void rpc_lease_ack::__set_lease_period_ms(const int64_t val) {
  this->lease_period_ms = val;
}
std::ostream& operator<<(std::ostream& out, const rpc_lease_ack& obj)
{
  obj.printTo(out);
  return out;
}


void swap(rpc_lease_ack &a, rpc_lease_ack &b) {
  using ::std::swap;
  swap(a.renewed, b.renewed);
  swap(a.lease_period_ms, b.lease_period_ms);
}

rpc_lease_ack::rpc_lease_ack(const rpc_lease_ack& other0) {
  renewed = other0.renewed;
  lease_period_ms = other0.lease_period_ms;
}
rpc_lease_ack& rpc_lease_ack::operator=(const rpc_lease_ack& other1) {
  renewed = other1.renewed;
  lease_period_ms = other1.lease_period_ms;
  return *this;
}
void rpc_lease_ack::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "rpc_lease_ack(";
  out << "renewed=" << to_string(renewed);
  out << ", " << "lease_period_ms=" << to_string(lease_period_ms);
  out << ")";
}


lease_service_exception::~lease_service_exception() throw() {
}


void lease_service_exception::__set_msg(const std::string& val) {
  this->msg = val;
}
std::ostream& operator<<(std::ostream& out, const lease_service_exception& obj)
{
  obj.printTo(out);
  return out;
}


void swap(lease_service_exception &a, lease_service_exception &b) {
  using ::std::swap;
  swap(a.msg, b.msg);
  swap(a.__isset, b.__isset);
}

lease_service_exception::lease_service_exception(const lease_service_exception& other2) : TException() {
  msg = other2.msg;
  __isset = other2.__isset;
}
lease_service_exception& lease_service_exception::operator=(const lease_service_exception& other3) {
  msg = other3.msg;
  __isset = other3.__isset;
  return *this;
}
void lease_service_exception::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "lease_service_exception(";
  out << "msg=" << to_string(msg);
  out << ")";
}

const char* lease_service_exception::what() const throw() {
  try {
    std::stringstream ss;
    ss << "TException - service has thrown: " << *this;
    this->thriftTExceptionMessageHolder_ = ss.str();
    return this->thriftTExceptionMessageHolder_.c_str();
  } catch (const std::exception&) {
    return "TException - service has thrown: lease_service_exception";
  }
}

}} // namespace
