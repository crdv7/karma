package mmux.hadoop.fs;

import java.io.IOException;
import java.io.OutputStream;
import java.nio.ByteBuffer;
import java.util.Collections;
import mmux.MMuxClient;
import mmux.kv.KVClient;
import mmux.util.ByteBufferUtils;
import org.apache.thrift.TException;

public class MMuxOutputStream extends OutputStream {
  private final static String FILE_LENGTH_KEY = "FileLength";
  private final MMuxClient mm;
  private final String path;
  private boolean closed;
  private MMuxBlock block;
  private long blockNum;
  private long blockSize;
  private KVClient client;

  MMuxOutputStream(MMuxClient mm, String path, KVClient client, long blockSize) {
    this.mm = mm;
    this.path = path;
    this.blockNum = 0;
    this.blockSize = blockSize;
    this.client = client;
    this.block = new MMuxBlock(blockSize);
  }

  private String fileLength() {
    return String.valueOf(blockNum * blockSize + block.usedBytes());
  }

  private ByteBuffer blockKey() {
    return ByteBufferUtils.fromString(String.valueOf(blockNum));
  }

  @Override
  public synchronized void write(int b) throws IOException {
    if (closed) {
      throw new IOException("Stream closed");
    }

    if (block.remaining() == 0) {
      flush();
    }
    block.write((byte) b);
  }

  @Override
  public synchronized void write(byte b[], int off, int len) throws IOException {
    if (closed) {
      throw new IOException("Stream closed");
    }
    while (len > 0) {
      int toWrite = Math.min(block.remaining(), len);
      block.write(b, off, toWrite);
      off += toWrite;
      len -= toWrite;

      if (block.remaining() == 0) {
        flush();
      }
    }
  }

  @Override
  public synchronized void flush() throws IOException {
    if (closed) {
      throw new IOException("Stream closed");
    }
    try {
      if (block.usedBytes() > 0) {
        client.upsert(ByteBufferUtils.fromByteBuffers(blockKey(), block.getData()));
        mm.fs().addTags(path, Collections.singletonMap(FILE_LENGTH_KEY, fileLength()));
        if (block.remaining() == 0) {
          block.reset();
          blockNum++;
        }
      }
    } catch (TException e) {
      throw new IOException(e);
    }
  }

  @Override
  public synchronized void close() throws IOException {
    if (closed) {
      return;
    }
    flush();
    super.close();
    mm.close(path);
    closed = true;
  }

}
