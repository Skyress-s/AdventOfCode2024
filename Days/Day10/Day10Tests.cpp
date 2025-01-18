//
// Created by mathm on 16/01/2025.
//

#include <fstream>

#include "Day10.h"
#include "Base/DayEnum/DayEnum.h"
#include "catch2/catch_test_macros.hpp"
#include "Days/Day01/Day01.h"
#include "Utility/IOUtility.h"


std::vector<StringType> GenerateSimpleTopoMap()
{
        return KT::IOUtility::ReadFile(KT::IOUtility::GetTestInputFilePathFromDay(EDay::Day10));
}

TEST_CASE("Day10 Tests")
{
        auto TopoMap {};
        SECTION("Load From Disk")
        {
                TopoMap = GenerateSimpleTopoMap();
                REQUIRE(TopoMap.size() > 0);
        }
        SECTION("Find Simple trailhead")
        {

                std::unordered_set<Math::SVector2I> TrailHeads{};
                Day10::FindTrailHeads1(TopoMap, TrailHeads);
                REQUIRE(TrailHeads.size() == 9);
                for (const Math::SVector2I& TrailHead : TrailHeads)
                {
                        REQUIRE(TopoMap[TrailHead.Y][TrailHead.X] == '0');
                }
        }


}
