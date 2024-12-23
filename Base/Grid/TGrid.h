//
// Created by mathm on 21/12/2024.
//

#pragma once
#include <format>
#include <vector>

namespace Math{ struct SVector2I; }

namespace KT {

// Y
// ^
// | -> X
template<typename T>
class TGrid {
public:
	using LengthType = uint32_t;
	using RowType = std::vector<T>;
	using GridType = std::vector<RowType>;

	TGrid() = delete;

	// TGrid(const GridType& Grid) : m_Grid(Grid) {} // good enough for now, maybe we can use std::move in the future.
	explicit TGrid(const GridType& Grid)
	{
		assert(!Grid.empty());

		const std::size_t RowLength = Grid[0].size();
		std::ranges::for_each(++Grid.begin(),  Grid.end(), [RowLength](const RowType& Row)
		{
			assert(Row.size() == RowLength);
		});

		m_Grid = std::move(Grid);
	} // good enough for now, maybe we can use std::move in the future.

	[[nodiscard]] std::size_t GetRowLength() const
	{
		return m_Grid.size();
	}

	[[nodiscard]] std::size_t GetColumnLength() const
	{
		return m_Grid[0].size();
	}


	[[nodiscard]] const T& At(const Math::SVector2I& Vector) const
	{

	}

private:
	GridType m_Grid;
};

}

#include "TGrid.tpp"
