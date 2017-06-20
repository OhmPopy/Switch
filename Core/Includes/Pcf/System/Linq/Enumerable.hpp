/// @file
/// @brief Contains Pcf::System::Linq::Enumerable class.
#pragma once

#include <iostream>

#include "../../As.hpp"
#include "../../Static.hpp"
#include "../../Types.hpp"
#include "../Func.hpp"
#include "../Object.hpp"
#include "../_String.hpp"
#include "../Collections/Generic/IEnumerable.hpp"
#include "../Collections/Generic/List.hpp"
#include "../Func.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Linq namespace provides classes and interfaces that support queries that use Language-Integrated Query (LINQ).
    namespace Linq {
      /// @brief Provides a set of static methods for querying objects that implement IEnumerable<T>.
      class pcf_public Enumerable pcf_static {
      public:
        /// @brief Applies an accumulator function over a sequence.
        /// @param source An IEnumerable<T> to aggregate over.
        /// @param func An accumulator function to be invoked on each element.
        /// @return The final accumulator value.
        /// @par Examples
        /// The following code example demonstrates how to reverse the order of words in a string by using Aggregate.
        /// @include EnumerableAgregate.cpp
        template<typename TSource>
        static TSource Agregate(const Collections::Generic::IEnumerable<TSource>& source, const System::Func<const TSource&, const TSource&, TSource>& func)  {
          int nb = 0;
          TSource agregated;
          for (TSource item : source) {
            if (nb++ == 0)
              agregated = item;
            else
              agregated = func(agregated, item);
          }
          return agregated;
        }
        
        /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
        /// @param source An IEnumerable<T> to aggregate over.
        /// @param seed The initial accumulator value.
        /// @param func An accumulator function to be invoked on each element.
        /// @return The final accumulator value.
        /// @par Examples
        /// The following code example demonstrates how to use Aggregate to apply an accumulator function and use a seed value.
        /// @include EnumerableAgregate2.cpp
        template<typename TAccumulate, typename TSource>
        static TAccumulate Agregate(const Collections::Generic::IEnumerable<TSource>& source, const TAccumulate& seed, const System::Func<const TAccumulate&, const TSource&, TAccumulate>& func)  {
          TAccumulate agregated = seed;
          for (TSource item : source)
            agregated = func(agregated, item);
          return agregated;
        }
        
        /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
        /// @param source An IEnumerable<T> to aggregate over.
        /// @param seed The initial accumulator value.
        /// @param objFunc An accumulator obj to be invoked on each element.
        /// @param func An accumulator function to be invoked on each element.
        /// @param objResultSelector A obj to transform the final accumulator value into the result value.
        /// @param resultSelector A function to transform the final accumulator value into the result value.
        /// @return The transformed final accumulator value.
        /// @par Examples
        /// The following code example demonstrates how to use Aggregate to apply an accumulator function and use a seed value.
        /// @include EnumerableAgregate3.cpp
        template<typename TResult, typename TAccumulate, typename TSource>
        static TResult Agregate(const Collections::Generic::IEnumerable<TSource>& source, const TAccumulate& seed, const System::Func<const TAccumulate&, const TSource&, TAccumulate>& func, const System::Func<const TAccumulate&, TResult>& resultSelector){
          TAccumulate agregated = seed;
          for (TSource item : source)
            agregated = func(agregated, item);
          return resultSelector(agregated);
        }
        
        /// @brief Determines whether all elements of a sequence satisfy a condition.
        /// @param source An IEnumerable<T> that contains the elements to apply the predicate to.
        /// @param func A function to test each element for a condition.
        /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
        /// @par Examples
        /// The following code example demonstrates how to use All<TSource> to determine whether all the elements in a sequence satisfy a condition. Variable allStartWithB is true if all the pet names start with "B" or if the pets array is empty.
        /// @include EnumerableAll.cpp
        template<typename TSource>
        static bool All(const Collections::Generic::IEnumerable<TSource>& source, const System::Func<const TSource&, bool>& func) {
          for (TSource item : source)
            if (func(item) == false)
              return false;
          return true;
        }
        
        /// @brief Determines whether a sequence contains any elements.
        /// @param source The IEnumerable<T> to check for emptiness.
        /// @return true if the source sequence contains any elements; otherwise, false.
        /// @par Examples
        /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
        /// @include EnumerableAny.cpp
        template<typename TSource>
        static bool Any(const Collections::Generic::IEnumerable<TSource>& source) {
          return source.GetEnumerator().MoveNext();
        }
        
        /// @brief Determines whether any element of a sequence satisfies a condition.
        /// @param source An IEnumerable<T> whose elements to apply the predicate to.
        /// @param predicate A function to test each element for a condition.
        /// @return true if any elements in the source sequence pass the test in the specified predicate; otherwise, false.
        /// @par Examples
        /// The following code example demonstrates how to use Any to determine whether any element in a sequence satisfies a condition.
        /// @include EnumerableAny2.cpp
        template<typename TSource>
        static bool Any(const Collections::Generic::IEnumerable<TSource>& source, const System::Func<const TSource&, bool>& predicate) {
          for (TSource item : source)
            if (predicate(item) == true)
              return true;
          return false;
        }
        
        /// @brief Creates an array from a IEnumerable<T>
        /// @par Examples
        /// The following code example demonstrates how to use ToArray<TSource> to force immediate query evaluation and return an array of results.
        /// @include EnumerableToArray.cpp
        template<typename TSource>
        static Collections::Generic::IEnumerable<TSource>& AsEnumerable(const Collections::Generic::IEnumerable<TSource>& source) {return source;}
        
        static double Average(const Collections::Generic::IEnumerable<int32>& source) {
          double average = 0;
          int32 count = 0;
          for (int32 item : source) {
            average+= item;
            ++count;
          }
          if (count == 0)
            return 0;
          return average / count;
        }
        
        static double Average(const Collections::Generic::IEnumerable<int64>& source) {
          double average = 0;
          int32 count = 0;
          for (int64 item : source) {
            average+= item;
            ++count;
          }
          if (count == 0)
            return 0;
          return average / count;
        }
        
        static double Average(const Collections::Generic::IEnumerable<float>& source) {
          double average = 0;
          int32 count = 0;
          for (float item : source) {
            average+= item;
            ++count;
          }
          if (count == 0)
            return 0;
          return average / count;
        }
        
        static double Average(const Collections::Generic::IEnumerable<double>& source) {
          double average = 0;
          int32 count = 0;
          for (double item : source) {
            average+= item;
            ++count;
          }
          if (count == 0)
            return 0;
          return average / count;
        }
        
        /// @brief Casts the elements of an IEnumerable to the specified type.
        /// @par Examples
        /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
        /// @include EnumerableCast.cpp
        template<typename TResult, typename TSource>
        static refptr<Collections::Generic::IEnumerable<TResult>> Cast(const Collections::Generic::IEnumerable<TSource>& source) {
          refptr<System::Collections::Generic::List<TResult>> list = pcf_new<System::Collections::Generic::List<TResult>>();
          for (TSource item : source)
            list->Add(as<TResult>(item));
          return list;
        }
        
        /// @brief Concatenates two sequences.
        /// @param first The first sequence to concatenate.
        /// @param second The sequence to concatenate to the first sequence.
        /// @return refptr<Collections::Generic::IEnumerable<TSource>> An IEnumerable<T> that contains the concatenated elements of the two input sequences.
        /// @par Examples
        /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
        /// @include EnumerableConcat.cpp
        template<typename TSource>
        static refptr<Collections::Generic::IEnumerable<TSource>> Concat(const Collections::Generic::IEnumerable<TSource>& first, const Collections::Generic::IEnumerable<TSource>& second) {
          refptr<System::Collections::Generic::List<TSource>> list = pcf_new<System::Collections::Generic::List<TSource>>();
          for (TSource item : first)
            list->Add(item);
          for (TSource item : second)
            list->Add(item);
          return list;
        }

        /// @brief Returns the maximum value in a generic sequence.
        /// @param source The IEnumerable that contains the elements to be cast to type TResult.
        /// @return An IEnumerable<T> that contains each element of the source sequence cast to the specified type.
        /// @par Examples
        /// The following code example demonstrates how to use Max<TSource>(IEnumerable<TSource>) to determine the maximum value in a sequence of IComparable<T> objects.
        /// @include EnumerableMax.cpp
        template<typename TSource>
        static const TSource& Max(const Collections::Generic::IEnumerable<TSource>& source) {
          const TSource* max = null;
          System::Collections::Generic::Enumerator<TSource> enumerator = source.GetEnumerator();
          while (enumerator.MoveNext())
            if (max == null || enumerator.Current() > *max)
              max = &enumerator.Current();
          return *max;
        }
        
        /// @brief Returns the minimum value in a generic sequence.
        /// @par Examples
        /// The following code example demonstrates how to use Min<TSource>(IEnumerable<TSource>) to determine the minimum value in a sequence of IComparable<T> objects.
        /// @include EnumerableMin.cpp
        template<typename TSource>
        static const TSource& Min(const Collections::Generic::IEnumerable<TSource>& source) {
          const TSource* min = null;
          System::Collections::Generic::Enumerator<TSource> enumerator = source.GetEnumerator();
          while (enumerator.MoveNext())
            if (min == null || enumerator.Current() < *min)
              min = &enumerator.Current();
          return *min;
        }
        
        /// @brief Inverts the order of the elements in a sequence.
        /// @par Examples
        /// The following code example demonstrates how to use Reverse<TSource> to reverse the order of elements in an array.
        /// @include EnumerableReverse.cpp
        template<typename TSource>
        static refptr<Collections::Generic::IEnumerable<TSource>> Reverse(const Collections::Generic::IEnumerable<TSource>& source) {
          refptr<System::Collections::Generic::List<TSource>> list = pcf_new<System::Collections::Generic::List<TSource>>();
          for (TSource item : source)
            list->Insert(0, item);
          return list;
        }
        
        /// @brief Creates an array from a IEnumerable<T>
        /// @par Examples
        /// The following code example demonstrates how to use ToArray<TSource> to force immediate query evaluation and return an array of results.
        /// @include EnumerableToArray.cpp
        template<typename TSource>
        static System::Array<TSource> ToArray(const Collections::Generic::IEnumerable<TSource>& source) {
          System::Array<TSource> array = new System::Array<TSource>();
          for (TSource item : source) {
            System::Array<TSource>::Resize(array, array.Length+1);
            array[array.Length-1] = item;
          }
          return array;
        }
      };

      namespace Extension {
        /// @brief Provides a set of methods for querying objects that implement IEnumerable<T>.
        template<typename T, typename TSource>
        class Enumerable {
        public:
          /// @brief Applies an accumulator function over a sequence.
          /// @param func An accumulator function to be invoked on each element.
          /// @return The final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to reverse the order of words in a string by using Aggregate.
          /// @include EnumerableAgregate.cpp
          TSource Agregate(const System::Func<const TSource&, const TSource&, TSource>& func) const {return System::Linq::Enumerable::Agregate<TSource>(static_cast<const T&>(*this), func);}

          /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
          /// @param seed The initial accumulator value.
          /// @param func An accumulator function to be invoked on each element.
          /// @return The final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to use Aggregate to apply an accumulator function and use a seed value.
          /// @include EnumerableAgregate2.cpp
          template<typename TAccumulate>
          TAccumulate Agregate(const TAccumulate& seed, const System::Func<const TAccumulate&, const TSource&, TAccumulate>& func) const {return System::Linq::Enumerable::Agregate<TAccumulate, TSource>(static_cast<const T&>(*this), seed, func);}

          /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
          /// @param seed The initial accumulator value.
          /// @param objFunc An accumulator obj to be invoked on each element.
          /// @param func An accumulator function to be invoked on each element.
          /// @param objResultSelector A obj to transform the final accumulator value into the result value.
          /// @param resultSelector A function to transform the final accumulator value into the result value.
          /// @return The transformed final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to use Aggregate to apply an accumulator function and use a seed value.
          /// @include EnumerableAgregate3.cpp
          template<typename TResult, typename TAccumulate>
          TResult Agregate(const TAccumulate& seed, const System::Func<const TAccumulate&, const TSource&, TAccumulate>& func, const System::Func<const TAccumulate&, TResult>& resultSelector) const {return System::Linq::Enumerable::Agregate<TResult, TAccumulate, TSource>(static_cast<const T&>(*this), seed, func, resultSelector);}

          /// @brief Determines whether all elements of a sequence satisfy a condition.
          /// @param func A function to test each element for a condition.
          /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
          /// @par Examples
          /// The following code example demonstrates how to use All<TSource> to determine whether all the elements in a sequence satisfy a condition. Variable allStartWithB is true if all the pet names start with "B" or if the pets array is empty.
          /// @include EnumerableAll.cpp
          bool All(const System::Func<const TSource&, bool>& func) const {return System::Linq::Enumerable::All<TSource>(static_cast<const T&>(*this), func);}

          /// @brief Determines whether a sequence contains any elements.
          /// @return true if the source sequence contains any elements; otherwise, false.
          /// @par Examples
          /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
          /// @include EnumerableAny.cpp
          bool Any() const {return System::Linq::Enumerable::Any<TSource>(static_cast<const T&>(*this));}

          /// @brief Determines whether any element of a sequence satisfies a condition.
          /// @param predicate A function to test each element for a condition.
          /// @return true if any elements in the source sequence pass the test in the specified predicate; otherwise, false.
          /// @par Examples
          /// The following code example demonstrates how to use Any to determine whether any element in a sequence satisfies a condition.
          /// @include EnumerableAny2.cpp
          bool Any(const System::Func<const TSource&, bool>& predicate) const {return System::Linq::Enumerable::Any<TSource>(static_cast<const T&>(*this), predicate);}
          
          /// @brief Creates an array from a IEnumerable<T>
          /// @par Examples
          /// The following code example demonstrates how to use ToArray<TSource> to force immediate query evaluation and return an array of results.
          /// @include EnumerableToArray.cpp
          refptr<Collections::Generic::IEnumerable<TSource>> AsEnumerable() const {return System::Linq::Enumerable::AsEnumerable<TSource>(static_cast<const T&>(*this));}
          
          double Average() const {return System::Linq::Enumerable::Average(static_cast<const T&>(*this));}

          /// @brief Casts the elements of an IEnumerable to the specified type.
          /// @par Examples
          /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
          /// @include EnumerableCast.cpp
          template<typename TResult>
          refptr<Collections::Generic::IEnumerable<TResult>> Cast() const {return System::Linq::Enumerable::Cast<TResult, TSource>(static_cast<const T&>(*this));}
          
          /// @brief Concatenates two sequences.
          /// @param second The sequence to concatenate to this sequence.
          /// @return refptr<Collections::Generic::IEnumerable<TSource>> An IEnumerable<T> that contains the concatenated elements of the two input sequences.
          /// @par Examples
          /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
          /// @include EnumerableConcat.cpp
          refptr<Collections::Generic::IEnumerable<TSource>> Concat(const Collections::Generic::IEnumerable<TSource>& second) const {return System::Linq::Enumerable::Concat<TSource>(static_cast<const T&>(*this), second);}
          
          /// @brief Returns the maximum value in a generic sequence.
          /// @return An IEnumerable<T> that contains each element of the source sequence cast to the specified type.
          /// @par Examples
          /// The following code example demonstrates how to use Max<TSource>(IEnumerable<TSource>) to determine the maximum value in a sequence of IComparable<T> objects.
          /// @include EnumerableMax.cpp
          const TSource& Max() const {return System::Linq::Enumerable::Max<TSource>(static_cast<const T&>(*this));}
          
          /// @brief Returns the minimum value in a generic sequence.
          /// @par Examples
          /// The following code example demonstrates how to use Min<TSource>(IEnumerable<TSource>) to determine the minimum value in a sequence of IComparable<T> objects.
          /// @include EnumerableMin.cpp
          const TSource& Min() const {return System::Linq::Enumerable::Min<TSource>(static_cast<const T&>(*this));}
          
          /// @brief Inverts the order of the elements in a sequence.
          /// @par Examples
          /// The following code example demonstrates how to use Reverse<TSource> to reverse the order of elements in an array.
          /// @include EnumerableReverse.cpp
          refptr<Collections::Generic::IEnumerable<TSource>> Reverse() const {return System::Linq::Enumerable::Reverse<TSource>(static_cast<const T&>(*this));}

          /// @brief Creates an array from a IEnumerable<T>
          /// @par Examples
          /// The following code example demonstrates how to use ToArray<TSource> to force immediate query evaluation and return an array of results.
          /// @include EnumerableToArray.cpp
          System::Array<TSource> ToArray() const {return System::Linq::Enumerable::ToArray<TSource>(static_cast<const T&>(*this));}

        protected:
          Enumerable() {}
        };
      }
    }
  }
}

using namespace Pcf;
