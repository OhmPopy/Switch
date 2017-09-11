﻿#include <Switch/System/String.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>
#include <Switch/LiteralOperatorConverter.hpp>
#include <Switch/Foreach.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class StringTest : public TestFixture {
  protected:
    void SetUp() override {}

    void TearDown() override {}

    void StringCreatedWithDefaultConstructor() {
      TUnit::Assert::AreEqual("", string());
    }
    
    void StringCreatedWithConstCharPointerConstructor() {
      TUnit::Assert::AreEqual("Test", string("Test"), _current_information);
    }
    
    void StringCreatedWithConstChar16PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test", string(u"Test"), _current_information);
    }
    
    void StringCreatedWithConstChar32PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test", string(U"Test"), _current_information);
    }
    
    void StringCreatedWithConstWCharPointerConstructor() {
      TUnit::Assert::AreEqual(U"Test", string(L"Test"), _current_information);
    }

    void StringCreatedWithConstRawCharPointerConstructor() {
      TUnit::Assert::AreEqual("Test \\ 1", string(R"(Test \ 1)"), _current_information);
    }
    
    void StringCreatedWithConstRawChar16PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test \\ 1", string(uR"(Test \ 1)"), _current_information);
    }
    
    void StringCreatedWithConstRawChar32PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test \\ 1", string(UR"(Test \ 1)"), _current_information);
    }
    
    void StringCreatedWithConstRawWCharPointerConstructor() {
      TUnit::Assert::AreEqual(U"Test \\ 1", string(LR"(Test \ 1)"), _current_information);
    }
    
    void StringCreatedWithCopyConstructor() {
      TUnit::Assert::AreEqual("Test1", string(string("Test1")), _current_information);
    }
    
    void StringCreatedWithConstCharPointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(_delegate {string(static_cast<const char*>(null));}, _current_information);
    }
    
    void StringCreatedWithConstChar16PointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(_delegate {string(static_cast<const char16*>(null));}, _current_information);
    }
    
    void StringCreatedWithConstChar32PointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(_delegate {string(static_cast<const char32*>(null));}, _current_information);
    }
    
    void StringCreatedWithConstWCharPointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(_delegate {string(static_cast<const wchar*>(null));}, _current_information);
    }
    
    void StringCreatedWithConstCharPointerAndNegativeStartIndexConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {string("strTest1", -1, 0);}, _current_information);
    }
    
    void StringCreatedWithConstCharPointerAndNegativeCountConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {string("strTest1", 0, -1);}, _current_information);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexGreaterThenLengthConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {string("strTest1", 10, 2);}, _current_information);
    }
    
    void StringCreatedWithConstCharPointerAndCountGraterThenLengthConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {string("strTest1", 0, 10);}, _current_information);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexAndCountEqualsZeroConstructor() {
      TUnit::Assert::AreEqual("", string("strTest1", 0, 0), _current_information);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexEqualsZeroAndCountEqualLengthConstructor() {
      TUnit::Assert::AreEqual("strTest1", string("strTest1", 0, 8), _current_information);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexAndCountInsideLengthConstructor() {
      TUnit::Assert::AreEqual("Test", string("strTest1", 3, 4), _current_information);
    }
    
    void StringCreatedWithConstCharPointerAndCountInsideLengthConstructor() {
      TUnit::Assert::AreEqual("str", string("strTest1", 3), _current_information);
    }
    
    void StringCreatedWithConstCharPointerAndCountEqualsLengthConstructor() {
      TUnit::Assert::AreEqual("strTest1", string("strTest1", 8), _current_information);
    }
    
    void StringCreatedWithConstCharPointerAndCountGreaterLengthConstructor() {
      TUnit::Assert::AreEqual("str", string("str", 8), _current_information);
    }
    
    void StringCreatedWithConstCharPointerEmptyAndCountGreaterLengthConstructor() {
      TUnit::Assert::AreEqual("", string("", 8), _current_information);
    }

    void StringCreatedByAssignment() {
      String s = "This is a string created by assignment.";
      TUnit::Assert::AreEqual("This is a string created by assignment.", s, _current_information);
    }

    void StringCreatedByAssignmentWithBackslash() {
      String s = "The path is C:\\PublicDocuments\\Report1.doc";
      TUnit::Assert::AreEqual("The path is C:\\PublicDocuments\\Report1.doc", s, _current_information);
    }

    void StringCreatedByAssignmentWithVerbatimBackslash() {
      String s = R"(The path is C:\PublicDocuments\Report1.doc)";
      TUnit::Assert::AreEqual("The path is C:\\PublicDocuments\\Report1.doc", s, _current_information);
    }

    void StringCreatedByConstructorWithChars() {
      Array<char> chars = { 'w', 'o', 'r', 'd' };
      String s(chars);
      TUnit::Assert::AreEqual("word", s, _current_information);
    }

    void StringCreatedByConstructorWith32bitsChars() {
      Array<char32> chars = { 'w', 'o', 'r', 'd' };
      String s(chars);
      TUnit::Assert::AreEqual("word", s, _current_information);
    }

    void CreateAStringThatConsistsOfACharacterRepeated20Times() {
      String s('C', 20);
      TUnit::Assert::AreEqual("CCCCCCCCCCCCCCCCCCCC", s, _current_information);
    }

    void StringCreatedByConstructorWithPointerOnSBytes() {
      sbyte bytes[] = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x00 };
      string s(bytes);
      TUnit::Assert::AreEqual("ABCDE", s, _current_information);
    }
    
    void StringCreatedByAssignmentWithUnicodeStringLiteral() {
      string s = U"こんにちは世界!";
      TUnit::Assert::AreEqual(U"こんにちは世界!", s, _current_information);
    }
    
    void SubscriptOperatorWithChar() {
      Array<char> chars = {'T', 'e', 's', 't'};
      string s = "Test";
      for (int i = 0; i < chars.Length; i++)
        TUnit::Assert::AreEqual(chars[i], static_cast<char>(s[i]), _current_information);
    }
    
    void SubscriptOperatorWithChar32() {
      Array<char32> chars = {U'こ', U'ん', U'に', U'ち', U'は', U'世', U'界', U'!'};
      string s = U"こんにちは世界!";
      int i = 0;
      for (char32 c : chars)
        TUnit::Assert::AreEqual(c, s[i++], _current_information);
      TUnit::Assert::AreEqual(chars.Length, i, _current_information);
    }
    
    void OperatorLitteralChar() {
      TUnit::Assert::AreEqual("Switch::System::String", _typeof("Test"_S).ToString(), _current_information);
    }
    
    void OperatorLitteralChar16() {
      TUnit::Assert::AreEqual("Switch::System::String", _typeof(u"Test"_S).ToString(), _current_information);
    }
    
    void OperatorLitteralChar32() {
      TUnit::Assert::AreEqual("Switch::System::String", _typeof(U"Test"_S).ToString(), _current_information);
    }
    
    void OperatorLitteralWChar() {
      TUnit::Assert::AreEqual("Switch::System::String", _typeof(L"Test"_S).ToString(), _current_information);
    }
    
    void OperatorAddConstCharPointer() {
      TUnit::Assert::AreEqual("string A string B", string("string A ") + "string B", _current_information);
    }
    
    void OperatorAddBoolean() {
      TUnit::Assert::AreEqual("string A False", string("string A ") + false, _current_information);
    }
    
    void OperatorAddBooleanObject() {
      TUnit::Assert::AreEqual("string A True", string("string A ") + Boolean(true), _current_information);
    }
    
    void OperatorAddByte() {
      TUnit::Assert::AreEqual("string A 18", string("string A ") + static_cast<byte>(18), _current_information);
    }
    
    void OperatorAddByteObject() {
      TUnit::Assert::AreEqual("string A 15", string("string A ") + Byte(15), _current_information);
    }
    
    void OperatorAddChar() {
      TUnit::Assert::AreEqual("string A a", string("string A ") + 'a', _current_information);
    }
    
    void OperatorAddChar16() {
      TUnit::Assert::AreEqual("string A d", string("string A ") + u'd', _current_information);
    }
    
    void OperatorAddChar32() {
      TUnit::Assert::AreEqual("string A d", string("string A ") + U'd', _current_information);
    }
    
    void OperatorAddWChar() {
      TUnit::Assert::AreEqual("string A d", string("string A ") + L'd', _current_information);
    }
    
    void OperatorAddCharObject() {
      TUnit::Assert::AreEqual("string A G", string("string A ") + Char('G'), _current_information);
    }
    
    void OperatorAddDouble() {
      TUnit::Assert::AreEqual("string A -0.987678", string("string A ") + -0.987678, _current_information);
    }
    
    void OperatorAddDoubleObject() {
      TUnit::Assert::AreEqual("string A -0.987678", string("string A ") + Double(-0.987678), _current_information);
    }
    
    void OperatorAddInt16() {
      TUnit::Assert::AreEqual("string A -32768", string("string A ") + Int16::MinValue, _current_information);
    }
    
    void OperatorAddInt16Object() {
      TUnit::Assert::AreEqual("string A 32767", string("string A ") + Int16(Int16::MaxValue), _current_information);
    }
    
    void OperatorAddInt32() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<int32>(42), _current_information);
    }
    
    void OperatorAddInt32Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + Int32(5467), _current_information);
    }
    
    void OperatorAddInt64() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<int64>(42), _current_information);
    }
    
    void OperatorAddInt64Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + Int64(5467), _current_information);
    }
    
    void OperatorAddSByte() {
      TUnit::Assert::AreEqual("string A -2", string("string A ") + static_cast<sbyte>(-2), _current_information);
    }
    
    void OperatorAddSByteObject() {
      TUnit::Assert::AreEqual("string A 15", string("string A ") + SByte(15), _current_information);
    }
    
    void OperatorAddUInt16() {
      TUnit::Assert::AreEqual("string A 0", string("string A ") + UInt16::MinValue, _current_information);
    }
    
    void OperatorAddUInt16Object() {
      TUnit::Assert::AreEqual("string A 6345", string("string A ") + UInt16(6345), _current_information);
    }
    
    void OperatorAddUInt32() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<uint32>(42), _current_information);
    }
    
    void OperatorAddUInt32Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + UInt32(5467), _current_information);
    }
    
    void OperatorAddUInt64() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<uint64>(42), _current_information);
    }
    
    void OperatorAddUInt64Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + UInt64(5467), _current_information);
    }
    
    void OperatorAddSingle() {
      TUnit::Assert::AreEqual("string A 0.0654", string("string A ") + 0.0654f, _current_information);
    }
    
    void OperatorAddSingleObject() {
      TUnit::Assert::AreEqual("string A 0.0654", string("string A ") + Single(0.0654f), _current_information);
    }
    
    void OperatorAddDateTimeObject() {
      TUnit::Assert::AreEqual("string A 01/01/1970 00:00:00", string("string A ") + DateTime(1970, 1, 1, 0, 0, 0), _current_information);
    }
    
    void CompareEmptyStrings() {
      TUnit::Assert::IsTrue(string::Compare("", "") ==  0, _current_information);
    }
    
    void CompareEmptyStringWithStringEmpty() {
      TUnit::Assert::IsTrue(string::Compare("", String::Empty) ==  0, _current_information);
    }
    
    void CompareEmptyStringWithAnyString() {
      TUnit::Assert::IsTrue(string::Compare("", "string To Compare") < 0, _current_information);
    }
    
    void CompareAnyStringWithEmptyString() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "") > 0, _current_information);
    }
    
    void CompareSameStrings() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Compare") == 0, _current_information);
    }
    
    void CompareGreaterString() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Comp") > 0, _current_information);
    }
    
    void CompareLessString() {
      TUnit::Assert::IsTrue(string::Compare("string To Comp", "string To Compare") < 0, _current_information);
    }
    
    void CompareIndex() {
      TUnit::Assert::IsTrue(string::Compare("Char To Compare", 4, "string To Compare", 6, 11) == 0, _current_information);
    }
    
    void CompareEmptyStringsWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("", "", true) == 0, _current_information);
    }
    
    void CompareEmptyStringWithStringEmptyWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("", String::Empty, true) ==  0, _current_information);
    }
    
    void CompareEmptyStringWithAnyStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("", "string To compare", true) < 0, _current_information);
    }
    
    void CompareAnyStringWithEmptyStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string To compare", "", true) > 0, _current_information);
    }
    
    void CompareSameStringsWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Compare", true) == 0, _current_information);
    }
    
    void CompareGreaterStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Comp", true) > 0, _current_information);
    }
    
    void CompareLessStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to comp", "string To Compare", true) < 0, _current_information);
    }
    
    void CompareDifferentCaseStringsWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Compare", true) == 0, _current_information);
    }
    
    void CompareGreaterDifferentCaseStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Comp", true) > 0, _current_information);
    }
    
    void CompareLessDifferentCaseStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to comp", "string To Compare", true) < 0, _current_information);
    }
    
    void CompareEmptyStringsWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("", "", false) == 0, _current_information);
    }
    
    void CompareEmptyStringWithStringEmptyWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("", String::Empty, false) ==  0, _current_information);
    }
    
    void CompareEmptyStringWithAnyStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("", "string To Compare",false) < 0, _current_information);
    }
    
    void CompareAnyStringWithEmptyStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "",false) > 0, _current_information);
    }
    
    void CompareSameStringsWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Compare",false) == 0, _current_information);
    }
    
    void CompareGreaterStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Comp",false) > 0, _current_information);
    }
    
    void CompareLessStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Comp", "string To Compare",false) < 0, _current_information);
    }
    
    void CompareDifferentCaseStringsWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Compare", false) > 0, _current_information);
    }
    
    void CompareGreaterDifferentCaseStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Comp", false) > 0, _current_information);
    }
    
    void CompareLessDifferentCaseStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string to comp", "string To Compare", false) > 0, _current_information);
    }
    
    void CompareIndexIgnoreCase() {
      TUnit::Assert::IsTrue(string::Compare("Char to compare", 4, "string To Compare", 6, 11,true) == 0, _current_information);
      TUnit::Assert::IsTrue(string::Compare("Char to compare", 4, "string To Compare", 6, 11,true) == 0, _current_information);
      TUnit::Assert::IsTrue(string::Compare("Char to Compare", 4, "string TO Compare", 6, 11, false) > 0, _current_information);
      TUnit::Assert::IsTrue(string::Compare("Char To Compare", 4, "string To Compare", 6, 11,false) == 0, _current_information);
    }
    
    void Concat() {
      TUnit::Assert::AreEqual(Object().ToString(), string::Concat(Object()), _current_information);
      TUnit::Assert::AreEqual(Object().ToString() + Object().ToString() + Object().ToString(), string::Concat<>(Array<Object> {Object(), Object(), Object()}), _current_information);
      TUnit::Assert::AreEqual(Object().ToString() + Object().ToString(), string::Concat(Object(), Object()), _current_information);
      TUnit::Assert::AreEqual( Object().ToString() + Object().ToString() + Object().ToString(), string::Concat(Object(), Object(), Object()),_current_information);
      
      TUnit::Assert::AreEqual("264", string::Concat(UInt32(264)), _current_information);
      TUnit::Assert::AreEqual("True", string::Concat(Boolean(true)), _current_information);
      TUnit::Assert::AreEqual("string to concatenate", string::Concat(string("string to concatenate")), _current_information);
      
      TUnit::Assert::AreEqual("264128", string::Concat(UInt32(264), UInt32(128)), _current_information);
      TUnit::Assert::AreEqual("TrueFalse", string::Concat(Boolean(true), Boolean(false)), _current_information);
      TUnit::Assert::AreEqual("string Astring B", string::Concat("string A", "string B"), _current_information);
      TUnit::Assert::AreEqual("264128378", string::Concat(UInt32(264), UInt32(128), UInt32(378)), _current_information);
      TUnit::Assert::AreEqual("TrueFalseTrue", string::Concat(Boolean(true), Boolean(false), Boolean(true)), _current_information);
      TUnit::Assert::AreEqual("string Astring Bstring C", string::Concat("string A", "string B", "string C"), _current_information);
      TUnit::Assert::AreEqual("string Astring Bstring Cstring D", string::Concat("string A", "string B", "string C", "string D"), _current_information);
    }
    
    void ConcatArray() {
      TUnit::Assert::AreEqual("264128378842", string::Concat<>(Array<Int32> {264, 128, 378, 842}), _current_information);
      TUnit::Assert::AreEqual("TrueFalseTrue", string::Concat<>(Array<Boolean> {true, false, true}), _current_information);
      TUnit::Assert::AreEqual("string To Concat", string::Concat<>(Array<string> {"string ", "To ", "Concat"}), _current_information);
    }
    
    void EndsWith() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith("beast"), _current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith("Beast"), _current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith("Beast", false), _current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith("Beast", true), _current_information);
    }
    
    void EndsWithChar32() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith('t'), _current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith('T'), _current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith('s'), _current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith('T', false), _current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith('T', true), _current_information);
    }
    
    void StartsWith() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith("This"), _current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith("this"), _current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith("this", false), _current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith("this", true), _current_information);
    }
    
    void StartsWithChar32() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith('T'), _current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith('t'), _current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith('h'), _current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith('t', false), _current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith('t', true), _current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith('T', true), _current_information);
    }
    
    void GetEnumeratorOnString() {
      string str = "This is a test for enumerator";
      string output;
      System::Collections::Generic::Enumerator<char32> enumerator = str.GetEnumerator();
      while (enumerator.MoveNext())
        output += enumerator.Current;
      TUnit::Assert::AreEqual("This is a test for enumerator", output, _current_information);
    }
    
    void ForeachOnString() {
      string str = "This is a test for foreach";
      string output;
      for (char32 item : str)
        output += item;
      TUnit::Assert::AreEqual("This is a test for foreach", output, _current_information);
    }
    
    void IteratorOnString() {
      string str = "This is a test for iterator";
      string output;
      for (string::const_iterator iterator = str.cbegin(); iterator != str.cend(); ++iterator)
        output += *iterator;
      TUnit::Assert::AreEqual("This is a test for iterator", output, _current_information);
    }
    
    void ForOnString() {
      string str = "This is a test for for";
      string output;
      for (int32 index = 0; index < str.Length; ++index)
        output += str[index];
      TUnit::Assert::AreEqual("This is a test for for", output, _current_information);
    }
    
    void GetHashCode() {
      TUnit::Assert::AreNotEqual("A"_S.GetHashCode(), "B"_S.GetHashCode(), _current_information);
      TUnit::Assert::AreEqual("ABCD"_S.GetHashCode(),"ABCD"_S.GetHashCode(), _current_information);
      TUnit::Assert::AreNotEqual("ABCD"_S.GetHashCode(), "ABCE"_S.GetHashCode(), _current_information);
      TUnit::Assert::AreEqual("ABCDE"_S.GetHashCode(), "ABCDE"_S.GetHashCode(), _current_information);
      TUnit::Assert::AreNotEqual("My string"_S.GetHashCode(), "My Strinh"_S.GetHashCode(), _current_information);
      TUnit::Assert::AreNotEqual("My string"_S.GetHashCode(), "My Gtrins"_S.GetHashCode(), _current_information);
      TUnit::Assert::AreEqual("another string"_S.GetHashCode(), "another string"_S.GetHashCode(), _current_information);
      
      refptr<string> clone;
      string testClone("Test Clone");
      clone = as<string>(testClone.Clone());
      TUnit::Assert::AreEqual(testClone.GetHashCode(),clone->GetHashCode(), _current_information);
    }
    
    void IsNullOrEmptyOnEmptyString() {
      TUnit::Assert::IsTrue(string::IsNullOrEmpty(""_S), _current_information);
    }
    
    void IsNullOrEmptyOnNonEmptyString() {
      TUnit::Assert::IsFalse(string::IsNullOrEmpty("Not Empty"_S), _current_information);
    }
    
    void IsNullOrEmptyOnStringEmpty() {
      TUnit::Assert::IsTrue(string::IsNullOrEmpty(string::Empty), _current_information);
    }
    
    void IndexOf() {
      TUnit::Assert::AreEqual(2, "This is the beast of the beast"_S.IndexOf('i'), _current_information);
      TUnit::Assert::AreEqual(5, "This is the beast of the beast"_S.IndexOf('i', 3), _current_information);
      TUnit::Assert::AreEqual(5, "This is the beast of the beast"_S.IndexOf('i', 3, 3), _current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.IndexOf('i', 3, 2), _current_information);
      TUnit::Assert::AreEqual(29, "This is the beast of the beast"_S.IndexOf('t', 29), _current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.IndexOf('t', 30), _current_information);
      
      TUnit::Assert::AreEqual(8, "This is the beast of the beast"_S.IndexOf("the"), _current_information);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.IndexOf("the", 19), _current_information);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.IndexOf("the", 19, 5), _current_information);
      
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.IndexOf("the", 18, 3), _current_information);
    }
    
    void IndexOfExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.IndexOf('i', 31);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.IndexOf('i', 26,5);}, _current_information);
      
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.IndexOf("the", 31);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.IndexOf("the", 26,5);}, _current_information);
    }
    
    void IndexOfAny() {
      Array<char32> separators = {'.', ',', ':','_'};
      
      TUnit::Assert::AreEqual(4,  "This, is : separator."_S.IndexOfAny(separators), _current_information);
      TUnit::Assert::AreEqual(9,  "This, is : separator."_S.IndexOfAny(separators, 5), _current_information);
      TUnit::Assert::AreEqual(9,  "This, is : separator."_S.IndexOfAny(separators, 5, 5), _current_information);
      TUnit::Assert::AreEqual(-1, "This, is : separator."_S.IndexOfAny(separators, 5, 4), _current_information);
      
      String xxxx_ = "xxxx_";
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 0, 5), _current_information);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 1, 4), _current_information);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 2, 3), _current_information);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 3, 2), _current_information);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 4, 1), _current_information);
      TUnit::Assert::AreEqual(-1, xxxx_.IndexOfAny(separators, 5, 0), _current_information);
    }
    
    void IndexOfAnyExceptions() {
      Array<char32> separators = {'.', ',', ':','_'};
      
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This, is : separator."_S.IndexOfAny(separators, 22);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This, is : separator."_S.IndexOfAny(separators, 18,5);}, _current_information);
      
      String xxxx_ = String("xxxx_");
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, -1,3);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 0,-1);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 2,-1);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 0,6);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 1,5);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 2,4);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 3,3);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 4,2);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 5,1);}, _current_information);
    }
    
    void Join() {
      Array<string> array = {"123", "a text", "ok"};
      TUnit::Assert::AreEqual("123, a text, ok", string::Join(", ", array, 0, 3), _current_information);
    }
    
    void JoinN() {
      string join[] = {"blue", "red", "green", "yellow"};
      TUnit::Assert::AreEqual("blue, red, green, yellow", string::Join(", ", join, 4), _current_information);
      TUnit::Assert::AreEqual("red, green", string::Join(", ", join, 4, 1, 2), _current_information);
    }
    
    void JoinNExceptions() {
      string join[] = {"blue", "red", "green", "yellow"};
      TUnit::Assert::Throws<ArgumentNullException>(_delegate {string::Join(", ", null, 4);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {string::Join(", ", join, 4,4,2);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {string::Join(", ", join, 4,1,4);}, _current_information);
    }
    
    void LastIndexOf() {
      TUnit::Assert::AreEqual(26, "This is the beast of the beast"_S.LastIndexOf('e'), _current_information);
      TUnit::Assert::AreEqual(26, "This is the beast of the beast"_S.LastIndexOf('e', 3), _current_information);
      TUnit::Assert::AreEqual(13, "This is the beast of the beast"_S.LastIndexOf('e', 11, 3), _current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.LastIndexOf('e', 11, 2), _current_information);
      
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.LastIndexOf("the"), _current_information);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.LastIndexOf("the", 19), _current_information);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.LastIndexOf("the", 19, 5), _current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.LastIndexOf("the", 19, 4), _current_information);
      TUnit::Assert::AreEqual(8, "This is the beast of the beast"_S.LastIndexOf("the", 5, 6), _current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.LastIndexOf("the", 5, 5), _current_information);
    }
    
    void LastIndexOfExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.LastIndexOf('e', 31);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.LastIndexOf('e', 29,2);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.LastIndexOf("the", 31);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.LastIndexOf("the", 29, 2);}, _current_information);
    }
    
    void LastIndexOfAny() {
      char32 nativeSeparator[] = {'.', ',', ':'};
      TUnit::Assert::AreEqual(20, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3)), _current_information);
      TUnit::Assert::AreEqual(20, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5), _current_information);
      TUnit::Assert::AreEqual(9, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5, 5), _current_information);
      TUnit::Assert::AreEqual(-1, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5, 4), _current_information);
    }
    
    void LastIndexOfAnyException() {
      char32 nativeSeparator[] = {'.', ',', ':'};
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 22);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 18,5);}, _current_information);
    }
    
    void PadLeft() {
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadLeft(13), _current_information);
      TUnit::Assert::AreEqual(" string To Pad", "string To Pad"_S.PadLeft(14), _current_information);
      TUnit::Assert::AreEqual("  string To Pad", "string To Pad"_S.PadLeft(15), _current_information);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadLeft(12, '*'), _current_information);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadLeft(13, '*'), _current_information);
      TUnit::Assert::AreEqual("*string To Pad", "string To Pad"_S.PadLeft(14, '*'), _current_information);
      TUnit::Assert::AreEqual("**string To Pad", "string To Pad"_S.PadLeft(15, '*'), _current_information);
    }
    
    void PadRight() {
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadRight(13), _current_information);
      TUnit::Assert::AreEqual("string To Pad ", "string To Pad"_S.PadRight(14), _current_information);
      TUnit::Assert::AreEqual("string To Pad  ", "string To Pad"_S.PadRight(15), _current_information);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadRight(12, '*'), _current_information);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadRight(13, '*'), _current_information);
      TUnit::Assert::AreEqual("string To Pad*", "string To Pad"_S.PadRight(14, '*'), _current_information);
      TUnit::Assert::AreEqual("string To Pad**", "string To Pad"_S.PadRight(15, '*'), _current_information);
    }
    
    void Remove() {
      TUnit::Assert::AreEqual("", "abc123ABC"_S.Remove(0),_current_information);
      TUnit::Assert::AreEqual("abc", "abc123ABC"_S.Remove(3), _current_information);
      TUnit::Assert::AreEqual("abcABC", "abc123ABC"_S.Remove(3, 3), _current_information);
      TUnit::Assert::AreEqual("abc", "abc123ABC"_S.Remove(3, 6), _current_information);
      TUnit::Assert::AreEqual("abc123ABC", "abc123ABC"_S.Remove(9), _current_information);
    }
    
    void RemoveExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"abc123ABC"_S.Remove(10);}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"abc123ABC"_S.Remove(8,2);}, _current_information);
    }

    void Insert() {
      TUnit::Assert::AreEqual("abc", ""_S.Insert(0,"abc"));
      TUnit::Assert::AreEqual("abc123ABC", "abcABC"_S.Insert(3,"123"));
      TUnit::Assert::AreEqual("abc123", "abc"_S.Insert(3,"123"));
    }
    void InsertExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"ok"_S.Insert(-1,"abc");}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {""_S.Insert(1,"abc");}, _current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"abc"_S.Insert(4,"123");}, _current_information);
    }
    
    void Replace() {
      TUnit::Assert::AreEqual("This*is*the*beast*of*the*beast", "This is the beast of the beast"_S.Replace(' ', '*'), _current_information);
      TUnit::Assert::AreEqual("This is thE bEast of thE bEast", "This is the beast of the beast"_S.Replace('e', 'E'), _current_information);
      TUnit::Assert::AreEqual("Thare are the beast of the beast", "This is the beast of the beast"_S.Replace("is", "are"), _current_information);
      TUnit::Assert::AreEqual("Th  the beast of the beast", "This is the beast of the beast"_S.Replace("is", ""), _current_information);
      TUnit::Assert::AreEqual("This text has\\_unescaped\\_\\_underscores !", "This text has_unescaped__underscores !"_S.Replace("_", "\\_"), _current_information);
    }
    
    void Split() {
      TUnit::Assert::AreEqual(Array<string> {}, ""_S.Split({'+', '-', '='}), _current_information);
      TUnit::Assert::AreEqual(Array<string> {"a"}, "a"_S.Split({'+', '-', '='}), _current_information);
      TUnit::Assert::AreEqual(Array<string> {"100", "42", "142"}, "100+42=142"_S.Split({'+', '-', '='}), _current_information);
      TUnit::Assert::AreEqual(Array<string> {"100+42=142"}, "100+42=142"_S.Split({'%', '*'}), _current_information);
      TUnit::Assert::AreEqual(Array<string> {"100+42=142"}, "100+42=142"_S.Split({}), _current_information);
      TUnit::Assert::AreEqual(Array<string> {"a", "b", "c"}, "a,b,c"_S.Split(','), _current_information);
      TUnit::Assert::AreEqual(Array<string> {"a", "", "", "b", "", "c"}, "a,,,b,,c"_S.Split(','), _current_information);
    }
    
    void SplitCount() {
      TUnit::Assert::AreEqual(Array<string> {"42", " 12, 19"}, "42, 12, 19"_S.Split({',', ' '}, 2), _current_information);
      TUnit::Assert::AreEqual(Array<string> {"42", "", "12", ".19"}, "42..12..19"_S.Split({'.'}, 4), _current_information);
      TUnit::Assert::AreEqual(Array<string> {"Banana"}, "Banana"_S.Split({','}, 2), _current_information);
      TUnit::Assert::AreEqual(Array<string> {"Darb\nSmarba "}, "Darb\nSmarba "_S.Split({}, 1), _current_information);
    }
    
    void SplitWithStringSplitOptionRemoveEmptyEntries() {
      TUnit::Assert::AreEqual(Array<string> {"a", "b", "c"}, "a,,,b,,c"_S.Split(',', StringSplitOptions::RemoveEmptyEntries), _current_information);
    }
  
    void SplitWithStringSplitOptioNone() {
      TUnit::Assert::AreEqual(Array<string> {"a", "", "", "b", "", "c"}, "a,,,b,,c"_S.Split(',', StringSplitOptions::None), _current_information);
    }
    
    void ToUpper() {
      TUnit::Assert::AreEqual("STRING TO UPPER OR TO LOWER", "string To Upper or To Lower"_S.ToUpper(), _current_information);
    }
    
    void ToLower() {
      TUnit::Assert::AreEqual("string to upper or to lower", "string To Upper or To Lower"_S.ToLower(), _current_information);
    }
    
    void TrimStart() {
      TUnit::Assert::AreEqual("string To Trim", "string To Trim"_S.TrimStart('x'), _current_information);
      TUnit::Assert::AreEqual("string To Trim", "xxxstring To Trim"_S.TrimStart('x'), _current_information);
      TUnit::Assert::AreEqual("string To Trim", "xxstring To Trim"_S.TrimStart('x'), _current_information);
      TUnit::Assert::AreEqual("string To Trim", "xstring To Trim"_S.TrimStart('x'), _current_information);
      TUnit::Assert::AreEqual("", ""_S.TrimStart('x'), _current_information);
      TUnit::Assert::AreEqual("", "x"_S.TrimStart('x'), _current_information);
      TUnit::Assert::AreEqual("", "xx"_S.TrimStart('x'), _current_information);
      TUnit::Assert::AreEqual("", "xxx"_S.TrimStart('x'), _current_information);
      TUnit::Assert::AreEqual(" x", "xx x"_S.TrimStart('x'), _current_information);
      TUnit::Assert::AreEqual("string To Trim Start", "          string To Trim Start"_S.TrimStart(' '), _current_information);
      TUnit::Assert::AreEqual("          string To Trim Start", "          string To Trim Start"_S.TrimStart('d'), _current_information);
    }
    
    void TrimSartMultiple() {
      Array<char32> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
      
      TUnit::Assert::AreEqual("abcdef1357924680", "2468013579abcdef1357924680"_S.TrimStart(numbers), _current_information);
      TUnit::Assert::AreEqual("", ""_S.TrimStart(numbers), _current_information);
      TUnit::Assert::AreEqual("", "24680135791357924680"_S.TrimStart(numbers), _current_information);
    }

  };

  _test(StringTest, StringCreatedWithDefaultConstructor)
  _test(StringTest, StringCreatedWithConstCharPointerConstructor)
  _test(StringTest, StringCreatedWithConstChar16PointerConstructor)
  _test(StringTest, StringCreatedWithConstChar32PointerConstructor)
  _test(StringTest, StringCreatedWithConstWCharPointerConstructor)
  _test(StringTest, StringCreatedWithConstRawCharPointerConstructor)
  _test(StringTest, StringCreatedWithConstRawChar16PointerConstructor)
  _test(StringTest, StringCreatedWithConstRawChar32PointerConstructor)
  _test(StringTest, StringCreatedWithConstRawWCharPointerConstructor)
  _test(StringTest, StringCreatedWithCopyConstructor)
  _test(StringTest, StringCreatedWithConstCharPointerNull)
  _test(StringTest, StringCreatedWithConstChar16PointerNull)
  _test(StringTest, StringCreatedWithConstChar32PointerNull)
  _test(StringTest, StringCreatedWithConstWCharPointerNull)
  _test(StringTest, StringCreatedWithConstCharPointerAndNegativeStartIndexConstructor)
  _test(StringTest, StringCreatedWithConstCharPointerAndNegativeCountConstructor)
  _test(StringTest, StringCreatedWithConstCharPointerAndStartIndexGreaterThenLengthConstructor)
  _test(StringTest, StringCreatedWithConstCharPointerAndCountGraterThenLengthConstructor)
  _test(StringTest, StringCreatedWithConstCharPointerAndStartIndexAndCountEqualsZeroConstructor)
  _test(StringTest, StringCreatedWithConstCharPointerAndStartIndexEqualsZeroAndCountEqualLengthConstructor)
  _test(StringTest, StringCreatedWithConstCharPointerAndStartIndexAndCountInsideLengthConstructor)
  _test(StringTest, StringCreatedWithConstCharPointerAndCountInsideLengthConstructor)
  _test(StringTest, StringCreatedWithConstCharPointerAndCountEqualsLengthConstructor)
  _test(StringTest, StringCreatedWithConstCharPointerAndCountGreaterLengthConstructor)
  _test(StringTest, StringCreatedWithConstCharPointerEmptyAndCountGreaterLengthConstructor)
  _test(StringTest, StringCreatedByAssignment)
  _test(StringTest, StringCreatedByAssignmentWithBackslash)
  _test(StringTest, StringCreatedByAssignmentWithVerbatimBackslash)
  _test(StringTest, StringCreatedByConstructorWithChars)
  _test(StringTest, StringCreatedByConstructorWith32bitsChars)
  _test(StringTest, CreateAStringThatConsistsOfACharacterRepeated20Times)
  _test(StringTest, StringCreatedByConstructorWithPointerOnSBytes)
  _test(StringTest, StringCreatedByAssignmentWithUnicodeStringLiteral)
  _test(StringTest, SubscriptOperatorWithChar)
  _test(StringTest, SubscriptOperatorWithChar32)
  _test(StringTest, OperatorLitteralChar)
  _test(StringTest, OperatorLitteralChar16)
  _test(StringTest, OperatorLitteralChar32)
  _test(StringTest, OperatorLitteralWChar)
  _test(StringTest, OperatorAddConstCharPointer)
  _test(StringTest, OperatorAddBoolean)
  _test(StringTest, OperatorAddByte)
  _test(StringTest, OperatorAddByteObject)
  _test(StringTest, OperatorAddChar)
  _test(StringTest, OperatorAddChar16)
  _test(StringTest, OperatorAddChar32)
  _test(StringTest, OperatorAddWChar)
  _test(StringTest, OperatorAddCharObject)
  _test(StringTest, OperatorAddDouble)
  _test(StringTest, OperatorAddDoubleObject)
  _test(StringTest, OperatorAddInt16)
  _test(StringTest, OperatorAddInt16Object)
  _test(StringTest, OperatorAddInt32)
  _test(StringTest, OperatorAddInt32Object)
  _test(StringTest, OperatorAddInt64)
  _test(StringTest, OperatorAddInt64Object)
  _test(StringTest, OperatorAddSByte)
  _test(StringTest, OperatorAddSByteObject)
  _test(StringTest, OperatorAddSingle)
  _test(StringTest, OperatorAddSingleObject)
  _test(StringTest, OperatorAddDateTimeObject)
  _test(StringTest, CompareEmptyStrings)
  _test(StringTest, CompareEmptyStringWithStringEmpty)
  _test(StringTest, CompareEmptyStringWithAnyString)
  _test(StringTest, CompareAnyStringWithEmptyString)
  _test(StringTest, CompareSameStrings)
  _test(StringTest, CompareGreaterString)
  _test(StringTest, CompareLessString)
  _test(StringTest, CompareIndex)
  _test(StringTest, CompareEmptyStringsWithIgnoreCaseTrue)
  _test(StringTest, CompareEmptyStringWithStringEmptyWithIgnoreCaseTrue)
  _test(StringTest, CompareEmptyStringWithAnyStringWithIgnoreCaseTrue)
  _test(StringTest, CompareAnyStringWithEmptyStringWithIgnoreCaseTrue)
  _test(StringTest, CompareSameStringsWithIgnoreCaseTrue)
  _test(StringTest, CompareGreaterStringWithIgnoreCaseTrue)
  _test(StringTest, CompareLessStringWithIgnoreCaseTrue)
  _test(StringTest, CompareGreaterDifferentCaseStringWithIgnoreCaseTrue)
  _test(StringTest, CompareLessDifferentCaseStringWithIgnoreCaseTrue)
  _test(StringTest, CompareEmptyStringsWithIgnoreCaseFalse)
  _test(StringTest, CompareEmptyStringWithStringEmptyWithIgnoreCaseFalse)
  _test(StringTest, CompareEmptyStringWithAnyStringWithIgnoreCaseFalse)
  _test(StringTest, CompareAnyStringWithEmptyStringWithIgnoreCaseFalse)
  _test(StringTest, CompareSameStringsWithIgnoreCaseFalse)
  _test(StringTest, CompareGreaterStringWithIgnoreCaseFalse)
  _test(StringTest, CompareLessStringWithIgnoreCaseFalse)
  _test(StringTest, CompareGreaterDifferentCaseStringWithIgnoreCaseFalse)
  _test(StringTest, CompareLessDifferentCaseStringWithIgnoreCaseFalse)
  _test(StringTest, CompareIndexIgnoreCase)
  _test(StringTest, Concat)
  _test(StringTest, ConcatArray)
  _test(StringTest, EndsWith)
  _test(StringTest, EndsWithChar32)
  _test(StringTest, StartsWith)
  _test(StringTest, StartsWithChar32)
  _test(StringTest, GetEnumeratorOnString)
  _test(StringTest, ForeachOnString)
  _test(StringTest, IteratorOnString)
  _test(StringTest, ForOnString)
  _test(StringTest, GetHashCode)
  _test(StringTest, IsNullOrEmptyOnEmptyString)
  _test(StringTest, IsNullOrEmptyOnNonEmptyString)
  _test(StringTest, IsNullOrEmptyOnStringEmpty)
  _test(StringTest, IndexOf)
  _test(StringTest, IndexOfExceptions)
  _test(StringTest, IndexOfAny)
  _test(StringTest, IndexOfAnyExceptions)
  _test(StringTest, Join)
  _test(StringTest, JoinN)
  _test(StringTest, JoinNExceptions)
  _test(StringTest, LastIndexOf)
  _test(StringTest, LastIndexOfExceptions)
  _test(StringTest, LastIndexOfAny)
  _test(StringTest, LastIndexOfAnyException)
  _test(StringTest, PadLeft)
  _test(StringTest, PadRight)
  _test(StringTest, Remove)
  _test(StringTest, RemoveExceptions)
  _test(StringTest, Insert)
  _test(StringTest, InsertExceptions)
  _test(StringTest, Replace)
  _test(StringTest, Split)
  _test(StringTest, SplitCount)
  _test(StringTest, SplitWithStringSplitOptionRemoveEmptyEntries)
  _test(StringTest, SplitWithStringSplitOptioNone)
  _test(StringTest, ToUpper)
  _test(StringTest, ToLower)
  _test(StringTest, TrimStart)
}
