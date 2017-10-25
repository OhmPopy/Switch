#include <Switch/System/IO/MemoryStream.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
TEST(MemoryStream, Ctor_Default) {
  IO::MemoryStream ms;
  EXPECT_EQ(0, ms.Length());
  EXPECT_EQ(0, ms.Position());
  EXPECT_TRUE(ms.CanRead());
  EXPECT_TRUE(ms.CanWrite());
  EXPECT_TRUE(ms.CanSeek());
  EXPECT_FALSE(ms.CanTimeout());
  EXPECT_EQ(0, ms.Capacity());
}

TEST(MemoryStream, Ctor_Capacity) {
  IO::MemoryStream ms(10);
  EXPECT_EQ(0, ms.Length());
  EXPECT_EQ(0, ms.Position());
  EXPECT_TRUE(ms.CanRead());
  EXPECT_TRUE(ms.CanWrite());
  EXPECT_TRUE(ms.CanSeek());
  EXPECT_FALSE(ms.CanTimeout());
}

TEST(MemoryStream, Ctor_Capacity_Exception) {
  EXPECT_THROW(IO::MemoryStream ms(-1), ArgumentOutOfRangeException);
}

TEST(MemoryStream, Ctor_Buffer_CanWrite) {
  Array<byte> buffer(10);
  IO::MemoryStream ms(buffer, true);
  EXPECT_EQ(10, ms.Length());
  EXPECT_EQ(0, ms.Position());
  EXPECT_TRUE(ms.CanRead());
  EXPECT_TRUE(ms.CanWrite());
  EXPECT_TRUE(ms.CanSeek());
  EXPECT_FALSE(ms.CanTimeout());
  EXPECT_EQ(10, ms.Capacity());
}

TEST(MemoryStream, Ctor_Buffer_CanNotWrite) {
  Array<byte> buffer(10);
  IO::MemoryStream ms(buffer, false);
  EXPECT_EQ(10, ms.Length());
  EXPECT_EQ(0, ms.Position());
  EXPECT_TRUE(ms.CanRead());
  EXPECT_FALSE(ms.CanWrite());
  EXPECT_TRUE(ms.CanSeek());
  EXPECT_FALSE(ms.CanTimeout());
  EXPECT_EQ(10, ms.Capacity());
}

TEST(MemoryStream, GetData_NotDynamic) {
  Array<byte> buffer = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  IO::MemoryStream ms(buffer, false);
  EXPECT_EQ(buffer.Data(), ms.Buffer());
  for (int32 i = 0; i < ms.Length(); i++)
    ASSERT_EQ(buffer[i], ms.Buffer()[i]);
}

TEST(MemoryStream, GetData_Dynamic) {
  IO::MemoryStream ms(10);
  ms.WriteByte(0);
  ms.WriteByte(1);
  ms.WriteByte(2);
  ms.WriteByte(3);
  ms.WriteByte(4);
  const byte* buffer = ms.Buffer();
  for (int32 i = 0; i < ms.Length(); i++)
    ASSERT_EQ(i, buffer[i]);
}

TEST(MemoryStream, Read_NotDynamic) {
  Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  IO::MemoryStream ms(buffer, false);
  Array<byte> readBuffer(10);
  EXPECT_EQ(10, ms.Read(readBuffer, 0, 10));
  for (int32 i = 0; i < 10; i++)
    ASSERT_EQ(i, readBuffer[i]);
}

TEST(MemoryStream, Read_NotDynamic_2) {
  Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  IO::MemoryStream ms(buffer, false);
  Array<byte> readBuffer(5);
  EXPECT_EQ(1, ms.Read(readBuffer, 0, 1)); // 0
  EXPECT_EQ(1, ms.Position());
  EXPECT_EQ(4, ms.Read(readBuffer, 1, 4)); // 0 1 2 3 4
  EXPECT_EQ(5, ms.Position());
  for (int32 i = 0; i < 5; i++)
    ASSERT_EQ(i, readBuffer[i]);
}

TEST(MemoryStream, Read_NotDynamic_Offset) {
  Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  Array<byte> reference = {2, 3, 4, 0, 1};
  IO::MemoryStream ms(buffer, false);
  Array<byte> readBuffer(5);
  EXPECT_EQ(2, ms.Read(readBuffer, 3, 2));
  EXPECT_EQ(2, ms.Position());
  EXPECT_EQ(3, ms.Read(readBuffer, 0, 3));
  EXPECT_EQ(5, ms.Position());
  for (int32 i = 0; i < 5; i++)
    ASSERT_EQ(reference[i], readBuffer[i]);
}

TEST(MemoryStream, Read_NotDynamic_Offset_Exceptions) {
  Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  IO::MemoryStream ms(buffer, false);
  Array<byte> readBuffer(5);
  EXPECT_THROW(ms.Read(readBuffer, 3, 3), ArgumentException);
  EXPECT_EQ(0, ms.Position());
  EXPECT_EQ(2, ms.Seek(2, IO::SeekOrigin::Begin));
  EXPECT_THROW(ms.Read(readBuffer, 0, 6), ArgumentException);
  EXPECT_EQ(2, ms.Position());
}

TEST(MemoryStream, Read_NotDynamic_Overflow) {
  Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  Array<byte> refBuffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 255, 255, 255, 255, 255};
  IO::MemoryStream ms(buffer, false);
  Array<byte> readBuffer = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
  EXPECT_EQ(5, ms.Read(readBuffer, 0, 5));
  EXPECT_EQ(5, ms.Position());
  EXPECT_EQ(5, ms.Read(readBuffer, 5, 10));
  EXPECT_EQ(10, ms.Position());
  EXPECT_EQ(0, ms.Read(readBuffer, 10, 5));
  EXPECT_EQ(10, ms.Position());
  for (int32 i = 0; i < 15; i++)
    ASSERT_EQ(refBuffer[i], readBuffer[i]);
}

TEST(MemoryStream, Read_NotDynamic_Exception) {
  Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  IO::MemoryStream ms(buffer, false);
  Array<byte> readBuffer;
  EXPECT_THROW(ms.Read(readBuffer, 0, 6), ArgumentException);
  EXPECT_THROW(ms.Read(readBuffer, 1, 5), ArgumentException);
  EXPECT_THROW(ms.Read(readBuffer, -1, 5), ArgumentOutOfRangeException);
  EXPECT_THROW(ms.Read(readBuffer, 0, -5), ArgumentOutOfRangeException);
}

TEST(MemoryStream, ReadByte_NotDynamic) {
  Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  IO::MemoryStream ms(buffer, false);
  for (int32 i = 0; i < 12; i++) {
    if (i < 10) ASSERT_EQ(i, ms.ReadByte());
    else ASSERT_EQ(-1, ms.ReadByte());
  }
}

TEST(MemoryStream, Seek_NotDynamic_NotWritable) {
  Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  IO::MemoryStream ms(buffer, false);
  EXPECT_EQ(0, ms.Seek(0, IO::SeekOrigin::Begin));
  EXPECT_EQ(0, ms.Position());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(1, ms.Seek(1, IO::SeekOrigin::Begin));
  EXPECT_EQ(1, ms.Position());
  EXPECT_EQ(1, ms.ReadByte());
  EXPECT_EQ(9, ms.Seek(9, IO::SeekOrigin::Begin));
  EXPECT_EQ(9, ms.Position());
  EXPECT_EQ(9, ms.ReadByte());
  EXPECT_EQ(10, ms.Seek(10, IO::SeekOrigin::Begin));
  EXPECT_EQ(10, ms.Position());
  EXPECT_EQ(-1, ms.ReadByte());
  EXPECT_EQ(11, ms.Seek(11, IO::SeekOrigin::Begin));
  EXPECT_EQ(11, ms.Position());
  EXPECT_EQ(-1, ms.ReadByte());
  EXPECT_EQ(20, ms.Seek(20, IO::SeekOrigin::Begin));
  EXPECT_EQ(20, ms.Position());
  EXPECT_EQ(-1, ms.ReadByte());
  EXPECT_EQ(Int32::MaxValue, ms.Seek(Int32::MaxValue, IO::SeekOrigin::Begin));
  EXPECT_EQ(Int32::MaxValue, ms.Position());
  EXPECT_EQ(-1, ms.ReadByte());
}

TEST(MemoryStream, Seek_NotDynamic_Exceptions) {
  Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  IO::MemoryStream ms(buffer, false);
  EXPECT_THROW(ms.Seek(-1, IO::SeekOrigin::Begin), IO::IOException);
  EXPECT_THROW(ms.Seek(-11, IO::SeekOrigin::End), IO::IOException);
  EXPECT_THROW(ms.Seek(static_cast<int64>(Int32::MaxValue)+1, IO::SeekOrigin::Begin), ArgumentOutOfRangeException);
  EXPECT_THROW(ms.Seek(1, (IO::SeekOrigin)-66), ArgumentException);
}

TEST(MemoryStream, SetLength_NotDynamic_Writable_Twice_ReadByte) {
  Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  IO::MemoryStream ms(buffer, true);
  ms.Length = 5;
  EXPECT_EQ(5, ms.Length());
  EXPECT_EQ(10, ms.Capacity());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(1, ms.ReadByte());
  EXPECT_EQ(2, ms.ReadByte());
  EXPECT_EQ(3, ms.ReadByte());
  EXPECT_EQ(4, ms.ReadByte());
  EXPECT_EQ(-1, ms.ReadByte());
  ms.Length = 10;
  EXPECT_EQ(10, ms.Length());
  EXPECT_EQ(10, ms.Capacity());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(-1, ms.ReadByte());
}

TEST(MemoryStream, SetLength_NotDynamic_Writable_Seek_ReadByte) {
  Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  IO::MemoryStream ms(buffer, true);
  ms.Length = 5;
  EXPECT_EQ(7, ms.Seek(7, IO::SeekOrigin::Begin));
  EXPECT_EQ(-1, ms.ReadByte());
  EXPECT_EQ(7, ms.Seek(2, IO::SeekOrigin::End));
  EXPECT_EQ(-1, ms.ReadByte());
  EXPECT_EQ(15, ms.Seek(15, IO::SeekOrigin::Begin));
  EXPECT_EQ(-1, ms.ReadByte());
}

TEST(MemoryStream, SetLength_Dynamic_ZeroCapacity) {
  IO::MemoryStream ms;
  ms.Length = 5;
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(-1, ms.ReadByte());
}

TEST(MemoryStream, SetLength_Dynamic_Capacity) {
  IO::MemoryStream ms(10);
  EXPECT_EQ(-1, ms.ReadByte());
  ms.Length = 5;
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(-1, ms.ReadByte());
}

TEST(MemoryStream, ToArray_NotDynamic) {
  Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  IO::MemoryStream ms(buffer, false);
  Array<byte> array = ms.ToArray();
  EXPECT_EQ(10, array.Length);
  for (int32 i = 0; i < array.Length; i++)
    ASSERT_EQ(i, array[i]);
}

TEST(MemoryStream, ToArray_NotDynamic_Empty) {
  Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  IO::MemoryStream ms(buffer, true);
  ms.Length = 0;
  Array<byte> array = ms.ToArray();
  EXPECT_EQ(0, array.Length);
}

TEST(MemoryStream, Write_Dynamic) {
  IO::MemoryStream ms(5);
  ms.Length = 5;
  EXPECT_EQ(5, ms.Seek(5, IO::SeekOrigin::Begin));
  EXPECT_EQ(5, ms.Position());
  Array<byte> bytes = { 0 , 1 , 2};
  ms.Write(bytes, 0, 3);
  EXPECT_EQ(8, ms.Position());
  EXPECT_EQ(0, ms.Seek(0, IO::SeekOrigin::Begin));
  EXPECT_EQ(0, ms.Position());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(1, ms.ReadByte());
  EXPECT_EQ(2, ms.ReadByte());
  EXPECT_EQ(-1, ms.ReadByte());
}

TEST(MemoryStream, Write_Dynamic_ChangeCapacity) {
  IO::MemoryStream ms(10);
  ms.Length = 5;
  EXPECT_EQ(5, ms.Seek(5, IO::SeekOrigin::Begin));
  EXPECT_EQ(5, ms.Position());
  Array<byte> bytes = { 0 , 1 , 2};
  ms.Write(bytes, 0, 3);
  EXPECT_EQ(8, ms.Position());
}

TEST(MemoryStream, Write_NotDynamic) {
  Array<byte> buffer(10);
  IO::MemoryStream ms(buffer, true);
  Array<byte> bytes = { 0 , 1 , 2, 3, 4};
  ms.Write(bytes, 0, 3);
  EXPECT_EQ(3, ms.Position());
  ms.Write(bytes, 2, 2);
  EXPECT_EQ(5, ms.Position());
  ms.Write(bytes, 0, 5);
  EXPECT_EQ(10, ms.Position());

  EXPECT_EQ(0, ms.Seek(-10,IO::SeekOrigin::Current));
  ms.Write({' '}, 0, 1);
  EXPECT_EQ(0, ms.Seek(-1,IO::SeekOrigin::Current));

  EXPECT_EQ(32, ms.ReadByte());
  EXPECT_EQ(1, ms.ReadByte());
  EXPECT_EQ(2, ms.ReadByte());

  EXPECT_EQ(2, ms.ReadByte());
  EXPECT_EQ(3, ms.ReadByte());

  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(1, ms.ReadByte());
  EXPECT_EQ(2, ms.ReadByte());
  EXPECT_EQ(3, ms.ReadByte());
  EXPECT_EQ(4, ms.ReadByte());
}

TEST(MemoryStream, WriteByte_Dynamic_ChangeCapacity) {
  IO::MemoryStream ms(10);
  ms.Length = 5;
  EXPECT_EQ(5, ms.Seek(5, IO::SeekOrigin::Begin));
  EXPECT_EQ(5, ms.Position());
  ms.WriteByte(0);
  ms.WriteByte(1);
  ms.WriteByte(2);
  EXPECT_EQ(8, ms.Position());
}

TEST(MemoryStream, WriteByte_NotDynamic) {
  Array<byte> buffer(10);
  IO::MemoryStream ms(buffer, true);
  ms.WriteByte(0); 
  ms.WriteByte(1); 
  ms.WriteByte(2);
  EXPECT_EQ(3, ms.Position());
  ms.WriteByte(2);
  ms.WriteByte(3);
  EXPECT_EQ(5, ms.Position());
  ms.WriteByte(0);
  ms.WriteByte(1);
  ms.WriteByte(2);
  ms.WriteByte(3);
  ms.WriteByte(4);
  EXPECT_EQ(10, ms.Position());

  EXPECT_EQ(0, ms.Seek(-10,IO::SeekOrigin::Current));
  ms.WriteByte(32);
  EXPECT_EQ(0, ms.Seek(-1,IO::SeekOrigin::Current));

  EXPECT_EQ(32, ms.ReadByte());
  EXPECT_EQ(1, ms.ReadByte());
  EXPECT_EQ(2, ms.ReadByte());

  EXPECT_EQ(2, ms.ReadByte());
  EXPECT_EQ(3, ms.ReadByte());

  EXPECT_EQ(0, ms.ReadByte());
  EXPECT_EQ(1, ms.ReadByte());
  EXPECT_EQ(2, ms.ReadByte());
  EXPECT_EQ(3, ms.ReadByte());
  EXPECT_EQ(4, ms.ReadByte());
}

TEST(MemoryStream, Write_NotDynamic_Empty) {
  Array<byte> buffer = {0,0,0,0,0,0,0,0,0,0};
  IO::MemoryStream ms(buffer, true);
  Array<byte> source;
  EXPECT_NO_THROW(ms.Write(source, 0, 0));
  EXPECT_EQ(0, ms.Position());
}

TEST(MemoryStream, Write_NotDynamic_Offset) {
  Array<byte> buffer = {0,0,0,0,0,0,0,0,0,0};
  IO::MemoryStream ms(buffer, true);
  //                   0   1   2   3   4   5   6   7   8   9  10  11  12  13  14   15
  Array<byte> source = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o', 32 };
  ms.Write(source, 0, 1);
  ms.Write(source, 2, 1);
  ms.Write(source, 4, 1);
  ms.Write(source, 15, 1);
  ms.Write(source, 7, 1);
  ms.Write(source, 4, 1);
  ms.Write(source, 11, 1);
  ms.Write(source, 11, 1);
  ms.Write(source, 14, 1);
  EXPECT_EQ(10, ms.Length());
  EXPECT_EQ("ace hello", String((const char*)buffer.Data()));
}


TEST(MemoryStream, WriteTo) {
  Array<byte> source = {'b','o','n','j','o','u','r'};
  Array<byte> buffer(7);
  IO::MemoryStream ms1;
  IO::MemoryStream ms2(buffer, true);

  ms1.Write(source, 0, 7);
  ms1.WriteTo(ms2);
  ms2.Seek(0, IO::SeekOrigin::Begin);

  ASSERT_EQ('b', ms2.ReadByte());
  ASSERT_EQ('o', ms2.ReadByte());
  ASSERT_EQ('n', ms2.ReadByte());
  ASSERT_EQ('j', ms2.ReadByte());
  ASSERT_EQ('o', ms2.ReadByte());
  ASSERT_EQ('u', ms2.ReadByte());
  ASSERT_EQ('r', ms2.ReadByte());
  ASSERT_EQ(-1, ms2.ReadByte());
}

TEST(MemoryStream, ReadMsdn) {
  IO::MemoryStream s;
  for (int32 i = 0; i < 122; i++)
      s.WriteByte((byte)i);
  s.Position = 0;

  // Now read s into a byte buffer with a little padding. 
  int32 bytesCount = Convert::ToInt32(s.Length()) + 10;
  Array<byte> bytes(bytesCount);
  int numBytesToRead = (int)s.Length();
  int numBytesRead = 0;
  do {
    // Read may return anything from 0 to 10. 
    int n = s.Read(bytes, numBytesRead, 10);
    numBytesRead += n;
    numBytesToRead -= n;
  } while (numBytesToRead > 0);
  s.Close();
  EXPECT_EQ(0, numBytesToRead);
  EXPECT_EQ(122, numBytesRead);
  EXPECT_TRUE(s.IsClosed());
  EXPECT_THROW(s.ReadByte(), ObjectDisposedException);
  EXPECT_THROW(s.Read(bytes, 0, 1), ObjectDisposedException);
  EXPECT_THROW(s.Seek(0, IO::SeekOrigin::Begin), ObjectDisposedException);
  EXPECT_THROW(s.Capacity = 0, ObjectDisposedException);
  EXPECT_THROW(s.Position = 0, ObjectDisposedException);
  EXPECT_THROW(s.Write({'1', '4', '5'}, 0, 1), ObjectDisposedException);
  EXPECT_THROW(s.WriteByte(1), ObjectDisposedException);
}

}
