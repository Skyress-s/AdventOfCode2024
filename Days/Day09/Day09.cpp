//
// Created by mathm on 05/01/2025.
//

#include "Day09.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <ranges>

#include "Base/DayEnum/DayEnum.h"
#include "Utility/TerminalUtility.h"


namespace KT::Days
{
using DiskType = std::vector<std::optional<long>>;


std::ostream& operator<<(std::ostream& Os, const std::optional<long>& Chunk)
{
          Os << (Chunk.has_value() ? std::to_string(Chunk.value()) : " ");
          return Os;
}

std::ostream& operator<<(std::ostream& Os, const DiskType& Disk)
{
          for (auto newclmap : Disk)
          {
                    Os << newclmap << ' ';
          }
          return Os;
}

EDay Day09::GetDay() const
{
          return EDay::Day09;
}

DiskType BuildDisk(const StringType& Input)
{
          std::cout << TerminalUtility::k_Cyan << "Building disk...\n" << TerminalUtility::k_Clear;
          DiskType Disk {};
          StringType Output;
          for (int i = 0; i < Input.size(); ++i)
          {
                    const bool bIsRealChunk = i % 2 == 0;

                    const int Number = Input[i] - '0';
                    for (int num : std::ranges::views::iota(0, Number)) // Not optimal but very fun
                    {
                              if (bIsRealChunk)
                              {
                                        const long Id = i / 2;
                                        Disk.push_back(std::optional<long>(Id));
                              }
                              else
                              {
                                        Disk.push_back(std::optional<long>());
                              }
                    }
          }
          std::cout << TerminalUtility::k_Green << "Finished Building disk!\n" << TerminalUtility::k_Clear;
          return Disk;
}

bool FlattenDisk(DiskType& OutDisk)
{
          std::cout << TerminalUtility::k_Cyan << "Flattening disk for Part 1...\n" << TerminalUtility::k_Clear;
          int LastIndex = OutDisk.size() - 1;
          for (int i = 0; i < OutDisk.size(); ++i)
          {
                    if (i >= LastIndex)
                              break;

                    if (!OutDisk[i].has_value())
                    {
                              for (; LastIndex >= 0; --LastIndex)
                              {
                                        if (i >= LastIndex)
                                                  break;

                                        if (OutDisk[LastIndex].has_value())
                                        {
                                                  std::swap(OutDisk[i], OutDisk[LastIndex]);
                                                  break;
                                        }
                              }
                    }
          }
          std::cout << TerminalUtility::k_Green << "Finished Flattening disk!\n" << TerminalUtility::k_Clear;
          return true;
          // todo do with list comprehension
}

bool FlattenDisk2(DiskType& OutDisk)
{
          std::cout << TerminalUtility::k_Cyan << "Flattening disk for Part 2... \n" << TerminalUtility::k_Clear;
          int LastIndex = OutDisk.size() - 1;

          std::pair<long, long> CurrentChunk {};

          for (int i = OutDisk.size() - 1; i >= 0; --i)
          {
                    if (OutDisk[i].has_value())
                    {
                              if (CurrentChunk.first != OutDisk[i].value())
                              {
                                        CurrentChunk = {};
                                        continue;
                              }
                              CurrentChunk.first = OutDisk[i].value();
                              CurrentChunk.second++;
                              continue;
                    }
                    if (CurrentChunk.second > 0)
                    {
                              uint16_t Spaces {0};
                              for (int k = 0; k < OutDisk.size(); ++k)
                              {
                                        const std::optional<long>& Value = OutDisk[k];
                                        if (!Value.has_value())
                                        {
                                                  Spaces++;
                                                  if (Spaces == CurrentChunk.second)
                                                  {

                                                  }
                                        }

                              }
                    }
          }
          std::cout << TerminalUtility::k_Green << "Finished Flattening disk!\n" << TerminalUtility::k_Clear;
          return true;
          // todo do with list comprehension
}

IDayProblemBase::DayReturnType ComputeChecksum(const DiskType& Disk)
{
          std::vector<int> test {1, 2, 3, 4, 5};
          auto ZipView = std::views::zip(Disk, std::views::iota(uint64_t(0)));
          // Have to use common to get the "common" iterator -> the begin and end are the same type of iterator.
          // We do this because the std::accumulate requires it. While ranges and views support them not being the same type (sentinels)
          // In newer versions of cpp, there will possibly be a std::ranges::accumulate -> avoid the std::views::common.
          auto CoolView = ZipView | std::views::common;
          std::cout << std::endl;
          auto Result = std::accumulate(CoolView.begin(), CoolView.end(), uint64_t(0),
                                        [](const uint64_t sum, const std::pair<const std::optional<long>, uint64_t>& value)
                                        {
                                                  if (value.first.has_value())
                                                  {
                                                            return sum + value.second * (uint64_t)value.first.value();
                                                  }
                                                  return sum;
                                        });

          return Result;
}

IDayProblemBase::DayReturnType Day09::SolvePart1(const std::vector<StringType>& Input)
{
          assert(("Size is expected to be 1", Input.size() == 1));
          DiskType Disk = BuildDisk(Input[0]);
          // std::cout << "Built Disk:\n" << Disk << "\n";
          FlattenDisk(Disk);
          // std::cout << "Flattened Disk:\n" << Disk << "\n";
          return ComputeChecksum(Disk);
}

IDayProblemBase::DayReturnType Day09::SolvePart2(const std::vector<StringType>& Input)
{
          assert(("Size is expected to be 1", Input.size() == 1));
          DiskType Disk = BuildDisk(Input[0]);
          // std::cout << "Built Disk:\n" << Disk << "\n";
          FlattenDisk(Disk);
          // std::cout << "Flattened Disk:\n" << Disk << "\n";
          return ComputeChecksum(Disk);
}
}
