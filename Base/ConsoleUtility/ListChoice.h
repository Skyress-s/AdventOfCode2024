//
// Created by mathm on 05/12/2024.
//


#pragma once
#include <assert.h>
#include <iostream>
#include <vector>
#include <cstdint>
#include <conio.h>
#include <functional>

#include "Base/BaseTypeDefs.h"
#include "Utility/TerminalUtility.h"

namespace KT::UI {

        constexpr StringType k_SelectedPrefix = "->";
        constexpr StringType k_UnselectedPrefix = "  ";

template<typename TEntry>
void PrintList(const std::vector<TEntry>& Entries, const int32_t CurrentSelected, std::function<StringType(const TEntry&)>& EntryToStringFunc) {

        for (int i = 0; i < Entries.size(); ++i) {

                if (i == CurrentSelected) {
                        std::cout << TerminalUtility::k_Cyan << k_SelectedPrefix << " ";
                } else {
                        std::cout << TerminalUtility::k_Clear << k_UnselectedPrefix << " ";
                }
                auto ent = Entries[i];
                std::cout << EntryToStringFunc(ent) << std::endl;
        }
        std::cout << TerminalUtility::k_Clear;
}

template<typename TEntry>
const TEntry& ListChoice(const std::vector<TEntry>& Entries, const StringType& Title, std::function<StringType(const TEntry&)>& EntryToStringFunc) {
        assert(!Entries.empty());

        TerminalUtility::ClearTerminalColor();
        int32_t CurrentSelected = 0;
        while (true) {
                std::cout << Title << "\n";
                PrintList(Entries, CurrentSelected, EntryToStringFunc);
                const int ch = getch();
                if (ch == 224) {
                        const int ch2 = getch();
                        switch (ch2) {
                                case 72: // Up
                                        CurrentSelected = std::max(0, CurrentSelected - 1);
                                        break;
                                case 80: // Down
                                        CurrentSelected = std::min(static_cast<int32_t>(Entries.size() - 1), CurrentSelected + 1);
                                        break;
                        }
                } else if (ch == 13) { // Enter
                        break;
                }
                TerminalUtility::ClearTerminal();
        }

        return Entries[CurrentSelected];
}

// template<typename TEntry>
// class ListChoice {
// public:
//         // ListChoice(const std::vector<TEntry>& Entries);
//
//
// private:
//         std::vector<TEntry> m_Entries;
//
//
// };

}
