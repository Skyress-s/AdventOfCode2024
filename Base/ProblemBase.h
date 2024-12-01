//
// Created by mathm on 01/12/2024.
//

#pragma once
#include <cstdint>
#include <string>


#include "BaseTypeDefs.h"

enum class EDay: uint8_t;

class ProblemBase {
public:
    virtual EDay GetDay() = 0;
    ProblemBase() = default;
    virtual ~ProblemBase() = default;
protected:
    virtual void Initialize() = 0;
    virtual void Solve(const StringType& Input) = 0;
    virtual void CleanUp() = 0;
    // Should be relative to the root (e.g. "day-01/input.txt")
    virtual StringType GetInputFilePathsFromRoot() = 0;
};
