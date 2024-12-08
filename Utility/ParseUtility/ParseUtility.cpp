#include "ParseUtility.h"

#include <cmath>

bool ParseUtility::IsNumber(const char Char) {
        return Char >= '0' && Char <= '9';
}

int32_t ParseUtility::ParseNumberFromStart(const StringType& String, int32_t* NumberLength) {
        int32_t Index = {0};
        std::vector<int32_t> Numbers;
        while (IsNumber(String[Index])) {
                const int32_t Number = String[Index] - '0';
                Numbers.insert(Numbers.begin(), Number);

                // Number += std::max(NumLength * 10, 1) * (String[Index] - '0');
                Index++;
        }

        int32_t Number {0};
        for (int i = 0; i < Numbers.size(); ++i) {

                int32_t test = std::pow(10, i);
                Number += std::max(1, test) * Numbers[i];
        }
        if (NumberLength != nullptr) {
                *NumberLength = Numbers.size();
        }
        return Number;
}
