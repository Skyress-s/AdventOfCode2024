//
// Created by mathm on 16/01/2025.
//

#include "Day10.h"

#include "Base/DayEnum/DayEnum.h"

bool Day10::FindTrailHeads1(const std::vector<StringType>& TopoMap, std::unordered_set<Math::SVector2I>& OutTrailHeads)
{
        for (int i = 0; i < TopoMap.size(); ++i)
        {
                const StringType& Row = TopoMap[i];
                for (int j = 0; j < Row.size(); ++j)
                {
                        const char& Char = Row[j];
                        if (Char == '0')
                        {
                                OutTrailHeads.emplace(j,i);
                        }
                }
        }
        return true;
}

namespace KT::Days{

EDay Day10::GetDay() const
{
        return EDay::Day10;
}

IDayProblemBase::DayReturnType Day10::SolvePart1(const std::vector<StringType>& Input)
{

        return INVALID_RESULT;
}

IDayProblemBase::DayReturnType Day10::SolvePart2(const std::vector<StringType>& Input)
{
        return INVALID_RESULT;
}
}

