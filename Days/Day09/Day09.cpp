//
// Created by mathm on 05/01/2025.
//

#include "Day09.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>

#include "Base/DayEnum/DayEnum.h"

namespace KT::Days
{
using DiskType = std::vector<std::optional<long>>;

EDay Day09::GetDay() const
{
        return EDay::Day09;
}

DiskType BuildDisk(const StringType& Input)
{
        std::cout << "Building disk...\n";
        DiskType Disk{};
        StringType Output;
        for (int i = 0; i < Input.size(); ++i)
        {
                const bool bIsRealChunk = i % 2 == 0;

                const int Number = Input[i] - '0';
                for (int num : std::ranges::views::iota(0, Number)) // Not optimal but very fun
                {
                        if (bIsRealChunk)
                        {
                                const long Id = i / 2;
                                Disk.push_back(std::optional<long>(Id));
                        }
                        else
                        {
                                Disk.push_back(std::optional<long>());
                        }
                }
        }
        std::cout << "Finished Building disk!\n";
        return Disk;
}

bool FlattenDisk(DiskType& OutDisk)
{
        // std::cout << "Last Iterator!" << (*Iterator).value() << std::endl;

        // std::ranges::for_each(std::ranges::views::zip(std::ranges::views::iota(0), OutDisk), [](auto pair)
        // {
        //
        // });

        // for (auto test : std::ranges::views::zip(std::ranges::views::iota(0), OutDisk))
        // {
        // }


        // without ranges

        std::cout << "Flattening disk...\n";
        int i;
        std::ranges::for_each(OutDisk.begin(), OutDisk.end(), [&OutDisk, &i](std::optional<long>& value)
        {
                if (!value.has_value())
                {
                        int y = OutDisk.size() - 1;
                        auto [Iterator, End] = std::ranges::find_last_if(OutDisk.begin(), OutDisk.end(), [&i, &y](const std::optional<long>& Value)
                        {
                                y--;
                                if (i >= y)
                                {
                                        return false;
                                }
                                return Value.has_value();
                        });
                        if (Iterator != End)
                                std::swap(value, *Iterator);
                }
                // std::cout << (value.has_value() ? std::to_string(value.value()) : ".") << ' ';
                i++;
        });
        std::cout << "Finished Flattening disk!\n";

        return false;
}

IDayProblemBase::DayReturnType ComputeChecksum(const DiskType& Disk)
{
        std::vector<int> test{1,2,3,4,5};
        auto ZipView = std::views::zip(Disk, std::views::iota(0));
        auto CoolView = ZipView | std::views::common;
        for (auto test1 : CoolView)
        {

                std::cout << test1.second << " ";
        }
        std::cout << std::endl;
        auto Result = std::accumulate(CoolView.begin(), CoolView.end(), int(0), [](int sum, const std::pair<const std::optional<long>, int>& value)
        {
                if (value.first.has_value())
                {
                        return sum + value.second * (int)value.first.value();
                }
                return sum;
        });
        std::cout << "aw,dpoaw,dpoa,wd" << Result << std::endl;
        return Result;
        // std::accumulate(ZipView.begin(), ZipView.end(), int (1), [](IDayProblemBase::DayReturnType Typr, const auto& Pair)
        // {
        //    return Typr;
        // });
        // std::ranges::for_each(std::views::zip(Disk, std::views::iota(0)), [](const auto Pair)
        // {
        //
        // });
}

IDayProblemBase::DayReturnType Day09::SolvePart1(const std::vector<StringType>& Input)
{
        DiskType Disk = BuildDisk(Input[0]);
        FlattenDisk(Disk);
        return ComputeChecksum(Disk);
        std::for_each(Disk.begin(), Disk.end(), [this](const std::optional<long>& input)
        {
                if (input.has_value())
                {
                        std::cout << input.value() << ' ';
                }
                else
                {
                        std::cout << '.' << ' ';
                }
        });
        std::cout << std::endl;
        return INVALID_RESULT;
}

IDayProblemBase::DayReturnType Day09::SolvePart2(const std::vector<StringType>& Input)
{
        return INVALID_RESULT;
}
}
