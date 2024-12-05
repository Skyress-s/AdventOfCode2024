#include <fstream>
#include <iomanip>
#include <iostream>

#include "Base/MenuSystem/MenuSystem.h"
#include "day-01/Day-01.h"
#include "Utility/IOUtility.h"

int main()
{
    MenuSystem Menu;
    Menu.AddProblem(std::make_unique_for_overwrite<Day01>());
    Menu.SolveProblem(EDay::Day01);
    std::cout << "Size of address: " << sizeof(void*) << std::endl;
    return 0;
}
