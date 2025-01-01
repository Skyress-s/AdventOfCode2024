//
// Created by mathm on 21/12/2024.
//

#include "Day08.h"

#include <iostream>
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

AntennasContainer AllAntennaValues(const std::vector<StringType>& Input)
{
          AntennasContainer Antennas{};

          for (auto RowItr = Input.begin(); RowItr != Input.end(); ++RowItr)
          {
                    for (auto CharItr = RowItr->begin(); CharItr != RowItr->end(); ++CharItr)
                    {
                              if (*CharItr != '.')
                              {
                                        Antennas.emplace(*CharItr, Math::SVector2I{(int16_t)std::distance(CharItr, RowItr->end()), (int16_t)std::distance(RowItr, Input.end())});
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

IDayProblemBase::DayReturnType Day08::SolvePart1(const std::vector<StringType>& Input)
{
          auto Antennas = AllAntennaValues(Input);


          std::cout << Antennas << std::endl;
          return INVALID_RESULT;
}

IDayProblemBase::DayReturnType Day08::SolvePart2(const std::vector<StringType>& Input)
{
          return INVALID_RESULT;
}
}
