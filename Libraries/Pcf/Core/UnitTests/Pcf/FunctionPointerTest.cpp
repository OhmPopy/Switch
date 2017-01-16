#include <Pcf/ExceptionPointer.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class FunctionPointerTest : public TestFixture {
  protected:
    static string result;
    void SetUp() override {result = string::Empty;}
    
    void CreateFunctionPointerEmptyThenInvoke() {
      FunctionPointer<> fct;
      Assert::IsTrue(fct.IsEmpty(), pcf_current_information);
      Assert::Throws<std::exception>(pcf_delegate {fct.Invoke();}, pcf_current_information);
    }
    
    void CreateFunctionPointerWithLambdaThenInvoke() {
      FunctionPointer<> fct = pcf_delegate {
        result = "fct called";
      };
      Assert::IsFalse(fct.IsEmpty(), pcf_current_information);
      fct.Invoke();
      Assert::AreEqual("fct called", result, pcf_current_information);
    }
    
    void CreateFunctionPointerWithLambdaAndWithArgumentThenInvoke() {
      FunctionPointer<void, const string&> fct = pcf_delegate(const string& value) {
        result = value;
      };
      Assert::IsFalse(fct.IsEmpty(), pcf_current_information);
      fct.Invoke("fct called");
      Assert::AreEqual("fct called", result, pcf_current_information);
    }
    
    void CreateFunctionPointerWithLambdaAndWithReturnThenInvoke() {
      FunctionPointer<string> fct = pcf_delegate {
        return "fct called";
      };
      Assert::IsFalse(fct.IsEmpty(), pcf_current_information);
      result = fct.Invoke();
      Assert::AreEqual("fct called", result, pcf_current_information);
    }
    
    void CreateFunctionPointerWithStaticMethodThenInvoke() {
      struct TestStatic {
        TestStatic() = delete;
        static void StaticFunc() {
          result = "fct called";
        }
      };
      FunctionPointer<> fct = TestStatic::StaticFunc;
      Assert::IsFalse(fct.IsEmpty(), pcf_current_information);
      fct.Invoke();
      Assert::AreEqual("fct called", result, pcf_current_information);
    }
    
    void CreateFunctionPointerWithStaticMethodAndWithArgumentThenInvoke() {
      struct TestStatic {
        TestStatic() = delete;
        static void StaticFunc(const string& value) {
          result = value;
        }
      };
      FunctionPointer<void, const string&> fct = TestStatic::StaticFunc;
      Assert::IsFalse(fct.IsEmpty(), pcf_current_information);
      fct.Invoke("fct called");
      Assert::AreEqual("fct called", result, pcf_current_information);
    }
    
    void CreateFunctionPointerWithStaticMethodAndWithReturnThenInvoke() {
      struct TestStatic {
        TestStatic() = delete;
        static string StaticFunc() {
          return "fct called";
        }
      };
      FunctionPointer<string> fct = TestStatic::StaticFunc;
      Assert::IsFalse(fct.IsEmpty(), pcf_current_information);
      result = fct.Invoke();
      Assert::AreEqual("fct called", result, pcf_current_information);
    }
    
    void CreateFunctionPointerWithMemberMethodThenInvoke() {
      struct TestMember {
        void MemberFunc() {
          result = "fct called";
        }
      };
      TestMember testMember;
      FunctionPointer<> fct = FunctionPointer<>(testMember, &TestMember::MemberFunc);
      Assert::IsFalse(fct.IsEmpty(), pcf_current_information);
      fct.Invoke();
      Assert::AreEqual("fct called", result, pcf_current_information);
    }
    
    void CreateFunctionPointerWithMemberMethodAndWithArgumentThenInvoke() {
      struct TestMember {
        void MemberFunc(const string& value) {
          result = value;
        }
      };
      TestMember testMember;
      FunctionPointer<void, const string&> fct = FunctionPointer<void, const string&>(testMember, &TestMember::MemberFunc);
      Assert::IsFalse(fct.IsEmpty(), pcf_current_information);
      fct.Invoke("fct called");
      Assert::AreEqual("fct called", result, pcf_current_information);
    }
    
    void CreateFunctionPointerWithMemberMethodAndWithReturnThenInvoke() {
      struct TestMember {
        string MemberFunc() {
          return "fct called";
        }
      };
      TestMember testMember;
      FunctionPointer<string> fct = FunctionPointer<string>(testMember, &TestMember::MemberFunc);
      Assert::IsFalse(fct.IsEmpty(), pcf_current_information);
      result = fct.Invoke();
      Assert::AreEqual("fct called", result, pcf_current_information);
    }
    
    void CreateFunctionPointerWithFunctorThenInvoke() {
      struct TestFunctor {
        void operator()() {
          result = "fct called";
        }
      };
      TestFunctor testFunctor;
      FunctionPointer<> fct = testFunctor;
      Assert::IsFalse(fct.IsEmpty(), pcf_current_information);
      fct.Invoke();
      Assert::AreEqual("fct called", result, pcf_current_information);
    }
    
    void CreateFunctionPointerWithFunctorAndWithArgumentThenInvoke() {
      struct TestFunctor {
        void operator()(const string& value) {
          result = value;
        }
      };
      TestFunctor testFunctor;
      FunctionPointer<void, const string&> fct = testFunctor;
      Assert::IsFalse(fct.IsEmpty(), pcf_current_information);
      fct.Invoke("fct called");
      Assert::AreEqual("fct called", result, pcf_current_information);
    }
    
    void CreateFunctionPointerWithFunctorAndWithReturnThenInvoke() {
      struct TestFunctor {
        string operator()() {
          return "fct called";
        }
      };
      TestFunctor testFunctor;
      FunctionPointer<string> fct = testFunctor;
      Assert::IsFalse(fct.IsEmpty(), pcf_current_information);
      result = fct.Invoke();
      Assert::AreEqual("fct called", result, pcf_current_information);
    }
  };
  
  string FunctionPointerTest::result;
  
  pcf_test(FunctionPointerTest, CreateFunctionPointerEmptyThenInvoke)
  pcf_test(FunctionPointerTest, CreateFunctionPointerWithLambdaThenInvoke)
  pcf_test(FunctionPointerTest, CreateFunctionPointerWithLambdaAndWithArgumentThenInvoke)
  pcf_test(FunctionPointerTest, CreateFunctionPointerWithLambdaAndWithReturnThenInvoke)
  pcf_test(FunctionPointerTest, CreateFunctionPointerWithStaticMethodThenInvoke)
  pcf_test(FunctionPointerTest, CreateFunctionPointerWithStaticMethodAndWithArgumentThenInvoke)
  pcf_test(FunctionPointerTest, CreateFunctionPointerWithStaticMethodAndWithReturnThenInvoke)
  pcf_test(FunctionPointerTest, CreateFunctionPointerWithMemberMethodThenInvoke)
  pcf_test(FunctionPointerTest, CreateFunctionPointerWithMemberMethodAndWithArgumentThenInvoke)
  pcf_test(FunctionPointerTest, CreateFunctionPointerWithMemberMethodAndWithReturnThenInvoke)
  pcf_test(FunctionPointerTest, CreateFunctionPointerWithFunctorThenInvoke)
  pcf_test(FunctionPointerTest, CreateFunctionPointerWithFunctorAndWithArgumentThenInvoke)
  pcf_test(FunctionPointerTest, CreateFunctionPointerWithFunctorAndWithReturnThenInvoke)
}
