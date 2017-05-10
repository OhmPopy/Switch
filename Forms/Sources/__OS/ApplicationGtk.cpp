#if (defined(__linux__) && defined(__use_native_interface__)) || defined(__use_gtk_interface__)

#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include "WidgetGtk.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace {
  Glib::RefPtr<Gtk::Application> application = Gtk::Application::create();
  int32 exitCode = 0;
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::Exit() {
  Environment::Exit(exitCode);
}

void FormsApi::Application::MessageLoop(const System::Windows::Forms::Form& mainForm, EventHandler idle) {
  exitCode = application->run(as<Gtk::Window>(((__OS::IWidget*)mainForm.Handle())->ToWidget()));
}

void FormsApi::Application::MessageBeep(MessageBoxIcon type) {
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  return DialogResult::Cancel;
}

void FormsApi::Application::Start() {

}

void FormsApi::Application::Stop() {

}

#endif
