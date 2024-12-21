//
// Created by mathm on 21/12/2024.
//

#pragma once
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
	TGrid(const GridType& Grid)
	{
		m_Grid = std::move(Grid);
	} // good enough for now, maybe we can use std::move in the future.

	LengthType GetMaxLength() const;

	[[nodiscard]] const T& At(const Math::SVector2I& Vector) const;

private:
	GridType m_Grid;
};

}

#include "TGrid.tpp"
