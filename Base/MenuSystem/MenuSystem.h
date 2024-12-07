//
// Created by mathm on 01/12/2024.
//

#pragma once
#include <memory>
#include <unordered_map>
#include <vector>

#include "Base/DayEnum/DayEnum.h"

class IDayProblemBase;
enum class EDay: uint8_t;

/// todo explain
/// assumes that there can only be one of each problem.
///
class MenuSystem {
public:
    explicit MenuSystem(const bool bUseTests, const bool bSolverPart1, const bool bSolverPart2);
    void AddProblem(std::unique_ptr<IDayProblemBase> NewProblem);

    void PrintAllProblems();
    void ChooseProblem();

    void SolveProblem1(const EDay Day, bool bTest) const;
    void SolveProblem2(const EDay Day, bool bTest) const;

private:
    std::vector<EDay> BuildDays() const;
    std::unordered_map<EDay, std::unique_ptr<IDayProblemBase>> m_Problems;
    bool m_bUseTests;
    bool m_bSolvePart1;
    bool m_bSolvePart2;
};
