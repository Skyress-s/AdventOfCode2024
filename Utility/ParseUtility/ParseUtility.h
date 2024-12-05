//
// Created by mathm on 05/12/2024.
//


#pragma once
#include "Base/BaseTypeDefs.h"
#include <vector>

namespace ParseUtility {

    template<typename T>
void ParseTest(const StringType& String, std::vector<T>& Output);


}

#include "ParseUtility.tpp"
