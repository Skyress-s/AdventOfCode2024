//
// Created by mathm on 19/01/2025.
//

#pragma once
#include "Base/Vector2D/Vector2D.h"


class Bound
{
public:
        explicit Bound(const Math::SVector2I& Min, const Math::SVector2I& Max);

        Math::SVector2I Min;
        Math::SVector2I Max;
};

namespace BoundUtility
{
bool IsLocationOOB(const Bound& Bound, const Math::SVector2I& Location);

}
