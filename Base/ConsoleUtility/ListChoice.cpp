//
// Created by mathm on 05/12/2024.
//
#include "ListChoice.h"

void KT::UI::PrintList2(const std::vector<StringType>& RowNames, const uint32_t Current) {

    for (int i = 0; i < RowNames.size(); ++i) {

        if (i == Current) {
            std::cout << TerminalUtility::k_Cyan << k_SelectedPrefix << " ";
        } else {
            std::cout << TerminalUtility::k_Clear << k_UnselectedPrefix << " ";
        }
        const StringType& RowName = RowNames[i];
        std::cout << RowName << std::endl;
    }
    std::cout << TerminalUtility::k_Clear;
}

//template<typename T>
//T KT::UI::Multiply(const T& A, const T& B) {
//    return A * B;
//}
