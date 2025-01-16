//
// Created by mathm on 16/01/2025.
//

#include "Day10.h"
#include "Base/DayEnum/DayEnum.h"
#include "cmake-build-release/_deps/catch2-src/src/catch2/catch_test_macros.hpp"
#include "Days/Day01/Day01.h"
#include "Utility/IOUtility.h"


std::vector<StringType> GenerateSimpleTopoMap()
{
        return KT::IOUtility::ReadFile(KT::IOUtility::GetTestInputFilePathFromDay(EDay::Day10));
        std::vector<StringType> SimpleTopoMap
        {
                {'1','6','7','4','5','6'},
                {'1','0','3','7','5','6'},
                {5,6,4,7,9,2},
                {5,4,5,4,6,4},
                {5,6,4,7,0,2},
                {1,2,3,7,5,6}
        };
        return SimpleTopoMap;
}

TEST_CASE("Day10 Tests")
{
        SECTION("Find Simple trailhead")
        {
                auto TopoMap = GenerateSimpleTopoMap();

                std::unordered_set<Math::SVector2I> TrailHeads{};
                Day10Operations::FindTrailHeads1(TopoMap, TrailHeads);
                REQUIRE(TrailHeads.size() == 2);
                // for (const Math::SVector2I& TrailHead : TrailHeads)
                // {
                //
                //         REQUIRE(TopoMap[TrailHead.Y][TrailHead.X] == 0);
                // }
                //
        }


}
