/// @file
/// @brief Contains Switch::System::IO::FileAttributes enum.
#pragma once

#include "../Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @enum FileAtributes
      /// @brief Provides attributes for files and directories.
      /// @see FileStream
      enum class FileAttributes {
        /// @brief The file is read-only.
        ReadOnly = 0x0001,
        /// @brief The file is hidden, and thus is not included in an ordinary directory listing.
        Hidden = 0x0002,
        /// @brief The file is a system file. The file is part of the operating system or is used exclusively by the operating system.
        System = 0x0004,
        /// @brief The file is a directory.
        Directory = 0x0010,
        /// @brief The file's archive status. Applications use this attribute to mark files for backup or removal.
        Archive = 0x0020,
        /// @brief Reserved for future use.
        Device = 0x0040,
        /// @brief The file is normal and has no other attributes set. This attribute is valid only if used alone.
        Normal = 0x0080,
        /// @brief The file is temporary. File systems attempt to keep all of the data in memory for quicker access rather than flushing the data back to mass storage. A temporary file should be deleted by the application as soon as it is no longer needed.
        Temporary = 0x0100,
        /// @brief The file is a sparse file. Sparse files are typically large files whose data are mostly zeros.
        SparseFile = 0x0200,
        /// @brief The file contains a reparse point, which is a block of user-defined data associated with a file or a directory.
        ReparsePoint = 0x0400,
        /// @brief The file is compressed.
        Compressed = 0x0800,
        /// @brief The file is offline. The data of the file is not immediately available.
        Offline = 0x1000,
        /// @brief The file will not be indexed by the operating system's content indexing service.
        NotContentIndexed = 0x2000,
        /// @brief The file or directory is encrypted. For a file, this means that all data in the file is encrypted. For a directory, this means that encryption is the default for newly created files and directories.
        Encrypted = 0x4000
      };
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::IO::FileAttributes> : public TrueType {};

template<>
class EnumToStrings<System::IO::FileAttributes> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::IO::FileAttributes::ReadOnly, "ReadOnly"}, {(int64)System::IO::FileAttributes::Hidden, "Hidden"}, {(int64)System::IO::FileAttributes::System, "System"}, {(int64)System::IO::FileAttributes::Directory, "Directory"}, {(int64)System::IO::FileAttributes::Archive, "Archive"}, {(int64)System::IO::FileAttributes::Device, "Device"}, {(int64)System::IO::FileAttributes::Normal, "Normal"}, {(int64)System::IO::FileAttributes::Temporary, "Temporary"}, {(int64)System::IO::FileAttributes::SparseFile, "SparseFile"}, {(int64)System::IO::FileAttributes::ReparsePoint, "ReparsePoint"}, {(int64)System::IO::FileAttributes::Compressed, "Compressed"}, {(int64)System::IO::FileAttributes::Offline, "Offline"}, {(int64)System::IO::FileAttributes::NotContentIndexed, "NotContentIndexed"}, {(int64)System::IO::FileAttributes::Encrypted, "Encrypted"}};
    flags = true;
  }
};
/// @endcond

using namespace Switch;
