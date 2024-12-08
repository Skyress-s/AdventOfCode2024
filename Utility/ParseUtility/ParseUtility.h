//
// Created by mathm on 05/12/2024.
//


#pragma once
#include <cstdint>

#include "Base/BaseTypeDefs.h"
#include <vector>

namespace ParseUtility {

    template<typename T>
void ParseTest(const StringType& String, std::vector<T>& Output);

bool IsNumber(const char Char);

int32_t ParseNumberFromStart(const StringType& String, int32_t* NumberLength = nullptr);

}

#include "ParseUtility.tpp"
