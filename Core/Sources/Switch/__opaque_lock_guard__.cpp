#include "../../Includes/Switch/Lock.hpp"
#include "../../Includes/Switch/System/Threading/Monitor.hpp"

__opaque_lock_guard__::__opaque_lock_guard__(const object& lock) : lock(lock) {
  System::Threading::Monitor::Enter(this->lock);
}

__opaque_lock_guard__::~__opaque_lock_guard__() {
  System::Threading::Monitor::Exit(this->lock);
}