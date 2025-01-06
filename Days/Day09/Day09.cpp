//
// Created by mathm on 05/01/2025.
//

#include "Day09.h"

#include <algorithm>
#include <iostream>
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
        return Disk;
}

bool FlattenDisk(DiskType& OutDisk)
{
        // std::cout << "Last Iterator!" << (*Iterator).value() << std::endl;

        std::ranges::for_each(OutDisk.rbegin(), OutDisk.rend(), [&OutDisk](std::optional<long>& Value)
        {
                if (Value.has_value())
                {
                        auto FirstNull = std::ranges::find_if(OutDisk, [&OutDisk](const std::optional<long>& CompValue)
                        {
                                return !CompValue.has_value();
                        });

                        std::swap(Value, *FirstNull);
                }
        });

        // without ranges

        /*
        std::ranges::for_each(OutDisk.begin(), OutDisk.end(), [&OutDisk](std::optional<long>& value)
        {
                if (!value.has_value())
                {
                        auto [Iterator, End] = std::ranges::find_last_if(OutDisk.begin(), OutDisk.end(), [](const std::optional<long>& Value)
                        {
                                return Value.has_value();
                        });
                        std::swap(value, *Iterator);
                }
                // std::cout << (value.has_value() ? std::to_string(value.value()) : ".") << ' ';
        });
        */

        std::cout << std::endl;
        for (const auto& Chunk : OutDisk)
        {
                if (!Chunk.has_value())
                {
                }
        }
        return false;
}

IDayProblemBase::DayReturnType Day09::SolvePart1(const std::vector<StringType>& Input)
{
        DiskType Disk = BuildDisk(Input[0]);
        FlattenDisk(Disk);
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
