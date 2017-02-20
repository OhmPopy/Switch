/// @file
/// @brief Contains Pcf::System::Int32 struct.
#pragma once

#include "../Property.h"
#include "../Types.h"
#include "IComparable.h"
#include "IConvertible.h"
#include "IFormattable.h"
#include "Object.h"
#include "_String.h"
#include "ValueType.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents a 32-bit signed integer.
    struct pcf_public Int32 final : public ValueType, public IComparable, public IConvertible, public IFormattable {
    public:
      /// @brief Represents the largest possible value of an Int32 2147483647 (0x7FFFFFFF). This field is constant.
      static Property<int32, ReadOnly> MaxValue;

      /// @brief Represents the smallest possible value of Int32 -2147483648 (0x80000000). This field is constant.
      static Property<int32, ReadOnly> MinValue;

      /// @brief Create a new instance of struct Int32
      /// @remarks Int32 is initialized by default to 0.
      Int32() {}

      /// @brief Create a new instance of struct Int32
      /// @param value Value for the Int32.
      Int32(int32 value) : value(value) {}
      
      /// @brief Determines whether two specified DateTime objects have the same value.
      /// @param dateTimeA The first DateTime to compare.
      /// @param dateTimeB The second DateTime to compare.
      /// @return Boolean true if the value of dateTimenA is the same as the value of dateTimeB; otherwise, false.
      bool Equals(int32 value) const {return this->value == value;}
      
      /// @brief Determines whether this instance of Exception and a specified object, which must also be a Exception object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const object& obj) const override {return is<Int32>(obj) && Equals(((const Int32&)obj).value);}

      /// @brief Converts the specified String representation of a logical value to its 32-bit signed integer equivalent.
      /// @param str A String containing the value to convert.
      /// @return* A 32-bit signed integer equivalent to the number contained in value.
      /// @exception ArgumentNullException The parameters value is null.
      static int32 Parse(const String& str);

      /// @brief Converts the specified String representation of a logical value to its 32-bit signed integer equivalent.
      /// @param str A String containing the value to convert.
      /// @param base The base of number to parse
      /// @return A 32-bit signed integer equivalent to the number contained in value.
      /// @exception ArgumentNullException The parameters value is null.
      static int32 Parse(const String& str, int32 base);

      /// @brief Converts the specified String representation of a logical value to its 32-bit signed integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param value When this method returns, contains the 32-bit signed integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A bool true if value was converted successfully; otherwise, false.
      static bool TryParse(const String& str, Int32& value);

      /// @brief Converts the specified String representation of a logical value to its 32-bit signed integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param value When this method returns, contains the 32-bit signed integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A bool true if value was converted successfully; otherwise, false.
      static bool TryParse(const String& str, int32& value);

      /// @brief Converts the specified String representation of a logical value to its 32-bit signed integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param base The base of number to parse
      /// @param value When this method returns, contains the 32-bit signed integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A bool true if value was converted successfully; otherwise, false.
      static bool TryParse(const String& str, int32 base, int32& value);

      /// @brief Converts the specified String representation of a logical value to its 32-bit signed integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param base The base of number to parse
      /// @param value When this method returns, contains the 32-bit signed integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A bool true if value was converted successfully; otherwise, false.
      static bool TryParse(const String& str, int32 base, Int32& value);

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current object.
      int32 GetHashCode() const noexcept override;

      /// @brief Returns a String that represents the current Int32.
      /// @return String A String that represents the current Int32.
      String ToString() const override;

      /// @brief Returns a String that represents the current Int32.
      /// @param format Format-control String.
      /// @param formatProvider an IFormatProvider for specifie the format.
      /// @return String A String that represents the current Int32.
      String ToString(const String& format, const IFormatProvider& formatProvider) const override;

      /// @brief Returns a String that represents the current Int32.
      /// @param format Format-control String.
      /// @return String A String that represents the current Int32.
      String ToString(const String& format) const;

      /// @brief Compares this instance to a specified Int32 object and returns an indication of their relative values.
      /// @param value An Int32 object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// @return Less than zero      This instance is less than value.
      /// @return Zero                This instance is equal to value.
      /// @return Greater than zero   This instance is greater than value.
      int32 CompareTo(const Int32& value) const;

      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// @return Less than zero      This instance is less than value.
      /// @return Zero                This instance is equal to value.
      /// @return Greater than zero   This instance is greater than value.
      /// -or-
      /// @return obj is nullNothingnullptra null reference.
      int32 CompareTo(const IComparable& obj) const override;

      /// @brief Returns the TypeCode for this instance.
      /// @return TypeCode The enumerated constant that is the TypeCode of the class or value type that implements this interface.
      TypeCode GetTypeCode() const override;

    private:
      friend class Convert;
 
      bool ToBoolean(const IFormatProvider& provider) const override;
      byte ToByte(const IFormatProvider& provider) const override;
      char32 ToChar(const IFormatProvider& provider) const override;
      DateTime ToDateTime(const IFormatProvider& provider) const override;
      double ToDouble(const IFormatProvider& provider) const override;
      int16 ToInt16(const IFormatProvider& provider) const override;
      int32 ToInt32(const IFormatProvider& provider) const override;
      int64 ToInt64(const IFormatProvider& provider) const override;
      uint16 ToUInt16(const IFormatProvider& provider) const override;
      uint32 ToUInt32(const IFormatProvider& provider) const override;
      uint64 ToUInt64(const IFormatProvider& provider) const override;
      sbyte ToSByte(const IFormatProvider& provider) const override;
      float ToSingle(const IFormatProvider& provider) const override;
      String ToString(const IFormatProvider& provider) const override;

      int32 value = 0;

    public:
      /// @cond
      Int32(const Int32& value) : value(value.value) {}
      operator int32() const;
      Int32& operator =(const Int32& value);
      Int32& operator +=(const Int32& value);
      Int32& operator -=(const Int32& value);
      Int32& operator *=(const Int32& value);
      Int32& operator /=(const Int32& value);
      Int32& operator %=(const Int32& value);
      Int32& operator &=(const Int32& value);
      Int32& operator |=(const Int32& value);
      Int32& operator ^=(const Int32& value);
      Int32& operator <<=(const Int32& value);
      Int32& operator >>=(const Int32& value);
      Int32& operator ++();
      const Int32 operator ++(int);
      Int32& operator --();
      const Int32 operator --(int);
      template<typename T> bool operator==(T value) const {return this->value == value;}
      template<typename T> bool operator!=(T value) const {return !this->operator==(value);}
      /// @endcond
    };
  }
}

using namespace Pcf;

