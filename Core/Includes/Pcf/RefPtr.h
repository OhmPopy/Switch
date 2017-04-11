/// @file
/// @brief Contains Pcf::RefPtr <T> class.
#pragma once

#include <atomic>
#include <exception>
#include <string>
#include <sstream>

#include "Types.h"
#include "UniquePtr.h"

/// @cond
namespace Pcf {
  template<typename T>
  class RefPtr;
}
class pcf_public __opaque_sub_object__ {
  template<typename T>
  friend class Pcf::RefPtr;
  __opaque_sub_object__() : UseCount(0) {}
  __opaque_sub_object__(const __opaque_sub_object__& so) : UseCount(so.UseCount.load()) {}
  
  std::atomic<int32> UseCount;
};
/// @endcond

namespace Pcf {
  /// @cond
  template <typename T=void>
  class RefPtr;
  /// @endcond

  /// @brief Represents a Reference Pointer class. A RefPtr is a memory-managing pointer to an object.
  /// @remarks A Reference Pointer is basically a pointer with a destructor. The destructor ensures that the object pointed to is deleted when it is no longer being used. You can have multiple pointers to the same object, so the object is only deleted when the last pointer is destroyed.
  /// @remarks A Reference Pointer has to have slightly different characteristics to a conventional C pointer. These differences show up in the behaviour of the pointer on assignment and when the pointer's address (i.e. the object being pointed to) is changed. Deciding the exact behaviour is difficult and very subjective. This could be solved by having a range of different classes with slightly different behaviour. You could then choose which one suits your problem. However, I don't agree with this approach - I think you get quickly bogged down with the subtle differences and lose sight of the program you are actually trying to write. So I provide just one kind of Reference Pointer which I believe is the most general-purpose. I think this is consistent with the STL, which provides just one kind of vector, map, list etc.
  /// @remarks The Reference Pointer contains the address of the object pointed to and a counter which stores the alias count. When one Reference Pointer is assigned to another, the second Reference Pointer becomes an alias of the first, which means that it is pointing to the same object. The alias count of the object is incremented to show that there are now two pointers pointing to the same object.
  /// @remarks In fact, an extra level of indirection needs to be used. A Reference Pointer class in fact contains a pointer to a sub-object which in turn contains the address of the contained object and an integer containing the alias count.
  /// @image html sharepointer.gif
  /// In this figure, there are two RefPtr objects pointing to the same sub-object (which is actually part of the RefPtr structure hidden from the user), which then points to the data object which is the user's data. The alias count is stored in the sub-object. There is an alias count of 2 because there are two RefPtr objects pointing to the sub-object.
  /// When a Reference Pointer goes out of scope or is destroyed for any reason, it is dealiased. This means that the Reference Pointer no longer points to the object. It's alias count is decremented to show that one less Reference Pointer is pointing at the object. When the alias count decrements to zero, this indicates that the object is no longer being pointed to by any Reference Pointers and so it is deleted automatically.
  /// A consequence of the Reference Pointer design is that if you change the object pointed to by one RefPtr, you change the object pointed to by its aliases too. In other words, if you change the address of one RefPtr, you are actually changing the address stored in the sub-object, which is visible to all other aliases, so these appear to change their stored address too. The result is that all aliases end up still being aliases and all pointing to the new object, whilst the old object gets deleted automatically because it is no longer pointed to.
  /// This behaviour is unlike conventional C pointers - if you allocate a new object to a pointer variable, you don't expect other pointer variables to change too. However, it can have very significant advantages in data structure design. It is common when designing large and complex data structures to have several different ways of accessing objects - for example you might store an object in a map which allows access to objects sorted in alphabetical order, but also store it in a vector which allows access to objects in the order in which they were created. Traditionally this could lead to problems in memory managing the object when removing it from one or other since it could become ambiguous which data structure is the container responsible for deallocating its memory. However, with Reference Pointers this problem disappears - put a Reference Pointer in both map and vector pointing to the same object, i.e. aliases. The object will persist until both Reference Pointers are deallocated. Furthermore, if the object pointed to needs to be changed, it can be changed by changing either alias. So, you can look it up in the map, change the address and the address pointed to by the other alias in the vector will automatically change to the new object - they remain consistent.
  /// For more information see also  http://stlplus.sourceforge.net/stlplus3/docs/smart_ptr.html
  /// @par Examples
  /// This example show how to used RefPtr :
  /// @include RefPtr.cpp
  template<typename T>
  class RefPtr {
  public:
    /// @brief Represents the empty RefPtr. This field is constant.
    static const RefPtr<T>& Empty() { static const RefPtr<T> value; return value; }
    
    /// @brief Represents a Null RefPtr. This field is constant.
    static const RefPtr<T>& Null() { static const RefPtr<T> value; return value; }
    
    /// @brief Create a new instance of class RefPtr
    /// @remarks RefPtr is initialized with default value RefPtr::Empty()
    RefPtr() {}
    
    /// @brief Create a new instance of class RefPtr with a specified sp RefPtr.
    /// @param sp RefPtr to copy
    /// @exception ArgumentNullException sp is null.
    /// @remarks the current object is equal to smartPointer and UseCount of both is incremented.
    RefPtr(const RefPtr<T>& sp) { Reset(sp); }
    
    template<typename TT>
    RefPtr(const RefPtr<TT>& sp) { Reset(sp); }
    
    RefPtr(RefPtr<T>&& sp) { Reset(sp); sp.Reset();}
    
    template<typename TT>
    RefPtr(RefPtr<TT>&& sp) { Reset(sp); sp.Reset();}
    
    /// @brief Create a new instance of class RefPtr with a specified obj pointer T
    /// @param obj Pointer T object to assign the current object. It can be null.
    /// @remarks The obj pointer must be create by operator new. If obj is a pointer on the stack, a error will occured at used.
    RefPtr(T* obj) { Reset(obj); }

    template<typename TT>
    RefPtr(UniquePtr<TT> up) { Reset(up.template As<T>().Release()); }
    
    /// @brief Delete the current object. Set the current object to null.
    /// @remarks UseCount is decremented. If alias count equal 0 the object T is deleted.
    void Delete() { Reset(); }
    
    /// @brief Gets the UseCount of object T
    /// @return The UseCount.
    /// @remarks return 0 if the current object is Empty or Null.
    int32 GetUseCount() const {
      if (this->subObject == null)
        return 0;
      
      return this->subObject->UseCount;
    }
    
    /// @brief Indicates whether the SharePointer is null.
    /// @return bool true if the SharePointer is null; otherwise, false.
    bool IsNull() const { return this->subObject == null; }
    
    /// @brief Indicates whether the specified sp SharPointer is an null or Empty.
    /// @param sp A RefPtr reference.
    /// @return bool true if the smartPointer parameter is null or an empty RefPtr; otherwise, false.
    static bool IsNullOrInvalid(const RefPtr<T>& sp) { return sp.IsNull(); }
    
    /// @brief Gets a bool indicate is the current RefPtr<T> is unique (UseCount = 1).
    /// @return Return true if the current SharePointer is unique; otherwise false.
    /// @remarks An Empty SharePointer are never unique, it always return true.
    bool IsUnique() const {
      if (this->subObject == null)
        return true;
      
      return this->subObject->UseCount == 1;
    }
    
    /// @brief Reset the current object. Set the current object to null.
    /// @remarks UseCount is decremented. If alias count equal 0 the object T is deleted.
    void Reset() { Reset(null); }
    
    /// @brief Reset the current object. Set the current object to the specifeid object pointer T.
    /// @param obj Pointer T object to assign the current object. It can be null.
    /// @remarks Before set, if the current object is not empty UseCount is decremented. If UseCount equal 0 the object T is deleted.
    /// @remarks The obj pointer must be create by operator new. If obj is a pointer on the stack, a error will occured at used.
    void Reset(T* obj) {
      if (this->subObject != null && --this->subObject->UseCount == 0) {
        delete this->subObject;
        delete this->ptr;
      }
      
      if (obj == null) {
        this->subObject = null;
        this->ptr = null;
        return;
      }
      
      this->subObject = new __opaque_sub_object__();
      this->ptr = obj;
      ++this->subObject->UseCount;
    }
    
    template<typename TT>
    void Reset(RefPtr<TT> obj) {
      if (this->subObject != null && --this->subObject->UseCount == 0) {
        delete this->subObject;
        delete this->ptr;
      }
      
      if (obj == null) {
        this->subObject = null;
        this->ptr = null;
        return;
      }
      
      this->subObject = obj.subObject;
      this->ptr = obj.template ToPointer<TT>();
      ++this->subObject->UseCount;
    }
    
    /// @brief Exchanges the contents of the RefPtr object with those of ptr, transferring ownership of any managed object between them without destroying either.
    /// @param ptr Another RefPtr object of the same type.
    void Swap(RefPtr<T>& ptr) {
      T* p = ptr.ptr;
      __opaque_sub_object__* s = ptr.subObject;
      ptr.ptr = this->ptr;
      ptr.subObject = this->subObject;
      this->ptr = p;
      this->subObject = s;
    }
    
    static void Swap(RefPtr<T>& ptrA, RefPtr<T>& ptrB) { ptrA.Swap(ptrB); }
    
    /// @brief Gets a reference on object T
    /// @return Reference on object T.
    /// @exception NullPointerException If the current object is Empty.
    T& ToObject() {
      if (this->subObject == null)
        throw std::exception();
      
      return *this->ptr;
    }
    
    /// @brief Gets a reference on object T
    /// @return Reference on object T.
    /// @exception NullPointerException If the current object is Empty.
    const T& ToObject() const {
      if (this->subObject == null)
        throw std::exception();
      
      return *this->ptr;
    }
    
    /// @brief Gets a casted reference TT on object T
    /// @return Reference TT on object T.
    /// @exception InvalidCastException if T is not a TT type.
    template<typename TT>
    TT& ToObject() {
      return *ToPointer<TT>();
    }
    
    /// @brief Gets a casted reference TT on object T
    /// @return Reference TT on object T.
    /// @exception InvalidCastException if T is not a TT type.
    template<typename TT>
    const TT& ToObject() const {
      return *ToPointer<TT>();
    }
    
    /*
     /// @brief Gets a reference on object T
     /// @retur Reference on object T.
     /// @exception NullPointerException If the current object is Empty.
     ref<T> ToReference() { return ToObject(); }
     
     /// @brief Gets a reference on object T
     /// @return Reference on object T.
     /// @exception NullPointerException If the current object is Empty.
     ref<T> ToReference() const { return ToObject(); }
     
     /// @brief Gets a casted reference TT on object T
     /// @return Reference TT on object T.
     /// @exception InvalidCastException if T is not a TT type.
     template<typename TT>
     ref<TT> ToReference() { return ToObject<TT>(); }
     
     /// @brief Gets a casted reference TT on object T
     /// @return Reference TT on object T.
     /// @exception InvalidCastException if T is not a TT type.
     template<typename TT>
     const ref<TT> ToReference() const { return ToObject<TT>(); }
     */
    
    /// @brief Gets a pointer on object T
    /// @return Pointer on object T.
    /// @exception InvalidCastException if T is not a TT type.
    T* ToPointer() {
      if (this->subObject == null)
        throw std::exception();
      
      return this->ptr;
    }
    
    /// @brief Gets a pointer on object T
    /// @return Pointer on object T.
    /// @exception NullPointerException If the current object is Empty.
    const T* ToPointer() const {
      if (this->subObject == null)
        throw std::exception();
      
      return this->ptr;
    }
    
    /// @brief Gets a pointer of type TT* on object T
    /// @return Pointer of type TT* on object T.
    /// @exception NullPointerException If the current object is Empty.
    template<typename TT>
    TT* ToPointer() {
      if (this->subObject == null)
        throw std::exception();
      
      TT* cast = dynamic_cast<TT*>(this->ptr);
      if (cast == null)
        throw std::exception();
      return cast;
    }
    
    /// @brief Gets a pointer of type TT* on object T
    /// @return Pointer of type TT* on object T.
    /// @exception InvalidCastException if T is not a TT type.
    template<typename TT>
    const TT* ToPointer() const {
      if (this->subObject == null)
        throw std::exception();
      
      const TT* cast = dynamic_cast<const TT*>(this->ptr);
      if (cast == null)
        throw std::exception();
      return cast;
    }
    
    /// @brief Creates an alias of the smartpointer with a different type
    /// @return RefPtr of type TT.
    template<typename TT>
    RefPtr<TT> StaticCast() const {
      try {
        if (this->ptr == null)
          return RefPtr<TT>::Null();
        
        TT* ptr = static_cast<TT*>(this->ptr);
        if (ptr == null)
          return RefPtr<TT>::Null();
        RefPtr<TT> sp;
        sp.subObject = this->subObject;
        sp.ptr = ptr;
        ++this->subObject->UseCount;
        return sp;
      } catch (const std::bad_cast&) {
        return RefPtr<TT>::Null();
      }
    }
    
    /// @brief Creates an alias of the smartpointer with a different type
    /// @return RefPtr of type TT.
    template<typename TT>
    RefPtr<TT> DynamicCast() const {
      try {
        if (this->ptr == null)
          return RefPtr<TT>::Null();
        
        TT* ptr = dynamic_cast<TT*>(this->ptr);
        if (ptr == null)
          return RefPtr<TT>::Null();
        RefPtr<TT> sp;
        sp.subObject = this->subObject;
        sp.ptr = ptr;
        ++this->subObject->UseCount;
        return sp;
      } catch (const std::bad_cast&) {
        return RefPtr<TT>::Null();
      }
    }
    
    /// @return Creates an alias of the smartpointer with a different type
    /// @return RefPtr of type TT.
    template<typename TT>
    RefPtr<TT> As() const {
      try {
        if (this->ptr == null)
          return RefPtr<TT>::Null();
        
        TT* ptr = dynamic_cast<TT*>(this->ptr);
        if (ptr == null)
          return RefPtr<TT>::Null();
        RefPtr<TT> sp;
        sp.subObject = this->subObject;
        sp.ptr = ptr;
        ++this->subObject->UseCount;
        return sp;
      } catch (const std::bad_cast&) {
        return RefPtr<TT>::Null();
      }
    }
    
    /// @brief Creates an alias of the smartpointer with a different type
    /// @param sp Pointer T object to assign the current object. It can be null.
    /// @return RefPtr of type TT.
    template<typename TT>
    static RefPtr<TT> StaticCast(const RefPtr<T>& sp) { return sp.StaticCast<TT>(); }
    
    /// @brief Creates an alias of the smartpointer with a different type
    /// @param sp Pointer T object to assign the current object. It can be null.
    /// @return RefPtr of type TT.
    template<typename TT>
    static RefPtr<TT> DynamicCast(const RefPtr<T>& sp) { return sp.DynamicCast<TT>(); }
    
    /// @brief Creates an alias of the smartpointer with a different type
    /// @param sp Pointer T object to assign the current object. It can be null.
    /// @return RefPtr of type TT.
    template<typename TT>
    static RefPtr<TT> As(const RefPtr<T>& sp) { return sp.As<TT>(); }
    
    /// @brief Creates an alias of the smartpointer with a different type
    /// @return RefPtr of type TT.
    template<typename TT>
    bool Is() const {
      try {
        if (this->ptr == null)
          return false;
        return dynamic_cast<TT*>(this->ptr) != null;
      } catch (const std::bad_cast&) {
        return false;
      }
    }
    
    /// @brief Creates an alias of the smartpointer with a different type
    /// @param sp Pointer T object to assign the current object. It can be null.
    /// @return RefPtr of type TT.
    template<typename TT>
    static bool Is(const RefPtr<T>& sp) { return sp.Is<TT>(); }
    
    /// @brief Creates an alias of the smartpointer with a different type
    /// @return RefPtr of type TT.
    template<typename TT>
    RefPtr<TT> ChangeType() const {
      if (dynamic_cast<TT*>(this->ptr) == null)
        throw std::exception();
      
      RefPtr<TT> sp;
      sp.subObject = this->subObject;
      sp.ptr = dynamic_cast<TT*>(this->ptr);
      ++this->subObject->UseCount;
      return sp;
    }
    
    /// @brief Creates an alias of the smartpointer with a different type
    /// @param sp Pointer T object to assign the current object. It can be null.
    /// @return RefPtr of type TT.
    template<typename TT>
    static RefPtr<TT> ChangeType(const RefPtr<T>& sp) { return sp.ChangeType<TT>(); }
    
    /// @brief Returns a string that represents the current RefPtr.
    /// @return string A string that represents the current RefPtr.
    std::string ToString() const {
      if (this->ptr == null)
        return "Pcf::RefPtr [Pointer=null]";
      std::stringstream s;
      s << "Pcf::RefPtr [Pointer=" << this->ptr << "]";
      return s.str();
    }
    
    template<typename ...Arguments>
    static RefPtr<T> Create(Arguments... arguments) {
      return RefPtr<T>(new T(arguments...));
    }

    template<typename TT, typename ...Arguments>
    static RefPtr<T> Create(Arguments... arguments) {
      return RefPtr<T>(new TT(arguments...));
    }
    
    /// @cond
    virtual ~RefPtr() { Reset(); }
    
    const T& operator*() const { return ToObject(); }
    T& operator*() { return ToObject(); }
    
    const T& operator()() const { return ToObject(); }
    T& operator()() { return ToObject(); }
    
    const T* operator&() const { return ToPointer(); }
    T* operator&() { return ToPointer(); }
    
    const T* operator->() const { return ToPointer(); }
    T* operator->() { return ToPointer(); }
    
    RefPtr<T>& operator =(const RefPtr<T>& sp) {
      Reset(sp);
      return *this;
    }
 
    template<typename TT>
    RefPtr<T>& operator=(const RefPtr<TT>& sp) {
      Reset(sp);
      return *this;
    }
    
    RefPtr<T>& operator=(T* obj) {
      Reset(obj);
      return *this;
    }
    
    template<typename TT>
    RefPtr<T>& operator=(UniquePtr<TT> up)  {
      Reset(up.template As<T>().Release());
      return *this;
    }
    
    bool operator==(const T* ptr) { return this->ptr == ptr; }
    
    bool operator==(const RefPtr<T>& sp) const { return this->subObject == sp.subObject && this->ptr == sp.ptr; }
    
    bool operator!=(const T* ptr) { return this->ptr != ptr; }
    
    bool operator!=(const RefPtr<T>& sp) const { return this->subObject != sp.subObject || this->ptr != sp.ptr; }
    
    operator bool() const { return this->ptr != null; }
    
    bool operator!() const { return this->ptr == null; }
    
    /// @endcond
    
  private:
    void Reset(const RefPtr<T>& sp){
      Reset(null);
      this->subObject = sp.subObject;
      this->ptr = sp.ptr;
      if (this->subObject != null)
        ++this->subObject->UseCount;
    }
    
  public:
    T* ptr = null;
    __opaque_sub_object__* subObject = null;
  };
  
  template <>
  class RefPtr<void> {
  public:
    template<typename T, typename ...Arguments>
    static RefPtr<T> Create(Arguments... arguments) {
      return RefPtr<T>::Create(arguments...);
    }

    template<typename TCreate, typename TResult, typename ...Arguments>
    static RefPtr<TResult> Create(Arguments... arguments) {
      return RefPtr<TResult>::template Create<TCreate>(arguments...);
    }
  };
  
  /// @brief Represents a Reference Pointer class. A RefPtr is a memory-managing pointer to an object.
  /// @remarks A Reference Pointer is basically a pointer with a destructor. The destructor ensures that the object pointed to is deleted when it is no longer being used. You can have multiple pointers to the same object, so the object is only deleted when the last pointer is destroyed.
  /// @remarks A Reference Pointer has to have slightly different characteristics to a conventional C pointer. These differences show up in the behaviour of the pointer on assignment and when the pointer's address (i.e. the object being pointed to) is changed. Deciding the exact behaviour is difficult and very subjective. This could be solved by having a range of different classes with slightly different behaviour. You could then choose which one suits your problem. However, I don't agree with this approach - I think you get quickly bogged down with the subtle differences and lose sight of the program you are actually trying to write. So I provide just one kind of Reference Pointer which I believe is the most general-purpose. I think this is consistent with the STL, which provides just one kind of vector, map, list etc.
  /// @remarks The Reference Pointer contains the address of the object pointed to and a counter which stores the alias count. When one Reference Pointer is assigned to another, the second Reference Pointer becomes an alias of the first, which means that it is pointing to the same object. The alias count of the object is incremented to show that there are now two pointers pointing to the same object.
  /// @remarks In fact, an extra level of indirection needs to be used. A Reference Pointer class in fact contains a pointer to a sub-object which in turn contains the address of the contained object and an integer containing the alias count.
  /// @image html sharepointer.gif
  /// @remarks In this figure, there are two RefPtr objects pointing to the same sub-object (which is actually part of the RefPtr structure hidden from the user), which then points to the data object which is the user's data. The alias count is stored in the sub-object. There is an alias count of 2 because there are two RefPtr objects pointing to the sub-object.
  /// @remarks When a Reference Pointer goes out of scope or is destroyed for any reason, it is dealiased. This means that the Reference Pointer no longer points to the object. It's alias count is decremented to show that one less Reference Pointer is pointing at the object. When the alias count decrements to zero, this indicates that the object is no longer being pointed to by any Reference Pointers and so it is deleted automatically.
  /// @remarks A consequence of the Reference Pointer design is that if you change the object pointed to by one RefPtr, you change the object pointed to by its aliases too. In other words, if you change the address of one RefPtr, you are actually changing the address stored in the sub-object, which is visible to all other aliases, so these appear to change their stored address too. The result is that all aliases end up still being aliases and all pointing to the new object, whilst the old object gets deleted automatically because it is no longer pointed to.
  /// @remarks This behaviour is unlike conventional C pointers - if you allocate a new object to a pointer variable, you don't expect other pointer variables to change too. However, it can have very significant advantages in data structure design. It is common when designing large and complex data structures to have several different ways of accessing objects - for example you might store an object in a map which allows access to objects sorted in alphabetical order, but also store it in a vector which allows access to objects in the order in which they were created. Traditionally this could lead to problems in memory managing the object when removing it from one or other since it could become ambiguous which data structure is the container responsible for deallocating its memory. However, with Reference Pointers this problem disappears - put a Reference Pointer in both map and vector pointing to the same object, i.e. aliases. The object will persist until both Reference Pointers are deallocated. Furthermore, if the object pointed to needs to be changed, it can be changed by changing either alias. So, you can look it up in the map, change the address and the address pointed to by the other alias in the vector will automatically change to the new object - they remain consistent.
  /// @remarks For more information see also  http://stlplus.sourceforge.net/stlplus3/docs/smart_ptr.html
  /// @par Examples
  /// This example show how to used RefPtr :
  /// @include RefPtr.cpp
  /// @ingroup Pcf
  template<typename T>
  using refptr = RefPtr<T>;
  
  /// @brief Represents a Reference Pointer class. A SharedPtr is a memory-managing pointer to an object.
  /// @remarks A Reference Pointer is basically a pointer with a destructor. The destructor ensures that the object pointed to is deleted when it is no longer being used. You can have multiple pointers to the same object, so the object is only deleted when the last pointer is destroyed.
  /// @remarks A Reference Pointer has to have slightly different characteristics to a conventional C pointer. These differences show up in the behaviour of the pointer on assignment and when the pointer's address (i.e. the object being pointed to) is changed. Deciding the exact behaviour is difficult and very subjective. This could be solved by having a range of different classes with slightly different behaviour. You could then choose which one suits your problem. However, I don't agree with this approach - I think you get quickly bogged down with the subtle differences and lose sight of the program you are actually trying to write. So I provide just one kind of Reference Pointer which I believe is the most general-purpose. I think this is consistent with the STL, which provides just one kind of vector, map, list etc.
  /// @remarks The Reference Pointer contains the address of the object pointed to and a counter which stores the alias count. When one Reference Pointer is assigned to another, the second Reference Pointer becomes an alias of the first, which means that it is pointing to the same object. The alias count of the object is incremented to show that there are now two pointers pointing to the same object.
  /// @remarks In fact, an extra level of indirection needs to be used. A Reference Pointer class in fact contains a pointer to a sub-object which in turn contains the address of the contained object and an integer containing the alias count.
  /// @image html sharepointer.gif
  /// @remarks In this figure, there are two SharedPtr objects pointing to the same sub-object (which is actually part of the SharedPtr structure hidden from the user), which then points to the data object which is the user's data. The alias count is stored in the sub-object. There is an alias count of 2 because there are two SharedPtr objects pointing to the sub-object.
  /// @remarks When a Reference Pointer goes out of scope or is destroyed for any reason, it is dealiased. This means that the Reference Pointer no longer points to the object. It's alias count is decremented to show that one less Reference Pointer is pointing at the object. When the alias count decrements to zero, this indicates that the object is no longer being pointed to by any Reference Pointers and so it is deleted automatically.
  /// @remarks A consequence of the Reference Pointer design is that if you change the object pointed to by one SharedPtr, you change the object pointed to by its aliases too. In other words, if you change the address of one SharedPtr, you are actually changing the address stored in the sub-object, which is visible to all other aliases, so these appear to change their stored address too. The result is that all aliases end up still being aliases and all pointing to the new object, whilst the old object gets deleted automatically because it is no longer pointed to.
  /// @remarks This behaviour is unlike conventional C pointers - if you allocate a new object to a pointer variable, you don't expect other pointer variables to change too. However, it can have very significant advantages in data structure design. It is common when designing large and complex data structures to have several different ways of accessing objects - for example you might store an object in a map which allows access to objects sorted in alphabetical order, but also store it in a vector which allows access to objects in the order in which they were created. Traditionally this could lead to problems in memory managing the object when removing it from one or other since it could become ambiguous which data structure is the container responsible for deallocating its memory. However, with Reference Pointers this problem disappears - put a Reference Pointer in both map and vector pointing to the same object, i.e. aliases. The object will persist until both Reference Pointers are deallocated. Furthermore, if the object pointed to needs to be changed, it can be changed by changing either alias. So, you can look it up in the map, change the address and the address pointed to by the other alias in the vector will automatically change to the new object - they remain consistent.
  /// @remarks For more information see also  http://stlplus.sourceforge.net/stlplus3/docs/smart_ptr.html
  /// @par Examples
  /// This example show how to used SharedPtr :
  /// @include SharedPtr.cpp
  /// @ingroup Pcf
  template<typename T>
  using SharedPtr = RefPtr<T>;
  
  template<typename T, typename ...Args>
  refptr<T> pcf_new(Args... args) {return refptr<T>(new T(args...));}
}

using namespace Pcf;
