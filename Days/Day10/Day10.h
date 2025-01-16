//
// Created by mathm on 16/01/2025.
//

#pragma once
#include <unordered_set>

#include "Base/IDayProblemBase.h"

enum class EDay: uint8_t;

namespace KT::Days {

class Day10 : public IDayProblemBase {
public:

        [[nodiscard]] EDay GetDay() const override;
        DayReturnType SolvePart1(const std::vector<StringType>& Input) override;
        DayReturnType SolvePart2(const std::vector<StringType>& Input) override;
};

}
