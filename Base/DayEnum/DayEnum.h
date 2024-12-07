//
// Created by mathm on 01/12/2024.
//

#pragma once
#include <cstdint>

#include "Base/BaseTypeDefs.h"

enum class EDay : uint8_t {
    Day01 = 1,
    Day02 = 2,
    Day03 = 3,
    Day04 = 4,
    Day05 = 5,
    Day06 = 6,
    Day07 = 7,
    Day08 = 8,
    Day09 = 9,
    Day10 = 10,
    Day11 = 11,
    Day12 = 12,
    Day13 = 13,
    Day14 = 14,
    Day15 = 15,
    Day16 = 16,
    Day17 = 17,
    Day18 = 18,
    Day19 = 19,
    Day20 = 20,
    Day21 = 21,
    Day22 = 22,
    Day23 = 23,
    Day24 = 24,
    Count // MUST be last
};

// Return value like "01", "02", etc.
StringType GetDayNumberString(const EDay Day);

StringType GetDayName(const EDay Day);

std::ostream& operator<<(std::ostream& os, const EDay day);
