//
// Created by mathm on 04/01/2025.
//

#include "GridMath.h"

#include <limits>
#include <math.h>

namespace GridMath {
bool IsCloseToInteger(const float Value){
          constexpr float c_Tollerance = std::numeric_limits<float>::min() * 1000.f;

          return std::abs(roundf(Value) - Value) < c_Tollerance;
}
}
