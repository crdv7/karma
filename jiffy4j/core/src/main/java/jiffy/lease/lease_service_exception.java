/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package jiffy.lease;

@SuppressWarnings({"cast", "rawtypes", "serial", "unchecked", "unused"})
@javax.annotation.Generated(value = "Autogenerated by Thrift Compiler (0.12.0)")
public class lease_service_exception extends org.apache.thrift.TException implements org.apache.thrift.TBase<lease_service_exception, lease_service_exception._Fields>, java.io.Serializable, Cloneable, Comparable<lease_service_exception> {
  private static final org.apache.thrift.protocol.TStruct STRUCT_DESC = new org.apache.thrift.protocol.TStruct("lease_service_exception");

  private static final org.apache.thrift.protocol.TField MSG_FIELD_DESC = new org.apache.thrift.protocol.TField("msg", org.apache.thrift.protocol.TType.STRING, (short)1);

  private static final org.apache.thrift.scheme.SchemeFactory STANDARD_SCHEME_FACTORY = new lease_service_exceptionStandardSchemeFactory();
  private static final org.apache.thrift.scheme.SchemeFactory TUPLE_SCHEME_FACTORY = new lease_service_exceptionTupleSchemeFactory();

  public @org.apache.thrift.annotation.Nullable java.lang.String msg; // required

  /** The set of fields this struct contains, along with convenience methods for finding and manipulating them. */
  public enum _Fields implements org.apache.thrift.TFieldIdEnum {
    MSG((short)1, "msg");

    private static final java.util.Map<java.lang.String, _Fields> byName = new java.util.HashMap<java.lang.String, _Fields>();

    static {
      for (_Fields field : java.util.EnumSet.allOf(_Fields.class)) {
        byName.put(field.getFieldName(), field);
      }
    }

    /**
     * Find the _Fields constant that matches fieldId, or null if its not found.
     */
    @org.apache.thrift.annotation.Nullable
    public static _Fields findByThriftId(int fieldId) {
      switch(fieldId) {
        case 1: // MSG
          return MSG;
        default:
          return null;
      }
    }

    /**
     * Find the _Fields constant that matches fieldId, throwing an exception
     * if it is not found.
     */
    public static _Fields findByThriftIdOrThrow(int fieldId) {
      _Fields fields = findByThriftId(fieldId);
      if (fields == null) throw new java.lang.IllegalArgumentException("Field " + fieldId + " doesn't exist!");
      return fields;
    }

    /**
     * Find the _Fields constant that matches name, or null if its not found.
     */
    @org.apache.thrift.annotation.Nullable
    public static _Fields findByName(java.lang.String name) {
      return byName.get(name);
    }

    private final short _thriftId;
    private final java.lang.String _fieldName;

    _Fields(short thriftId, java.lang.String fieldName) {
      _thriftId = thriftId;
      _fieldName = fieldName;
    }

    public short getThriftFieldId() {
      return _thriftId;
    }

    public java.lang.String getFieldName() {
      return _fieldName;
    }
  }

  // isset id assignments
  public static final java.util.Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> metaDataMap;
  static {
    java.util.Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> tmpMap = new java.util.EnumMap<_Fields, org.apache.thrift.meta_data.FieldMetaData>(_Fields.class);
    tmpMap.put(_Fields.MSG, new org.apache.thrift.meta_data.FieldMetaData("msg", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    metaDataMap = java.util.Collections.unmodifiableMap(tmpMap);
    org.apache.thrift.meta_data.FieldMetaData.addStructMetaDataMap(lease_service_exception.class, metaDataMap);
  }

  public lease_service_exception() {
  }

  public lease_service_exception(
    java.lang.String msg)
  {
    this();
    this.msg = msg;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public lease_service_exception(lease_service_exception other) {
    if (other.isSetMsg()) {
      this.msg = other.msg;
    }
  }

  public lease_service_exception deepCopy() {
    return new lease_service_exception(this);
  }

  @Override
  public void clear() {
    this.msg = null;
  }

  @org.apache.thrift.annotation.Nullable
  public java.lang.String getMsg() {
    return this.msg;
  }

  public lease_service_exception setMsg(@org.apache.thrift.annotation.Nullable java.lang.String msg) {
    this.msg = msg;
    return this;
  }

  public void unsetMsg() {
    this.msg = null;
  }

  /** Returns true if field msg is set (has been assigned a value) and false otherwise */
  public boolean isSetMsg() {
    return this.msg != null;
  }

  public void setMsgIsSet(boolean value) {
    if (!value) {
      this.msg = null;
    }
  }

  public void setFieldValue(_Fields field, @org.apache.thrift.annotation.Nullable java.lang.Object value) {
    switch (field) {
    case MSG:
      if (value == null) {
        unsetMsg();
      } else {
        setMsg((java.lang.String)value);
      }
      break;

    }
  }

  @org.apache.thrift.annotation.Nullable
  public java.lang.Object getFieldValue(_Fields field) {
    switch (field) {
    case MSG:
      return getMsg();

    }
    throw new java.lang.IllegalStateException();
  }

  /** Returns true if field corresponding to fieldID is set (has been assigned a value) and false otherwise */
  public boolean isSet(_Fields field) {
    if (field == null) {
      throw new java.lang.IllegalArgumentException();
    }

    switch (field) {
    case MSG:
      return isSetMsg();
    }
    throw new java.lang.IllegalStateException();
  }

  @Override
  public boolean equals(java.lang.Object that) {
    if (that == null)
      return false;
    if (that instanceof lease_service_exception)
      return this.equals((lease_service_exception)that);
    return false;
  }

  public boolean equals(lease_service_exception that) {
    if (that == null)
      return false;
    if (this == that)
      return true;

    boolean this_present_msg = true && this.isSetMsg();
    boolean that_present_msg = true && that.isSetMsg();
    if (this_present_msg || that_present_msg) {
      if (!(this_present_msg && that_present_msg))
        return false;
      if (!this.msg.equals(that.msg))
        return false;
    }

    return true;
  }

  @Override
  public int hashCode() {
    int hashCode = 1;

    hashCode = hashCode * 8191 + ((isSetMsg()) ? 131071 : 524287);
    if (isSetMsg())
      hashCode = hashCode * 8191 + msg.hashCode();

    return hashCode;
  }

  @Override
  public int compareTo(lease_service_exception other) {
    if (!getClass().equals(other.getClass())) {
      return getClass().getName().compareTo(other.getClass().getName());
    }

    int lastComparison = 0;

    lastComparison = java.lang.Boolean.valueOf(isSetMsg()).compareTo(other.isSetMsg());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetMsg()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.msg, other.msg);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    return 0;
  }

  @org.apache.thrift.annotation.Nullable
  public _Fields fieldForId(int fieldId) {
    return _Fields.findByThriftId(fieldId);
  }

  public void read(org.apache.thrift.protocol.TProtocol iprot) throws org.apache.thrift.TException {
    scheme(iprot).read(iprot, this);
  }

  public void write(org.apache.thrift.protocol.TProtocol oprot) throws org.apache.thrift.TException {
    scheme(oprot).write(oprot, this);
  }

  @Override
  public java.lang.String toString() {
    java.lang.StringBuilder sb = new java.lang.StringBuilder("lease_service_exception(");
    boolean first = true;

    sb.append("msg:");
    if (this.msg == null) {
      sb.append("null");
    } else {
      sb.append(this.msg);
    }
    first = false;
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws org.apache.thrift.TException {
    // check for required fields
    // check for sub-struct validity
  }

  private void writeObject(java.io.ObjectOutputStream out) throws java.io.IOException {
    try {
      write(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(out)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private void readObject(java.io.ObjectInputStream in) throws java.io.IOException, java.lang.ClassNotFoundException {
    try {
      read(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(in)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private static class lease_service_exceptionStandardSchemeFactory implements org.apache.thrift.scheme.SchemeFactory {
    public lease_service_exceptionStandardScheme getScheme() {
      return new lease_service_exceptionStandardScheme();
    }
  }

  private static class lease_service_exceptionStandardScheme extends org.apache.thrift.scheme.StandardScheme<lease_service_exception> {

    public void read(org.apache.thrift.protocol.TProtocol iprot, lease_service_exception struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TField schemeField;
      iprot.readStructBegin();
      while (true)
      {
        schemeField = iprot.readFieldBegin();
        if (schemeField.type == org.apache.thrift.protocol.TType.STOP) { 
          break;
        }
        switch (schemeField.id) {
          case 1: // MSG
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.msg = iprot.readString();
              struct.setMsgIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          default:
            org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
        }
        iprot.readFieldEnd();
      }
      iprot.readStructEnd();

      // check for required fields of primitive type, which can't be checked in the validate method
      struct.validate();
    }

    public void write(org.apache.thrift.protocol.TProtocol oprot, lease_service_exception struct) throws org.apache.thrift.TException {
      struct.validate();

      oprot.writeStructBegin(STRUCT_DESC);
      if (struct.msg != null) {
        oprot.writeFieldBegin(MSG_FIELD_DESC);
        oprot.writeString(struct.msg);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

  }

  private static class lease_service_exceptionTupleSchemeFactory implements org.apache.thrift.scheme.SchemeFactory {
    public lease_service_exceptionTupleScheme getScheme() {
      return new lease_service_exceptionTupleScheme();
    }
  }

  private static class lease_service_exceptionTupleScheme extends org.apache.thrift.scheme.TupleScheme<lease_service_exception> {

    @Override
    public void write(org.apache.thrift.protocol.TProtocol prot, lease_service_exception struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TTupleProtocol oprot = (org.apache.thrift.protocol.TTupleProtocol) prot;
      java.util.BitSet optionals = new java.util.BitSet();
      if (struct.isSetMsg()) {
        optionals.set(0);
      }
      oprot.writeBitSet(optionals, 1);
      if (struct.isSetMsg()) {
        oprot.writeString(struct.msg);
      }
    }

    @Override
    public void read(org.apache.thrift.protocol.TProtocol prot, lease_service_exception struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TTupleProtocol iprot = (org.apache.thrift.protocol.TTupleProtocol) prot;
      java.util.BitSet incoming = iprot.readBitSet(1);
      if (incoming.get(0)) {
        struct.msg = iprot.readString();
        struct.setMsgIsSet(true);
      }
    }
  }

  private static <S extends org.apache.thrift.scheme.IScheme> S scheme(org.apache.thrift.protocol.TProtocol proto) {
    return (org.apache.thrift.scheme.StandardScheme.class.equals(proto.getScheme()) ? STANDARD_SCHEME_FACTORY : TUPLE_SCHEME_FACTORY).getScheme();
  }
}

