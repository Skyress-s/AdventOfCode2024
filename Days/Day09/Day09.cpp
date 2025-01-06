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
EDay Day09::GetDay() const
{
        return EDay::Day09;
}

std::vector<std::optional<long>> BuildDisk(const StringType& Input)
{
        std::vector<std::optional<long>> Disk{};
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

IDayProblemBase::DayReturnType Day09::SolvePart1(const std::vector<StringType>& Input)
{
        const std::vector<std::optional<long>> DiskChunks = BuildDisk(Input[0]);
        std::for_each(DiskChunks.begin(), DiskChunks.end(), [this](const std::optional<long>& input)
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
