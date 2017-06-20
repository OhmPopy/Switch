/// @file
/// @brief Contains Pcf::System::DateTimeKind enum.
#pragma once

#include "../Types.hpp"
#include "Enum.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @enum DateTimeKind
    /// @brief Specifies whether a DateTime object represents a local time, a Coordinated Universal Time (UTC), or is not specified as either local time or UTC.
    /// @see DateTime
    enum class DateTimeKind {
      /// @brief The time represented is not specified as either local time or Coordinated.
      /// Universal Time (UTC).
      Unspecified,
      /// @brief The time represented is UTC.
      Utc,
      /// @brief The time represented is local time.
      Local
    };
  }
}

/// @cond
template<>
class EnumToStrings<System::DateTimeKind> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::DateTimeKind::Unspecified, "Unspecified"}, {(int64)System::DateTimeKind::Utc, "Utc"}, {(int64)System::DateTimeKind::Local, "Local"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;