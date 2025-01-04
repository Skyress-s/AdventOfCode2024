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
#include "Utility/GridMath.h"
#include "Utility/PrimeFactorization.h"


std::ostream& operator<<(std::ostream& Os, const std::vector<int16_t>& Numbers)
{
          for (const int16_t Number : Numbers)
          {
                    Os << Number << ' ';
          }
          return Os;
}

int main()
{
          // const Math::SVector2I From1To2 = Math::SVector2I(2, 5) - Math::SVector2I(2, 2);
          /*
          const Math::SVector2I From1To2 = {3, 4};

          std::vector<int16_t> XFactorization = BasicPrimeFactorization(From1To2.X);
          std::vector<int16_t> YFactorization = BasicPrimeFactorization(From1To2.Y);

          std::cout << "Before : \n";
          std::cout << XFactorization << '\n';
          std::cout << YFactorization << '\n';

          std::vector<int16_t> CommonPrimes{};

          for (int i = 0; i < XFactorization.size(); ++i)
          {
                    const int16_t CurrentPrime = XFactorization[i];
                    auto result = std::ranges::find_if(YFactorization, [CurrentPrime](const int16_t Prime)
                    {
                              return CurrentPrime == Prime;
                    });
                    if (result != YFactorization.end())
                    {
                              CommonPrimes.emplace_back(CurrentPrime);
                    }
          }


          std::cout << "Common Primes: \n";
          std::cout << CommonPrimes << '\n';
          */


          // getch();
          // return 0;

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
