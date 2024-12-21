//
// Created by mathm on 21/12/2024.
//

#pragma once
#include "Base/IDayProblemBase.h"

enum class EDay : uint8_t;

namespace KT::Days {

class Day08 : public IDayProblemBase {
public:
	[[nodiscard]] EDay GetDay() const override;
	DayReturnType SolvePart1(const std::vector<StringType>& Input) override;
	DayReturnType SolvePart2(const std::vector<StringType>& Input) override;
};

}
