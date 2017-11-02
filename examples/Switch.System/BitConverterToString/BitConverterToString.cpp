#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<byte> arrayOne = {0, 1, 2, 4, 8, 16, 32, 64, 128, 255};
      Array<byte> arrayTwo = {32, 0, 0, 42, 0, 65, 0, 125, 0, 197, 0, 168, 3, 41, 4, 172, 32};
      Array<byte> arrayThree = {15, 0, 0, 128, 16, 39, 240, 216, 241, 255, 127};
      Array<byte> arrayFour = {15, 0, 0, 0, 0, 16, 0, 255, 3, 0, 0, 202, 154, 59, 255, 255, 255, 255, 127};
      Console::WriteLine("This example of the BitConverter::ToString( unsigned char[ ] ) \n"
                         "method generates the following output.\n" );
      WriteByteArray(arrayOne, "arrayOne");
      WriteByteArray(arrayTwo, "arrayTwo");
      WriteByteArray(arrayThree, "arrayThree");
      WriteByteArray(arrayFour, "arrayFour");
    }
    
  private:
    // Display a byte array with a name.
    static void WriteByteArray(const Array<byte>& bytes, const String& name ) {
      string underLine = "--------------------------------";
      Console::WriteLine(name);
      Console::WriteLine(underLine.Substring(0, Math::Min(name.Length, underLine.Length)));
      Console::WriteLine(BitConverter::ToString( bytes ));
      Console::WriteLine();
    }
  };
}

_startup(Examples::Program)

// This code produces the following output:
//
// This example of the BitConverter::ToString( unsigned char[ ] )
// method generates the following output.
//
// arrayOne
// --------
// 00-01-02-04-08-10-20-40-80-FF
//
// arrayTwo
// --------
// 20-00-00-2A-00-41-00-7D-00-C5-00-A8-03-29-04-AC-20
//
// arrayThree
// ----------
// 0F-00-00-80-10-27-F0-D8-F1-FF-7F
//
// arrayFour
// ---------
// 0F-00-00-00-00-10-00-FF-03-00-00-CA-9A-3B-FF-FF-FF-FF-7F
