//
// Created by mathm on 16/01/2025.
//

#pragma once
#include <unordered_set>

#include "Base/IDayProblemBase.h"
#include "Base/Vector2D/Vector2D.h"

enum class EDay: uint8_t;

namespace Day10Operations
{
        bool FindTrailHeads1(const std::vector<StringType>& TopoMap, std::unordered_set<Math::SVector2I>& OutTrailHeads);
}
namespace KT::Days {


class Day10 : public IDayProblemBase {
public:
        [[nodiscard]] EDay GetDay() const override;
        DayReturnType SolvePart1(const std::vector<StringType>& Input) override;
        DayReturnType SolvePart2(const std::vector<StringType>& Input) override;
};

}
