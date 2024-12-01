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

    void Solve(const StringType &Input) override;

    void CleanUp() override;

    EDay GetDay() override;

    StringType GetInputFilePathsFromRoot() override;
};
