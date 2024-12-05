//
// Created by mathm on 01/12/2024.
//

#pragma once
#include <cstdint>
#include <vector>

#include "Base/BaseTypeDefs.h"

enum class EDay : uint8_t;

namespace KT::IOUtility {
    std::vector<StringType> ReadFile(const StringType& Path);

    StringType GetInputFilePathFromDay(const EDay Day);
    StringType GetTestInputFilePathFromDay(const EDay Day);
};
