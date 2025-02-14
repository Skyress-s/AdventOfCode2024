﻿//
// Created by mathm on 12/12/2024.
//

#pragma once

#include "Base/IDayProblemBase.h"

enum class Eday : uint8_t;

namespace KT::Days {

        class Day05 : public IDayProblemBase {
        public:
            [[nodiscard]] EDay GetDay() const override;
            virtual DayReturnType SolvePart1(const std::vector<StringType>& Input) override;
            virtual DayReturnType SolvePart2(const std::vector<StringType>& Input) override;
        };

}
