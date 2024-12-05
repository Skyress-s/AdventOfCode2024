//
// Created by mathm on 01/12/2024.
//

#include "MenuSystem.h"

#include <assert.h>
#include <iostream>
#include <vector>

#include "Base/ProblemBase.h"
#include "Base/DayEnum/DayEnum.h"
#include "Utility/IOUtility.h"

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

void MenuSystem::SolveProblem1(const EDay Day, const bool bTest) const {
    assert(m_Problems.contains(Day));

    StringType Path;
    if (bTest) {
        Path = KT::IOUtility::GetTestInputFilePathFromDay(m_Problems.find(Day)->second->GetDay());
    }
    else {
        Path = KT::IOUtility::GetInputFilePathFromDay(m_Problems.find(Day)->second->GetDay());
    }
    const std::vector<StringType> Lines = KT::IOUtility::ReadFile(Path);
    const int32_t AnswerPart1 = m_Problems.find(Day)->second->SolvePart1(Lines);
    std::cout << "Answer To Part1: " << AnswerPart1 << std::endl;
}

void MenuSystem::SolveProblem2(const EDay Day, const bool bTest) const {
    assert(m_Problems.contains(Day));

    StringType Path;
    if (bTest) {
        Path = KT::IOUtility::GetTestInputFilePathFromDay(m_Problems.find(Day)->second->GetDay());
    }
    else {
        Path = KT::IOUtility::GetInputFilePathFromDay(m_Problems.find(Day)->second->GetDay());
    }
    const std::vector<StringType> Lines = KT::IOUtility::ReadFile(Path);
    const int32_t AnswerPart2 = m_Problems.find(Day)->second->SolvePart2(Lines);
    std::cout << "Answer To Part2: " << AnswerPart2 << std::endl;
}
