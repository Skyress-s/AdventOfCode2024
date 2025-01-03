//
// Created by mathm on 21/12/2024.
//

#include "Day08.h"

#include <iostream>
#include <numeric>
#include <ranges>
#include <unordered_set>

#include "Base/DayEnum/DayEnum.h"
#include "Base/Vector2D/Vector2D.h"
#include "Base/Grid/TGrid.h"

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
                    Os << '{' << Vector << '}' << ' ';
          }
          Os << '\n';
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

std::vector<Math::SVector2I> ComputeResonantAntinodesFromAntennaPair(const Math::SVector2I& Antenna1, const Math::SVector2I& Antenna2)
{
          const Math::SVector2I From1To2 = Antenna2 - Antenna1;


          const float ForwardPerUp = std::abs(From1To2.X / From1To2.Y);

          for (int i = 1; i < std::abs(From1To2.Y); ++i)
          {
                    float X = (float)i * ForwardPerUp;
                    Math::SVector2I(, From1To2.Y);
          }



          std::vector<Math::SVector2I> Antinodes{};
          Antinodes.emplace_back(Antenna1 - From1To2);
          Antinodes.emplace_back(Antenna2 + From1To2);
          return Antinodes;
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

IDayProblemBase::DayReturnType Day08::SolvePart1(const std::vector<StringType>& Input)
{
          const AntennasContainer Antennas = AllAntennaValues(Input);

          std::vector<char> AntennaTypes = std::accumulate(Antennas.begin(), Antennas.end(), std::vector<char>{}, [](std::vector<char> vector, const std::pair<char, Math::SVector2I>& Value)
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

          std::vector<char> AntennaTypes = std::accumulate(Antennas.begin(), Antennas.end(), std::vector<char>{}, [](std::vector<char> vector, const std::pair<char, Math::SVector2I>& Value)
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
}
