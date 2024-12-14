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
};

using SVector2I = TVector2D<int16_t>;

} // Math
