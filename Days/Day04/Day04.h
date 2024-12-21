//
// Created by mathm on 09/12/2024.
//

#pragma once
#include "Base/IDayProblemBase.h"

namespace KT {
namespace Days {

class Day04 final : public IDayProblemBase {
public:
      [[nodiscard]] EDay GetDay() const override;

      DayReturnType SolvePart1(const std::vector<StringType>& Input) override;

      DayReturnType SolvePart2(const std::vector<StringType>& Input) override;

};

} // Days
} // KT

