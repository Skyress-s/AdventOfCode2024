//
// Created by mathm on 01/12/2024.
//

#include "MenuSystem.h"

#include <cassert>
#include <iostream>
#include <ranges>
#include <vector>

#include "Base/IDayProblemBase.h"
#include "Base/ConsoleUtility/ListChoice.h"
#include "Base/TemplateTest.h"
#include "Base/DayEnum/DayEnum.h"
#include "Utility/IOUtility.h"
#include "Utility/TerminalUtility.h"

namespace KT {
} // KT
MenuSystem::MenuSystem(const bool bUseTests, const bool bSolverPart1, const bool bSolverPart2) {
    m_bUseTests = bUseTests;
    m_bSolvePart1 = bSolverPart1;
    m_bSolvePart2 = bSolverPart2;
}

void MenuSystem::AddProblem(std::unique_ptr<IDayProblemBase> NewProblem) {
    m_Problems.insert(std::make_pair(NewProblem->GetDay(), std::move(NewProblem)));
}


void MenuSystem::PrintAllProblems() {
    std::cout << "Problems: \n";
    for (const auto& ProblemPair: m_Problems) {
        std::cout << ProblemPair.first << "\n";
    }

}

void MenuSystem::ChooseProblem() {

    std::function<StringType(const EDay&)> EntryToString = [](const EDay& day) {
        return "Day" + GetDayNumberString(day);
    };
    auto Days = BuildDays();
    std::vector<KT::UI::TListItem<EDay>> ListItems{};
    for (const auto& Day: Days) {
        ListItems.emplace_back(Day, GetDayName(Day));
    }

    const EDay ChosenDay = KT::UI::ListChoice2<EDay>(ListItems, "Choose a problem to solve: ");
    if (m_bSolvePart1)
        SolveProblem1(ChosenDay, m_bUseTests);
    if (m_bSolvePart2)
        SolveProblem2(ChosenDay, m_bUseTests);
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
    const IDayProblemBase::DayReturnType AnswerPart1 = m_Problems.find(Day)->second->SolvePart1(Lines);
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
    const IDayProblemBase::DayReturnType AnswerPart2 = m_Problems.find(Day)->second->SolvePart2(Lines);
    std::cout << "Answer To Part2: " << AnswerPart2 << std::endl;
}

std::vector<EDay> MenuSystem::BuildDays() const {
    std::vector<EDay> Days;

    for (const auto& Day: std::views::keys(m_Problems)) {
        Days.push_back(Day);
    }

    return Days;
}
