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

// Thanks to copilot for this function.
template<typename T>
void ParseTest(const std::string& Input, std::vector<T>& Output, const std::string& Delimiters) {
    std::istringstream stream(Input);
    std::string token;
    while (std::getline(stream, token)) {
        size_t start = 0, end = 0;
        while ((end = token.find_first_of(Delimiters, start)) != std::string::npos) {
            if (end != start) {
                std::istringstream valueStream(token.substr(start, end - start));
                T value;
                valueStream >> value;
                Output.push_back(value);
            }
            start = end + 1;
        }
        if (start < token.size()) {
            std::istringstream valueStream(token.substr(start));
            T value;
            valueStream >> value;
            Output.push_back(value);
        }
    }
}

}
