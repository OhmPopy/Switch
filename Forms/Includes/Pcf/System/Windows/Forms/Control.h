/// @file
/// @brief Contains Pcf::System::Windows::Forms::Control class.
#pragma once

#include <Pcf/System/Collections/Generic/Dictionary.h>
#include <Pcf/System/Collections/Generic/List.h>
#include <Pcf/System/Drawing/Color.h>
#include <Pcf/System/Drawing/SolidBrush.h>
#include <Pcf/System/Drawing/SystemColors.h>
#include <Pcf/System/Drawing/Font.h>
#include <Pcf/System/Nullable.h>
#include "../../ComponentModel/Component.h"
#include "ControlStyles.h"
#include "InvalidateEventHandler.h"
#include "Message.h"
#include "MouseEventHandler.h"
#include "PaintEventHandler.h"

/// @cond
namespace __OS {
  class FormsApi;
}
/// @endcond

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Defines the base class for controls, which are components with visual representation.
        /// @remarks To create your own control class, inherit from the UserControl, Control classes, or from the other Windows Forms provided controls. For more information about authoring custom controls, see Developing Custom Windows Forms Controls with the .NET Framework.
        /// @remarks The Control class implements very basic functionality required by classes that display information to the user. It handles user input through the keyboard and pointing devices. It handles message routing and security. It defines the bounds of a control (its position and size), although it does not implement painting. It provides a window handle (hWnd).
        /// @remarks Windows Forms controls use ambient properties so child controls can appear like their surrounding environment. An ambient property is a control property that, if not set, is retrieved from the parent control. If the control does not have a Parent, and the property is not set, the control attempts to determine the value of the ambient property through the Site property. If the control is not sited, if the site does not support ambient properties, or if the property is not set on the AmbientProperties, the control uses its own default values. Typically, an ambient property represents a characteristic of a control, such as BackColor, that is communicated to a child control. For example, a Button will have the same BackColor as its parent Form by default. Ambient properties provided by the Control class include: Cursor, Font, BackColor, ForeColor, and RightToLeft.
        /// @note To make your Windows Forms application support visual styles, be sure to set the FlatStyle property to System and include a manifest with your executable. A manifest is an XML file that is included either as a resource within your application executable or as a separate file that resides in the same directory as the executable file. For an example of a manifest, see the Example section of the FlatStyle enumeration. For more information about using visual styles, see Visual Styles.
        /// @note Windows Forms has accessibility support built in, and provides information about your application that enables it to work with accessibility client applications such as screen enlarger and reviewer utilities, voice input utilities, on-screen keyboards, alternative input devices, and keyboard enhancement utilities. Sometimes you will want to provide additional information to accessibility client applications. There are two ways of providing this additional information. You can set the AccessibleName, AccessibleDescription, AccessibleDefaultActionDescription, and AccessibleRole property values, which will be reported to accessibility client applications. This method is typically used to provide limited accessibility information for existing controls. Alternatively, you can write your own class deriving from the AccessibleObject or Control.ControlAccessibleObject classes, providing as much accessibility information as needed.
        /// @note To maintain better performance, do not set the size of a control in its constructor. The preferred method is to override the DefaultSize property.
        /// @note Do not add data bindings for a Control in its constructor. Doing so will cause errors in code generation and can cause unwanted behavior.
        /// @note The majority of the controls in the System::Windows::Forms namespace use the underlying Windows common control as a base to build on. For more information about the Windows common controls, see General Control Reference.
        /// @note To identify Windows Forms controls from a separate process, use a standard SendMessage call to pass the WM_GETCONTROLNAME message. WM_GETCONTROLNAME is independent of the language and Windows hierarchy. For more information, see the "Recommended Solution for Windows Forms" topic in Automating Windows Forms::
        /// @note Use the InvokeRequired property to synchronize access to the control from multiple threads. For more information about multithreaded Windows Forms controls, see How to: Make Thread-Safe Calls to Windows Forms Controls
        class pcf_public Control : public System::ComponentModel::Component {
          enum class State;
        public:
          /// @brief Represents a collection of Control objects.
          /// @remarks The Add, Remove, and RemoveAt methods enable you to add and remove individual controls from the collection. You can also use the AddRange or Clear methods to add or remove all the controls from the collection.
          /// @remarks You can determine if a Control is a member of the collection by passing the control into the Contains method. To get the index value of the location of a Control in the collection, pass the control into the IndexOf method. The collection can be copied into an array by calling the CopyTo method.
          /// @par Examples
          /// @code
          /// // Remove the RadioButton control if it exists.
          /// void RemoveButtonClick(const object& sender, const System::EventArgs& e) {
          ///   if (panel1.Controls().Contains(removeButton)) {
          ///     panel1.Controls().Remove(removeButton);
          ///   }
          /// }
          /// @endcode
          class ControlCollection : public System::Collections::Generic::List<ref<Control>> {
          public:
            ControlCollection(ref<Control> parent) : parent(parent) {}

            void Add(const ref<Control>& value) override {
              ChangeParent(value);
              this->System::Collections::Generic::List<ref<Control>>::Add(value);
            }

            void Insert(int32 index, const ref<Control>& value) override {
              ChangeParent(value);
              this->System::Collections::Generic::List<ref<Control>>::Insert(index, value);
            }

            bool Remove(const ref<Control>& value) override {
              RemoveParent(value);
              return this->System::Collections::Generic::List<ref<Control>>::Remove(value);
            }

          private:
            void ChangeParent(ref<Control> value) {
              if (value().data->parent != null)
                value().data->parent().data->controls.Remove(value);
              else if (this->parent().Visible)
                value().CreateControl();
              value().data->parent = this->parent;
            }

            void RemoveParent(ref<Control> value) {value().data->parent = null;}
            ref<Control> parent;
          };

          /// @brief Initializes a new instance of the Control class with default settings.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          Control();

          /// @brief Initializes a new instance of the Control class as a child control, with specific text.
          /// @param parent The Control to be the parent of the control.
          /// @param text The text displayed by the control.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          /// @remarks This version of the Control constructor sets the initial Text property value to the text parameter value. The constructor also adds the control to the parent control's Control::ControlCollection.
          Control(const Control& parent, const string& text) : Control() {
            this->Parent = parent;
            this->Text = text;
          }

          /// @brief Initializes a new instance of the Control class with specific text, size, and location.
          /// @param text The text displayed by the control.
          /// @param left The X position of the control, in pixels, from the left edge of the control's container. The value is assigned to the Left property.
          /// @param top The Y position of the control, in pixels, from the top edge of the control's container. The value is assigned to the Top property.
          /// @param width The height of the control, in pixels. The value is assigned to the Height property.
          /// @param height The width of the control, in pixels. The value is assigned to the Width property.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          /// @remarks This version of the Control constructor sets the initial Text property value to the text parameter value. The initial Size and Location of the control are determined by the left, top, width and height parameter values.
          /// @note To maintain better performance, do not set the size of a control in its constructor. The preferred method is to virtual the DefaultSize property.
          Control(const string& text, int32 left, int32 top, int32 width, int32 height) : Control() {
            this->Text = text;
            this->Bounds = System::Drawing::Rectangle(left, top, width, height);
          }

          /// @brief Initializes a new instance of the Control class as a child control, with specific text, size, and location.
          /// @param parent The Control to be the parent of the control.
          /// @param text The text displayed by the control.
          /// @param left The X position of the control, in pixels, from the left edge of the control's container. The value is assigned to the Left property.
          /// @param top The Y position of the control, in pixels, from the top edge of the control's container. The value is assigned to the Top property.
          /// @param width The height of the control, in pixels. The value is assigned to the Height property.
          /// @param height The width of the control, in pixels. The value is assigned to the Width property.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          /// @remarks This version of the Control constructor sets the initial Text property value to the text parameter value. The constructor also adds the control to the parent control's Control.ControlCollection. The initial Size and Location of the control are determined by the left, top, width and height parameter values.
          /// @note To maintain better performance, do not set the size of a control in its constructor. The preferred method is to virtual the DefaultSize property.
          Control(const Control& parent, const string& text, int32 left, int32 top, int32 width, int32 height) : Control() {
            this->Parent = parent;
            this->Text = text;
          }

          /// @cond
          //Control(const Control& control) : data(control.data) {}
          Control(const Control& control) = delete;
          ~Control() {
            if (this->Parent() != null)
              this->Parent()().data->controls.Remove(*this);
            if (this->data.IsUnique() && this->data->handle)
              this->DestroyHandle();
          }
          /// @endcond

          /// @brief Gets or sets the background color for the control.
          /// @param color A Color that represents the background color of the control. The default is the value of the DefaultBackColor property.
          /// @remarks The BackColor property does not support transparent colors unless the SupportsTransparentBackColor value of System::Windows::Forms::ControlStyles is set to true.
          /// @remarks The BackColor property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a Button will have the same BackColor as its parent Form by default. For more information about ambient properties, see the AmbientProperties class or the Control class overview.
          Property<System::Drawing::Color> BackColor {
            //pcf_get { return !this->data->backColor.HasValue && this->data->parent != null ? this->data->parent().BackColor() : this->data->backColor.GetValueOrDefault(DefaultBackColor); },
            pcf_get{ return this->data->backColor.GetValueOrDefault(DefaultBackColor); },
            pcf_set {
              if (this->data->backColor != value) {
                this->data->backColor = value;
                this->OnBackColorChanged(EventArgs());
              }
            }
          };

          /// @brief Gets or sets the size and location of the control including its nonclient elements, in pixels, relative to the parent control.
          /// @param value A Rectangle in pixels relative to the parent control that represents the size and location of the control including its nonclient elements.
          /// @remarks The bounds of the control include the nonclient elements such as scroll bars, borders, title bars, and menus. The SetBoundsCore method is called to set the Bounds property. The Bounds property is not always changed through its set method so you should override the SetBoundsCore method to ensure that your code is executed when the Bounds property is set.
          Property<System::Drawing::Rectangle> Bounds {
            pcf_get { return Drawing::Rectangle(this->Location(), this->Size()); },
            pcf_set {
              this->Location(value.Location());
              this->Size(value.Size());
            }
          };

          /// @brief Gets the collection of controls contained within the control.
          /// @param controls A Control.ControlCollection representing the collection of controls contained within the control.
          /// @remarks A Control can act as a parent to a collection of controls. For example, when several controls are added to a Form, each of the controls is a member of the Control.ControlCollection assigned to the Controls property of the form, which is derived from the Control class.
          /// @remarks You can manipulate the controls in the Control.ControlCollection assigned to the Controls property by using the methods available in the Control.ControlCollection class.
          /// @remarks When adding several controls to a parent control, it is recommended that you call the SuspendLayout method before initializing the controls to be added. After adding the controls to the parent control, call the ResumeLayout method. Doing so will increase the performance of applications with many controls.
          /// @remarks Use the Controls property to iterate through all controls of a form, including nested controls. Use the GetNextControl method to retrieve the previous or next child control in the tab order. Use the ActiveControl property to get or set the active control of a container control.
          Property<ControlCollection&, ReadOnly> Controls {
            pcf_get->ControlCollection& {return this->data().controls; }
          };

          static Property<System::Drawing::Color, ReadOnly> DefaultBackColor;
          static Property<System::Drawing::Color, ReadOnly> DefaultForeColor;

          Property<System::Drawing::Color> ForeColor {
            pcf_get{ return this->data->foreColor.GetValueOrDefault(DefaultForeColor); },
            pcf_set {
              if (this->data->foreColor != value) {
                this->data->foreColor = value;
                this->OnForeColorChanged(EventArgs());
              }
            }
          };

          /// @brief Gets the window handle that the control is bound to.
          /// @return intptr An IntPtr that contains the window handle (HWND) of the control.
          /// @remarks The value of the Handle property is a Windows HWND. If the handle has not yet been created, referencing this property will force the handle to be created.
          Property<intptr, ReadOnly> Handle {
            pcf_get {
              if (this->data->handle == 0)
                CreateHandle();
              return this->data->handle;
            }
          };

          /// @brief Gets or sets the height of the control.
          /// @return int32 The height of the control in pixels.
          /// @remarks Changes made to the Height and Top property values cause the Bottom property value of the control to change.
          /// @note The minimum height for the derived control Splitter is one pixel. The default height for the Splitter control is three pixels. Setting the height of the Splitter control to a value less than one will reset the property value to the default height.
          Property<int32> Height {
            pcf_get { return this->data->size.Height(); },
            pcf_set { this->Size(System::Drawing::Size(this->data->size.Width(), value)); }
          };

          Property<bool, ReadOnly> IsHandleCreated {
            pcf_get { return this->data->handle != 0; }
          };

          /// @brief Gets or sets the coordinates of the upper-left corner of the control relative to the upper-left corner of its container.
          /// @return System::Drawing::Point The Point that represents the upper-left corner of the control relative to the upper-left corner of its container.
          /// @remarks Because the Point class is returned by value, meaning accessing the property returns a copy of the upper-left point of the control. So, adjusting the X or Y properties of the Point returned from this property will not affect the Left, Right, Top, or Bottom property values of the control. To adjust these properties set each property value individually, or set the Location property with a new Point.
          /// @remarks If the Control is a Form, the Location property value represents the upper-left corner of the Form in screen coordinates.
          Property<System::Drawing::Point> Location {
            pcf_get { return this->data->location; },
            pcf_set {
            if (this->data->location != value) {
              this->data->location = value;
              this->OnLocationChanged(EventArgs());
            }
          }
          };

          /// @brief Gets or sets the name of the control.
          /// @return string The name of the control. The default is an empty string ("").
          /// @remarks The Name property can be used at run time to evaluate the object by name rather than type and programmatic name.
          Property<string> Name {
            pcf_get { return this->data->name; },
            pcf_set {
            if (this->data->name != value) {
              this->data->name = value;
              this->OnNameChanged(EventArgs());
            }
          }
          };

          /// @brief Gets or sets the parent container of the control.
          /// @return Control A Control that represents the parent or container control of the control.
          /// @remarks Setting the Parent property value to null removes the control from the Control.ControlCollection of its current parent control.
          Property<ref<Control>> Parent {
            pcf_get { return this->data->parent; },
            pcf_set {
              if (this->data->parent != value) {
                if (value == null && this->data->parent != null)
                  this->data->parent().data->controls.Remove(*this);
                else
                  const_cast<Control&>(value()).data->controls.Add(*this);
                this->OnParentChanged(EventArgs());
              }
            }
          };

          /// @brief Gets or sets the height and width of the control.
          /// @return System::Drawing::Size The Size that represents the height and width of the control in pixels.
          /// @remarks Because the Size class is returned by value, meaning accessing the property returns a copy of the size of the control. So, adjusting the Width or Height properties of the Size returned from this property will not affect the Width or Height of the control. To adjust the Width or Height of the control, you must set the control's Width or Height property, or set the Size property with a new Size.
          /// @note To maintain better performance, do not set the Size of a control in its constructor. The preferred method is to override the DefaultSize property.
          Property<System::Drawing::Size> Size {
            pcf_get { return this->data->size; },
            pcf_set {
            if (this->data->size != value) {
              this->data->size = value;
              this->OnSizeChanged(EventArgs());
            }
          }
          };

          /// @brief Gets or sets the text associated with this control.
          /// @return string The text associated with this control.
          /// @remarks The Text property of the control is used differently by each derived class. For example the Text property of a Form is displayed in the title bar at the top of the form, is fairly small in character count, and usually displays the application or document name. However, the Text property of a RichTextBox can be large and can include numerous nonvisual characters used to format the text. For example, the text displayed in a RichTextBox can be formatted by adjusting the Font properties, or by the addition of spaces or tab characters to align the text.
          /// @note When overriding the Text property in a derived class, use the base class's Text property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and setaccessors of the Text property; you can override only one if needed.
          Property<const string&> Text {
            pcf_get->const string& { return this->GetText(); },
            pcf_set { this->SetText(value); }
          };

          Property<bool> Visible {
            pcf_get { return this->data->visible; },
            pcf_set {
              if (this->data->visible != value) {
                this->data->visible = value;
                this->OnVisibleChanged(EventArgs());
              }
            }
          };

          Property<int32> Width {
            pcf_get { return this->data->size.Width(); },
            pcf_set { this->Size(System::Drawing::Size(value, this->data->size.Height())); }
          };

          void CreateControl() {
            if (this->data->size.IsEmpty())
              this->data->size = this->DefaultSize;
            if (this->data->visible && !this->IsHandleCreated)
              CreateHandle();
            for (ref<Control> control : this->data->controls)
              control().CreateControl();
            OnCreateControl();
          }

          static const ref<Control> FromHandle(intptr handle) {
            if (handles.ContainsKey(handle))
              return handles[handle];
            return ref<Control>::Null();
          }

          void Invalidate() { Invalidate(false); }

          void Invalidate(bool invalidateChildren);

          void Invalidate(const System::Drawing::Rectangle& rect) { Invalidate(rect, false); }

          void Invalidate(const System::Drawing::Rectangle& rect, bool invalidateChildren);

          System::Drawing::Point PointToClient(System::Drawing::Point point) const;

          System::Drawing::Point PointToScreen(System::Drawing::Point point) const;

          bool PreProcessMessage(const Message& msg);

          virtual void WndProc(Message& message);

          InvalidateEventHandler Invalidated;
          EventHandler BackColorChanged;
          EventHandler Click;
          EventHandler DoubleClick;
          EventHandler ForeColorChanged;
          EventHandler HandleCreated;
          EventHandler HandleDestroyed;
          EventHandler LocationChanged;
          EventHandler LostFocus;
          EventHandler MouseCaptureChanged;
          MouseEventHandler MouseClick;
          MouseEventHandler MouseDoubleClick;
          MouseEventHandler MouseDown;
          EventHandler MouseEnter;
          EventHandler MouseHover;
          EventHandler MouseLeave;
          MouseEventHandler MouseMove;
          MouseEventHandler MouseUp;
          MouseEventHandler MouseWheel;
          EventHandler NameChanged;
          PaintEventHandler Paint;
          EventHandler ParentChanged;
          EventHandler SizeChanged;
          EventHandler TextChanged;
          EventHandler VisibleChanged;

        protected:
          Property<System::Drawing::Size, ReadOnly> DefaultSize {
            pcf_get { return this->GetDefaultSize(); }
          };

          virtual void CreateHandle();

          virtual void DefWndProc(Message& message);

          virtual void DestroyHandle();

          virtual System::Drawing::Size GetDefaultSize() const { return System::Drawing::Size(0, 0); }

          bool GetStyle(ControlStyles flag) { return ((int32)this->data->style & (int32)flag) == (int32)flag; }

          virtual const string& GetText() const { return this->data->text; }

          virtual void OnCreateControl() {}

          virtual void OnBackColorChanged(const EventArgs& e);

          virtual void OnClick(const EventArgs& e) { this->Click(*this, e); }

          virtual void OnDoubleClick(const EventArgs& e) { this->DoubleClick(*this, e); }

          virtual void OnForeColorChanged(const EventArgs& e);

          virtual void OnHandleCreated(const EventArgs& e) { this->HandleCreated(*this, e); }

          virtual void OnHandleDestroyed(const EventArgs& e) { this->HandleDestroyed(*this, e); }

          virtual void OnInvalidated(const InvalidateEventArgs& e) { this->Invalidated(*this, e); }

          virtual void OnLocationChanged(const EventArgs& e);

          virtual void OnLostFocus(const EventArgs& e) { this->LostFocus(*this, e); }

          virtual void OnMouseCaptureChanged(const EventArgs& e) { this->MouseCaptureChanged(*this, e); }

          virtual void OnMouseClick(const MouseEventArgs& e) { this->MouseClick(*this, e); }

          virtual void OnMouseDoubleClick(const MouseEventArgs& e) { this->MouseDoubleClick(*this, e); }

          virtual void OnMouseDown(const MouseEventArgs& e) { this->MouseDown(*this, e); }

          virtual void OnMouseEnter(const EventArgs& e) { this->MouseEnter(*this, e); }

          virtual void OnMouseHover(const EventArgs& e) { this->MouseHover(*this, e); }

          virtual void OnMouseLeave(const EventArgs& e) { this->MouseLeave(*this, e); }

          virtual void OnMouseMove(const MouseEventArgs& e) { this->MouseMove(*this, e); }

          virtual void OnMouseUp(const MouseEventArgs& e) { this->MouseUp(*this, e); }

          virtual void OnMouseWheel(const MouseEventArgs& e) { this->MouseWheel(*this, e); }

          virtual void OnNameChanged(const EventArgs& e) { this->NameChanged(*this, e); }

          virtual void OnPaint(PaintEventArgs& e) { this->Paint(*this, e); }

          virtual void OnParentChanged(const EventArgs& e) { this->ParentChanged(*this, e); }

          virtual void OnSizeChanged(const EventArgs& e);

          virtual void OnTextChanged(const EventArgs& e);

          virtual void OnVisibleChanged(const EventArgs& e);

          void SetStyle(ControlStyles flag, bool value) { this->data->style = value ? (ControlStyles)((int32)this->data->state | (int32)flag) : (ControlStyles)((int32)this->data->style & ~(int32)flag); }

          virtual void SetText(const string& value) {
            if (this->data->text != value) {
              this->data->text = value;
              this->OnTextChanged(EventArgs());
            }
          }

          /// @cond
          struct ControlData {
            ControlData(ref<Control> control) : controls(control) {}
            Nullable<System::Drawing::Color> backColor;
            System::Drawing::SolidBrush backBrush {System::Drawing::SystemColors::Control};
            ControlCollection controls;
            System::Drawing::Color defaultBackColor;
            System::Drawing::Color defaultForeColor;
            Nullable<System::Drawing::Color> foreColor;
            intptr handle = 0;
            System::Drawing::Point location;
            string name;
            ref<Control> parent;
            System::Drawing::Size size;
            string text;
            bool visible = true;
            System::Collections::Generic::Dictionary<int32, Action<Message&>> messageActions;
            State state = State::Empty;
            ControlStyles style = (ControlStyles)0;
          };
          friend class __OS::FormsApi;
          refptr<ControlData> data = pcf_new<ControlData>(*this);
          static System::Collections::Generic::Dictionary<intptr, ref<Control>> handles;
          /// @endcond

        private:
          void WmCaptureChange(Message& message);
          void WmClose(Message& message);
          void WmCommand(Message& message);
          void WmContextMenu(Message& message);
          void WmCreate(Message& message);
          void WmCtlColorControl(Message& message);
          void WmDestroy(Message& message);
          void WmDisplayChange(Message& message);
          void WmDrawItem(Message& message);
          void WmEraseBkgnd(Message& message);
          void WmExitMenuLoop(Message& message);
          void WmGetObject(Message& message);
          void WmHelp(Message& message);
          void WmImeChar(Message& message);
          void WmImeNotify(Message& message);
          void WmImeStartComposition(Message& message);
          void WmInitMenuPopup(Message& message);
          void WmInputLangChange(Message& messsage);
          void WmInputLangChangeRequest(Message& messsage);
          void WmKeyChar(Message& messsage);
          void WmKillFocus(Message& message);
          void WmMeasureItem(Message& message);
          void WmMenuChar(Message& message);
          void WmMenuSelect(Message& message);
          void WmMouseDown(Message& message);
          void WmMouseEnter(Message& message);
          void WmMouseHover(Message& message);
          void WmMouseLeave(Message& message);
          void WmMouseMove(Message& message);
          void WmMouseUp(Message& message);
          void WmMouseWheel(Message& message);
          void WmNotify(Message& message);
          void WmNotifyFormat(Message& message);
          void WmPaint(Message& message);
          void WmParentNotify(Message& message);
          void WmPrintClient(Message& message);
          void WmQueryNewPalette(Message& message);
          void WmShowWindow(Message& message);
          void WmSetCursor(Message& message);
          void WmSetFocus(Message& message);
          void WmSysCommand(Message& message);
          void WmUpdateUIState(Message& message);
          void WmWindowPosChanged(Message& message);
          void WmWindowPosChanging(Message& message);

          System::Drawing::Rectangle GetClientRectangle() const;
          bool GetState(State flag) const { return ((int32)this->data->state & (int32)flag) == (int32)flag; }
          void SetState(State flag, bool value) { this->data->state = value ? (State)((int32)this->data->state | (int32)flag) : (State)((int32)this->data->state & ~(int32)flag); }

          enum class State {
            Empty = 0,
            DoubleClickFired = 0b1,
            MouseEntered = 0x10,
          };

          static ref<Control> controlEntered;
        };
      }
    }
  }
}
