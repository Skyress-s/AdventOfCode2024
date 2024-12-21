//
// Created by mathm on 01/12/2024.
//

#pragma once
#include "Base/IDayProblemBase.h"

enum class EDay : uint8_t;

namespace KT::Days {
class Day01 final : public IDayProblemBase {
public:
        Day01() = default;

        ~Day01() override = default;

protected:
        DayReturnType SolvePart1(const std::vector<StringType>& Input) override;

        int32_t SolvePart2(const std::vector<StringType>& Input) override;

        [[nodiscard]] EDay GetDay() const override;
};
}
