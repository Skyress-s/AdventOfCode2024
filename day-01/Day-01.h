//
// Created by mathm on 01/12/2024.
//

#pragma once
#include "Base/ProblemBase.h"

enum class EDay : uint8_t;

class Day01 final : public ProblemBase {
public:
    Day01() = default;
    ~Day01() override;
protected:
    void Initialize() override;

    int32_t SolvePart1(const std::vector<StringType>& Input) override;
    int32_t SolvePart2(const std::vector<StringType>& Input) override;

    void CleanUp() override;

    EDay GetDay() override;

    StringType GetInputFilePathsFromRoot() override;
};
