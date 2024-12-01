#include <fstream>
#include <iostream>

#include "Base/MenuSystem/MenuSystem.h"
#include "day-01/Day-01.h"
#include "Utility/IOUtility.h"

int main()
{
    // MenuSystem Men;
    // Menu.AddProblem(std::make_unique_for_overwrite<Day01>());
    // Menu.PrintAllProblems();

    KT::IOUtility::ReadFile("../Test.txt");

    return 0;
}
