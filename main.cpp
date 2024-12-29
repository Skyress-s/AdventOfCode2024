#include <variant>
#include <functional>
#include <bits/ranges_algo.h>

#include "Base/MenuSystem/MenuSystem.h"
#include "Days/Day01/Day01.h"
#include "Days/Day02/Day02.h"
#include "Days/Day03/Day03.h"
#include "Days/Day04/Day04.h"
#include "Days/Day05/Day05.h"
#include "Days/Day06/Day06.h"
#include "Utility/IOUtility.h"
#include "Utility/ParseUtility/ParseUtility.h"
#include "Base/ConsoleUtility/ListChoice.h"
#include "Base/TemplateTest.h"
#include "Base/Grid/TGrid.h"
#include "Days/Day07/Day07.h"
#include "Days/Day08/Day08.h"

int main()
{

	const int Choice = KT::UI::ListChoice2<int>({{1, "Solve Part 1"}, {2, "Solve Part 2"}, {3, "Solve Part 1 and 2"}}, "Question Setup");
	const bool bTest = KT::UI::ListChoice2<bool>({{true, "Yes"}, {false, "No"}}, "Do you want to run tests?");

	MenuSystem Menu(bTest, Choice == 1 || Choice == 3, Choice == 2 || Choice == 3);
	Menu.AddProblem(std::make_unique_for_overwrite<KT::Days::Day01>());
	Menu.AddProblem(std::make_unique_for_overwrite<KT::Days::Day02>());
	Menu.AddProblem(std::make_unique_for_overwrite<KT::Days::Day03>());
	Menu.AddProblem(std::make_unique_for_overwrite<KT::Days::Day04>());
	Menu.AddProblem(std::make_unique_for_overwrite<KT::Days::Day05>());
	Menu.AddProblem(std::make_unique_for_overwrite<KT::Days::Day06>());
	Menu.AddProblem(std::make_unique_for_overwrite<KT::Days::Day07>());
	Menu.AddProblem(std::make_unique_for_overwrite<KT::Days::Day08>());

	try
	{
		Menu.ChooseProblem();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	getch();
	// std::cin >> std::ws; // Give Used time to read the output and then exit.

	return 0;
}
