/// @file
/// @brief Contains Switch::System::Windows::Forms::Shortcut enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies shortcut keys that can be used by menu items.
        enum class Shortcut {
          Alt0 = 262192,
          Alt1,
          Alt2,
          Alt3,
          Alt4,
          Alt5,
          Alt6,
          Alt7,
          Alt8,
          Alt9,
          AltBksp = 262152,
          AltDownArrow = 262184,
          AltF1 = 262256,
          AltF10 = 262265,
          AltF11,
          AltF12,
          AltF2 = 262257,
          AltF3,
          AltF4,
          AltF5,
          AltF6,
          AltF7,
          AltF8,
          AltF9,
          AltLeftArrow = 262181,
          AltRightArrow = 262183,
          AltUpArrow = 262182,
          Cmd0 = 131120,
          Cmd1,
          Cmd2,
          Cmd3,
          Cmd4,
          Cmd5,
          Cmd6,
          Cmd7,
          Cmd8,
          Cmd9,
          CmdA = 131137,
          CmdB,
          CmdC,
          CmdD,
          CmdDel = 131118,
          CmdE = 131141,
          CmdF,
          CmdF1 = 131184,
          CmdF10 = 131193,
          CmdF11,
          CmdF12,
          CmdF2 = 131185,
          CmdF3,
          CmdF4,
          CmdF5,
          CmdF6,
          CmdF7,
          CmdF8,
          CmdF9,
          CmdG = 131143,
          CmdH,
          CmdI,
          CmdIns = 131117,
          CmdJ = 131146,
          CmdK,
          CmdL,
          CmdM,
          CmdN,
          CmdO,
          CmdP,
          CmdQ,
          CmdR,
          CmdS,
          CmdShift0 = 196656,
          CmdShift1,
          CmdShift2,
          CmdShift3,
          CmdShift4,
          CmdShift5,
          CmdShift6,
          CmdShift7,
          CmdShift8,
          CmdShift9,
          CmdShiftA = 196673,
          CmdShiftB,
          CmdShiftC,
          CmdShiftD,
          CmdShiftE,
          CmdShiftF,
          CmdShiftF1 = 196720,
          CmdShiftF10 = 196729,
          CmdShiftF11,
          CmdShiftF12,
          CmdShiftF2 = 196721,
          CmdShiftF3,
          CmdShiftF4,
          CmdShiftF5,
          CmdShiftF6,
          CmdShiftF7,
          CmdShiftF8,
          CmdShiftF9,
          CmdShiftG = 196679,
          CmdShiftH,
          CmdShiftI,
          CmdShiftJ,
          CmdShiftK,
          CmdShiftL,
          CmdShiftM,
          CmdShiftN,
          CmdShiftO,
          CmdShiftP,
          CmdShiftQ,
          CmdShiftR,
          CmdShiftS,
          CmdShiftT,
          CmdShiftU,
          CmdShiftV,
          CmdShiftW,
          CmdShiftX,
          CmdShiftY,
          CmdShiftZ,
          CmdT = 131156,
          CmdU,
          CmdV,
          CmdW,
          CmdX,
          CmdY,
          CmdZ,
          Del = 46,
          F1 = 112,
          F10 = 121,
          F11,
          F12,
          F2 = 113,
          F3,
          F4,
          F5,
          F6,
          F7,
          F8,
          F9,
          Ins = 45,
          None = 0,
          ShiftDel = 65582,
          ShiftF1 = 65648,
          ShiftF10 = 65657,
          ShiftF11,
          ShiftF12,
          ShiftF2 = 65649,
          ShiftF3,
          ShiftF4,
          ShiftF5,
          ShiftF6,
          ShiftF7,
          ShiftF8,
          ShiftF9,
          ShiftIns = 65581
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::Forms::Shortcut> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::Shortcut::Alt0, "Alt0"}, {(int64)System::Windows::Forms::Shortcut::Alt1, "Alt1"}, {(int64)System::Windows::Forms::Shortcut::Alt2, "Alt2"}, {(int64)System::Windows::Forms::Shortcut::Alt3, "Alt3"}, {(int64)System::Windows::Forms::Shortcut::Alt4, "Alt4"}, {(int64)System::Windows::Forms::Shortcut::Alt5, "Alt5"}, {(int64)System::Windows::Forms::Shortcut::Alt6, "Alt6"}, {(int64)System::Windows::Forms::Shortcut::Alt7, "Alt7"}, {(int64)System::Windows::Forms::Shortcut::Alt8, "Alt8"}, {(int64)System::Windows::Forms::Shortcut::Alt9, "Alt9"}, {(int64)System::Windows::Forms::Shortcut::AltBksp, "AltBksp"}, {(int64)System::Windows::Forms::Shortcut::AltDownArrow, "AltDownArrow"}, {(int64)System::Windows::Forms::Shortcut::AltF1, "AltF1"}, {(int64)System::Windows::Forms::Shortcut::AltF10, "AltF10"}, {(int64)System::Windows::Forms::Shortcut::AltF11, "AltF11"}, {(int64)System::Windows::Forms::Shortcut::AltF12, "AltF12"}, {(int64)System::Windows::Forms::Shortcut::AltF2, "AltF2"}, {(int64)System::Windows::Forms::Shortcut::AltF3, "AltF3"}, {(int64)System::Windows::Forms::Shortcut::AltF4, "AltF4"}, {(int64)System::Windows::Forms::Shortcut::AltF5, "AltF5"}, {(int64)System::Windows::Forms::Shortcut::AltF6, "AltF6"}, {(int64)System::Windows::Forms::Shortcut::AltF7, "AltF7"}, {(int64)System::Windows::Forms::Shortcut::AltF8, "AltF8"}, {(int64)System::Windows::Forms::Shortcut::AltF9, "AltF9"}, {(int64)System::Windows::Forms::Shortcut::AltLeftArrow, "AltLeftArrow"}, {(int64)System::Windows::Forms::Shortcut::AltRightArrow, "AltRightArrow"}, {(int64)System::Windows::Forms::Shortcut::AltUpArrow, "AltUpArrow"}, {(int64)System::Windows::Forms::Shortcut::Cmd0, "Cmd0"}, {(int64)System::Windows::Forms::Shortcut::Cmd1, "Cmd1"}, {(int64)System::Windows::Forms::Shortcut::Cmd2, "Cmd2"}, {(int64)System::Windows::Forms::Shortcut::Cmd3, "Cmd3"}, {(int64)System::Windows::Forms::Shortcut::Cmd4, "Cmd4"}, {(int64)System::Windows::Forms::Shortcut::Cmd5, "Cmd5"}, {(int64)System::Windows::Forms::Shortcut::Cmd6, "Cmd6"}, {(int64)System::Windows::Forms::Shortcut::Cmd7, "Cmd7"}, {(int64)System::Windows::Forms::Shortcut::Cmd8, "Cmd8"}, {(int64)System::Windows::Forms::Shortcut::Cmd9, "Cmd9"}, {(int64)System::Windows::Forms::Shortcut::CmdA, "CmdA"}, {(int64)System::Windows::Forms::Shortcut::CmdB, "CmdB"}, {(int64)System::Windows::Forms::Shortcut::CmdC, "CmdC"}, {(int64)System::Windows::Forms::Shortcut::CmdD, "CmdD"}, {(int64)System::Windows::Forms::Shortcut::CmdDel, "CmdDel"}, {(int64)System::Windows::Forms::Shortcut::CmdE, "CmdE"}, {(int64)System::Windows::Forms::Shortcut::CmdF, "CmdF"}, {(int64)System::Windows::Forms::Shortcut::CmdF1, "CmdF1"}, {(int64)System::Windows::Forms::Shortcut::CmdF10, "CmdF10"}, {(int64)System::Windows::Forms::Shortcut::CmdF11, "CmdF11"}, {(int64)System::Windows::Forms::Shortcut::CmdF12, "CmdF12"}, {(int64)System::Windows::Forms::Shortcut::CmdF2, "CmdF2"}, {(int64)System::Windows::Forms::Shortcut::CmdF3, "CmdF3"}, {(int64)System::Windows::Forms::Shortcut::CmdF4, "CmdF4"}, {(int64)System::Windows::Forms::Shortcut::CmdF5, "CmdF5"}, {(int64)System::Windows::Forms::Shortcut::CmdF6, "CmdF6"}, {(int64)System::Windows::Forms::Shortcut::CmdF7, "CmdF7"}, {(int64)System::Windows::Forms::Shortcut::CmdF8, "CmdF8"}, {(int64)System::Windows::Forms::Shortcut::CmdF9, "CmdF9"}, {(int64)System::Windows::Forms::Shortcut::CmdG, "CmdG"}, {(int64)System::Windows::Forms::Shortcut::CmdH, "CmdH"}, {(int64)System::Windows::Forms::Shortcut::CmdI, "CmdI"}, {(int64)System::Windows::Forms::Shortcut::CmdIns, "CmdIns"}, {(int64)System::Windows::Forms::Shortcut::CmdJ, "CmdJ"}, {(int64)System::Windows::Forms::Shortcut::CmdK, "CmdK"}, {(int64)System::Windows::Forms::Shortcut::CmdL, "CmdL"}, {(int64)System::Windows::Forms::Shortcut::CmdM, "CmdM"}, {(int64)System::Windows::Forms::Shortcut::CmdN, "CmdN"}, {(int64)System::Windows::Forms::Shortcut::CmdO, "CmdO"}, {(int64)System::Windows::Forms::Shortcut::CmdP, "CmdP"}, {(int64)System::Windows::Forms::Shortcut::CmdQ, "CmdQ"}, {(int64)System::Windows::Forms::Shortcut::CmdR, "CmdR"}, {(int64)System::Windows::Forms::Shortcut::CmdS, "CmdS"}, {(int64)System::Windows::Forms::Shortcut::CmdShift0, "CmdShift0"}, {(int64)System::Windows::Forms::Shortcut::CmdShift1, "CmdShift1"}, {(int64)System::Windows::Forms::Shortcut::CmdShift2, "CmdShift2"}, {(int64)System::Windows::Forms::Shortcut::CmdShift3, "CmdShift3"}, {(int64)System::Windows::Forms::Shortcut::CmdShift4, "CmdShift4"}, {(int64)System::Windows::Forms::Shortcut::CmdShift5, "CmdShift5"}, {(int64)System::Windows::Forms::Shortcut::CmdShift6, "CmdShift6"}, {(int64)System::Windows::Forms::Shortcut::CmdShift7, "CmdShift7"}, {(int64)System::Windows::Forms::Shortcut::CmdShift8, "CmdShift8"}, {(int64)System::Windows::Forms::Shortcut::CmdShift9, "CmdShift9"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftA, "CmdShiftA"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftB, "CmdShiftB"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftC, "CmdShiftC"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftD, "CmdShiftD"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftE, "CmdShiftE"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftF, "CmdShiftF"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftF1, "CmdShiftF1"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftF10, "CmdShiftF10"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftF11, "CmdShiftF11"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftF12, "CmdShiftF12"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftF2, "CmdShiftF2"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftF3, "CmdShiftF3"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftF4, "CmdShiftF4"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftF5, "CmdShiftF5"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftF6, "CmdShiftF6"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftF7, "CmdShiftF7"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftF8, "CmdShiftF8"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftF9, "CmdShiftF9"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftG, "CmdShiftG"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftH, "CmdShiftH"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftI, "CmdShiftI"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftJ, "CmdShiftJ"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftK, "CmdShiftK"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftL, "CmdShiftL"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftM, "CmdShiftM"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftN, "CmdShiftN"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftO, "CmdShiftO"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftP, "CmdShiftP"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftQ, "CmdShiftQ"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftR, "CmdShiftR"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftS, "CmdShiftS"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftT, "CmdShiftT"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftU, "CmdShiftU"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftV, "CmdShiftV"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftW, "CmdShiftW"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftX, "CmdShiftX"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftY, "CmdShiftY"}, {(int64)System::Windows::Forms::Shortcut::CmdShiftZ, "CmdShiftZ"}, {(int64)System::Windows::Forms::Shortcut::CmdT, "CmdT"}, {(int64)System::Windows::Forms::Shortcut::CmdU, "CmdU"}, {(int64)System::Windows::Forms::Shortcut::CmdV, "CmdV"}, {(int64)System::Windows::Forms::Shortcut::CmdW, "CmdW"}, {(int64)System::Windows::Forms::Shortcut::CmdX, "CmdX"}, {(int64)System::Windows::Forms::Shortcut::CmdY, "CmdY"}, {(int64)System::Windows::Forms::Shortcut::CmdZ, "CmdZ"}, {(int64)System::Windows::Forms::Shortcut::Del, "Del"}, {(int64)System::Windows::Forms::Shortcut::F1, "F1"}, {(int64)System::Windows::Forms::Shortcut::F10, "F10"}, {(int64)System::Windows::Forms::Shortcut::F11, "F11"}, {(int64)System::Windows::Forms::Shortcut::F12, "F12"}, {(int64)System::Windows::Forms::Shortcut::F2, "F2"}, {(int64)System::Windows::Forms::Shortcut::F3, "F3"}, {(int64)System::Windows::Forms::Shortcut::F4, "F4"}, {(int64)System::Windows::Forms::Shortcut::F5, "F5"}, {(int64)System::Windows::Forms::Shortcut::F6, "F6"}, {(int64)System::Windows::Forms::Shortcut::F7, "F7"}, {(int64)System::Windows::Forms::Shortcut::F8, "F8"}, {(int64)System::Windows::Forms::Shortcut::F9, "F9"}, {(int64)System::Windows::Forms::Shortcut::Ins, "Ins"}, {(int64)System::Windows::Forms::Shortcut::None, "None"}, {(int64)System::Windows::Forms::Shortcut::ShiftDel, "ShiftDel"}, {(int64)System::Windows::Forms::Shortcut::ShiftF1, "ShiftF1"}, {(int64)System::Windows::Forms::Shortcut::ShiftF10, "ShiftF10"}, {(int64)System::Windows::Forms::Shortcut::ShiftF11, "ShiftF11"}, {(int64)System::Windows::Forms::Shortcut::ShiftF12, "ShiftF12"}, {(int64)System::Windows::Forms::Shortcut::ShiftF2, "ShiftF2"}, {(int64)System::Windows::Forms::Shortcut::ShiftF3, "ShiftF3"}, {(int64)System::Windows::Forms::Shortcut::ShiftF4, "ShiftF4"}, {(int64)System::Windows::Forms::Shortcut::ShiftF5, "ShiftF5"}, {(int64)System::Windows::Forms::Shortcut::ShiftF6, "ShiftF6"}, {(int64)System::Windows::Forms::Shortcut::ShiftF7, "ShiftF7"}, {(int64)System::Windows::Forms::Shortcut::ShiftF8, "ShiftF8"}, {(int64)System::Windows::Forms::Shortcut::ShiftF9, "ShiftF9"}, {(int64)System::Windows::Forms::Shortcut::ShiftIns, "ShiftIns"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;