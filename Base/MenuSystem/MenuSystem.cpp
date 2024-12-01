//
// Created by mathm on 01/12/2024.
//

#include "MenuSystem.h"

#include <iostream>
#include <vector>

#include "Base/ProblemBase.h"
#include "Base/DayEnum/DayEnum.h"

namespace KT {
} // KT
void MenuSystem::AddProblem(std::unique_ptr<ProblemBase> NewProblem) {
    m_Problems.insert(std::make_pair(NewProblem->GetDay(), std::move(NewProblem)));
}


void MenuSystem::PrintAllProblems() {
    std::cout << "Problems: \n";
    for (const auto& ProblemPair: m_Problems) {
        std::cout << ProblemPair.first << "\n";
    }

}
