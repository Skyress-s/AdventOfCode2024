//
// Created by mathm on 07/12/2024.
//

#include "Day03.h"

#include <iostream>
#include <regex>
#include <variant>

#include "Base/DayEnum/DayEnum.h"
#include "Utility/ParseUtility/ParseUtility.h"

namespace KT::Days {
EDay Day03::GetDay() {
      return EDay::Day03;
}

constexpr StringType k_MulInstruction = "mul(";

int32_t Day03::SolvePart1(const std::vector<StringType>& Input) {
      int32_t Sum{0};

      // I should probably use some pattern matching lib or std::variant / std::visit here?

      std::vector<StringType> Lines = Input;
      for (StringType Line: Lines) {
            int32_t Index{0};

            Index = Line.find(k_MulInstruction);
            while (Index != StringType::npos) {
                  std::cout << "Line: " << Line << std::endl;
                  const int32_t NumberStart = Index + k_MulInstruction.size();
                  int32_t FirstNumberSize{0};
                  const int32_t FirstNumber = ParseUtility::ParseNumberFromStart(
                        Line.substr(NumberStart), &FirstNumberSize);
                  if (FirstNumberSize > 3) {
                        Line = Line.substr(NumberStart);
                        Index = Line.find(k_MulInstruction);
                        continue;
                  }

                  if (NumberStart + FirstNumberSize >= Line.size() || Line[NumberStart + FirstNumberSize] !=
                      ',') {
                        Line = Line.substr(NumberStart);
                        Index = Line.find(k_MulInstruction);
                        continue;
                  }

                  int32_t SecondNumberSize{0};
                  const int32_t SecondNumber = ParseUtility::ParseNumberFromStart(
                        Line.substr(NumberStart + FirstNumberSize + 1), &SecondNumberSize);
                  if (SecondNumberSize > 3) {
                        Line = Line.substr(NumberStart);
                        Index = Line.find(k_MulInstruction);
                        continue;
                  }

                  if (NumberStart + FirstNumberSize + SecondNumberSize + 1 >= Line.size() || Line[
                            NumberStart + FirstNumberSize + SecondNumberSize + 1] != ')') {
                        Line = Line.substr(NumberStart);
                        Index = Line.find(k_MulInstruction);
                        continue;
                  }

                  // If we reach here. Valid number
                  Sum += FirstNumber * SecondNumber;

                  Line = Line.substr(NumberStart);
                  Index = Line.find(k_MulInstruction);
            }
      }
      return Sum;
}
constexpr StringType k_DoInstruction = "do()";
constexpr StringType k_DontInstruction = "don't()";

enum class EInstruction : uint8_t {
      Do,
      Dont,
      Mul
};

struct MulInstruction {
      int32_t FirstNumber;
      int32_t SecondNumber;
};

struct Instruction {
      EInstruction m_InstructionType;

      uint32_t m_Index;

      std::variant<std::monostate /*for Do and Don't instructions*/, MulInstruction> m_InstructionData;
};

std::ostream& operator<<(std::ostream& os, const Instruction& Instruction) {
      os << "Instruction: ";
      switch (Instruction.m_InstructionType) {
            case EInstruction::Do:
                  os << "Do";
                  break;
            case EInstruction::Dont:
                  os << "Dont";
                  break;
            case EInstruction::Mul:
                  const MulInstruction& MulInstructionNew = std::get<MulInstruction>(Instruction.m_InstructionData);
                  os << "Mul {" << MulInstructionNew.FirstNumber << ", " << MulInstructionNew.SecondNumber << "}";
                  break;
      }
      os << " Index: " << Instruction.m_Index;
      return os;
}

int32_t Day03::SolvePart2(const std::vector<StringType>& Input) {

      std::vector<Instruction> Instructions{};

      // Find all instructions and the indices.
      /*
      for (const StringType& Line: Input) { // Do instructions
            int32_t DoInstructionIndex = Line.find(k_DoInstruction);
            while (DoInstructionIndex != std::variant_npos) {
                  Instructions.emplace_back(EInstruction::Do, DoInstructionIndex, std::monostate{});
                  DoInstructionIndex = Line.find(k_DoInstruction, DoInstructionIndex + 1); // Find next
            }
      }

      for (const auto& Line: Input) { // Dont instructions
            int32_t DontInstructionIndex = Line.find(k_DontInstruction);
            while (DontInstructionIndex != std::variant_npos) {
                  Instructions.emplace_back(EInstruction::Dont, DontInstructionIndex, std::monostate{});
                  DontInstructionIndex = Line.find(k_DontInstruction, DontInstructionIndex + 1); // Find next
            }
      }
      */

      for (const StringType& Line: Input) {
            // int32_t InstructionIndex = Line.find(k_MulInstruction);
            // while (InstructionIndex != std::variant_npos) {
                  // std::regex MulInstructionRegex{R"((mul\()(\d{0,3})\,(\d{0,3})\))"};
                  std::regex MulInstructionRegex{R"(do\(\)|don't\(\)|(mul\()(\d{0,3})\,(\d{0,3})\))"};
                  std::smatch matches;
                  auto begin = std::sregex_iterator(Line.begin(), Line.end(), MulInstructionRegex);
                  auto end = std::sregex_iterator();

                  for (std::sregex_iterator itr = begin; itr != end; ++itr) {

                        std::cout << " hrhrhr" << itr->str(0) << std::endl;

                        std::smatch match = *itr;
                        const StringType& InstructionType = match.str(1);
                        if (InstructionType == k_MulInstruction) {
                              int32_t test = itr->position(0);
                              Instructions.push_back(Instruction{EInstruction::Mul, static_cast<uint32_t>(test), MulInstruction{std::stoi(itr->str(2)), std::stoi(itr->str(3))}});
                        }
                        else if (InstructionType == k_DoInstruction) {
                              Instructions.push_back(Instruction{EInstruction::Do, static_cast<uint32_t>(itr->position(0)), std::monostate{}});
                        }
                        else {
                              Instructions.push_back(Instruction{EInstruction::Dont, static_cast<uint32_t>(itr->position(0)), std::monostate{}});
                        }
                        // std::cout << "1 " << match.str(0) << std::endl;
                        // std::cout << "2 " << match.str(1) << std::endl;
                        // std::cout << "3 " << match.str(2) << std::endl;
                        // std::cout << "4 " << match.str(3) << std::endl;
                  }

            // }
      }


      for (const Instruction& Instruction: Instructions) {
      std::cout << Instruction << std::endl;
      }

      //
      // Perform logic.

      return INVALID_RESULT;
}
} // KT
