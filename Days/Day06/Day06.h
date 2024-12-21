//
// Created by mathm on 14/12/2024.
//

#pragma once

#include "Base/IDayProblemBase.h"

enum class EDay : uint8_t;

namespace KT::Days {

class Day06 final : public IDayProblemBase {
public:
	[[nodiscard]] EDay GetDay() const final ;
	DayReturnType SolvePart1(const std::vector<StringType>& Input) override;
	int32_t SolvePart2(const std::vector<StringType> &Input) override;
};

}
