//
// Created by mathm on 01/12/2024.
//

#include "TerminalUtility.h"

#include <iostream>
#include <limits>

namespace KT {
void TerminalUtility::ClearCin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void TerminalUtility::ClearTerminal() {
    std::cout << "\033[2J\033[H";

}

StringType TerminalUtility::GetTerminalColorCode(const ETerminalColor Color) {

    switch (Color) {
        case ETerminalColor::Black:
            return "\033[30m";
        case ETerminalColor::BrightBlack:
            return "\033[90m";
        case ETerminalColor::Red:
            return "\033[31m";
        case ETerminalColor::BrightRed:
            return "\033[91m";
        case ETerminalColor::Green:
            return "\033[32m";
        case ETerminalColor::BrightGreen:
            return "\033[92m";
        case ETerminalColor::Yellow:
            return "\033[33m";
        case ETerminalColor::BrightYellow:
            return "\033[93m";
        case ETerminalColor::Blue:
            return "\033[34m";
        case ETerminalColor::BrightBlue:
            return "\033[94m";
        case ETerminalColor::Magenta:
            return "\033[35m";
        case ETerminalColor::BrightMagenta:
            return "\033[95m";
        case ETerminalColor::Cyan:
            return "\033[36m";
        case ETerminalColor::BrightCyan:
            return "\033[96m";
        case ETerminalColor::White:
            return "\033[37m";
        case ETerminalColor::BrightWhite:
            return "\033[97m";
        default:
            throw std::runtime_error("Color value not handled color!");
    }
}

void TerminalUtility::SetTerminalColor(const ETerminalColor Color) {
    std::cout << GetTerminalColorCode(Color);
}

void TerminalUtility::ClearTerminalColor() {
    // std::cout << "\033[0m";
    std::cout << k_Clear;
}
} // KT
