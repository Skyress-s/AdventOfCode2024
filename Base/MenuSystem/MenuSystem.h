//
// Created by mathm on 01/12/2024.
//

#pragma once
#include <memory>
#include <unordered_map>

#include "Base/DayEnum/DayEnum.h"

class ProblemBase;
enum class EDay: uint8_t;

/// todo explain
/// assumes that there can only be one of each problem.
///
class MenuSystem {

public:
    void AddProblem(std::unique_ptr<ProblemBase> NewProblem);

    void PrintAllProblems();

    void SolveProblem(const EDay Day) const;

private:
    std::unordered_map<EDay, std::unique_ptr<ProblemBase>> m_Problems;
};
