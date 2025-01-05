//
// Created by mathm on 21/12/2024.
//

#include "Day08.h"

#include <iostream>
#include <math.h>
#include <numeric>
#include <ranges>
#include <unordered_set>

#include "Utility/GridMath.h"
#include "Base/DayEnum/DayEnum.h"
#include "Base/Vector2D/Vector2D.h"
#include "Base/Grid/TGrid.h"
#include "Utility/PrimeFactorization.h"

namespace std
{
template <>
struct hash<std::pair<char, Math::SVector2I>>
{
          std::size_t operator()(const std::pair<char, Math::SVector2I>& Vector) const noexcept
          {
                    return std::hash<int16_t>()(Vector.second.X) ^ (std::hash<int16_t>()(Vector.second.Y) << 1);
          }
};
}

namespace KT::Days
{
EDay Day08::GetDay() const
{
          return EDay::Day08;
}

using AntennasContainer = std::unordered_set<std::pair<char, Math::SVector2I>>;

std::ostream& operator<<(std::ostream& Os, const AntennasContainer& Antennas)
{
          for (const auto& Antenna : Antennas)
          {
                    Os << Antenna.first << " " << Antenna.second << '\n';
          }
          return Os;
}

std::ostream& operator<<(std::ostream& Os, const std::unordered_set<Math::SVector2I>& VectorSet)
{
          for (const Math::SVector2I& Vector : VectorSet)
          {
                    Os << Vector << ' ';
          }
          Os << '\n';
          return Os;
}

std::ostream& operator<<(std::ostream& Os, const std::vector<int16_t>& Values)
{
          for (const int16_t Vector : Values)
          {
                    Os << Vector << ' ';
          }
          return Os;
}

AntennasContainer AllAntennaValues(const std::vector<StringType>& Input)
{
          AntennasContainer Antennas{};

          assert(!Input.empty());

          for (auto RowItr = Input.begin(); RowItr != Input.end(); ++RowItr)
          {
                    for (auto CharItr = RowItr->begin(); CharItr != RowItr->end(); ++CharItr)
                    {
                              if (*CharItr != '.')
                              {
                                        const int16_t X = (int16_t)std::distance(RowItr->begin(), CharItr);
                                        const int16_t Y = (int16_t)(std::distance(Input.begin(), RowItr));
                                        Antennas.emplace(*CharItr, Math::SVector2I{X, Y});
                              }
                    }
          }
          return Antennas;
}

TGrid<char> BuildGridFromInput(const std::vector<StringType>& Input)
{
          TGrid<char>::GridType Grid;
          for (auto ItrY = Input.begin(); ItrY != Input.end(); ++ItrY)
          {
                    TGrid<char>::RowType Row;
                    for (auto ItrX = ItrY->begin(); ItrX != ItrY->end(); ++ItrX)
                    {
                              Row.push_back(*ItrX);
                    }
                    Grid.push_back(Row);
          }
          return TGrid(Grid);
}

std::vector<Math::SVector2I> ComputeAntinodesFromAntennaPair(const Math::SVector2I& Antenna1, const Math::SVector2I& Antenna2)
{
          const Math::SVector2I From1To2 = Antenna2 - Antenna1;
          std::vector<Math::SVector2I> Antinodes{};
          Antinodes.emplace_back(Antenna1 - From1To2);
          Antinodes.emplace_back(Antenna2 + From1To2);
          return Antinodes;
}

// bool IsCloseToInteger(const float Value)
// {
//           constexpr float c_Tollerance = std::numeric_limits<float>::min() * 1000.f;
//           return std::abs(roundf(Value) - Value) < c_Tollerance;
// }


bool LocationOOB(const Math::SVector2I& Max, Math::SVector2I& Location)
{
          return Location.X < 0 || Location.Y < 0 || Location.X > Max.X || Location.Y > Max.Y;
}

void FilterAntinodesOOB(const Math::SVector2I& Max, std::unordered_set<Math::SVector2I>& InOutAntinodes)
{
          for (int i = 0; i < InOutAntinodes.size(); ++i)
          {
                    const Math::SVector2I& Antinode = *std::next(InOutAntinodes.begin(), i);
                    if (Antinode.X < 0 || Antinode.Y < 0 || Antinode.X >= Max.X || Antinode.Y >= Max.Y)
                    {
                              InOutAntinodes.erase(Antinode);
                              i--;
                    }
          }
}


std::unordered_set<Math::SVector2I> ComputeResonantAntinodesFromAntennaPair(const Math::SVector2I& Max, const Math::SVector2I& Antenna1,
                                                                            const Math::SVector2I& Antenna2)
{
          const Math::SVector2I From1To2 = Antenna2 - Antenna1;

          std::vector<int16_t> XFactorization = BasicPrimeFactorization(static_cast<int16_t>(abs(From1To2.X)));
          std::vector<int16_t> YFactorization = BasicPrimeFactorization(static_cast<int16_t>(abs(From1To2.Y)));

          std::vector<int16_t> CommonPrimes{};

          for (int i = 0; i < XFactorization.size(); ++i)
          {
                    const int16_t CurrentPrime = XFactorization[i];
                    auto FoundYItr = std::ranges::find_if(YFactorization, [CurrentPrime](const int16_t Prime)
                    {
                              return CurrentPrime == Prime;
                    });
                    if (FoundYItr != YFactorization.end())
                    {
                              XFactorization.erase(XFactorization.begin() + i);
                              i--;
                              YFactorization.erase(FoundYItr);

                              CommonPrimes.emplace_back(CurrentPrime);
                    }
          }

          std::cout << "Common Primes: " << CommonPrimes << '\n';

          Math::SVector2I Delta = From1To2;
          for (const int16_t CommonPrime : CommonPrimes)
          {
                    Delta = Delta / CommonPrime;
          }

          if (Delta.X == 0)
          {
                    Delta.Y = std::clamp(Delta.Y, static_cast<int16_t>(-1), static_cast<int16_t>(1));
          }
          if (Delta.Y == 0)
          {
                    Delta.X = std::clamp(Delta.X, static_cast<int16_t>(-1), static_cast<int16_t>(1));
          }

          std::cout << "final delta: " << Delta << '\n';

          std::unordered_set<Math::SVector2I> Antinodes{};

          Math::SVector2I CurrentLocation = Antenna1;
          while (!LocationOOB(Max, CurrentLocation))
          {
                    Antinodes.emplace(CurrentLocation);
                    CurrentLocation = CurrentLocation + Delta;
          }

          CurrentLocation = Antenna1;
          while (!LocationOOB(Max, CurrentLocation))
          {
                    Antinodes.emplace(CurrentLocation);
                    CurrentLocation = CurrentLocation - Delta;
          }


          return Antinodes;

}

std::unordered_set<Math::SVector2I> ComputeAntinodesForAntennaType(const AntennasContainer& Antennas, const char AntennaType)
{
          std::unordered_set<Math::SVector2I> Antinodes{};

          auto Antenna0View = std::views::filter(Antennas, [&AntennaType](const auto& Antenna)
          {
                    return Antenna.first == AntennaType;
          });


          for (const std::pair<char, Math::TVector2D<short>>& Antenna1 : Antenna0View)
          {
                    for (const std::pair<char, Math::TVector2D<short>>& Antenna2 : Antenna0View)
                    {
                              const bool bIsUnique = Antenna1 != Antenna2;
                              if (bIsUnique)
                              {
                                        std::vector<Math::SVector2I> NewAntinodes = ComputeAntinodesFromAntennaPair(Antenna1.second, Antenna2.second);
                                        for (const Math::SVector2I& NewAntinode : NewAntinodes)
                                        {
                                                  Antinodes.emplace(NewAntinode);
                                        }
                              }
                    }
          }

          return Antinodes;
}

std::unordered_set<Math::SVector2I> ComputeResonantAntinodesForAntennaType(const Math::SVector2I& Max, const AntennasContainer& Antennas,
                                                                           const char AntennaType)
{
          std::unordered_set<Math::SVector2I> Antinodes{};

          auto Antenna0View = std::views::filter(Antennas, [&AntennaType](const auto& Antenna)
          {
                    return Antenna.first == AntennaType;
          });


          for (const std::pair<char, Math::TVector2D<short>>& Antenna1 : Antenna0View)
          {
                    for (const std::pair<char, Math::TVector2D<short>>& Antenna2 : Antenna0View)
                    {
                              const bool bIsUnique = Antenna1 != Antenna2;
                              if (bIsUnique)
                              {
                                        std::unordered_set<Math::SVector2I> NewAntinodes = ComputeResonantAntinodesFromAntennaPair(
                                                  Max, Antenna1.second, Antenna2.second);
                                        Antinodes.merge(NewAntinodes);
                              }
                    }
          }

          return Antinodes;
}

IDayProblemBase::DayReturnType Day08::SolvePart1(const std::vector<StringType>& Input)
{
          const AntennasContainer Antennas = AllAntennaValues(Input);

          std::vector<char> AntennaTypes = std::accumulate(Antennas.begin(), Antennas.end(), std::vector<char>{},
                                                           [](std::vector<char> vector, const std::pair<char, Math::SVector2I>& Value)
                                                           {
                                                                     const bool bContains = std::ranges::any_of(vector, [Value](const char& Antenna)
                                                                     {
                                                                               return Antenna == Value.first;
                                                                     });
                                                                     // const bool bContains = std::ranges::count_if(vector, [Value](const char& Antenna)
                                                                     // {
                                                                     //           return Antenna == Value.first;
                                                                     // }) > 0;
                                                                     if (!bContains)
                                                                               vector.push_back(Value.first);

                                                                     return vector;
                                                           });

          std::cout << "Antenna Types: ";
          for (const char AntennaType : AntennaTypes)
          {
                    std::cout << AntennaType << ' ';
          }
          std::cout << '\n';

          std::unordered_set<Math::SVector2I> Antinodes{};
          for (const char AntennaType : AntennaTypes)
          {
                    std::unordered_set<Math::SVector2I> NewAntinodes = ComputeAntinodesForAntennaType(Antennas, AntennaType);
                    Antinodes.merge(NewAntinodes);
          }

          std::cout << "Total Before Filtering " << Antinodes.size() << ':' << std::endl;
          std::cout << Antinodes << std::endl;
          // Loop through them and create the
          FilterAntinodesOOB({(int16_t)Input.size(), (int16_t)Input[0].size()}, Antinodes);

          std::cout << "After Filtering " << Antinodes.size() << ':' << std::endl;
          std::cout << Antinodes << std::endl;
          return (IDayProblemBase::DayReturnType)Antinodes.size();
}

IDayProblemBase::DayReturnType Day08::SolvePart2(const std::vector<StringType>& Input)
{
          const AntennasContainer Antennas = AllAntennaValues(Input);

          // std::unordered_set<Math::SVector2I> Antinodess = ComputeResonantAntinodesFromAntennaPair({10, 10}, {5, 5}, {5, 4});
          // std::cout << Antinodess << '\n';
          // return INVALID_RESULT;


          std::vector<char> AntennaTypes = std::accumulate(Antennas.begin(), Antennas.end(), std::vector<char>{},
                                                           [](std::vector<char> vector, const std::pair<char, Math::SVector2I>& Value)
                                                           {
                                                                     const bool bContains = std::ranges::any_of(vector, [Value](const char& Antenna)
                                                                     {
                                                                               return Antenna == Value.first;
                                                                     });
                                                                     if (!bContains)
                                                                               vector.push_back(Value.first);

                                                                     return vector;
                                                           });

          std::cout << "Antenna Types: ";
          for (const char AntennaType : AntennaTypes)
          {
                    std::cout << AntennaType << ' ';
          }
          std::cout << '\n';

          std::unordered_set<Math::SVector2I> Antinodes{};
          const Math::SVector2I Max{
                    (int16_t)(static_cast<int16_t>(Input[0].size()) - static_cast<int16_t>(1)),
                    (int16_t)(static_cast<int16_t>(Input.size()) - static_cast<int16_t>(1))
          };
          for (const char AntennaType : AntennaTypes)
          {
                    // todo I don't like that i just duplicate the functon here. Could easily use a std::function as param or similar here.
                    std::unordered_set<Math::SVector2I> NewAntinodes = ComputeResonantAntinodesForAntennaType(Max, Antennas, AntennaType);
                    Antinodes.merge(NewAntinodes);
          }

          std::cout << "Total Before Filtering " << Antinodes.size() << ':' << std::endl;
          std::cout << Antinodes << std::endl;

          std::cout << "After Filtering " << Antinodes.size() << ':' << std::endl;
          std::cout << Antinodes << std::endl;
          return (IDayProblemBase::DayReturnType)Antinodes.size();
}
}
