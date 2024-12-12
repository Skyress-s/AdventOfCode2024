#include <variant>

#include "Base/ConsoleUtility/ListChoice.h"
#include "Base/MenuSystem/MenuSystem.h"
#include "Days/Day01/Day01.h"
#include "Days/Day02/Day02.h"
#include "Days/Day03/Day03.h"
#include "Days/Day04/Day04.h"
#include "Utility/IOUtility.h"
#include "Utility/ParseUtility/ParseUtility.h"


int main()
{
    // std::cout << "Size of address: " << sizeof(void*) << std::endl;

    // Not too pretty. But it works for now. I need to actually solve the problems!
    std::function<StringType(const int32_t&)> Func = [](const int32_t& Value) {
        if (Value == 1)
            return "Solve Part 1";
        if (Value == 2)
            return "Solve Part 2";

        return "Solve Part 1 and 2";
    };

    const int32_t Choice =  KT::UI::ListChoice({1,2,3}, "Question Setup", Func);
    KT::TerminalUtility::ClearTerminal();
    // return 0;
    MenuSystem Menu(false, Choice == 1 || Choice == 3, Choice == 2 || Choice == 3);
    Menu.AddProblem(std::make_unique_for_overwrite<KT::Days::Day01>());
    Menu.AddProblem(std::make_unique_for_overwrite<KT::Days::Day02>());
    Menu.AddProblem(std::make_unique_for_overwrite<KT::Days::Day03>());
    Menu.AddProblem(std::make_unique_for_overwrite<KT::Days::Day04>());

    try {
        Menu.ChooseProblem();
    } catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    getch();
    // std::cin >> std::ws; // Give Used time to read the output and then exit.

    return 0;
}
