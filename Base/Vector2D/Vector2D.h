﻿//
// Created by mathm on 14/12/2024.
//

#pragma once

#include <cstdint>
#include <functional>
#include <ostream>

namespace Math
{
template <typename T>
struct TVector2D
{
	// TVector2D() = default;
	T X{};
	T Y{};

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
		return TVector2D(X + Rhs.X, Y + Rhs.Y);
	}

	TVector2D operator-(const TVector2D& Rhs) const
	{
		return TVector2D(X - Rhs.X, Y - Rhs.Y);
	}

	friend std::ostream& operator<<(std::ostream& os, const TVector2D& Vector)
    {
        os << "X: " << Vector.X << " Y: " << Vector.Y;
        return os;
    }
};

using SVector2I = TVector2D<int16_t>;
}

namespace std
{
template <>
struct hash<Math::SVector2I>
{
	std::size_t operator()(const Math::SVector2I& Vector) const noexcept
	{
        return std::hash<int16_t>()(Vector.X) ^ (std::hash<int16_t>()(Vector.Y) << 1);
    }
};
}
