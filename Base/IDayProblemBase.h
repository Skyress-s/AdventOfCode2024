//
// Created by mathm on 01/12/2024.
//

#pragma once
#include <cstdint>
#include <string>
#include <vector>

#include "BaseTypeDefs.h"

enum class EDay: uint8_t;


class IDayProblemBase {
public:
    [[nodiscard]] virtual EDay GetDay() const = 0;
    IDayProblemBase() = default;
    virtual ~IDayProblemBase() = default;

public:
    virtual int32_t SolvePart1(const std::vector<StringType>& Input) = 0;
    virtual int32_t SolvePart2(const std::vector<StringType>& Input) = 0;
};
