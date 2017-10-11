#include <cstdlib>
#include <cstddef>
#include <cstring>

#include "../../../include/Switch/System/Array.hpp"
#include "../../../include/Switch/System/Type.hpp"
#include "../../../include/Switch/System/Collections/Specialized/StringDictionary.hpp"
#include "../../Native/Api.hpp"

using namespace System;

Type::Type(const Type& type) : FullName(_delegate {return this->GetFullName();}),  Name(_delegate {return this->GetName();}), Namespace(_delegate {return this->GetNamespace();}), type(type.type) {
}

Type::Type() : FullName(_delegate {return this->GetFullName();}),  Name(_delegate {return this->GetName();}), Namespace(_delegate {return this->GetNamespace();}), type(typeid(*this)) {
}

Type::Type(const ::type& type) : FullName(_delegate {return this->GetFullName();}),  Name(_delegate {return this->GetName();}), Namespace(_delegate {return this->GetNamespace();}), type(type) {
}

Type& Type::operator=(const Type& type) {
  memcpy((void*)&this->type, (void*)&type.type, sizeof(type.type));
  return *this;
}

bool Type::Equals(const Object& obj) const {
  return is<Type>(obj) && Equals(static_cast<const Type&>(obj));
}

bool Type::Equals(const Type& type) const {
  return this->type == type.type;
}

String Type::GetFullName() const {
  String fullName = Native::TypeApi::Demangle(this->type.name());
  for (string item : {"Switch::System::Func", "Switch::System::Tuple"}) {
    if (fullName.StartsWith(item)) {
      fullName = fullName.Replace(", std::nullptr_t", "");
      break;
    }
  }

  // replace some keywords by other...
  for (auto keyValue : System::Collections::Specialized::StringDictionary {{"std::nullptr_t", "Switch::NUllPtr"}, {"std::__1::allocator", "Switch::Allocator"}, {"std::allocator", "Switch::Allocator"}, {"std::initializer_list", "Switch::InitializerList"}, {"const", ""}, {"__property__", "_property"}, {"__readonly__", "_readonly"}, {"__writeonly__", "_writeonly"}, {"__readwrite__", "_readwrite"},}) {
    if (fullName.Contains(keyValue.Key))
      fullName = fullName.Replace(keyValue.Key, keyValue.Value);
  }
  return fullName.TrimEnd('*');
}

String Type::GetName() const {
  String fullName = GetFullName();
  int length = fullName.LastIndexOf("<");
  if (length == -1)
    length = fullName.Length;
  if (fullName.LastIndexOf("::", 0, length) == -1)
    return fullName;
  return fullName.Substring(fullName.LastIndexOf("::", 0, length) + 2);
}

String Type::GetNamespace() const {
  String fullName = GetFullName();
  int length = fullName.LastIndexOf("<");
  if (length == -1)
    length = fullName.Length;
  if (fullName.LastIndexOf("::", 0, length) == -1)
    return fullName;
  return fullName.Remove(fullName.LastIndexOf("::", 0, length));
}

String Type::ToString() const {
  return FullName;
}
