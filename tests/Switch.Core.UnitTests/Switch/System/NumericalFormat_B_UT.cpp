#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(NumericalFormatTest, B_ParsePrecision) {
    ASSERT_EQ("0", String::Format("{0:B}", Int32(0)));
    ASSERT_EQ("10011111101100101011", String::Format("{0:B}", Int32(654123)));
    ASSERT_EQ("1111111111111111111111111111111", String::Format("{0:B}", Int32::MaxValue));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B}", Int32(-1)));
    ASSERT_EQ("11111111111101100000010011010101", String::Format("{0:B}", Int32(-654123)));
    ASSERT_EQ("10000000000000000000000000000000", String::Format("{0:B}", Int32::MinValue));
  }

  TEST(NumericalFormatTest, B1_ParsePrecision) {
    ASSERT_EQ("0", String::Format("{0:B1}", Int32(0)));
    ASSERT_EQ("10011111101100101011", String::Format("{0:B1}", Int32(654123)));
    ASSERT_EQ("1111111111111111111111111111111", String::Format("{0:B1}", Int32::MaxValue));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B1}", Int32(-1)));
    ASSERT_EQ("11111111111101100000010011010101", String::Format("{0:B1}", Int32(-654123)));
    ASSERT_EQ("10000000000000000000000000000000", String::Format("{0:B1}", Int32::MinValue));
  }

  TEST(NumericalFormatTest, B00_ParsePrecision) {
    ASSERT_EQ("0", String::Format("{0:B00}", Int32(0)));
    ASSERT_EQ("10011111101100101011", String::Format("{0:B00}", Int32(654123)));
    ASSERT_EQ("1111111111111111111111111111111", String::Format("{0:B00}", Int32::MaxValue));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B00}", Int32(-1)));
    ASSERT_EQ("11111111111101100000010011010101", String::Format("{0:B00}", Int32(-654123)));
    ASSERT_EQ("10000000000000000000000000000000", String::Format("{0:B00}", Int32::MinValue));
  }

  TEST(NumericalFormatTest, B001_ParsePrecision) {
    ASSERT_EQ("0", String::Format("{0:B001}", Int32(0)));
    ASSERT_EQ("10011111101100101011", String::Format("{0:B001}", Int32(654123)));
    ASSERT_EQ("1111111111111111111111111111111", String::Format("{0:B001}", Int32::MaxValue));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B001}", Int32(-1)));
    ASSERT_EQ("11111111111101100000010011010101", String::Format("{0:B001}", Int32(-654123)));
    ASSERT_EQ("10000000000000000000000000000000", String::Format("{0:B001}", Int32::MinValue));
  }

  TEST(NumericalFormatTest, B0000010_ParsePrecision) {
    ASSERT_EQ("0000000000", String::Format("{0:B0000010}", Int32(0)));
    ASSERT_EQ("10011111101100101011", String::Format("{0:B0000010}", Int32(654123)));
    ASSERT_EQ("1111111111111111111111111111111", String::Format("{0:B0000010}", Int32::MaxValue));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B0000010}", Int32(-1)));
    ASSERT_EQ("11111111111101100000010011010101", String::Format("{0:B0000010}", Int32(-654123)));
    ASSERT_EQ("10000000000000000000000000000000", String::Format("{0:B0000010}", Int32::MinValue));
  }

  TEST(NumericalFormatTest, B99_Int64) {
    ASSERT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:B99}", Int64(0)));
    ASSERT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000010011111101100101011", String::Format("{0:B99}", Int64(654123)));
    ASSERT_EQ("000000000000000000000000000000000000111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B99}", Int64::MaxValue));
    ASSERT_EQ("000000000000000000000000000000000001111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B99}", Int64(-1)));
    ASSERT_EQ("000000000000000000000000000000000001111111111111111111111111111111111111111111101100000010011010101", String::Format("{0:B99}", Int64(-654123)));
    ASSERT_EQ("000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:B99}", Int64::MinValue));
  }

  TEST(NumericalFormatTest, B99_UInt64) {
    ASSERT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:B99}", UInt64(0)));
    ASSERT_EQ("000000000000000000000000000000000000000000000000000000000000000000000000000000010011111101100101011", String::Format("{0:B99}", UInt64(654123)));
    ASSERT_EQ("000000000000000000000000000000000001111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B99}", UInt64::MaxValue));
  }

  TEST(NumericalFormatTest, B_Byte) {
    ASSERT_EQ("0", String::Format("{0:B}", Byte(0)));
    ASSERT_EQ("1", String::Format("{0:B}", Byte(1)));
    ASSERT_EQ("10", String::Format("{0:B}", Byte(2)));
    ASSERT_EQ("11", String::Format("{0:B}", Byte(3)));
    ASSERT_EQ("100", String::Format("{0:B}", Byte(4)));
    ASSERT_EQ("101", String::Format("{0:B}", Byte(5)));
    ASSERT_EQ("11001101", String::Format("{0:B}", Byte(0xCD)));
    ASSERT_EQ("11111111", String::Format("{0:B}", Byte(0xFF)));
  }

  TEST(NumericalFormatTest, B0_Byte) {
    ASSERT_EQ("0", String::Format("{0:B0}", Byte(0)));
    ASSERT_EQ("1", String::Format("{0:B0}", Byte(1)));
    ASSERT_EQ("10", String::Format("{0:B0}", Byte(2)));
    ASSERT_EQ("11", String::Format("{0:B0}", Byte(3)));
    ASSERT_EQ("100", String::Format("{0:B0}", Byte(4)));
    ASSERT_EQ("101", String::Format("{0:B0}", Byte(5)));
    ASSERT_EQ("11001101", String::Format("{0:B0}", Byte(0xCD)));
    ASSERT_EQ("11111111", String::Format("{0:B0}", Byte(0xFF)));
  }

  TEST(NumericalFormatTest, B1_Byte) {
    ASSERT_EQ("0", String::Format("{0:B1}", Byte(0)));
    ASSERT_EQ("1", String::Format("{0:B1}", Byte(1)));
    ASSERT_EQ("10", String::Format("{0:B1}", Byte(2)));
    ASSERT_EQ("11", String::Format("{0:B1}", Byte(3)));
    ASSERT_EQ("100", String::Format("{0:B1}", Byte(4)));
    ASSERT_EQ("101", String::Format("{0:B1}", Byte(5)));
    ASSERT_EQ("11001101", String::Format("{0:B1}", Byte(0xCD)));
    ASSERT_EQ("11111111", String::Format("{0:B1}", Byte(0xFF)));
  }

  TEST(NumericalFormatTest, B2_Byte) {
    ASSERT_EQ("00", String::Format("{0:B2}", Byte(0)));
    ASSERT_EQ("01", String::Format("{0:B2}", Byte(1)));
    ASSERT_EQ("10", String::Format("{0:B2}", Byte(2)));
    ASSERT_EQ("11", String::Format("{0:B2}", Byte(3)));
    ASSERT_EQ("100", String::Format("{0:B2}", Byte(4)));
    ASSERT_EQ("101", String::Format("{0:B2}", Byte(5)));
    ASSERT_EQ("11001101", String::Format("{0:B2}", Byte(0xCD)));
    ASSERT_EQ("11111111", String::Format("{0:B2}", Byte(0xFF)));
  }

  TEST(NumericalFormatTest, B3_Byte) {
    ASSERT_EQ("000", String::Format("{0:B3}", Byte(0)));
    ASSERT_EQ("001", String::Format("{0:B3}", Byte(1)));
    ASSERT_EQ("010", String::Format("{0:B3}", Byte(2)));
    ASSERT_EQ("011", String::Format("{0:B3}", Byte(3)));
    ASSERT_EQ("100", String::Format("{0:B3}", Byte(4)));
    ASSERT_EQ("101", String::Format("{0:B3}", Byte(5)));
    ASSERT_EQ("11001101", String::Format("{0:B3}", Byte(0xCD)));
    ASSERT_EQ("11111111", String::Format("{0:B3}", Byte(0xFF)));
  }

  TEST(NumericalFormatTest, B4_Byte) {
    ASSERT_EQ("0000", String::Format("{0:B4}", Byte(0)));
    ASSERT_EQ("0001", String::Format("{0:B4}", Byte(1)));
    ASSERT_EQ("0010", String::Format("{0:B4}", Byte(2)));
    ASSERT_EQ("0011", String::Format("{0:B4}", Byte(3)));
    ASSERT_EQ("0100", String::Format("{0:B4}", Byte(4)));
    ASSERT_EQ("0101", String::Format("{0:B4}", Byte(5)));
    ASSERT_EQ("11001101", String::Format("{0:B4}", Byte(0xCD)));
    ASSERT_EQ("11111111", String::Format("{0:B4}", Byte(0xFF)));
  }

  TEST(NumericalFormatTest, B8_Byte) {
    ASSERT_EQ("00000000", String::Format("{0:B8}", Byte(0)));
    ASSERT_EQ("00000001", String::Format("{0:B8}", Byte(1)));
    ASSERT_EQ("00000010", String::Format("{0:B8}", Byte(2)));
    ASSERT_EQ("00000011", String::Format("{0:B8}", Byte(3)));
    ASSERT_EQ("00000100", String::Format("{0:B8}", Byte(4)));
    ASSERT_EQ("00000101", String::Format("{0:B8}", Byte(5)));
    ASSERT_EQ("11001101", String::Format("{0:B8}", Byte(0xCD)));
    ASSERT_EQ("11111111", String::Format("{0:B8}", Byte(0xFF)));
  }

  TEST(NumericalFormatTest, B9_Byte) {
    ASSERT_EQ("000000000", String::Format("{0:B9}", Byte(0)));
    ASSERT_EQ("000000001", String::Format("{0:B9}", Byte(1)));
    ASSERT_EQ("000000010", String::Format("{0:B9}", Byte(2)));
    ASSERT_EQ("000000011", String::Format("{0:B9}", Byte(3)));
    ASSERT_EQ("000000100", String::Format("{0:B9}", Byte(4)));
    ASSERT_EQ("000000101", String::Format("{0:B9}", Byte(5)));
    ASSERT_EQ("011001101", String::Format("{0:B9}", Byte(0xCD)));
    ASSERT_EQ("011111111", String::Format("{0:B9}", Byte(0xFF)));
  }

  TEST(NumericalFormatTest, B_UInt16) {
    ASSERT_EQ("0", String::Format("{0:B}", UInt16(0)));
    ASSERT_EQ("11", String::Format("{0:B}", UInt16(3)));
    ASSERT_EQ("1110", String::Format("{0:B}", UInt16(14)));
    ASSERT_EQ("11100001", String::Format("{0:B}", UInt16(225)));
    ASSERT_EQ("110001001001", String::Format("{0:B}", UInt16(3145)));
    ASSERT_EQ("111111111111111", String::Format("{0:B}", UInt16(32767)));
    ASSERT_EQ("1111111111111111", String::Format("{0:B}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, B0_UInt16) {
    ASSERT_EQ("0", String::Format("{0:B0}", UInt16(0)));
    ASSERT_EQ("11", String::Format("{0:B0}", UInt16(3)));
    ASSERT_EQ("1110", String::Format("{0:B0}", UInt16(14)));
    ASSERT_EQ("11100001", String::Format("{0:B0}", UInt16(225)));
    ASSERT_EQ("110001001001", String::Format("{0:B0}", UInt16(3145)));
    ASSERT_EQ("111111111111111", String::Format("{0:B0}", UInt16(32767)));
    ASSERT_EQ("1111111111111111", String::Format("{0:B0}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, B1_UInt16) {
    ASSERT_EQ("0", String::Format("{0:B1}", UInt16(0)));
    ASSERT_EQ("11", String::Format("{0:B1}", UInt16(3)));
    ASSERT_EQ("1110", String::Format("{0:B1}", UInt16(14)));
    ASSERT_EQ("11100001", String::Format("{0:B1}", UInt16(225)));
    ASSERT_EQ("110001001001", String::Format("{0:B1}", UInt16(3145)));
    ASSERT_EQ("111111111111111", String::Format("{0:B1}", UInt16(32767)));
    ASSERT_EQ("1111111111111111", String::Format("{0:B1}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, B4_UInt16) {
    ASSERT_EQ("0000", String::Format("{0:B4}", UInt16(0)));
    ASSERT_EQ("0011", String::Format("{0:B4}", UInt16(3)));
    ASSERT_EQ("1110", String::Format("{0:B4}", UInt16(14)));
    ASSERT_EQ("11100001", String::Format("{0:B4}", UInt16(225)));
    ASSERT_EQ("110001001001", String::Format("{0:B4}", UInt16(3145)));
    ASSERT_EQ("111111111111111", String::Format("{0:B4}", UInt16(32767)));
    ASSERT_EQ("1111111111111111", String::Format("{0:B4}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, B8_UInt16) {
    ASSERT_EQ("00000000", String::Format("{0:B8}", UInt16(0)));
    ASSERT_EQ("00000011", String::Format("{0:B8}", UInt16(3)));
    ASSERT_EQ("00001110", String::Format("{0:B8}", UInt16(14)));
    ASSERT_EQ("11100001", String::Format("{0:B8}", UInt16(225)));
    ASSERT_EQ("110001001001", String::Format("{0:B8}", UInt16(3145)));
    ASSERT_EQ("111111111111111", String::Format("{0:B8}", UInt16(32767)));
    ASSERT_EQ("1111111111111111", String::Format("{0:B8}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, B17_UInt16) {
    ASSERT_EQ("00000000000000000", String::Format("{0:B17}", UInt16(0)));
    ASSERT_EQ("00000000000000011", String::Format("{0:B17}", UInt16(3)));
    ASSERT_EQ("00000000000001110", String::Format("{0:B17}", UInt16(14)));
    ASSERT_EQ("00000000011100001", String::Format("{0:B17}", UInt16(225)));
    ASSERT_EQ("00000110001001001", String::Format("{0:B17}", UInt16(3145)));
    ASSERT_EQ("00111111111111111", String::Format("{0:B17}", UInt16(32767)));
    ASSERT_EQ("01111111111111111", String::Format("{0:B17}", UInt16(65535)));
  }

  TEST(NumericalFormatTest, B_UInt32) {
    ASSERT_EQ("0", String::Format("{0:B}", UInt32(0)));
    ASSERT_EQ("1110", String::Format("{0:B}", UInt32(14)));
    ASSERT_EQ("11100001", String::Format("{0:B}", UInt32(225)));
    ASSERT_EQ("110001001001", String::Format("{0:B}", UInt32(3145)));
    ASSERT_EQ("1111110111111111", String::Format("{0:B}", UInt32(65023)));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B}", UInt32::MaxValue));
  }

  TEST(NumericalFormatTest, B0_UInt32) {
    ASSERT_EQ("0", String::Format("{0:B0}", UInt32(0)));
    ASSERT_EQ("1110", String::Format("{0:B0}", UInt32(14)));
    ASSERT_EQ("11100001", String::Format("{0:B0}", UInt32(225)));
    ASSERT_EQ("110001001001", String::Format("{0:B0}", UInt32(3145)));
    ASSERT_EQ("1111110111111111", String::Format("{0:B0}", UInt32(65023)));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B0}", UInt32::MaxValue));
  }

  TEST(NumericalFormatTest, B5_UInt32) {
    ASSERT_EQ("00000", String::Format("{0:B5}", UInt32(0)));
    ASSERT_EQ("01110", String::Format("{0:B5}", UInt32(14)));
    ASSERT_EQ("11100001", String::Format("{0:B5}", UInt32(225)));
    ASSERT_EQ("110001001001", String::Format("{0:B5}", UInt32(3145)));
    ASSERT_EQ("1111110111111111", String::Format("{0:B5}", UInt32(65023)));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B5}", UInt32::MaxValue));
  }

  TEST(NumericalFormatTest, B8_UInt32) {
    ASSERT_EQ("00000000", String::Format("{0:B8}", UInt32(0)));
    ASSERT_EQ("00001110", String::Format("{0:B8}", UInt32(14)));
    ASSERT_EQ("11100001", String::Format("{0:B8}", UInt32(225)));
    ASSERT_EQ("110001001001", String::Format("{0:B8}", UInt32(3145)));
    ASSERT_EQ("1111110111111111", String::Format("{0:B8}", UInt32(65023)));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B8}", UInt32::MaxValue));
  }

  TEST(NumericalFormatTest, B33_UInt32) {
    ASSERT_EQ("000000000000000000000000000000000", String::Format("{0:B33}", UInt32(0)));
    ASSERT_EQ("000000000000000000000000000001110", String::Format("{0:B33}", UInt32(14)));
    ASSERT_EQ("000000000000000000000000011100001", String::Format("{0:B33}", UInt32(225)));
    ASSERT_EQ("000000000000000000000110001001001", String::Format("{0:B33}", UInt32(3145)));
    ASSERT_EQ("000000000000000001111110111111111", String::Format("{0:B33}", UInt32(65023)));
    ASSERT_EQ("011111111111111111111111111111111", String::Format("{0:B33}", UInt32::MaxValue));
  }

  TEST(NumericalFormatTest, B_UInt64) {
    ASSERT_EQ("0", String::Format("{0:B}", UInt64(0)));
    ASSERT_EQ("1110", String::Format("{0:B}", UInt64(14)));
    ASSERT_EQ("111111011111111", String::Format("{0:B}", UInt64(32511)));
    ASSERT_EQ("11110111111101111111011111110111", String::Format("{0:B}", UInt64(4160223223u)));
    ASSERT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B}", UInt64(1844674407370955u)));
    ASSERT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B}", UInt64::MaxValue));
  }

  TEST(NumericalFormatTest, B15_UInt64) {
    ASSERT_EQ("000000000000000", String::Format("{0:B15}", UInt64(0)));
    ASSERT_EQ("000000000001110", String::Format("{0:B15}", UInt64(14)));
    ASSERT_EQ("111111011111111", String::Format("{0:B15}", UInt64(32511)));
    ASSERT_EQ("11110111111101111111011111110111", String::Format("{0:B15}", UInt64(4160223223u)));
    ASSERT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B15}", UInt64(1844674407370955u)));
    ASSERT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B15}", UInt64::MaxValue));
  }

  TEST(NumericalFormatTest, B36_UInt64) {
    ASSERT_EQ("000000000000000000000000000000000000", String::Format("{0:B36}", UInt64(0)));
    ASSERT_EQ("000000000000000000000000000000001110", String::Format("{0:B36}", UInt64(14)));
    ASSERT_EQ("000000000000000000000111111011111111", String::Format("{0:B36}", UInt64(32511)));
    ASSERT_EQ("000011110111111101111111011111110111", String::Format("{0:B36}", UInt64(4160223223u)));
    ASSERT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B36}", UInt64(1844674407370955u)));
    ASSERT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B36}", UInt64::MaxValue));
  }

  TEST(NumericalFormatTest, B65_UInt64) {
    ASSERT_EQ("00000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:B65}", UInt64(0)));
    ASSERT_EQ("00000000000000000000000000000000000000000000000000000000000001110", String::Format("{0:B65}", UInt64(14)));
    ASSERT_EQ("00000000000000000000000000000000000000000000000000111111011111111", String::Format("{0:B65}", UInt64(32511)));
    ASSERT_EQ("00000000000000000000000000000000011110111111101111111011111110111", String::Format("{0:B65}", UInt64(4160223223u)));
    ASSERT_EQ("00000000000000110100011011011100010111010110001110001000011001011", String::Format("{0:B65}", UInt64(1844674407370955u)));
    ASSERT_EQ("01111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B65}", UInt64::MaxValue));
  }

  TEST(NumericalFormatTest, B_SByte) {
    ASSERT_EQ("0", String::Format("{0:B}", SByte(0)));
    ASSERT_EQ("101", String::Format("{0:B}", SByte(5)));
    ASSERT_EQ("1111111", String::Format("{0:B}", SByte(127)));
    ASSERT_EQ("11111011", String::Format("{0:B}", SByte(-5)));
    ASSERT_EQ("10000001", String::Format("{0:B}", SByte(-127)));
  }

  TEST(NumericalFormatTest, B0_SByte) {
    ASSERT_EQ("0", String::Format("{0:B0}", SByte(0)));
    ASSERT_EQ("101", String::Format("{0:B0}", SByte(5)));
    ASSERT_EQ("1111111", String::Format("{0:B0}", SByte(127)));
    ASSERT_EQ("11111011", String::Format("{0:B0}", SByte(-5)));
    ASSERT_EQ("10000001", String::Format("{0:B0}", SByte(-127)));
  }

  TEST(NumericalFormatTest, B1_SByte) {
    ASSERT_EQ("0", String::Format("{0:B1}", SByte(0)));
    ASSERT_EQ("101", String::Format("{0:B1}", SByte(5)));
    ASSERT_EQ("1111111", String::Format("{0:B1}", SByte(127)));
    ASSERT_EQ("11111011", String::Format("{0:B1}", SByte(-5)));
    ASSERT_EQ("10000001", String::Format("{0:B1}", SByte(-127)));
  }

  TEST(NumericalFormatTest, B2_SByte) {
    ASSERT_EQ("00", String::Format("{0:B2}", SByte(0)));
    ASSERT_EQ("101", String::Format("{0:B2}", SByte(5)));
    ASSERT_EQ("1111111", String::Format("{0:B2}", SByte(127)));
    ASSERT_EQ("11111011", String::Format("{0:B2}", SByte(-5)));
    ASSERT_EQ("10000001", String::Format("{0:B2}", SByte(-127)));
  }

  TEST(NumericalFormatTest, B3_SByte) {
    ASSERT_EQ("000", String::Format("{0:B3}", SByte(0)));
    ASSERT_EQ("101", String::Format("{0:B3}", SByte(5)));
    ASSERT_EQ("1111111", String::Format("{0:B3}", SByte(127)));
    ASSERT_EQ("11111011", String::Format("{0:B3}", SByte(-5)));
    ASSERT_EQ("10000001", String::Format("{0:B3}", SByte(-127)));
  }

  TEST(NumericalFormatTest, B4_SByte) {
    ASSERT_EQ("0000", String::Format("{0:B4}", SByte(0)));
    ASSERT_EQ("0101", String::Format("{0:B4}", SByte(5)));
    ASSERT_EQ("1111111", String::Format("{0:B4}", SByte(127)));
    ASSERT_EQ("11111011", String::Format("{0:B4}", SByte(-5)));
    ASSERT_EQ("10000001", String::Format("{0:B4}", SByte(-127)));
  }

  TEST(NumericalFormatTest, B8_SByte) {
    ASSERT_EQ("00000000", String::Format("{0:B8}", SByte(0)));
    ASSERT_EQ("00000101", String::Format("{0:B8}", SByte(5)));
    ASSERT_EQ("01111111", String::Format("{0:B8}", SByte(127)));
    ASSERT_EQ("11111011", String::Format("{0:B8}", SByte(-5)));
    ASSERT_EQ("10000001", String::Format("{0:B8}", SByte(-127)));
  }

  TEST(NumericalFormatTest, B12_SByte) {
    ASSERT_EQ("000000000000", String::Format("{0:B12}", SByte(0)));
    ASSERT_EQ("000000000101", String::Format("{0:B12}", SByte(5)));
    ASSERT_EQ("000001111111", String::Format("{0:B12}", SByte(127)));
    ASSERT_EQ("000011111011", String::Format("{0:B12}", SByte(-5)));
    ASSERT_EQ("000010000001", String::Format("{0:B12}", SByte(-127)));
  }

  TEST(NumericalFormatTest, B_Int16) {
    ASSERT_EQ("0", String::Format("{0:B}", Int16(0)));
    ASSERT_EQ("11", String::Format("{0:B}", Int16(3)));
    ASSERT_EQ("1110", String::Format("{0:B}", Int16(14)));
    ASSERT_EQ("11100001", String::Format("{0:B}", Int16(225)));
    ASSERT_EQ("110001001001", String::Format("{0:B}", Int16(3145)));
    ASSERT_EQ("111111111111111", String::Format("{0:B}", Int16(32767)));
    ASSERT_EQ("1111111111111111", String::Format("{0:B}", Int16(-1)));
    ASSERT_EQ("1111111111110010", String::Format("{0:B}", Int16(-14)));
    ASSERT_EQ("1111111100011111", String::Format("{0:B}", Int16(-225)));
    ASSERT_EQ("1111001110110111", String::Format("{0:B}", Int16(-3145)));
    ASSERT_EQ("1000000000000000", String::Format("{0:B}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, B0_Int16) {
    ASSERT_EQ("0", String::Format("{0:B0}", Int16(0)));
    ASSERT_EQ("11", String::Format("{0:B0}", Int16(3)));
    ASSERT_EQ("1110", String::Format("{0:B0}", Int16(14)));
    ASSERT_EQ("11100001", String::Format("{0:B0}", Int16(225)));
    ASSERT_EQ("110001001001", String::Format("{0:B0}", Int16(3145)));
    ASSERT_EQ("111111111111111", String::Format("{0:B0}", Int16(32767)));
    ASSERT_EQ("1111111111111111", String::Format("{0:B0}", Int16(-1)));
    ASSERT_EQ("1111111111110010", String::Format("{0:B0}", Int16(-14)));
    ASSERT_EQ("1111111100011111", String::Format("{0:B0}", Int16(-225)));
    ASSERT_EQ("1111001110110111", String::Format("{0:B0}", Int16(-3145)));
    ASSERT_EQ("1000000000000000", String::Format("{0:B0}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, B1_Int16) {
    ASSERT_EQ("0", String::Format("{0:B1}", Int16(0)));
    ASSERT_EQ("11", String::Format("{0:B1}", Int16(3)));
    ASSERT_EQ("1110", String::Format("{0:B1}", Int16(14)));
    ASSERT_EQ("11100001", String::Format("{0:B1}", Int16(225)));
    ASSERT_EQ("110001001001", String::Format("{0:B1}", Int16(3145)));
    ASSERT_EQ("111111111111111", String::Format("{0:B1}", Int16(32767)));
    ASSERT_EQ("1111111111111111", String::Format("{0:B1}", Int16(-1)));
    ASSERT_EQ("1111111111110010", String::Format("{0:B1}", Int16(-14)));
    ASSERT_EQ("1111111100011111", String::Format("{0:B1}", Int16(-225)));
    ASSERT_EQ("1111001110110111", String::Format("{0:B1}", Int16(-3145)));
    ASSERT_EQ("1000000000000000", String::Format("{0:B1}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, B4_Int16) {
    ASSERT_EQ("0000", String::Format("{0:B4}", Int16(0)));
    ASSERT_EQ("0011", String::Format("{0:B4}", Int16(3)));
    ASSERT_EQ("1110", String::Format("{0:B4}", Int16(14)));
    ASSERT_EQ("11100001", String::Format("{0:B4}", Int16(225)));
    ASSERT_EQ("110001001001", String::Format("{0:B4}", Int16(3145)));
    ASSERT_EQ("111111111111111", String::Format("{0:B4}", Int16(32767)));
    ASSERT_EQ("1111111111111111", String::Format("{0:B4}", Int16(-1)));
    ASSERT_EQ("1111111111110010", String::Format("{0:B4}", Int16(-14)));
    ASSERT_EQ("1111111100011111", String::Format("{0:B4}", Int16(-225)));
    ASSERT_EQ("1111001110110111", String::Format("{0:B4}", Int16(-3145)));
    ASSERT_EQ("1000000000000000", String::Format("{0:B4}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, B8_Int16) {
    ASSERT_EQ("00000000", String::Format("{0:B8}", Int16(0)));
    ASSERT_EQ("00000011", String::Format("{0:B8}", Int16(3)));
    ASSERT_EQ("00001110", String::Format("{0:B8}", Int16(14)));
    ASSERT_EQ("11100001", String::Format("{0:B8}", Int16(225)));
    ASSERT_EQ("110001001001", String::Format("{0:B8}", Int16(3145)));
    ASSERT_EQ("111111111111111", String::Format("{0:B8}", Int16(32767)));
    ASSERT_EQ("1111111111111111", String::Format("{0:B8}", Int16(-1)));
    ASSERT_EQ("1111111111110010", String::Format("{0:B8}", Int16(-14)));
    ASSERT_EQ("1111111100011111", String::Format("{0:B8}", Int16(-225)));
    ASSERT_EQ("1111001110110111", String::Format("{0:B8}", Int16(-3145)));
    ASSERT_EQ("1000000000000000", String::Format("{0:B8}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, B17_Int16) {
    ASSERT_EQ("00000000000000000", String::Format("{0:B17}", Int16(0)));
    ASSERT_EQ("00000000000000011", String::Format("{0:B17}", Int16(3)));
    ASSERT_EQ("00000000000001110", String::Format("{0:B17}", Int16(14)));
    ASSERT_EQ("00000000011100001", String::Format("{0:B17}", Int16(225)));
    ASSERT_EQ("00000110001001001", String::Format("{0:B17}", Int16(3145)));
    ASSERT_EQ("00111111111111111", String::Format("{0:B17}", Int16(32767)));
    ASSERT_EQ("01111111111111111", String::Format("{0:B17}", Int16(-1)));
    ASSERT_EQ("01111111111110010", String::Format("{0:B17}", Int16(-14)));
    ASSERT_EQ("01111111100011111", String::Format("{0:B17}", Int16(-225)));
    ASSERT_EQ("01111001110110111", String::Format("{0:B17}", Int16(-3145)));
    ASSERT_EQ("01000000000000000", String::Format("{0:B17}", Int16(-32768)));
  }

  TEST(NumericalFormatTest, B_Int32) {
    ASSERT_EQ("0", String::Format("{0:B}", Int32(0)));
    ASSERT_EQ("11", String::Format("{0:B}", Int32(3)));
    ASSERT_EQ("1110", String::Format("{0:B}", Int32(14)));
    ASSERT_EQ("111111111111111", String::Format("{0:B}", Int32(32767)));
    ASSERT_EQ("1111111111111111111111111111111", String::Format("{0:B}", Int32(2147483647)));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B}", Int32(-1)));
    ASSERT_EQ("11111111111111101000000011111010", String::Format("{0:B}", Int32(-98054)));
    ASSERT_EQ("10000000000000000000000000000001", String::Format("{0:B}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, B2_Int32) {
    ASSERT_EQ("00", String::Format("{0:B2}", Int32(0)));
    ASSERT_EQ("11", String::Format("{0:B2}", Int32(3)));
    ASSERT_EQ("1110", String::Format("{0:B2}", Int32(14)));
    ASSERT_EQ("111111111111111", String::Format("{0:B2}", Int32(32767)));
    ASSERT_EQ("1111111111111111111111111111111", String::Format("{0:B2}", Int32(2147483647)));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B2}", Int32(-1)));
    ASSERT_EQ("11111111111111101000000011111010", String::Format("{0:B2}", Int32(-98054)));
    ASSERT_EQ("10000000000000000000000000000001", String::Format("{0:B2}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, B5_Int32) {
    ASSERT_EQ("00000", String::Format("{0:B5}", Int32(0)));
    ASSERT_EQ("00011", String::Format("{0:B5}", Int32(3)));
    ASSERT_EQ("01110", String::Format("{0:B5}", Int32(14)));
    ASSERT_EQ("111111111111111", String::Format("{0:B5}", Int32(32767)));
    ASSERT_EQ("1111111111111111111111111111111", String::Format("{0:B5}", Int32(2147483647)));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B5}", Int32(-1)));
    ASSERT_EQ("11111111111111101000000011111010", String::Format("{0:B5}", Int32(-98054)));
    ASSERT_EQ("10000000000000000000000000000001", String::Format("{0:B5}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, B8_Int32) {
    ASSERT_EQ("00000000", String::Format("{0:B8}", Int32(0)));
    ASSERT_EQ("00000011", String::Format("{0:B8}", Int32(3)));
    ASSERT_EQ("00001110", String::Format("{0:B8}", Int32(14)));
    ASSERT_EQ("111111111111111", String::Format("{0:B8}", Int32(32767)));
    ASSERT_EQ("1111111111111111111111111111111", String::Format("{0:B8}", Int32(2147483647)));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B8}", Int32(-1)));
    ASSERT_EQ("11111111111111101000000011111010", String::Format("{0:B8}", Int32(-98054)));
    ASSERT_EQ("10000000000000000000000000000001", String::Format("{0:B8}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, B11_Int32) {
    ASSERT_EQ("00000000000", String::Format("{0:B11}", Int32(0)));
    ASSERT_EQ("00000000011", String::Format("{0:B11}", Int32(3)));
    ASSERT_EQ("00000001110", String::Format("{0:B11}", Int32(14)));
    ASSERT_EQ("111111111111111", String::Format("{0:B11}", Int32(32767)));
    ASSERT_EQ("1111111111111111111111111111111", String::Format("{0:B11}", Int32(2147483647)));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B11}", Int32(-1)));
    ASSERT_EQ("11111111111111101000000011111010", String::Format("{0:B11}", Int32(-98054)));
    ASSERT_EQ("10000000000000000000000000000001", String::Format("{0:B11}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, B33_Int32) {
    ASSERT_EQ("000000000000000000000000000000000", String::Format("{0:B33}", Int32(0)));
    ASSERT_EQ("000000000000000000000000000000011", String::Format("{0:B33}", Int32(3)));
    ASSERT_EQ("000000000000000000000000000001110", String::Format("{0:B33}", Int32(14)));
    ASSERT_EQ("000000000000000000111111111111111", String::Format("{0:B33}", Int32(32767)));
    ASSERT_EQ("001111111111111111111111111111111", String::Format("{0:B33}", Int32(2147483647)));
    ASSERT_EQ("011111111111111111111111111111111", String::Format("{0:B33}", Int32(-1)));
    ASSERT_EQ("011111111111111101000000011111010", String::Format("{0:B33}", Int32(-98054)));
    ASSERT_EQ("010000000000000000000000000000001", String::Format("{0:B33}", Int32(-2147483647)));
  }

  TEST(NumericalFormatTest, B_Int64) {
    ASSERT_EQ("0", String::Format("{0:B}", Int64(0)));
    ASSERT_EQ("101", String::Format("{0:B}", Int64(5)));
    ASSERT_EQ("111111111111111", String::Format("{0:B}", Int64(32767)));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B}", Int64(4294967295ll)));
    ASSERT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B}", Int64(1844674407370955ll)));
    ASSERT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B}", Int64(-1)));
    ASSERT_EQ("1111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:B}", -Int64(1844674407370955ll)));
  }

  TEST(NumericalFormatTest, B2_Int64) {
    ASSERT_EQ("00", String::Format("{0:B2}", Int64(0)));
    ASSERT_EQ("101", String::Format("{0:B2}", Int64(5)));
    ASSERT_EQ("111111111111111", String::Format("{0:B2}", Int64(32767)));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B2}", Int64(4294967295ll)));
    ASSERT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B2}", Int64(1844674407370955ll)));
    ASSERT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B2}", Int64(-1)));
    ASSERT_EQ("1111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:B2}", -Int64(1844674407370955ll)));
  }

  TEST(NumericalFormatTest, B8_Int64) {
    ASSERT_EQ("00000000", String::Format("{0:B8}", Int64(0)));
    ASSERT_EQ("00000101", String::Format("{0:B8}", Int64(5)));
    ASSERT_EQ("111111111111111", String::Format("{0:B8}", Int64(32767)));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B8}", Int64(4294967295ll)));
    ASSERT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B8}", Int64(1844674407370955ll)));
    ASSERT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B8}", Int64(-1)));
    ASSERT_EQ("1111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:B8}", -Int64(1844674407370955ll)));
  }

  TEST(NumericalFormatTest, B16_Int64) {
    ASSERT_EQ("0000000000000000", String::Format("{0:B16}", Int64(0)));
    ASSERT_EQ("0000000000000101", String::Format("{0:B16}", Int64(5)));
    ASSERT_EQ("0111111111111111", String::Format("{0:B16}", Int64(32767)));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B16}", Int64(4294967295ll)));
    ASSERT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B16}", Int64(1844674407370955ll)));
    ASSERT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B16}", Int64(-1)));
    ASSERT_EQ("1111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:B16}", -Int64(1844674407370955ll)));
  }

  TEST(NumericalFormatTest, B20_Int64) {
    ASSERT_EQ("00000000000000000000", String::Format("{0:B20}", Int64(0)));
    ASSERT_EQ("00000000000000000101", String::Format("{0:B20}", Int64(5)));
    ASSERT_EQ("00000111111111111111", String::Format("{0:B20}", Int64(32767)));
    ASSERT_EQ("11111111111111111111111111111111", String::Format("{0:B20}", Int64(4294967295ll)));
    ASSERT_EQ("110100011011011100010111010110001110001000011001011", String::Format("{0:B20}", Int64(1844674407370955ll)));
    ASSERT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B20}", Int64(-1)));
    ASSERT_EQ("1111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:B20}", -Int64(1844674407370955ll)));
  }

  TEST(NumericalFormatTest, B64_Int64) {
    ASSERT_EQ("0000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:B64}", Int64(0)));
    ASSERT_EQ("0000000000000000000000000000000000000000000000000000000000000101", String::Format("{0:B64}", Int64(5)));
    ASSERT_EQ("0000000000000000000000000000000000000000000000000111111111111111", String::Format("{0:B64}", Int64(32767)));
    ASSERT_EQ("0000000000000000000000000000000011111111111111111111111111111111", String::Format("{0:B64}", Int64(4294967295ll)));
    ASSERT_EQ("0000000000000110100011011011100010111010110001110001000011001011", String::Format("{0:B64}", Int64(1844674407370955ll)));
    ASSERT_EQ("1111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B64}", Int64(-1)));
    ASSERT_EQ("1111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:B64}", -Int64(1844674407370955ll)));
  }

  TEST(NumericalFormatTest, B65_Int64) {
    ASSERT_EQ("00000000000000000000000000000000000000000000000000000000000000000", String::Format("{0:B65}", Int64(0)));
    ASSERT_EQ("00000000000000000000000000000000000000000000000000000000000000101", String::Format("{0:B65}", Int64(5)));
    ASSERT_EQ("00000000000000000000000000000000000000000000000000111111111111111", String::Format("{0:B65}", Int64(32767)));
    ASSERT_EQ("00000000000000000000000000000000011111111111111111111111111111111", String::Format("{0:B65}", Int64(4294967295ll)));
    ASSERT_EQ("00000000000000110100011011011100010111010110001110001000011001011", String::Format("{0:B65}", Int64(1844674407370955ll)));
    ASSERT_EQ("01111111111111111111111111111111111111111111111111111111111111111", String::Format("{0:B65}", Int64(-1)));
    ASSERT_EQ("01111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:B65}", -Int64(1844674407370955ll)));
  }


  TEST(NumericalFormatTest, B_Double) {
    ASSERT_THROW(String::Format("{0:B}", Double(105.132)), FormatException);
    ASSERT_THROW(String::Format("{0:B}", Double(0.0)), FormatException);
    ASSERT_THROW(String::Format("{0:B5}", Double(10.0)), FormatException);
    ASSERT_THROW(String::Format("{0:B8}", Double(10000.132)), FormatException);
    ASSERT_THROW(String::Format("{0:B8}", Double(10000.132)), FormatException);
  }

  TEST(NumericalFormatTest, B_Single) {
    ASSERT_THROW(String::Format("{0:B}", Single(105.132f)), FormatException);
    ASSERT_THROW(String::Format("{0:B}", Single(0.0f)), FormatException);
    ASSERT_THROW(String::Format("{0:B5}", Single(10.0f)), FormatException);
    ASSERT_THROW(String::Format("{0:B8}", Single(1540.132f)), FormatException);
    ASSERT_THROW(String::Format("{0:B8}", Single(100.2540f)), FormatException);
  }

  TEST(NumericalFormatTest, b) {
    ASSERT_EQ("1111111", String::Format("{0:b4}", Byte(0x7F)));
    ASSERT_EQ("11111011", String::Format("{0:b4}", SByte(-5)));
    ASSERT_EQ("1111001110110111", String::Format("{0:b}", Int16(-3145)));
    ASSERT_EQ("110001001001", String::Format("{0:b4}", UInt16(3145)));
    ASSERT_EQ("11111111111111101000000011111010", String::Format("{0:b}", Int32(-98054)));
    ASSERT_EQ("111111111111111", String::Format("{0:b5}", UInt32(32767)));
    ASSERT_EQ("1111111111111001011100100100011101000101001110001110111100110101", String::Format("{0:b16}", Int64(-1844674407370955ll)));
    ASSERT_EQ("1100110011001100110011001100110011001100110011001110011010011", String::Format("{0:b22}", UInt64(1844674407370955987ull)));
  }

  TEST(NumericalFormatTest, b_ToString) {
    ASSERT_EQ("1111111", Byte(0x7F).ToString("b4"));
    ASSERT_EQ("11111011", SByte(-5).ToString("b4"));
    ASSERT_EQ("1111001110110111", Int16(-3145).ToString("b"));
    ASSERT_EQ("110001001001", UInt16(3145).ToString("b4"));
    ASSERT_EQ("11111111111111101000000011111010", Int32(-98054).ToString("b"));
    ASSERT_EQ("111111111111111", UInt32(32767).ToString("b5"));
    ASSERT_EQ("1111111111111001011100100100011101000101001110001110111100110101", Int64(-1844674407370955ll).ToString("b16"));
    ASSERT_EQ("1100110011001100110011001100110011001100110011001110011010011", UInt64(1844674407370955987ull).ToString("b22"));
  }

}

