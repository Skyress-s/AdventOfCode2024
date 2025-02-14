﻿//
// Created by mathm on 16/01/2025.
//

#include <fstream>

#include "Day10.h"
#include "Base/DayEnum/DayEnum.h"
#include "catch2/catch_test_macros.hpp"
#include "Days/Day01/Day01.h"
#include "Utility/IOUtility.h"
#include <ranges>
#include <algorithm>


std::vector<StringType> GenerateSimpleTopoMap()
{
        return KT::IOUtility::ReadFile(KT::IOUtility::GetTestInputFilePathFromDay(EDay::Day10));
}

TEST_CASE("Jaho")
{
        SECTION("IsTrueTrue?")
        {
                REQUIRE(true == true);
        }

        std::vector<std::vector<int>> t1{
                {1, 2, 3, 4, 5, 6, 7},
                {1, 2, 3, 4, 5, 6, 7, 9},
                {1, 2, 3, 4, 7, 8, 9},
                {1, 2, 3, 4, 5, 6, 7, 8, 9},
                {1, 2, 3, 4, 6, 7, 8, 9},
        };
        std::vector<int> t2{1, 2, 3, 4, 5, 6, 7, 8, 9};
        const bool AnyOf = std::ranges::any_of(t1, [t2](const std::vector<int>& Trail)
        {
                return t2 == Trail;
        });
        SECTION("AnyOf?")
        {
                REQUIRE(AnyOf);
        }
}

TEST_CASE("Day10 Tests")
{
        // Finding map
        std::vector<StringType> TopoMap{};
        TopoMap = GenerateSimpleTopoMap();
        SECTION("Load From Disk")
        {
                REQUIRE(TopoMap.size() > 0);
        }

        SECTION("IsLocationValid")
        {
                const bool Invalid = Day10::IsLocationValid(TopoMap, {0, 0}, {0, 1});
                REQUIRE(Invalid == false);
                const bool Valid = Day10::IsLocationValid(TopoMap, {2, 0}, {3, 0});
                REQUIRE(Valid == true);
        }

        // Trail Heads
        std::unordered_set<Math::SVector2I> TrailHeads{};
        Day10::FindTrailHeads1(TopoMap, TrailHeads);
        SECTION("Find Simple trailhead")
        {
                REQUIRE(TrailHeads.size() == 9);
                for (const Math::SVector2I& TrailHead : TrailHeads)
                {
                        REQUIRE(TopoMap[TrailHead.Y][TrailHead.X] == '0');
                }
        }

        IDayProblemBase::DayReturnType UniqueHikingTrails = Day10::FindNumUniqueHikingTrails(TopoMap, TrailHeads);
        SECTION("Unique Hiking Trails")
        {
                REQUIRE(UniqueHikingTrails == 36);
        }
}
