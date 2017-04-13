/// @file
/// @brief Contains Pcf::System::Version class.
#pragma once

#include "../Property.h"
#include "../Types.h"
#include "ArgumentException.h"
#include "ArgumentOutOfRangeException.h"
#include "ICloneable.h"
#include "IComparable.h"
#include "Runtime/Serialization/ISerializable.h"
#include "Runtime/Serialization/SerializationInfo.h"
#include "Object.h"
#include "String.h"

#undef major
#undef minor

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Provides methods for creating, manipulating, searching, and sorting arrays, thereby serving as the base class for all arrays.
    class pcf_public Version final : public Object, public ICloneable, public IComparable, public Runtime::Serialization::ISerializable {
    public:
      /// @brief Initializes a new instance of the Version class.
      /// @remarks Version is initialized with default values :
      /// - Major = 0,
      /// - Minor = 0,
      Version() {}

      /// @brief Initializes a new instance of the Version class using the specified major and minor values.
      /// @param major The major version number.
      /// @param minor The minor version number.
      /// @exception ArgumentOutOfRangeException major or minor is less than zero.
      Version(int32 major, int32 minor) : major(major), minor(minor) {
        if (major < 0 || minor < 0)
          throw ArgumentOutOfRangeException(pcf_current_information);
      }
      
      /// @brief Initializes a new instance of the Version class using the specified major, minor and build values.
      /// @param major The major version number.
      /// @param minor The minor version number.
      /// @param build The build version number.
      /// @exception ArgumentOutOfRangeException major, minor or build is less than zero.
      Version(int32 major, int32 minor, int32 build) : major(major), minor(minor), build(build) {
        if (major < 0 || minor < 0 || build < 0)
          throw ArgumentOutOfRangeException(pcf_current_information);
      }
      
      /// @brief Initializes a new instance of the Version class using the specified major, minor, build and revision values.
      /// @param major The major version number.
      /// @param minor The minor version number.
      /// @param build The build version number.
      /// @param revision The revision version number.
      /// @exception ArgumentOutOfRangeException major, minor, build or revision is less than zero.
      Version(int32 major, int32 minor, int32 build, int32 revision) : major(major), minor(minor), build(build), revision(revision) {
        if (major < 0 || minor < 0 || build < 0 || revision < 0)
          throw ArgumentOutOfRangeException(pcf_current_information);
      }
      
      /// @cond
      Version(const Version& version) : major(version.major), minor(version.minor), build(version.build), revision(version.revision) {}
      Version& operator =(const Version& version) {
        this->major = version.major;
        this->minor = version.minor;
        this->build = version.build;
        this->revision = version.revision;
        return *this;
      }
      /// @endcond

      /// @brief Gets the value of the build component of the version number for the current Version object.
      /// @return int32 The build number, or -1 if the build number is undefined.
      Property<int32, ReadOnly> Build {
        pcf_get {return this->build;}
      };

      /// @brief Gets the value of the major component of the version number for the current Version object.
      /// @return int32 The major version number.
      Property<int32, ReadOnly> Major {
        pcf_get {return this->major;}
      };

      /// @brief Gets the high 16 bits of the revision number.
      /// @return int16 A 16-bit signed integer represented the high 16 bits of the revision number, or -1 if the revision number is undefined.
      /// @remarks Suppose you release an interim version of your application to temporarily correct a problem until you can release a permanent solution.
      /// @remarks The temporary version does not warrant a new revision number, but it does need to be identified as a different version.
      /// @remarks In this case, encode the identification information in the high and low 16-bit portions of the 32-bit revision number.
      /// @remarks Use the Revision property to obtain the entire revision number, use the MajorRevision property to obtain the high 16 bits, and use the MinorRevision property to obtain the low 16 bits.
      Property<int16, ReadOnly> MajorRevision {
        pcf_get {return (int16)((this->revision & 0xFFFF0000) >> 16);}
      };

      /// @brief Gets the value of the minor component of the version number for the current Version object.
      /// @return int32 The minor version number.
      Property<int32, ReadOnly> Minor {
        pcf_get {return this->minor;}
      };

      /// @brief Gets the low 16 bits of the revision number.
      /// @return int16 A 16-bit signed integer represented the low 16 bits of the revision number, or -1 if the revision number is undefined.
      /// @remarks Suppose you release an interim version of your application to temporarily correct a problem until you can release a permanent solution.
      /// @remarks The temporary version does not warrant a new revision number, but it does need to be identified as a different version.
      /// @remarks In this case, encode the identification information in the high and low 16-bit portions of the 32-bit revision number.
      /// @remarks Use the Revision property to obtain the entire revision number, use the MajorRevision property to obtain the high 16 bits, and use the MinorRevision property to obtain the low 16 bits.
      Property<int16, ReadOnly> MinorRevision {
        pcf_get {return (int16)(this->revision & 0x0000FFFF);}
      };

      /// @brief Gets the value of the revision component of the version number for the current Version object.
      /// @return int32 The revision number, or -1 if the revision number is undefined.
      Property<int32, ReadOnly> Revision {
        pcf_get {return this->revision;}
      };

      /// @brief Returns a new Version object whose value is the same as the current Version object.
      /// @return object* A new object whose values are a copy of the current Version object.
      refptr<object> Clone() const override {return pcf_new<Version>(*this);}

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than obj.
      /// Zero                This instance is equal to obj.
      /// Greater than zero   This instance is greater than obj.
      int32 CompareTo(const IComparable& obj) const override {
        if (!is<Version>(obj))
          return 1;
        return CompareTo((const Version &)obj);
      }
      
      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param value An Version to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      int32 CompareTo(const Version& value) const {
        if (this->major < value.major) return -1;
        if (this->major > value.major) return 1;
        if (this->minor < value.minor) return -1;
        if (this->minor > value.minor) return 1;
        if (this->build < value.build) return -1;
        if (this->build > value.build) return 1;
        if (this->revision < value.revision) return -1;
        if (this->revision > value.revision) return 1;
        return 0;
      }
      
      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param value The Version to compare with the current object.
      /// @return bool true if the specified value is equal to the current object. otherwise, false.
      bool Equals(const Version& value) const {return CompareTo(value) == 0;}

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const object& obj) const override {
        if (!is<Version>(obj))
          return false;
        return Equals((const Version&)obj);
      }
      
      /// @brief Serves as a hash function for a particular type.
      /// @return int32 A hash code for the current object.
      int32 GetHashCode() const override {
        int32 hash = this->major ^ this->minor;
        if (this->build != -1)
          hash ^= this->build;
        if (this->revision != -1)
          hash ^= this->revision;
        return hash;
      }
      
      /// @brief Parse a version string and fill the object
      /// @param version The string version
      /// @return Version a Version object
      static Version Parse(const String& version) {
        Array<String> versions = version.Split('.', StringSplitOptions(StringSplitOptions::RemoveEmptyEntries));
        switch (versions.Length()) {
          case 2: return Version(Convert::ToInt32(versions[0]), Convert::ToInt32(versions[1]));
          case 3: return Version(Convert::ToInt32(versions[0]), Convert::ToInt32(versions[1]), Convert::ToInt32(versions[2]));;
          case 4: return Version(Convert::ToInt32(versions[0]), Convert::ToInt32(versions[1]), Convert::ToInt32(versions[2]), Convert::ToInt32(versions[3]));
        }
        throw ArgumentException(pcf_current_information);
      }
      
      static bool TryParse(const String& version, Version& result) {
        try {
          result = Parse(version);
          return true;
        } catch(...) {
          return false;
        }
      }
      
      
      /// @brief Returns a string that represents the current object.
      /// @return string A string that represents the current object.
      String ToString() const override {return ToString(2 + (this->build != -1 ? 1 : 0) + (this->revision != -1 ? 1 : 0));}
      
      String ToString(int32 fieldCount) const {
        if (fieldCount < 0 || fieldCount> 4 || (fieldCount >= 3 && this->build == -1) || (fieldCount == 4 && this->revision == -1))
          throw ArgumentOutOfRangeException(pcf_current_information);
        string result;
        if (fieldCount >= 1)
          result += string::Format("{0}", this->major);
        if (fieldCount >= 2)
          result += string::Format(".{0}", this->minor);
        if (fieldCount >= 3)
          result += string::Format(".{0}", this->build);
        if (fieldCount == 4)
          result += string::Format(".{0}", this->revision);
        return result;
      }

      /// @brief Populates a SerializationInfo with the data needed to serialize the target object.
      /// @param info The SerializationInfo to populate with data.
      /// @remarks Any objects that are included in the SerializationInfo are automatically tracked and serialized by the formatter.
      /// @remarks Code that calls GetObjectData requires the SecurityPermission for providing serialization services. Associated enumeration: SecurityPermissionFlag.SerializationFormatter.
      /// @note It is not guaranteed that this method will be called only once per object instance during serialization. Therefore, the method should be implemented in such a way that its behavior will be the same regardless of the number of times it is called.
      void GetObjectData(System::Runtime::Serialization::SerializationInfo& info) const override {
        info.AddValue("Major", this->major);
        info.AddValue("Minor", this->minor);
        info.AddValue("Build", this->build);
        info.AddValue("Revision", this->revision);
      }
      
    private :
      int32 major = 0;
      int32 minor = 0;
      int32 build = -1;
      int32 revision = -1;
    };
  }
}

using namespace Pcf;
