//
// Created by mathm on 01/12/2024.
//

#pragma once
#include <memory>
#include <unordered_map>

class ProblemBase;
enum class EDay: uint8_t;

/// todo explain
/// assumes that there can only be one of each problem.
///
class MenuSystem {

public:
    void AddProblem(std::unique_ptr<ProblemBase> NewProblem);

    void PrintAllProblems();

private:
    std::unordered_map<EDay, std::unique_ptr<ProblemBase>> m_Problems;
};
