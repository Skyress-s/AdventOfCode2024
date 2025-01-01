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
          std::size_t operator()(const Math::SVector2I& Vector) const noexcept
          {
                    return std::hash<int16_t>()(Vector.X) ^ (std::hash<int16_t>()(Vector.Y) << 1);
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

AntennasContainer AllAntennaValues(const std::vector<StringType>& Input)
{
          AntennasContainer Antennas{};

          std::for_each(Input.begin(), Input.end(), [&Antennas](const StringType& Row)
          {
                    std::for_each(Row.begin(), Row.end(), [&Antennas](const char& CharLocation)
                    {
                              if (CharLocation != '.')
                              {
                              }
                    });
                    for (const char& Antenna : Row)
                    {
                              Antennas.emplace(Antenna, Math::SVector2I{0, 0});
                    }
          });
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
          TGrid<char> Grid = BuildGridFromInput(Input);


          std::cout << Grid << std::endl;
          return INVALID_RESULT;
}

IDayProblemBase::DayReturnType Day08::SolvePart2(const std::vector<StringType>& Input)
{
          return INVALID_RESULT;
}
}
