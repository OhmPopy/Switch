#include <Switch/Property.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class PropertyWriteOnlyTest : public TestFixture {
  protected:
    void CreatePropertyAndSetItWithEqualOperator() {
      int32 v = 42;
      property<int32, writeonly> Value {
        _set {v = value;}
      };

      Value = 24;
      Assert::AreEqual(24, v, _current_information);
    }
    
    void CreatePropertyAndSetItWithSetFunction() {
      int32 v = 42;
      property<int32, writeonly> Value {
        _set {v = value;}
      };
      
      Value.Set(24);
      Assert::AreEqual(24, v, _current_information);
    }
    
    void CreatePropertyAndSetItWithFunctor() {
      int32 v = 42;
      property<int32, writeonly> Value {
        _set {v = value;}
      };
      
      Value(24);
      Assert::AreEqual(24, v, _current_information);
    }
    
    class PropertyTestClass {
    public:
      PropertyTestClass() {}
      PropertyTestClass(const PropertyTestClass& property) : name(property.name) {}
      
      property<string, writeonly> Name {
        _set {this->name = value;}
      };
      
    public:
      string name = "Test property";
    };
    
    void PropertyCopyConstructor() {
      refptr<PropertyTestClass> p1 = ref_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = ref_new<PropertyTestClass>(*p1);
      p2->Name = "Other Value";
      p1 = null;
      Assert::AreEqual("Other Value", p2->name, _current_information);
    }
    
    void PropertyEqualOperator() {
      refptr<PropertyTestClass> p1 = ref_new<PropertyTestClass>();
      refptr<PropertyTestClass> p2 = ref_new<PropertyTestClass>();
      *p2 = *p1;
      p2->Name = "Other Value";
      p1 = null;
      Assert::AreEqual("Other Value", p2->name, _current_information);
    }
  };
  
  _test(PropertyWriteOnlyTest, CreatePropertyAndSetItWithEqualOperator)
  _test(PropertyWriteOnlyTest, CreatePropertyAndSetItWithSetFunction)
  _test(PropertyWriteOnlyTest, CreatePropertyAndSetItWithFunctor)
  _test(PropertyWriteOnlyTest, PropertyCopyConstructor)
  _test(PropertyWriteOnlyTest, PropertyEqualOperator)
}