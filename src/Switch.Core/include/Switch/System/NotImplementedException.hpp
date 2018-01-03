/// @file
/// @brief Contains Switch::System::NotImplementedException exception.
#pragma once

#include "SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when a requested method or operation is not implemented.
    class export_ NotImplementedException : public SystemException {
    public:
      /// @brief Create a new instance of class NotImplementedException
      /// @remarks Message is set with the default message associate to the error.
      NotImplementedException() : SystemException() {}

      /// @brief Create a new instance of class NotImplementedException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      NotImplementedException(const NotImplementedException& value) : SystemException(value) {}

      /// @brief Create a new instance of class NotImplementedException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      NotImplementedException(const System::Runtime::CompilerServices::Caller& information) : SystemException(information) {}

      /// @brief Create a new instance of class NotImplementedException
      /// @param message Message string associate to the error.
      NotImplementedException(const System::String& message) : SystemException(message) {}

      /// @brief Create a new instance of class NotImplementedException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      NotImplementedException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, information) {}

      /// @brief Create a new instance of class NotImplementedException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      NotImplementedException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "The method or operation is not implemented."; }
    };
  }
}

using namespace Switch;

