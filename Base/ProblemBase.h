//
// Created by mathm on 01/12/2024.
//

#pragma once
#include <string>

#include "BaseTypeDefs.h"


class ProblemBase {
public:
    ProblemBase() = default;
    virtual ~ProblemBase() = default;
    virtual void Initialize() = 0;
    virtual void Solve() = 0;
    virtual void CleanUp() = 0;
    virtual StringType GetProblemName() = 0;
};
