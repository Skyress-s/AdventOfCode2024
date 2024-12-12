//
// Created by mathm on 09/12/2024.
//

#include "Day04.h"

#include <algorithm>
#include <assert.h>
#include <iostream>
#include <bits/fs_fwd.h>

#include "Base/DayEnum/DayEnum.h"

namespace KT::Days
{
      constexpr inline StringType k_XMAS = "XMAS";
      constexpr inline StringType k_XMAX_R = "SAMX";

      struct Item
      {
            char North[4] = {'_', '_', '_', '_'};
            char NorthEast[4] = {'_', '_', '_', '_'};
            char NorthWest[4] = {'_', '_', '_', '_'};
            char West[4] = {'_', '_', '_', '_'};
            char East[4] = {'_', '_', '_', '_'};
      };

      using Width_t = uint16_t;
      using RowType = std::vector<char>;
      using GridType = std::vector<RowType>;


      GridType BuildGrid(const std::vector<StringType> &Input)
      {
            GridType Grid = {};
            for (const StringType &Line: Input)
            {
                  RowType Row{};
                  for (const char &Character: Line)
                  {
                        Row.emplace_back(Character);
                  }
                  Grid.emplace_back(Row);
            }
            return Grid;
      }


      inline void PrintGrid(const GridType &Grid)
      {
            for (const RowType &Row: Grid)
            {
                  for (const char &Character: Row)
                  {
                        std::cout << Character << " ";
                  }
                  std::cout << std::endl;
            }
      }

      inline bool IsLocationInGrid(const GridType &Grid, const size_t Row, const size_t Column)
      {
            // std::cout << "Location is in grid: " << (Grid.size() && Column < Grid[0].size()) << " Row: " << Row << ", " << Column << std::endl;
            return Row < Grid.size()
                   // && Row >= 0
                   && Column < Grid[0].size();
            // && Column >= 0;
      }

      inline char GetCharAtRowAndCollumn(const GridType &Grid, const Width_t Row, const Width_t Col)
      {
            return Grid[Row][Col];
      }

      inline bool HasLocationChar(const GridType &Grid, const Width_t Row, const Width_t Col, const char Char)
      {
            return IsLocationInGrid(Grid, Row, Col) && GetCharAtRowAndCollumn(Grid, Row, Col) == Char;
      }


      /// The Word must start at this location
      /// @param Grid
      /// @param Word
      /// @param Row
      /// @param Col
      /// @return num instances of world found
      inline uint8_t SearchLocationForWord(const GridType &Grid, const StringType &Word, const Width_t Row,
                                           const Width_t Col)
      {
            if (Word.empty())
                  return false;

            // special case for first character
            // std::cout << "Char: " << GetCharAtRowAndCollumn(Grid, Row, Col) << ". At location: " << Row << ", " << Col << std::endl;
            if (!IsLocationInGrid(Grid, Row, Col) || Word[0] != GetCharAtRowAndCollumn(Grid, Row, Col))
            {
                  return false;
            }

            uint16_t NumMatches[8] = {0, 0, 0, 0, 0, 0, 0, 0};
            // Going clockwise from 12 o'clock.
            for (int i = 1; i < Word.size(); ++i)
            {
                  NumMatches[0] += HasLocationChar(Grid, Row + i, Col, Word[i]);
                  NumMatches[1] += HasLocationChar(Grid, Row + i, Col + i, Word[i]);
                  NumMatches[2] += HasLocationChar(Grid, Row, Col + i, Word[i]);
                  NumMatches[3] += HasLocationChar(Grid, Row - i, Col + i, Word[i]);
                  NumMatches[4] += HasLocationChar(Grid, Row - i, Col, Word[i]);
                  NumMatches[5] += HasLocationChar(Grid, Row - i, Col - i, Word[i]);
                  NumMatches[6] += HasLocationChar(Grid, Row, Col - i, Word[i]);
                  NumMatches[7] += HasLocationChar(Grid, Row + i, Col - i, Word[i]);
            }

            uint32_t NumInstancesWord{0};
            for (int num_match: NumMatches)
            {
                  NumInstancesWord += num_match == Word.size() - 1;
            }
            return NumInstancesWord;
      }

      inline uint8_t SearchLocationForWordX(const GridType &Grid, const StringType &Word, const Width_t Row,
                                            const Width_t Col)
      {
            if (Word.empty())
                  return false;

            // special case for first character
            // std::cout << "Char: " << GetCharAtRowAndCollumn(Grid, Row, Col) << ". At location: " << Row << ", " << Col << std::endl;
            if (!IsLocationInGrid(Grid, Row, Col) || Word[0] != GetCharAtRowAndCollumn(Grid, Row, Col))
            {
                  return false;
            }

            uint16_t NumMatches[4] = {0, 0, 0, 0};
            // Going clockwise from 12 o'clock.
            for (int i = 1; i < Word.size(); ++i)
            {
                  // NumMatches[0] += HasLocationChar(Grid, Row + i,      Col,     Word[i]);
                  NumMatches[0] += HasLocationChar(Grid, Row + i, Col + i, Word[i]);
                  // NumMatches[2] += HasLocationChar(Grid, Row,          Col + i, Word[i]);
                  NumMatches[1] += HasLocationChar(Grid, Row - i, Col + i, Word[i]);
                  // NumMatches[4] += HasLocationChar(Grid, Row - i,      Col,     Word[i]);
                  NumMatches[2] += HasLocationChar(Grid, Row - i, Col - i, Word[i]);
                  // NumMatches[6] += HasLocationChar(Grid, Row,          Col - i, Word[i]);
                  NumMatches[3] += HasLocationChar(Grid, Row + i, Col - i, Word[i]);
            }

            uint32_t NumInstancesWord{0};
            for (const int num_match: NumMatches)
            {
                  NumInstancesWord += num_match == Word.size() - 1;
            }
            return NumInstancesWord;
      }

      uint64_t FindInstancesWordInGrid(const GridType &Grid, const StringType &Word)
      {
            assert(!Grid.empty());
            assert(!Grid[0].empty());

            uint32_t NumInstancesWord{0};
            for (int i = 0; i < Grid.size(); ++i)
            {
                  const RowType &Row = Grid[i];
                  for (int j = 0; j < Row.size(); ++j)
                  {
                        NumInstancesWord += SearchLocationForWord(Grid, Word, i, j);
                  }
            }
            return NumInstancesWord;
      }

      uint64_t FindInstancesWordInGridX(const GridType &Grid, const StringType &Word1, const StringType &Word2)
      {
            assert(!Grid.empty());
            assert(!Grid[0].empty());

            uint32_t NumInstancesWord{0};
            for (int i = 0; i < Grid.size(); ++i)
            {
                  const RowType &Row = Grid[i];
                  for (int j = 0; j < Row.size(); ++j)
                  {
                        uint32_t NumInstancesWord1 = SearchLocationForWordX(Grid, Word1, i, j);
                        uint32_t NumInstancesWord2 = SearchLocationForWordX(Grid, Word2, i, j);;
                        NumInstancesWord += (NumInstancesWord1 == 2 && NumInstancesWord2 == 2);
                  }
            }
            return NumInstancesWord;
      }

      EDay Day04::GetDay() const
      {
            return EDay::Day04;
      }

      int32_t Day04::SolvePart1(const std::vector<StringType> &Input)
      {
            GridType Grid = BuildGrid(Input);

            PrintGrid(Grid);

            // construct 2d array.
            // Search along directions.
            return FindInstancesWordInGrid(Grid, k_XMAS);
      }

      int32_t Day04::SolvePart2(const std::vector<StringType> &Input)
      {
            GridType Grid = BuildGrid(Input);

            return FindInstancesWordInGridX(Grid, "AM", "AS");
      }
}
