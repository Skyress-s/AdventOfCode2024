//
// Created by mathm on 21/12/2024.
//

#include "Day08.h"

#include <iostream>

#include "Base/DayEnum/DayEnum.h"
#include "Base/Vector2D/Vector2D.h"
#include "Base/Grid/TGrid.h"

namespace KT::Days
{
EDay Day08::GetDay() const
{
	return EDay::Day08;
}

IDayProblemBase::DayReturnType Day08::SolvePart1(const std::vector<StringType>& Input)
{
	TGrid<char> Grid({{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}});
	std::cout << Grid << std::endl;
	std::cout << Grid.At(0,0) << "\n";
	std::cout << Grid.At(1, 2);

	return INVALID_RESULT;
}

IDayProblemBase::DayReturnType Day08::SolvePart2(const std::vector<StringType>& Input)
{
	return INVALID_RESULT;
}
}
