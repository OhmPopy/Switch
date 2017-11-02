#include <Switch/Switch>

using namespace System;
using namespace TUnit;

namespace UnitTests {
  class _test_fixture(TeastCase1) {
    void _test(TestOne)() {
      Assert::IsTrue(true, _caller);
    }
    
    void _test(TestTwo)() {
      Assert::IsFalse(false, _caller);
    }
    
    void _test(TestThree)() {
      Assert::IsEmpty("", _caller);
    }
  };

  // Used _test to add unit test to execute at the unit test suit.
  _add_test(TeastCase1, TestOne);
  _add_test(TeastCase1, TestTwo);
  _add_test(TeastCase1, TestThree);
}

// This code produces the following output:
//
// Start 9 tests from 3 test cases
//   Start 3 tests from TeastCase1
//     PASSED TeastCase1.TestOne (0 ms)
//     PASSED TeastCase1.TestTwo (0 ms)
//     PASSED TeastCase1.TestThree (0 ms)
//   End 3 tests from TeastCase1 (3 ms total)
//
//   Start 4 tests from TeastCase2
//     PASSED TeastCase2.TestOne (0 ms)
//     PASSED TeastCase2.TestTwo (0 ms)
//     PASSED TeastCase2.TestThree (0 ms)
//     PASSED TeastCase2.TestFour (0 ms)
//   End 4 tests from TeastCase2 (0 ms total)
//
//   Start 2 tests from TeastCase3
//     PASSED TeastCase3.TestOne (0 ms)
//     PASSED TeastCase3.TestTwo (0 ms)
//   End 2 tests from TeastCase3 (1 ms total)
//
//   Summary :
//     PASSED 9 tests.
// End 9 tests from 3 test cases ran. (5 ms total)
