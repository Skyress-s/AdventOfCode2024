//
// Created by mathm on 01/12/2024.
//

#pragma once
#include <cstdint>

#include "Base/BaseTypeDefs.h"

namespace KT::TerminalUtility {
void ClearCin();
void ClearTerminal();

inline constexpr StringType k_Black = "\033[30m";
inline constexpr StringType k_BrightBlack = "\033[90m";
inline constexpr StringType k_Red = "\033[31m";
inline constexpr StringType k_BrightRed = "\033[91m";
inline constexpr StringType k_Green = "\033[32m";
inline constexpr StringType k_BrightGreen = "\033[92m";
inline constexpr StringType k_Yellow = "\033[33m";
inline constexpr StringType k_BrightYellow = "\033[93m";
inline constexpr StringType k_Blue = "\033[34m";
inline constexpr StringType k_BrightBlue = "\033[94m";
inline constexpr StringType k_Magenta = "\033[35m";
inline constexpr StringType k_BrightMagenta = "\033[95m";
inline constexpr StringType k_Cyan = "\033[36m";
inline constexpr StringType k_BrightCyan = "\033[96m";
inline constexpr StringType k_White = "\033[37m";
inline constexpr StringType k_BrightWhite = "\033[97m";
inline constexpr StringType k_Clear ="\033[0m";

enum class ETerminalColor : uint8_t {
        Black,
        BrightBlack,
        Red,
        BrightRed,
        Green,
        BrightGreen,
        Yellow,
        BrightYellow,
        Blue,
        BrightBlue,
        Magenta,
        BrightMagenta,
        Cyan,
        BrightCyan,
        White,
        BrightWhite
};

StringType GetTerminalColorCode(const ETerminalColor Color);
void SetTerminalColor(ETerminalColor Color);
void ClearTerminalColor();
};
