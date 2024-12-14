//
// Created by mathm on 14/12/2024.
//

#include "Day06.h"

#include <iostream>
#include <memory>

#include "Base/DayEnum/DayEnum.h"
#include "Base/Vector2D/Vector2D.h"
// Y
// ^
// | --> X


struct SGrid
{
public:
	SGrid() = delete;
	explicit SGrid(const std::vector<std::vector<bool>>& Grid);

	bool At(const Math::SVector2I& Vector)
	{
		return m_Grid[Vector.Y][Vector.X];
	}

private:
	const std::vector<std::vector<bool>>& m_Grid;

	friend std::ostream& operator<<(std::ostream& os, const SGrid& Grid)
	{

		for (const auto& Row : Grid.m_Grid)
		{
			for (const auto& Cell : Row)
			{
				os << Cell << " ";
			}
			os << '\n';
		}
		return os;
	}
};

SGrid::SGrid(const std::vector<std::vector<bool>>& Grid) : m_Grid(Grid)
{
}

namespace KT::Days
{
EDay Day06::GetDay() const
{
	return EDay::Day06;
}

int32_t Day06::SolvePart1(const std::vector<StringType>& Input)
{
	std::vector<std::vector<bool>> TestGrid{{true, true, false}, {true, true, false}, {true, true, false}};
	SGrid Grid(TestGrid);

	std::cout << Grid << '\n';

	return 0;
}

int32_t Day06::SolvePart2(const std::vector<StringType>& Input)
{
	return 0;
}
}
