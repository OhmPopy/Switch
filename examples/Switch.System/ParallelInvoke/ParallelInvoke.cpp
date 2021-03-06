#include <Switch/Switch>

using namespace System;
using namespace System::Threading;
using namespace System::Threading::Tasks;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      try {
        Parallel::Invoke(
          BasicAction,  // Param #0 - static method
        delegate_ {     // Param #1 - lambda expression
          lock_(lck)
          Console::WriteLine("Method=beta, Thread={0}", Thread::CurrentThread().ManagedThreadId);
        },
        delegate<void> {delegate_ {    // Param #2 - in-line delegate
            lock_(lck)
            Console::WriteLine("Method=gamma, Thread={0}", Thread::CurrentThread().ManagedThreadId);
          }
        }
        );
      }
      // No exception is expected in this example, but if one is still thrown from a task,
      // it will be wrapped in AggregateException and propagated to the main thread.
      catch (const AggregateException& e) {
        Console::WriteLine("An action has thrown an exception. THIS WAS UNEXPECTED.\n{0}", e.InnerException().ToString());
      }
    }

    static void BasicAction() {
      lock_(lck)
      Console::WriteLine("Method=alpha, Thread={0}", Thread::CurrentThread().ManagedThreadId);
    }

    static object lck;
  };

  object Program::lck;
}

startup_(Examples::Program);

// This code produces the following output:
//
