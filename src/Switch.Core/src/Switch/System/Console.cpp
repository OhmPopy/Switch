#include <cstdio>
#include <cstring>
#include <cwchar>
#include <iostream>

#include "../../../include/Switch/System/IO/IOException.hpp"
#include "../../../include/Switch/System/Buffer.hpp"
#include "../../../include/Switch/System/Console.hpp"
#include "../../../include/Switch/System/Environment.hpp"
#include "../../../include/Switch/System/Text/UTF8Encoding.hpp"
#include "../../Native/Api.hpp"

namespace {
  // This hack is necessary in windows because std::cout does not work properly with Utf8 and unicode code page
  // Moreover std::cout on Windows is very slow.
  // printf work correctly...
  std::ostream& operator<<(std::ostream& output, const char* value) {
    printf("%s", value);
    return output;
  }
  
  refptr<System::Text::Encoding> inputEncoding = ref_new<System::Text::UTF8Encoding>(false);
  refptr<System::Text::Encoding> outputEncoding = ref_new<System::Text::UTF8Encoding>(false);
  
  bool treatControlCAsInput = false;
}

using namespace System;

void Console::StandardErrorOutput::Write(const System::String& s) {
  if (outputEncoding->GetCodePage() == 65001) // Utf8
    std::cerr << (const char*)s.Data();
  else if (outputEncoding->IsSingleByte()) // Ascii
    std::cerr << s.ToCCharArray(outputEncoding->GetCodePage()).Data();
  else if (outputEncoding->GetCodePage() == 1200) { // Unicode
    System::Array<byte> bytes = outputEncoding->GetBytes(s);
    System::Array<char16> str(bytes.Length + 1);
    Buffer::BlockCopy(bytes, 0, str, 0, bytes.Length);
    str[bytes.Length] = 0;
    std::wcerr << str.Data();
  } else { // Utf32
    System::Array<byte> bytes = outputEncoding->GetBytes(s);
    System::Array<char32> str(bytes.Length + 1);
    Buffer::BlockCopy(bytes, 0, str, 0, bytes.Length);
    str[bytes.Length] = 0;
    std::wcerr << str.Data();
  }
}

void Console::StandardOutput::Write(const System::String& s) {
  if (outputEncoding->GetCodePage() == 65001) // Utf8
    std::cout << (const char*)s.Data();
  else if (outputEncoding->IsSingleByte()) // Ascii
    std::cout << s.ToCCharArray(outputEncoding->GetCodePage()).Data();
  else if (outputEncoding->GetCodePage() == 1200) { // Unicode
    int32 length = outputEncoding->GetByteCount(s);
    System::Array<char16> str(length + 1);
    outputEncoding->GetBytes(s, (byte*)str.Data(), length);
    str[length] = 0;
    std::wcout << str.Data();
  } else { // Utf32
    int32 length = outputEncoding->GetByteCount(s);
    System::Array<char32> str(length + 1);
    outputEncoding->GetBytes(s, (byte*)str.Data(), length);
    str[length] = 0;
    std::wcout << str.Data();
  }
}

namespace {
  Console::StandardInput sin;
  Console::StandardErrorOutput serror;
  Console::StandardOutput sout;
  System::IO::TextReader* defaultIn = &sin;
  System::IO::TextWriter* defaultError = &serror;
  System::IO::TextWriter* defaultOut = &sout;
  System::IO::TextReader* in = &sin;
  System::IO::TextWriter* error = &serror;
  System::IO::TextWriter* out = &sout;
}

_property<ConsoleColor> Console::BackgroundColor {
  [] {return Native::ConsoleApi::GetBackgroundColor();},
  [](ConsoleColor value) {
    if (!Enum<ConsoleColor>::IsDefined(value))
      throw ArgumentException(_caller);
    if (!Native::ConsoleApi::SetBackgroundColor(value))
      throw System::IO::IOException(_caller);
  }
};

_property<int32> Console::BufferHeight{
  [] {return Native::ConsoleApi::GetBufferHeight(); },
  [](int32 value) {
    Native::ConsoleApi::SetBufferHeight(value);
  }
};

_property<int32> Console::BufferWidth{
  [] {return Native::ConsoleApi::GetBufferWidth(); },
  [](int32 value) {
    Native::ConsoleApi::SetBufferWidth(value);
  }
};

_property<bool, _readonly> Console::CapsLock {
  [] {return Native::ConsoleApi::GetCapsLock();}
};

_property<int32> Console::CursorLeft {
  [] {return Native::ConsoleApi::GetCursorLeft();},
  [](int32 value) {
    if (value < 0 || value >= Native::ConsoleApi::GetWindowWidth())
      throw ArgumentOutOfRangeException(_caller);
      
    Native::ConsoleApi::SetCursorLeft(value);
  }
};

_property<int32> Console::CursorSize {
  [] {return Native::ConsoleApi::GetCursorSize();},
  [](int32 value) {
    if (value < 1 || value > 100)
      throw ArgumentOutOfRangeException(_caller);
      
    Native::ConsoleApi::SetCursorSize(value);
  }
};

_property<int32> Console::CursorTop {
  [] {return Native::ConsoleApi::GetCursorTop();},
  [](int32 value) {
    if (value < 0 || value >= Native::ConsoleApi::GetBufferHeight())
      throw ArgumentOutOfRangeException(_caller);
      
    Native::ConsoleApi::SetCursorTop(value);
  }
};

_property<bool> Console::CursorVisible {
  [] {return Native::ConsoleApi::GetCursorVisible();},
  [](bool value) {Native::ConsoleApi::SetCursorVisible(value);}
};

_property<Console::StandardErrorOutput&, _readonly> Console::Error {
  []()->Console::StandardErrorOutput& {
    static StandardErrorOutput e;
    return e;
  }
};

_property<ConsoleColor> Console::ForegroundColor {
  [] {return Native::ConsoleApi::GetForegroundColor();},
  [](ConsoleColor value) {
    if (!Enum<ConsoleColor>::IsDefined(value))
      throw ArgumentException(_caller);
    Native::ConsoleApi::SetForegroundColor(value);
  }
};

_property<Console::StandardInput&, _readonly> Console::In {
  []()->Console::StandardInput& {
    static StandardInput i;
    return i;
  }
};

_property<const refptr<System::Text::Encoding>&> Console::InputEncoding {
  []()->const refptr<System::Text::Encoding>& {return inputEncoding;},
  [](const refptr<System::Text::Encoding>& value) {
    inputEncoding = value;
    Native::ConsoleApi::SetInputCodePage(inputEncoding->GetCodePage());
  }
};

_property<bool, _readonly> Console::IsErrorRedirected{
  [] {return error != defaultError; }
};

_property<bool, _readonly> Console::IsInputRedirected{
  [] {return in != defaultIn; }
};

_property<bool, _readonly> Console::IsOutputRedirected{
  [] {return out != defaultOut; }
};

_property<bool, _readonly> Console::KeyAvailable {
  [] {
    Console::__f();
    return Native::ConsoleApi::KeyAvailable();
  }
};

_property<int32, _readonly> Console::LargestWindowHeight{
  [] {return Native::ConsoleApi::GetLargestWindowHeight(); }
};

_property<int32, _readonly> Console::LargestWindowWidth{
  [] {return Native::ConsoleApi::GetLargestWindowWidth(); }
};

_property<bool, _readonly> Console::NumberLock{
  [] {return Native::ConsoleApi::GetNumberLock(); }
};

_property<Console::StandardOutput&, _readonly> Console::Out {
  []()->Console::StandardOutput& {
    static StandardOutput o;
    return o;
  }
};

_property<const refptr<System::Text::Encoding>&> Console::OutputEncoding {
  []()->const refptr<System::Text::Encoding>& {return outputEncoding;},
  [](const refptr<System::Text::Encoding>& value) {
    outputEncoding = value;
    Native::ConsoleApi::SetOutputCodePage(outputEncoding->GetCodePage());
  }
};

_property<string> Console::Title {
  [] {return Native::ConsoleApi::GetTitle(); },
  [](const string & value) {Native::ConsoleApi::SetTitle(value);}
};

_property<bool> Console::TreatControlCAsInput {
  [] {return treatControlCAsInput;},
  [](bool value) {treatControlCAsInput = value;}
};

_property<int32> Console::WindowHeight {
  []{return Native::ConsoleApi::GetWindowHeight(); },
  [](int32 value) {
    Native::ConsoleApi::SetWindowHeight(value);
  }
};

_property<int32> Console::WindowLeft {
  []{return Native::ConsoleApi::GetWindowLeft(); },
  [](int32 value) {
    Native::ConsoleApi::SetWindowLeft(value);
  }
};

_property<int32> Console::WindowTop {
  []{return Native::ConsoleApi::GetWindowTop(); },
  [](int32 value) {
    Native::ConsoleApi::SetWindowTop(value);
  }
};

_property<int32> Console::WindowWidth {
  [] {return Native::ConsoleApi::GetWindowWidth(); },
  [](int32 value) {
    Native::ConsoleApi::SetWindowWidth(value);
  }
};

ConsoleCancelEventHandler Console::CancelKeyPress;

void Console::Beep(int32 frequency, int32 duration) {
  if (frequency < 37 || frequency > 32767 || duration <= 0)
    throw ArgumentOutOfRangeException(_caller);
    
  Native::ConsoleApi::Beep(frequency, duration);
}

void Console::Clear() {
  Native::ConsoleApi::Clrscr();
}

void Console::MoveBufferArea(int32 sourceLeft, int32 sourceTop, int32 sourceWidth, int32 sourceHeight, int32 targetLeft, int32 targetTop, char32 sourceChar, ConsoleColor sourceForeColor, ConsoleColor sourceBackColor) {

}


int32 Console::Read() {
  out->Flush();
  return in->Read();
}

struct AutoEchoVisible {
  AutoEchoVisible() {Native::ConsoleApi::SetEchoVisible(true);}
  ~AutoEchoVisible() {Native::ConsoleApi::SetEchoVisible(false);}
};

String Console::ReadLine() {
  AutoEchoVisible autoEchoVisible;
  out->Flush();
  return in->ReadLine();
}

ConsoleKeyInfo Console::ReadKey() {
  return ReadKey(false);
}

ConsoleKeyInfo Console::ReadKey(bool intercept) {
  int32 KeyChar = 0;
  int32 KeyCode = 0;
  bool alt = false;
  bool shift = false;
  bool ctrl = false;
  ConsoleKeyInfo keyInfo;
  
  out->Flush();
  Native::ConsoleApi::ReadKey(KeyChar, KeyCode, alt, shift, ctrl);
  keyInfo = ConsoleKeyInfo(KeyChar, (ConsoleKey)KeyCode, shift, alt, ctrl);
  
  if (intercept == false)
    Write(Char(keyInfo.KeyChar()));
    
  return keyInfo;
}

void Console::ResetColor() {
  Native::ConsoleApi::ResetColor();
}

void Console::SetError(System::IO::TextWriter& e) { error = &e; }

void Console::SetInt(System::IO::TextReader& i) { in = &i; }

void Console::SetOut(System::IO::TextWriter& o) { out = &o; }


void Console::Write(bool value) {
  Write(string::Format("{0}", value));
}

void Console::Write(char value) {
  Write(string::Format("{0}", value));
}

void Console::Write(char16 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(char32 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(wchar value) {
  Write(string::Format("{0}", value));
}

void Console::Write(double value) {
  Write(string::Format("{0}", value));
}

void Console::Write(int32 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(int64 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(const object& value) {
  Write(string::Format("{0}", value.ToString()));
}

void Console::Write(float value) {
  Write(string::Format("{0}", value));
}

void Console::Write(const String& value) {
  _lock(*out)
  out->Write(value);
}

void Console::Write(uint32 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(uint64 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(const char value[]) {
  Write(string::Format("{0}", value));
}

void Console::Write(const char16 value[]) {
  Write(string::Format("{0}", value));
}

void Console::Write(const char32 value[]) {
  Write(string::Format("{0}", value));
}

void Console::Write(const wchar value[]) {
  Write(string::Format("{0}", value));
}

void Console::Write(llong value) {
  Write(String::Format("{0}", value));
}

void Console::Write(ullong value) {
  Write(String::Format("{0}", value));
}

void Console::Write(unsigned char* value) {
  Write(String::Format("{0}", value));
}

void Console::WriteLine() {
  Write(string::Format("{0}", Environment::NewLine));
}

void Console::WriteLine(bool value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(char value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(char16 value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(char32 value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(wchar value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(double value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(int32 value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(int64 value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(const object& value) {
  Write(string::Format("{0}{1}", value.ToString(), Environment::NewLine));
}

void Console::WriteLine(float value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(const String& value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(uint32 value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(uint64 value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(llong value) {
  Write(String::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(ullong value) {
  Write(String::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(const char value[]) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(const char16 value[]) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(const char32 value[]) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(const wchar value[]) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::__f() {
  out->Flush();
}
