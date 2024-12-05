#include <fstream>
#include <iomanip>
#include <iostream>

#include "Base/MenuSystem/MenuSystem.h"
#include "Day01/Day01.h"
#include "Day02/Day02.h"
#include "Utility/IOUtility.h"

int main()
{
    // std::cout << "Size of address: " << sizeof(void*) << std::endl;

    MenuSystem Menu;
    Menu.AddProblem(std::make_unique_for_overwrite<Day01>());
    Menu.AddProblem(std::make_unique_for_overwrite<KT::Days::Day02>());
    Menu.SolveProblem2(EDay::Day02, false);
    return 0;
}
