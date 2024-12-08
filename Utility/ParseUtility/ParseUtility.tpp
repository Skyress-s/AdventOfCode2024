//
// Created by mathm on 05/12/2024.
//
#include <sstream>
#include <vector>

#include "Utility/TerminalUtility.h"

namespace ParseUtility {

template<typename T>
void ParseUtility::ParseTest(const StringType& String, std::vector<T>& Output) {
    std::istringstream Stream(String);
    T Value;
    while (Stream >> Value) {
        Output.push_back(Value);
    }
}


}
