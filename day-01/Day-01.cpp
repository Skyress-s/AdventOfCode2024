//
// Created by mathm on 01/12/2024.
//

#include "Day-01.h"

#include <algorithm>
#include <assert.h>
#include <iostream>
#include <ostream>
#include <unordered_map>

#include "Base/DayEnum/DayEnum.h"


void ToLists(const std::vector<StringType>& Lines, std::vector<int32_t>& LeftNumbers, std::vector<int32_t>& RightNumbers) {
    std::vector<std::pair<int32_t, int32_t>> Result;
    for (auto& Row: Lines) {
        int a, b;
        int num = sscanf(Row.c_str(), "%d    %d", &a, &b);
        if (num != 2) {
            std::cerr << "Failed to parse input: values: " << num << std::endl;
            return;
        }

        LeftNumbers.emplace_back(a);
        RightNumbers.emplace_back(b);
    }

    assert(LeftNumbers.size() == RightNumbers.size());
}


Day01::~Day01() = default;

void Day01::Initialize() {
}

int32_t Day01::SolvePart1(const std::vector<StringType>& Input) {
    std::vector<int32_t> LeftNumbers, RightNumbers;
    ToLists(Input, LeftNumbers, RightNumbers);

    std::ranges::sort(LeftNumbers);
    std::ranges::sort(RightNumbers);

    uint32_t TotalDiff = 0;
    for (int i = 0; i < LeftNumbers.size(); i++) {
        const int32_t Left = LeftNumbers[i];
        const int32_t Right = RightNumbers[i];
        TotalDiff += std::abs(Left - Right);
        std::cout << "Left: " << Left << " Right: " << Right << std::endl;
    }
    return TotalDiff;
}

int32_t Day01::SolvePart2(const std::vector<StringType>& Input) {
    std::vector<int32_t> LeftNumbers, RightNumbers;
    ToLists(Input, LeftNumbers, RightNumbers);

    std::unordered_map<int32_t /*LeftSide*/, int32_t /*NumOnRightSide*/> Map;

    // Counting right side
    for (const int32_t RightNumber: RightNumbers) {
        auto test = Map.find(RightNumber);
        if (test != Map.end()) {
            test->second++;
        }
        else {
            // Map.insert({RightNumber, 1});
            Map.emplace(RightNumber, 1);
        }
    }

    int32_t SimilarityScore{};

    for (const auto LeftNumber: LeftNumbers) {
        const auto& Iter = Map.find(LeftNumber);

        // Continue if does not exist in RHS
        if (Iter == Map.end()) {
            continue;
        }

        SimilarityScore += LeftNumber * Iter->second;
    }
    return SimilarityScore;
}

void Day01::CleanUp() {
}

EDay Day01::GetDay() {
    return EDay::Day01;
}

StringType Day01::GetInputFilePathsFromRoot() {
    return {"day-01/input.txt"};
}
