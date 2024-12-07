﻿//
// Created by mathm on 07/12/2024.
//

#pragma once
#include "Base/IDayProblemBase.h"

namespace KT::Days {

class Day03 : public IDayProblemBase {

public: // Override
        ~Day03() = default;

        EDay GetDay() override;

        int32_t SolvePart1(const std::vector<StringType>& Input) override;

        int32_t SolvePart2(const std::vector<StringType>& Input) override;

protected:

public: // Methods

public: // Variables
};

}