/// @file
/// @brief Contains Switch::System::NullReferenceException exception.
#pragma once

#include "SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when there is an attempt to dereference a null object reference.
    class export_ NullReferenceException : public SystemException {
    public:
      /// @brief Create a new instance of class NullReferenceException
      /// @remarks Message is set with the default message associate to the error.
      NullReferenceException() : SystemException() {}

      /// @brief Create a new instance of class NullReferenceException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      NullReferenceException(const NullReferenceException& value) : SystemException(value) {}

      /// @brief Create a new instance of class NullReferenceException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      explicit NullReferenceException(const System::Runtime::CompilerServices::Caller& information) : SystemException(information) {}

      /// @brief Create a new instance of class NullReferenceException
      /// @param message Message string associate to the error.
      explicit NullReferenceException(const System::String& message) : SystemException(message) {}

      /// @brief Create a new instance of class NullReferenceException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      NullReferenceException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, information) {}

      /// @brief Create a new instance of class NullReferenceException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      NullReferenceException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "Object reference not set to an instance of an object."; }
    };
  }
}

using namespace Switch;

