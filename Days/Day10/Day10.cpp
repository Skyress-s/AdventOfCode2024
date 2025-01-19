//
// Created by mathm on 16/01/2025.
//

#include "Day10.h"

#include <cassert>
#include <iostream>
#include <set>

#include "Base/Bounds/Bound.h"
#include "Base/DayEnum/DayEnum.h"
#include "Base/Direction/Type.h"
#include "catch2/matchers/catch_matchers_contains.hpp"

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
                                OutTrailHeads.emplace(j, i);
                        }
                }
        }
        return true;
}
void PrintElevations(const std::vector<StringType>& TopoMap, std::vector<Math::SVector2I>& Trail)
{
        std::cout << "Trail\n";
        for (auto Step : Trail)
        {
                std::cout << Step << ' ';
        }
        std::cout << '\n';
        for (const Math::SVector2I& Step : Trail)
        {
                std::cout << TopoMap[Step.Y][Step.X] << ' ';
        }
}


IDayProblemBase::DayReturnType Day10::FindNumUniqueHikingTrails(const std::vector<StringType>& TopoMap, const std::unordered_set<Math::SVector2I>& TrailHeads)
{
        using Trail_t = std::vector<Math::SVector2I>;

        // Bound Bounds = Bound({0, 0}, {(int16_t)TopoMap[0].size(), (int16_t)TopoMap.size()});

        // Initializing Trails heads
        std::vector<Trail_t> PrevTrails {};
        std::vector<Trail_t> Trails{};
        for (const Math::SVector2I& TrailHead : TrailHeads)
        {
                Trails.emplace_back(Trail_t({TrailHead}));
        }

        IDayProblemBase::DayReturnType UniqueHikingTrails{};

        while (Trails.size() > 0)
        {
                Trail_t& CurrentTrail = Trails[0];

                assert(("Trail is empty!", !CurrentTrail.empty()));
                // const Math::SVector2I& CurrentLocation = *std::prev(CurrentTrail.end());
                const Math::SVector2I& CurrentLocation = CurrentTrail.back();
                // find next valid locations.
                uint8_t NumValidLocations{0};
                for (Direction::Type Direction = Direction::Type::First; Direction <= Direction::Type::Last; ++Direction)
                {
                        const Math::SVector2I TestLocation = CurrentLocation + Direction::GetDirection(Direction);
                        if (IsLocationValid(TopoMap, CurrentLocation, TestLocation))
                        {
                                NumValidLocations++;
                                Trail_t NewTrail = CurrentTrail;
                                NewTrail.emplace_back(TestLocation);
                                if (NewTrail.size() == 10)
                                {
                                        PrintElevations(TopoMap, NewTrail);
                                        std::cout << std::endl;
                                        auto val = std::ranges::any_of(PrevTrails, [&NewTrail](const Trail_t& Trail)
                                        {
                                                return NewTrail == Trail;
                                        });
                                        if (val)
                                        {
                                                std::cout << "Found dup!!!!\n";
                                        }
                                        std::cout << std::endl;
                                        PrevTrails.emplace_back(NewTrail);
                                        UniqueHikingTrails += 1;
                                }
                                else
                                {
                                        Trails.emplace_back(NewTrail);
                                }
                        }
                }

                Trails.erase(Trails.begin());
                // End of trail. No valid Locations
        }
        return UniqueHikingTrails;
}

bool Day10::IsLocationValid(const std::vector<StringType>& TopoMap, const Math::SVector2I& Location, const Math::SVector2I& TestLocation)
{
        const Math::SVector2I Min = {0, 0};
        const Math::SVector2I Max = {(int16_t)(TopoMap[0].size() - 1), (int16_t)(TopoMap.size() - 1)};
        const Bound MapBound = Bound(Min, Max);
        // assert((BoundUtility::IsLocationOOB(Location, MapBound), "Location "));
        if (BoundUtility::IsLocationOOB(MapBound, Location))
                return false;
        if (BoundUtility::IsLocationOOB(MapBound, TestLocation))
                return false;

        const uint8_t LocationValue = TopoMap[Location.Y][Location.X] - '0';
        const uint8_t TestLocationValue = TopoMap[TestLocation.Y][TestLocation.X] - '0';

        return TestLocationValue == (LocationValue + 1);
}

namespace KT::Days
{
EDay Day10::GetDay() const
{
        return EDay::Day10;
}

IDayProblemBase::DayReturnType Day10::SolvePart1(const std::vector<StringType>& Input)
{
        std::unordered_set<Math::SVector2I> TrailHeads{};
        ::Day10::FindTrailHeads1(Input, TrailHeads);


        return INVALID_RESULT;
}

IDayProblemBase::DayReturnType Day10::SolvePart2(const std::vector<StringType>& Input)
{
        return INVALID_RESULT;
}
}
