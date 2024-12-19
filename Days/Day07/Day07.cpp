//
// Created by mathm on 19/12/2024.
//

#include "Day07.h"

#include <algorithm>
#include <fstream>
#include <iostream>

#include "Base/DayEnum/DayEnum.h"
#include "Utility/ParseUtility/ParseUtility.h"

namespace KT::Days
{

enum class EOperation : uint8_t
{
	Addition,
	Multiply
};

template<typename TStream>
concept ConceptStreamOut = requires (TStream& Stream, const NumberType& Value)
{
	{Stream << Value};// -> std::same_as<TStream&>;
};


// template<ConceptReapeatStreamOut TStream>
template<typename TStream>
requires ConceptStreamOut<TStream>
void StreamEquationTargetAndNumbers(TStream& os, const NumberType EquationResult, const std::vector<NumberType>& Numbers)
{
	os << "Equation Result: " << EquationResult << " Numbers: ";
	for (const NumberType Number : Numbers)
	{
		os << Number << " ";
	}
	os << '\n';
}

std::pair<NumberType, std::vector<NumberType>> ParseEquation(const StringType& Line)
{
	std::vector<NumberType> LineNumbers;
	ParseUtility::ParseTest(Line, LineNumbers, " :");

	const NumberType EquationResult = LineNumbers[0];
	const std::vector<NumberType> Numbers{LineNumbers.begin() + 1, LineNumbers.end()};

	return {EquationResult, Numbers};
}

EDay Day07::GetDay() const
{
	return EDay::Day07;
}

int32_t Day07::SolvePart1(const std::vector<StringType>& Input)
{
	std::ofstream File("print.txt");
	std::for_each(Input.begin(), Input.end(), [&File](const StringType& Line)
	{
		const auto [EquationResult, Numbers] = ParseEquation(Line); // This is very nice!

		std::tuple<std::vector<EOperation>, NumberType> Equations {};

		NumberType SecondNumber;
		NumberType FirstNumber;
		for (const NumberType Number : Numbers)
		{
			SecondNumber = Number;

			std::tuple<std::vector<EOperation>, NumberType> NewEquations {};

			for (const auto& [Operations, CurrentSum] : Equations)
			{

			}

			const NumberType AdditionResult = FirstNumber + SecondNumber;
			const NumberType MultiplicationResult = FirstNumber * SecondNumber;
		}

		// std::ofstream& test2 = File << " haah" << "haha";
		//
		// PrintEquation(File, EquationResult, Numbers);
		StreamEquationTargetAndNumbers(std::cout, EquationResult, Numbers);
	});
		File.close();
	return INVALID_RESULT;
}

int32_t Day07::SolvePart2(const std::vector<StringType>& Input)
{
	return INVALID_RESULT;
}
}
