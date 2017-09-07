/// @file
/// @brief Contains Switch::System::Diagnostics::TraceEventCache class.
#pragma once

#include "../../Types.hpp"
#include "../DateTime.hpp"
#include "../Environment.hpp"
#include "../Collections/Stack.hpp"
#include "../Threading/Thread.hpp"
#include "Stopwatch.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Provides trace event data specific to a thread and a process.
      class _public TraceEventCache : public Object {
      public:
        /// @brief Initializes a new instance of the TraceEventCache class.
        TraceEventCache() {}
        
        /// @cond
        TraceEventCache(const TraceEventCache& tec) : dateTime(tec.dateTime) {}
        TraceEventCache& operator=(const TraceEventCache& tec) {this->dateTime = tec.dateTime; return *this;}
        /// @endcond

        /// @brief Gets the call stack for the current thread.
        /// @return string A string containing stack trace information. This value can be an empty string ("").
        /// @remarks The Callstack property gets the call stack from the StackTrace property of the Environment class. The property value lists method calls in reverse chronological order. That is, the most recent method call is described first. One line of stack trace information is listed for each method call on the stack. For more information, see StackTrace.
        property<String, readonly> CallStack {
          _get {return Environment::StackTrace();}
        };
        
        /// @brief Gets the date and time at which the event trace occurred.
        /// @return DateTime A DateTime structure whose value is a date and time expressed in Coordinated Universal Time (UTC).
        /// @remarks The first time the property is accessed in an instance of the TraceEventCache class, the current time is returned. Subsequent queries of this property in that instance return that same DateTime value, allowing it to be used as a timestamp.
        property<System::DateTime, readonly> DateTime {
          _get {
            if (this->dateTime == DateTime::MinValue)
              this->dateTime = System::DateTime::Now;
            return this->dateTime;
          }
        };
        
        /// @brief Gets the correlation data, contained in a stack.
        /// @return System::Collections::Stack A Stack containing correlation data.
        /// @remarks The correlation data is stored as an object in the call context with the name "System.Diagnostics.Trace.CorrelationManagerSlot". The CorrelationManager class provides methods used to store a logical operation identity in a thread-bound context and automatically tag each trace event generated by the thread with the stored identity. The CorrelationManager is accessed through the Trace.CorrelationManager property. Each call to the StartLogicalOperation method pushes a new logical operation identity onto the stack. Each call to the StopLogicalOperation method pops a logical operation identity from the stack
        property<System::Collections::Stack, readonly> LogicalOperationStack {
          _get {return System::Collections::Stack();}
        };
        
        /// @brief Gets the unique identifier of the current process.
        /// @return int32 The system-generated unique identifier of the current process.
        /// @remarks Until the process terminates, the process identifier uniquely identifies the process throughout the system.
        property<int32, readonly> ProcessdId {
          _get {return -1;}
        };
        
        /// @brief Gets a unique identifier for the current managed thread.
        /// @return string A string that represents a unique integer identifier for this managed thread.
        /// @remarks The thread identifier is the value of the Thread.ManagedThreadId property formatted as a string.
        property<string, readonly> ThreadId {
          _get {return string::Format("{0}", System::Threading::Thread::CurrentThread().ManagedThreadId);}
        };
        
        /// @brief Gets the current number of ticks in the timer mechanism.
        /// @return int64 The tick counter value of the underlying timer mechanism.
        /// @remarks The get accessor calls the Stopwatch.GetTimestamp method to get the timestamp. If the Stopwatch class uses a high-resolution performance counter, GetTimestamp returns the current value of that counter. If the Stopwatch class uses the system timer, GetTimestamp returns the Ticks property of DateTime.Now.
        property<int64, readonly> Timestamp {
          _get {return Stopwatch::GetTimestamp();}
        };
        
      private:
        System::DateTime dateTime;
      };
    }
  }
}

using namespace Switch;