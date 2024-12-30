//
// Created by mathm on 21/12/2024.
//

#include "Day08.h"

#include <iostream>
#include <ranges>

#include "Base/DayEnum/DayEnum.h"
#include "Base/Vector2D/Vector2D.h"
#include "Base/Grid/TGrid.h"

namespace KT::Days
{

EDay Day08::GetDay() const
{
        return EDay::Day08;
}

TGrid<char> BuildGridFromInput(const std::vector<StringType>& Input)
{
        TGrid<char>::GridType Grid;
        for (auto ItrY = Input.begin(); ItrY != Input.end(); ++ItrY)
        {
                TGrid<char>::RowType Row;
                for (auto ItrX = ItrY->begin(); ItrX != ItrY->end(); ++ItrX)
                {
                        Row.push_back(*ItrX);
                }
                Grid.push_back(Row);
        }
        return TGrid(Grid);
}

IDayProblemBase::DayReturnType Day08::SolvePart1(const std::vector<StringType>& Input)
{
        TGrid<char> Grid = BuildGridFromInput(Input);


        std::cout << Grid << std::endl;
        return INVALID_RESULT;
}

IDayProblemBase::DayReturnType Day08::SolvePart2(const std::vector<StringType>& Input)
{
        return INVALID_RESULT;
}
}
