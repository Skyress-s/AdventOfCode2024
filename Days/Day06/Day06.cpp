//
// Created by mathm on 14/12/2024.
//

#include "Day06.h"

#include <algorithm>
#include <assert.h>
#include <iostream>
#include <memory>
#include <unordered_set>
#include <iostream>
#include <ranges>
#include <set>

#include "Base/DayEnum/DayEnum.h"
#include "Base/Vector2D/Vector2D.h"
// Y
// ^
// | --> X


enum EDirection
{
	Up, Down, Left, Right
};

struct SGrid
{
public:
	SGrid() = delete;

	explicit SGrid(std::vector<std::vector<bool>>& Grid, const Math::SVector2I GuardLocation) : m_GuardLocation(GuardLocation) // : m_Grid(Grid)
	{
		m_Grid = std::move(Grid);
	};

	[[nodiscard]] bool At(const Math::SVector2I& Vector) const
	{
		return m_Grid[Vector.Y][Vector.X];
	}

	void SetGuardLocation(const Math::SVector2I& GuardLocation)
	{
		m_GuardLocation = GuardLocation;
	}

	[[nodiscard]] Math::SVector2I GetGuardLocation() const
	{
		return m_GuardLocation;
	}

	[[nodiscard]] bool IsLocationOOB(const Math::SVector2I& Vector) const
	{
		return Vector.X < 0 || Vector.Y < 0 || Vector.X >= m_Grid[0].size() || Vector.Y >= m_Grid.size();
	}

	template<typename TIterator>
	requires std::forward_iterator<TIterator>
	// typename std::iterator_traits<TIterator>::value_type
	void PrintWithPath(TIterator Begin, TIterator End) const
	{
		// using ValueType = typename std::iterator_traits<TIterator>::value_type;
		// for (TIterator Itr = Begin; Itr != End; ++Itr)
		// {
		//
		// }
		for (std::vector<std::vector<bool>>::const_reverse_iterator YItr = m_Grid.crbegin(); YItr != m_Grid.crend(); ++YItr)
		{
			const auto Row = *YItr;
			for (auto XItr = Row.begin(); XItr != Row.end(); ++XItr)
			{
				const uint8_t YIndex = std::ranges::distance(YItr, m_Grid.rend()) - 1;
				const uint8_t XIndex = std::ranges::distance(Row.begin(), XItr);

				std::ranges::any_of(Begin, End, [XIndex, YIndex](const Math::SVector2I& Location)
				{
					return Location == Math::SVector2I(XIndex, YIndex);
				})
					? std::cout << 'X'
					: std::cout << (*XItr ? '#' : '.');
			}
			std::cout << '\n';
		}
	}

	const std::vector<std::vector<bool>>& GetGridConst() const { return m_Grid; }

private:
	std::vector<std::vector<bool>> m_Grid;
	Math::SVector2I m_GuardLocation{};

	friend std::ostream& operator<<(std::ostream& os, const SGrid& Grid)
	{
		for (std::vector<std::vector<bool>>::const_reverse_iterator YItr = Grid.m_Grid.crbegin(); YItr != Grid.m_Grid.crend(); ++YItr)
		{
			const auto Row = *YItr;
			for (auto XItr = Row.begin(); XItr != Row.end(); ++XItr)
			{
				const uint8_t YIndex = std::ranges::distance(YItr, Grid.m_Grid.crend()) - 1;
				const uint8_t XIndex = std::ranges::distance(Row.begin(), XItr);
				if (Math::SVector2I(XIndex, YIndex) == Grid.m_GuardLocation)
				{
					os << '?' << " ";
					continue;
				}
				os << (*XItr ? '#' : '.') << " ";
			}
			std::cout << '\n';
		}
		return os;
	}
};

SGrid BuildGridAndGetStartLocation(const std::vector<StringType>& Lines)
{
	assert(!Lines.empty());

	std::vector<std::vector<bool>> GridValues;
	GridValues.reserve(Lines[0].size());

	Math::SVector2I GuardLocation{};
	for (int i = 0; i < Lines.size(); ++i)
	{
		GridValues.emplace_back();
		const StringType& Line = Lines[i];
		for (int j = 0; j < Line.size(); ++j)
		{
			const char& Char = Line[j];
			switch (Char)
			{
			case '.':
				GridValues[i].emplace_back(false);
				break;
			case '#':
				GridValues[i].emplace_back(true);
				break;
			case '^':
			case 'v':
			case '<':
			case '>':
				GuardLocation = Math::SVector2I(j, i);
			default:
				GridValues[i].emplace_back(false);
				break;
			}
		}
	}
	std::reverse(GridValues.begin(), GridValues.end());
	GuardLocation.Y = GridValues.size() - 1 - GuardLocation.Y;
	return SGrid(GridValues, GuardLocation);
}

bool IsPositionBlocked(const SGrid& Grid, const Math::SVector2I& Position)
{
	return Grid.At(Position);
}

Math::SVector2I RotateDirectionClockwise(const Math::SVector2I& Direction)
{
	int16_t X = 0 * Direction.X + 1 * Direction.Y;
	int16_t Y = -1 * Direction.X + 0 * Direction.Y;
	return {X, Y};
}

// Return the new direction
Math::SVector2I ProcessGuard(SGrid& Grid, const Math::SVector2I& Direction)
{
	const Math::SVector2I NewPosition = Grid.GetGuardLocation() + Direction;
	Math::SVector2I NewDirection = Direction;
	if (!Grid.IsLocationOOB(NewPosition) && IsPositionBlocked(Grid, NewPosition))
	{
		NewDirection = RotateDirectionClockwise(Direction);
		return NewDirection;
	}
	Grid.SetGuardLocation(NewPosition);
	return Direction;
}

// void PrintGridWithPath(const SGrid& Grid, const std::unordered_set<Math::SVector2I>& VisitedLocations)
// {
// 	for (auto itr = Grid.GetGridConst().crbegin(); itr != Grid.GetGridConst().crend(); ++itr)
// 	{
// 		const uint16_t YIndex = std::distance(Grid.GetGridConst().crend() + 1, itr);
// 		const std::vector<bool>& Row = *itr;
// 		for (auto XItr = Row.cbegin(); XItr != Row.cend(); ++XItr)
// 		{
// 			const bool Value = *XItr;
// 			if ()
// 		}
//
// 	}
// }


namespace KT::Days
{
EDay Day06::GetDay() const
{
	return EDay::Day06;
}

int32_t Day06::SolvePart1(const std::vector<StringType>& Input)
{
	std::unordered_set<Math::SVector2I> VisitedLocations{};
	SGrid Grid = BuildGridAndGetStartLocation(Input);
	// std::cout << Grid << '\n'; // that's so cool!
	Math::SVector2I Direction{0, 1};

	std::cout << Grid.GetGuardLocation() << '\n';
	VisitedLocations.emplace(Grid.GetGuardLocation());

	while (true)
	{
		// std::cout << Grid << '\n'; // that's so cool!
		Direction = ProcessGuard(Grid, Direction);
		if (Grid.IsLocationOOB(Grid.GetGuardLocation()))
		{
			break;
		}
		// std::cout << Grid.GetGuardLocation() << '\n';
		VisitedLocations.emplace(Grid.GetGuardLocation());
	}

	for (auto visited_location : VisitedLocations)
	{
		std::cout << visited_location << '\n';
	}

	Grid.PrintWithPath(VisitedLocations.begin(), VisitedLocations.end());

	return (int32_t)VisitedLocations.size();
}

std::ostream& operator<<(std::ostream& os, const std::set<Math::SVector2I>& Set)
{
	os << "Set{";
	for (auto itr = Set.begin(); itr != Set.end(); ++itr)
	{
		os << *itr << '\n';
	}
	return os << "}\n";
}

EDirection GetDirection(const Math::SVector2I& From, const Math::SVector2I& To)
{
	if (From.X < To.X)
	{
		return Right;
	}
	if (From.X > To.X)
	{
		return Left;
	}
	if (From.Y < To.Y)
	{
		return Up;
	}
	if (From.Y > To.Y)
	{
		return Down;
	}
}

bool ProcessPath(const SGrid& Grid, const Math::SVector2I& StartLocation, const Math::SVector2I& StartDirection, const Math::SVector2I& NewObstruction)
{
	// std::cout << "New Path! \n";
	std::vector<std::pair<Math::SVector2I, EDirection>> VisitedLocations;
	VisitedLocations.reserve(5000);
	Math::SVector2I CurrentLocation = StartLocation;
	Math::SVector2I CurrentDirection = StartDirection;

	uint8_t NumMatches{0};
	bool bHasLooped{false};

	VisitedLocations.emplace_back(StartLocation, GetDirection(StartLocation, StartLocation + StartDirection));

	while (true)
	{
		const Math::SVector2I NewPosition = CurrentLocation + CurrentDirection;
		const Math::SVector2I NewDirection = CurrentDirection;

		if (Grid.IsLocationOOB(NewPosition))
		{
			return false;
		}

		if (IsPositionBlocked(Grid, NewPosition) || NewPosition == NewObstruction)
		{
			CurrentDirection = RotateDirectionClockwise(CurrentDirection);
		}
		else // New Valid Position
		{
			std::pair NewLocationPair {NewPosition, GetDirection(NewPosition,  NewPosition + NewDirection)};

			auto LoopFilter = VisitedLocations | std::views::filter([NewLocationPair](const auto& VisitedLocation)
			{
				return VisitedLocation == NewLocationPair;
			});

			const auto bLoop = !LoopFilter.empty();
			if (bLoop)
            {
				return true;
            }

			VisitedLocations.emplace_back(NewLocationPair);
			CurrentLocation = NewPosition;

		}
	}
}

int32_t Day06::SolvePart2(const std::vector<StringType>& Input)
{
	SGrid Grid = BuildGridAndGetStartLocation(Input);
	Math::SVector2I Direction{0, 1};

	uint16_t NumMatches{0};

	std::unordered_set<Math::SVector2I> Obstructions{};

	std::vector<Math::SVector2I> VisitedLocations;
	const Math::SVector2I StartLocation = Grid.GetGuardLocation();
	const Math::SVector2I StartDirection = Direction;
	Math::SVector2I CurrentLocation = Grid.GetGuardLocation();
	Math::SVector2I CurrentDirection = Direction;
	VisitedLocations.emplace_back(CurrentLocation);
	while (true)
	{
		Math::SVector2I NewPosition = CurrentLocation + CurrentDirection;

		if (Grid.IsLocationOOB(NewPosition))
		{
			break;
		}

		Math::SVector2I NewDirection = CurrentDirection;
		if (IsPositionBlocked(Grid, NewPosition))
		{
			CurrentDirection = RotateDirectionClockwise(CurrentDirection);
		}
		else // New Valid Location
		{
			CurrentLocation = NewPosition;
			VisitedLocations.emplace_back(CurrentLocation);
		}
	}

	// Skipping first one.
	for (auto Itr = ++VisitedLocations.begin(); Itr != VisitedLocations.end(); ++Itr)
	{
		if (ProcessPath(Grid, StartLocation, StartDirection, *Itr))
        {
            if (!Obstructions.contains(*Itr + CurrentDirection))
            {
                NumMatches++;
                Obstructions.emplace(*Itr + CurrentDirection);
            }
        }


	}

	return NumMatches;
}
}
