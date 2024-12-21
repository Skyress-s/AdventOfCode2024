//
// Created by mathm on 21/12/2024.
//

#include "Day08.h"

#include <bits/ranges_algo.h>

#include "Base/DayEnum/DayEnum.h"
#include "Base/Grid/TGrid.h"

namespace KT::Days {
EDay Day08::GetDay() const
{
	return EDay::Day08;
}

IDayProblemBase::DayReturnType Day08::SolvePart1(const std::vector<StringType>& Input)
{
	KT::TGrid<char> test;
	std::ranges::for_each(Input, [](const StringType& Line)
	{

	});
}

IDayProblemBase::DayReturnType Day08::SolvePart2(const std::vector<StringType>& Input)
{
}
}
