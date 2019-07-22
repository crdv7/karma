/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package jiffy.storage;

@SuppressWarnings({"cast", "rawtypes", "serial", "unchecked", "unused"})
@javax.annotation.Generated(value = "Autogenerated by Thrift Compiler (0.12.0)")
public class sequence_id implements org.apache.thrift.TBase<sequence_id, sequence_id._Fields>, java.io.Serializable, Cloneable, Comparable<sequence_id> {
  private static final org.apache.thrift.protocol.TStruct STRUCT_DESC = new org.apache.thrift.protocol.TStruct("sequence_id");

  private static final org.apache.thrift.protocol.TField CLIENT_ID_FIELD_DESC = new org.apache.thrift.protocol.TField("client_id", org.apache.thrift.protocol.TType.I64, (short)1);
  private static final org.apache.thrift.protocol.TField CLIENT_SEQ_NO_FIELD_DESC = new org.apache.thrift.protocol.TField("client_seq_no", org.apache.thrift.protocol.TType.I64, (short)2);
  private static final org.apache.thrift.protocol.TField SERVER_SEQ_NO_FIELD_DESC = new org.apache.thrift.protocol.TField("server_seq_no", org.apache.thrift.protocol.TType.I64, (short)3);

  private static final org.apache.thrift.scheme.SchemeFactory STANDARD_SCHEME_FACTORY = new sequence_idStandardSchemeFactory();
  private static final org.apache.thrift.scheme.SchemeFactory TUPLE_SCHEME_FACTORY = new sequence_idTupleSchemeFactory();

  public long client_id; // required
  public long client_seq_no; // required
  public long server_seq_no; // required

  /** The set of fields this struct contains, along with convenience methods for finding and manipulating them. */
  public enum _Fields implements org.apache.thrift.TFieldIdEnum {
    CLIENT_ID((short)1, "client_id"),
    CLIENT_SEQ_NO((short)2, "client_seq_no"),
    SERVER_SEQ_NO((short)3, "server_seq_no");

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
        case 1: // CLIENT_ID
          return CLIENT_ID;
        case 2: // CLIENT_SEQ_NO
          return CLIENT_SEQ_NO;
        case 3: // SERVER_SEQ_NO
          return SERVER_SEQ_NO;
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
  private static final int __CLIENT_ID_ISSET_ID = 0;
  private static final int __CLIENT_SEQ_NO_ISSET_ID = 1;
  private static final int __SERVER_SEQ_NO_ISSET_ID = 2;
  private byte __isset_bitfield = 0;
  public static final java.util.Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> metaDataMap;
  static {
    java.util.Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> tmpMap = new java.util.EnumMap<_Fields, org.apache.thrift.meta_data.FieldMetaData>(_Fields.class);
    tmpMap.put(_Fields.CLIENT_ID, new org.apache.thrift.meta_data.FieldMetaData("client_id", org.apache.thrift.TFieldRequirementType.REQUIRED, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I64)));
    tmpMap.put(_Fields.CLIENT_SEQ_NO, new org.apache.thrift.meta_data.FieldMetaData("client_seq_no", org.apache.thrift.TFieldRequirementType.REQUIRED, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I64)));
    tmpMap.put(_Fields.SERVER_SEQ_NO, new org.apache.thrift.meta_data.FieldMetaData("server_seq_no", org.apache.thrift.TFieldRequirementType.REQUIRED, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I64)));
    metaDataMap = java.util.Collections.unmodifiableMap(tmpMap);
    org.apache.thrift.meta_data.FieldMetaData.addStructMetaDataMap(sequence_id.class, metaDataMap);
  }

  public sequence_id() {
  }

  public sequence_id(
    long client_id,
    long client_seq_no,
    long server_seq_no)
  {
    this();
    this.client_id = client_id;
    setClientIdIsSet(true);
    this.client_seq_no = client_seq_no;
    setClientSeqNoIsSet(true);
    this.server_seq_no = server_seq_no;
    setServerSeqNoIsSet(true);
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public sequence_id(sequence_id other) {
    __isset_bitfield = other.__isset_bitfield;
    this.client_id = other.client_id;
    this.client_seq_no = other.client_seq_no;
    this.server_seq_no = other.server_seq_no;
  }

  public sequence_id deepCopy() {
    return new sequence_id(this);
  }

  @Override
  public void clear() {
    setClientIdIsSet(false);
    this.client_id = 0;
    setClientSeqNoIsSet(false);
    this.client_seq_no = 0;
    setServerSeqNoIsSet(false);
    this.server_seq_no = 0;
  }

  public long getClientId() {
    return this.client_id;
  }

  public sequence_id setClientId(long client_id) {
    this.client_id = client_id;
    setClientIdIsSet(true);
    return this;
  }

  public void unsetClientId() {
    __isset_bitfield = org.apache.thrift.EncodingUtils.clearBit(__isset_bitfield, __CLIENT_ID_ISSET_ID);
  }

  /** Returns true if field client_id is set (has been assigned a value) and false otherwise */
  public boolean isSetClientId() {
    return org.apache.thrift.EncodingUtils.testBit(__isset_bitfield, __CLIENT_ID_ISSET_ID);
  }

  public void setClientIdIsSet(boolean value) {
    __isset_bitfield = org.apache.thrift.EncodingUtils.setBit(__isset_bitfield, __CLIENT_ID_ISSET_ID, value);
  }

  public long getClientSeqNo() {
    return this.client_seq_no;
  }

  public sequence_id setClientSeqNo(long client_seq_no) {
    this.client_seq_no = client_seq_no;
    setClientSeqNoIsSet(true);
    return this;
  }

  public void unsetClientSeqNo() {
    __isset_bitfield = org.apache.thrift.EncodingUtils.clearBit(__isset_bitfield, __CLIENT_SEQ_NO_ISSET_ID);
  }

  /** Returns true if field client_seq_no is set (has been assigned a value) and false otherwise */
  public boolean isSetClientSeqNo() {
    return org.apache.thrift.EncodingUtils.testBit(__isset_bitfield, __CLIENT_SEQ_NO_ISSET_ID);
  }

  public void setClientSeqNoIsSet(boolean value) {
    __isset_bitfield = org.apache.thrift.EncodingUtils.setBit(__isset_bitfield, __CLIENT_SEQ_NO_ISSET_ID, value);
  }

  public long getServerSeqNo() {
    return this.server_seq_no;
  }

  public sequence_id setServerSeqNo(long server_seq_no) {
    this.server_seq_no = server_seq_no;
    setServerSeqNoIsSet(true);
    return this;
  }

  public void unsetServerSeqNo() {
    __isset_bitfield = org.apache.thrift.EncodingUtils.clearBit(__isset_bitfield, __SERVER_SEQ_NO_ISSET_ID);
  }

  /** Returns true if field server_seq_no is set (has been assigned a value) and false otherwise */
  public boolean isSetServerSeqNo() {
    return org.apache.thrift.EncodingUtils.testBit(__isset_bitfield, __SERVER_SEQ_NO_ISSET_ID);
  }

  public void setServerSeqNoIsSet(boolean value) {
    __isset_bitfield = org.apache.thrift.EncodingUtils.setBit(__isset_bitfield, __SERVER_SEQ_NO_ISSET_ID, value);
  }

  public void setFieldValue(_Fields field, @org.apache.thrift.annotation.Nullable java.lang.Object value) {
    switch (field) {
    case CLIENT_ID:
      if (value == null) {
        unsetClientId();
      } else {
        setClientId((java.lang.Long)value);
      }
      break;

    case CLIENT_SEQ_NO:
      if (value == null) {
        unsetClientSeqNo();
      } else {
        setClientSeqNo((java.lang.Long)value);
      }
      break;

    case SERVER_SEQ_NO:
      if (value == null) {
        unsetServerSeqNo();
      } else {
        setServerSeqNo((java.lang.Long)value);
      }
      break;

    }
  }

  @org.apache.thrift.annotation.Nullable
  public java.lang.Object getFieldValue(_Fields field) {
    switch (field) {
    case CLIENT_ID:
      return getClientId();

    case CLIENT_SEQ_NO:
      return getClientSeqNo();

    case SERVER_SEQ_NO:
      return getServerSeqNo();

    }
    throw new java.lang.IllegalStateException();
  }

  /** Returns true if field corresponding to fieldID is set (has been assigned a value) and false otherwise */
  public boolean isSet(_Fields field) {
    if (field == null) {
      throw new java.lang.IllegalArgumentException();
    }

    switch (field) {
    case CLIENT_ID:
      return isSetClientId();
    case CLIENT_SEQ_NO:
      return isSetClientSeqNo();
    case SERVER_SEQ_NO:
      return isSetServerSeqNo();
    }
    throw new java.lang.IllegalStateException();
  }

  @Override
  public boolean equals(java.lang.Object that) {
    if (that == null)
      return false;
    if (that instanceof sequence_id)
      return this.equals((sequence_id)that);
    return false;
  }

  public boolean equals(sequence_id that) {
    if (that == null)
      return false;
    if (this == that)
      return true;

    boolean this_present_client_id = true;
    boolean that_present_client_id = true;
    if (this_present_client_id || that_present_client_id) {
      if (!(this_present_client_id && that_present_client_id))
        return false;
      if (this.client_id != that.client_id)
        return false;
    }

    boolean this_present_client_seq_no = true;
    boolean that_present_client_seq_no = true;
    if (this_present_client_seq_no || that_present_client_seq_no) {
      if (!(this_present_client_seq_no && that_present_client_seq_no))
        return false;
      if (this.client_seq_no != that.client_seq_no)
        return false;
    }

    boolean this_present_server_seq_no = true;
    boolean that_present_server_seq_no = true;
    if (this_present_server_seq_no || that_present_server_seq_no) {
      if (!(this_present_server_seq_no && that_present_server_seq_no))
        return false;
      if (this.server_seq_no != that.server_seq_no)
        return false;
    }

    return true;
  }

  @Override
  public int hashCode() {
    int hashCode = 1;

    hashCode = hashCode * 8191 + org.apache.thrift.TBaseHelper.hashCode(client_id);

    hashCode = hashCode * 8191 + org.apache.thrift.TBaseHelper.hashCode(client_seq_no);

    hashCode = hashCode * 8191 + org.apache.thrift.TBaseHelper.hashCode(server_seq_no);

    return hashCode;
  }

  @Override
  public int compareTo(sequence_id other) {
    if (!getClass().equals(other.getClass())) {
      return getClass().getName().compareTo(other.getClass().getName());
    }

    int lastComparison = 0;

    lastComparison = java.lang.Boolean.valueOf(isSetClientId()).compareTo(other.isSetClientId());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetClientId()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.client_id, other.client_id);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = java.lang.Boolean.valueOf(isSetClientSeqNo()).compareTo(other.isSetClientSeqNo());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetClientSeqNo()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.client_seq_no, other.client_seq_no);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = java.lang.Boolean.valueOf(isSetServerSeqNo()).compareTo(other.isSetServerSeqNo());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetServerSeqNo()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.server_seq_no, other.server_seq_no);
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
    java.lang.StringBuilder sb = new java.lang.StringBuilder("sequence_id(");
    boolean first = true;

    sb.append("client_id:");
    sb.append(this.client_id);
    first = false;
    if (!first) sb.append(", ");
    sb.append("client_seq_no:");
    sb.append(this.client_seq_no);
    first = false;
    if (!first) sb.append(", ");
    sb.append("server_seq_no:");
    sb.append(this.server_seq_no);
    first = false;
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws org.apache.thrift.TException {
    // check for required fields
    // alas, we cannot check 'client_id' because it's a primitive and you chose the non-beans generator.
    // alas, we cannot check 'client_seq_no' because it's a primitive and you chose the non-beans generator.
    // alas, we cannot check 'server_seq_no' because it's a primitive and you chose the non-beans generator.
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
      // it doesn't seem like you should have to do this, but java serialization is wacky, and doesn't call the default constructor.
      __isset_bitfield = 0;
      read(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(in)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private static class sequence_idStandardSchemeFactory implements org.apache.thrift.scheme.SchemeFactory {
    public sequence_idStandardScheme getScheme() {
      return new sequence_idStandardScheme();
    }
  }

  private static class sequence_idStandardScheme extends org.apache.thrift.scheme.StandardScheme<sequence_id> {

    public void read(org.apache.thrift.protocol.TProtocol iprot, sequence_id struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TField schemeField;
      iprot.readStructBegin();
      while (true)
      {
        schemeField = iprot.readFieldBegin();
        if (schemeField.type == org.apache.thrift.protocol.TType.STOP) { 
          break;
        }
        switch (schemeField.id) {
          case 1: // CLIENT_ID
            if (schemeField.type == org.apache.thrift.protocol.TType.I64) {
              struct.client_id = iprot.readI64();
              struct.setClientIdIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 2: // CLIENT_SEQ_NO
            if (schemeField.type == org.apache.thrift.protocol.TType.I64) {
              struct.client_seq_no = iprot.readI64();
              struct.setClientSeqNoIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 3: // SERVER_SEQ_NO
            if (schemeField.type == org.apache.thrift.protocol.TType.I64) {
              struct.server_seq_no = iprot.readI64();
              struct.setServerSeqNoIsSet(true);
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
      if (!struct.isSetClientId()) {
        throw new org.apache.thrift.protocol.TProtocolException("Required field 'client_id' was not found in serialized data! Struct: " + toString());
      }
      if (!struct.isSetClientSeqNo()) {
        throw new org.apache.thrift.protocol.TProtocolException("Required field 'client_seq_no' was not found in serialized data! Struct: " + toString());
      }
      if (!struct.isSetServerSeqNo()) {
        throw new org.apache.thrift.protocol.TProtocolException("Required field 'server_seq_no' was not found in serialized data! Struct: " + toString());
      }
      struct.validate();
    }

    public void write(org.apache.thrift.protocol.TProtocol oprot, sequence_id struct) throws org.apache.thrift.TException {
      struct.validate();

      oprot.writeStructBegin(STRUCT_DESC);
      oprot.writeFieldBegin(CLIENT_ID_FIELD_DESC);
      oprot.writeI64(struct.client_id);
      oprot.writeFieldEnd();
      oprot.writeFieldBegin(CLIENT_SEQ_NO_FIELD_DESC);
      oprot.writeI64(struct.client_seq_no);
      oprot.writeFieldEnd();
      oprot.writeFieldBegin(SERVER_SEQ_NO_FIELD_DESC);
      oprot.writeI64(struct.server_seq_no);
      oprot.writeFieldEnd();
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

  }

  private static class sequence_idTupleSchemeFactory implements org.apache.thrift.scheme.SchemeFactory {
    public sequence_idTupleScheme getScheme() {
      return new sequence_idTupleScheme();
    }
  }

  private static class sequence_idTupleScheme extends org.apache.thrift.scheme.TupleScheme<sequence_id> {

    @Override
    public void write(org.apache.thrift.protocol.TProtocol prot, sequence_id struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TTupleProtocol oprot = (org.apache.thrift.protocol.TTupleProtocol) prot;
      oprot.writeI64(struct.client_id);
      oprot.writeI64(struct.client_seq_no);
      oprot.writeI64(struct.server_seq_no);
    }

    @Override
    public void read(org.apache.thrift.protocol.TProtocol prot, sequence_id struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TTupleProtocol iprot = (org.apache.thrift.protocol.TTupleProtocol) prot;
      struct.client_id = iprot.readI64();
      struct.setClientIdIsSet(true);
      struct.client_seq_no = iprot.readI64();
      struct.setClientSeqNoIsSet(true);
      struct.server_seq_no = iprot.readI64();
      struct.setServerSeqNoIsSet(true);
    }
  }

  private static <S extends org.apache.thrift.scheme.IScheme> S scheme(org.apache.thrift.protocol.TProtocol proto) {
    return (org.apache.thrift.scheme.StandardScheme.class.equals(proto.getScheme()) ? STANDARD_SCHEME_FACTORY : TUPLE_SCHEME_FACTORY).getScheme();
  }
}

