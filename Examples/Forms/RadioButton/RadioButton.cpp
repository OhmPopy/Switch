#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace FormExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->radioButton1.Text = "radioButton 1";
      this->radioButton1.Location = System::Drawing::Point(30, 30);
      this->radioButton1.Checked = true;
      this->radioButton1.Parent = *this;
      
      this->radioButton2.Text = "radioButton 2";
      this->radioButton2.Location = System::Drawing::Point(30, 60);
      this->radioButton2.Parent = *this;
      
      this->radioButton3.Text = "radioButton 3";
      this->radioButton3.Location = System::Drawing::Point(30, 90);
      this->radioButton3.Parent = *this;
      
      this->Text = "RadioButton example";
    }
    
  private:
    RadioButton radioButton1;
    RadioButton radioButton2;
    RadioButton radioButton3;
  };
}

pcf_startup (FormExample::Form1)
