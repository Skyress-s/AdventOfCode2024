#include <iostream>

#include "Base/MenuSystem/MenuSystem.h"
#include "day-01/Day-01.h"

int main()
{
    MenuSystem Menu;
    Menu.AddProblem(std::make_unique_for_overwrite<Day01>());
    Menu.PrintAllProblems();

    return 0;
}
