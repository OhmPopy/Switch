#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // make an array
      Array<int> myArray = {10, 20, 30, 40, 50, 60, 70};

      Console::WriteLine("Items of myArray : ");
      lock_(myArray.SyncRoot) {
        for (int item : myArray)
          Console::Write("{0} ", item);
      }
      Console::WriteLine();
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
// Items of myArray :
// 10 20 30 40 50 60 70
