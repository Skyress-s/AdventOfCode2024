//
// Created by mathm on 05/12/2024.
//

#pragma once
#include "Base/BaseTypeDefs.h"

class IDaySolver {
public:
    virtual void SolvePart1(const StringType& Path) = 0;
    virtual void SolvePart2(const StringType& Path) = 0;
};

template<typename InputType>
class TDaySolver : public IDaySolver {
public:
protected:
    virtual SolvePart1(const InputType& Input) = 0;
    virtual SolvePart2(const InputType& Input) = 0;
};
