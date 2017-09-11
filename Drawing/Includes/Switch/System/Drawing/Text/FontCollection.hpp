/// @file
/// @brief Contains Switch::System::Drawing::FontFamily class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include "../FontFamily.hpp"

/// @cond
namespace __OS {
  class DrawingApi;
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief The System::Drawing::Text namespace provides advanced GDI+ typography functionality.
      namespace Text {
        /// @brief Provides a base class for installed and private font collections.
        /// @remarks The FontCollection allows you to get a list of the font families contained in the collection with its Families property. For additional information on fonts and text, including example code, see Using Fonts and Text.
        class _export FontCollection : public object {
        public:
          /// @brief Gets the array of FontFamily objects associated with this FontCollection.
          /// @return Array<FontFamily> An array of FontFamily objects.
          _property<const Array<FontFamily>&, _readonly> Families{
            _get->const Array<FontFamily>& {return this->families;}
          };

        protected:
          /// @cond
          FontCollection();
          Array<FontFamily> families;
          /// @endcond
        };
      }
    }
  }
}
