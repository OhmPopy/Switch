#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine();
      Console::WriteLine("GetFolderPath: {0}", Environment::GetFolderPath(Environment::SpecialFolder::MyPictures));
    }
  };
}

pcf_startup (Examples::Program)


// This example produces results similar to the following if you run it on macOS:
//
// GetFolderPath: /!---OMITTED---!/Pictures