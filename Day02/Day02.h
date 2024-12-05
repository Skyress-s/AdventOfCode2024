//
// Created by mathm on 05/12/2024.
//

#pragma once
#include "Base/ProblemBase.h"

enum class EDay : uint8_t;

namespace KT::Days {

class Day02 final : public ProblemBase {
public:
    EDay GetDay() override;

    int32_t SolvePart1(const std::vector<StringType>& Input) override;

    int32_t SolvePart2(const std::vector<StringType>& Input) override;

protected:
    void Initialize() override;

    void CleanUp() override;
};

} // KT::Days
