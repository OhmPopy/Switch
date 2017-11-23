/// @file
/// @brief Contains Switch::System::UriFormat enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Controls how URI information is escaped.
    /// @par Library
    /// Switch.System
    enum class UriFormat {
      /// @brief Characters that have a reserved meaning in the requested URI components remain escaped. All others are not escaped. See Remarks.
      SafeUnescaped = 0,
      /// @brief No escaping is performed.
      Unescaped = 1,
      /// @brief Escaping is performed according to the rules in RFC 2396.
      UriEscaped = 2,
    };
  }
}

/// @cond
template<>
class EnumToStrings<System::UriFormat> {
public:
  void operator()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::UriFormat::SafeUnescaped, "SafeUnescaped"}, {(int64)System::UriFormat::Unescaped, "Unescaped"}, {(int64)System::UriFormat::UriEscaped, "UriEscaped"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
