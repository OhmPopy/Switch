#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Define an array of integers.
      Array<int> values = {0, 15, -15, 0x100000,  -0x100000, 1000000000, -1000000000, Int32::MinValue, Int32::MaxValue};

      // Convert each integer to a byte array.
      Console::WriteLine("{0,16}{1,10}{2,17}", "Integer", "Endian", "Byte Array");
      Console::WriteLine("{0,16}{1,10}{2,17}", "-------", "------", "----------");
      for (auto value : values) {
        Array<byte> byteArray = BitConverter::GetBytes(value);
        Console::WriteLine("{0,16}{1,10}{2,17}", value, BitConverter::IsLittleEndian ? "Little" : " Big", BitConverter::ToString(byteArray));
      }
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
//          Integer    Endian       Byte Array
//          -------    ------       ----------
//                0    Little      00-00-00-00
//               15    Little      0F-00-00-00
//              -15    Little      F1-FF-FF-FF
//          1048576    Little      00-00-10-00
//         -1048576    Little      00-00-F0-FF
//       1000000000    Little      00-CA-9A-3B
//      -1000000000    Little      00-36-65-C4
//      -2147483648    Little      00-00-00-80
//       2147483647    Little      FF-FF-FF-7F
