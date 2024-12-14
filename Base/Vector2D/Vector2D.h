//
// Created by mathm on 14/12/2024.
//

#pragma once

#include <cstdint>

namespace Math {

template<typename T>
struct TVector2D {
	T X;
	T Y;

	bool operator==(const TVector2D& Rhs) const
	{
		return X == Rhs.X && Y == Rhs.Y;
	}

	bool operator!=(const TVector2D& Rhs) const
	{
		return !(*this == Rhs);
	}

	TVector2D operator+(const TVector2D& Rhs) const
	{
		return {X + Rhs.X, Y + Rhs.Y};
	}
};

using SVector2I = TVector2D<int16_t>;

} // Math
