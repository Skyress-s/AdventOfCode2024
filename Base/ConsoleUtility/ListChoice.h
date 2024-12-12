//
// Created by mathm on 05/12/2024.
//

#pragma once

#include <cassert>
#include <iostream>
#include <vector>
#include <cstdint>
#include <conio.h>
#include <functional>
#include <ranges>

#include "Base/BaseTypeDefs.h"
#include "Utility/TerminalUtility.h"

namespace KT::UI {

        constexpr StringType k_SelectedPrefix = "->";
        constexpr StringType k_UnselectedPrefix = "  ";

template<typename TEntry>
using TListItem = std::pair<TEntry, StringType>;

void PrintList2(const std::vector<StringType>& RowNames, const uint32_t Current);

template<typename TEntry>
[[nodiscard]] const TEntry& ListChoice2(const std::vector<TListItem<TEntry>>& ListItems, const StringType& Title);



}

#include "ListChoice.tpp"