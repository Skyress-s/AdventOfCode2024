﻿//
// Created by mathm on 07/12/2024.
//

#pragma once
#include "Base/IDayProblemBase.h"

namespace KT::Days {

class Day03 final : public IDayProblemBase {

public: // Override
        ~Day03() = default;

        [[nodiscard]] EDay GetDay() const override;

        DayReturnType SolvePart1(const std::vector<StringType>& Input) override;

        DayReturnType SolvePart2(const std::vector<StringType>& Input) override;

protected:

public: // Methods

public: // Variables
};

}
