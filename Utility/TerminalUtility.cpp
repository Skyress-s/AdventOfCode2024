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
} // KT
