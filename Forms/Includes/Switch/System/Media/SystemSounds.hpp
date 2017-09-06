/// @file
/// @brief Contains Switch::System::Media::SystemSounds class.
#pragma once

#include "SystemSound.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Media namespace contains classes for playing sound files and accessing sounds provided by the system.
    namespace Media {
      class SystemSounds {
      public:
        static property<SystemSound, readonly> Asterisk;

        static property<SystemSound, readonly> Beep;

        static property<SystemSound, readonly> Exclamation;

        static property<SystemSound, readonly> Hand;

        static property<SystemSound, readonly> Question;
      };
    }
  }
}
