/// @file
/// @brief Contains Pcf::System::IO::DriveType enum.
#pragma once

#include "../Enum.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Defines constants for drive types, including CDRom, Fixed, Network, NoRootDirectory, Ram, Removable, and Unknown.
      /// @see DriveInfo
      enum class DriveType {
        /// @brief The type of drive is unknown.
        Unknown,
        /// @brief The drive does not have a root directory.
        NoRootDirectory,
        /// @brief The drive is a removable storage device, such as a floppy disk drive or a USB flash drive.
        Removable,
        /// @brief The drive is a fixed disk.
        Fixed,
        /// @brief The drive is a network drive.
        Network,
        /// @brief The drive is an optical disc device, such as a CD or DVD-ROM.
        CDRom,
        /// @brief The drive is a RAM disk.
        Ram
      };
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::IO::DriveType> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::IO::DriveType::Unknown, "Unknown"}, {(int64)System::IO::DriveType::NoRootDirectory, "NoRootDirectory"}, {(int64)System::IO::DriveType::Removable, "Removable"}, {(int64)System::IO::DriveType::Fixed, "Fixed"}, {(int64)System::IO::DriveType::Network, "Network"}, {(int64)System::IO::DriveType::CDRom, "CDRom"}, {(int64)System::IO::DriveType::Ram, "Ram"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;