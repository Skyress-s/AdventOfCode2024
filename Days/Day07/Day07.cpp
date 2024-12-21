//
// Created by mathm on 19/12/2024.
//

#include "Day07.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>

#include "Base/DayEnum/DayEnum.h"
#include "Utility/ParseUtility/ParseUtility.h"

namespace KT::Days
{

enum class EOperation : uint8_t
{
	Addition,
	Multiply,
	Concatenate
};

std::ostream& operator<<(std::ostream& OutStream, const EOperation Operation)
{
	switch (Operation)
	{
	case EOperation::Addition:
		OutStream << "Addition";
		break;
	case EOperation::Multiply:
		OutStream << "Multiply";
		break;
	case EOperation::Concatenate:
		OutStream << "Concatenate";
		break;
	}
	return OutStream;
}

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

IDayProblemBase::DayReturnType Day07::SolvePart1(const std::vector<StringType>& Input)
{
	uint64_t SumValidEquationResults {};
	std::for_each(Input.begin(), Input.end(), [&SumValidEquationResults](const StringType& Line)
	{
		const auto [EquationResult, Numbers] = ParseEquation(Line); // This is very nice!

		std::vector<std::tuple<std::vector<EOperation>, NumberType>> Equations {};
		Equations.reserve(pow(2, Numbers.size() - 1));
		Equations.emplace_back(std::vector<EOperation>(), Numbers.front());

		NumberType SecondNumber;
		for (auto Itr = ++Numbers.cbegin(); Itr != Numbers.cend(); ++Itr)
		{
			{
				const NumberType Number = *Itr;
				SecondNumber = Number;
			}
			std::vector<std::tuple<std::vector<EOperation>, NumberType>> NewEquations {};

			for (const auto& [Operations, CurrentSum] : Equations)
			{
				const NumberType AdditionSum = CurrentSum + SecondNumber;
				const NumberType MultiplySum = CurrentSum * SecondNumber;

				std::vector<EOperation> Operations1 {Operations};
				Operations1.emplace_back(EOperation::Addition);
				std::vector<EOperation> Operations2 {Operations};
				Operations2.emplace_back(EOperation::Multiply);

				NewEquations.emplace_back(Operations1, AdditionSum);
				NewEquations.emplace_back(Operations2, MultiplySum);
			}

			Equations.swap(NewEquations);
		}


		// std::cout << "Equations: ";
		for (const auto& [Operations, Sum]  : Equations)
		{
			// std::cout << "Result: " << Sum << " -> ";
			// for (const EOperation Operation : Operations)
			// {
			// 	std::cout << Operation << " ";
			// }
			// std::cout << std::endl;

			if (Sum == EquationResult)
			{
				std::cout << "VALID RESULT: " << EquationResult << std::endl;
				SumValidEquationResults += Sum;
				break;
			}
		}
		// StreamEquationTargetAndNumbers(std::cout, EquationResult, Numbers);
	});
	std::cout << SumValidEquationResults << std::endl;
	return SumValidEquationResults;
}

IDayProblemBase::DayReturnType Day07::SolvePart2(const std::vector<StringType>& Input)
{
	uint64_t SumValidEquationResults {};
	std::for_each(Input.begin(), Input.end(), [&SumValidEquationResults](const StringType& Line)
	{
		const auto [EquationResult, Numbers] = ParseEquation(Line); // This is very nice!

		std::vector<std::tuple<std::vector<EOperation>, NumberType>> Equations {};
		Equations.reserve(pow(2, Numbers.size() - 1));
		Equations.emplace_back(std::vector<EOperation>(), Numbers.front());

		NumberType SecondNumber;
		for (auto Itr = ++Numbers.cbegin(); Itr != Numbers.cend(); ++Itr)
		{
			{
				const NumberType Number = *Itr;
				SecondNumber = Number;
			}
			std::vector<std::tuple<std::vector<EOperation>, NumberType>> NewEquations {};

			for (const auto& [Operations, CurrentSum] : Equations)
			{
				const NumberType AdditionSum = CurrentSum + SecondNumber;
				const NumberType MultiplySum = CurrentSum * SecondNumber;
				const NumberType ConcatenateSum = std::stoll(std::to_string(CurrentSum) + std::to_string(SecondNumber));

				// These are not nececary for the calculation. Should be removed.
				std::vector<EOperation> Operations1 {Operations};
				Operations1.emplace_back(EOperation::Addition);
				std::vector<EOperation> Operations2 {Operations};
				Operations2.emplace_back(EOperation::Multiply);
				std::vector<EOperation> Operations3 {Operations};
				Operations3.emplace_back(EOperation::Concatenate);

				NewEquations.emplace_back(Operations1, AdditionSum);
				NewEquations.emplace_back(Operations2, MultiplySum);
				NewEquations.emplace_back(Operations3, ConcatenateSum);
			}

			Equations.swap(NewEquations);
		}


		// std::cout << "Equations: ";
		for (const auto& [Operations, Sum]  : Equations)
		{
			// std::cout << "Result: " << Sum << " -> ";
			// for (const EOperation Operation : Operations)
			// {
			// 	std::cout << Operation << " ";
			// }
			// std::cout << std::endl;

			if (Sum == EquationResult)
			{
				std::cout << "VALID RESULT: " << EquationResult << std::endl;
				SumValidEquationResults += Sum;
				break;
			}
		}
		// StreamEquationTargetAndNumbers(std::cout, EquationResult, Numbers);
	});
	std::cout << SumValidEquationResults << std::endl;
	return SumValidEquationResults;
}
}
