//
// Created by mathm on 19/01/2025.
//

#include "Bound.h"

Bound::Bound(const Math::SVector2I& Min, const Math::SVector2I& Max): Min(Min), Max(Max)
{
}

bool BoundUtility::IsLocationOOB(const Bound& Bound, const Math::SVector2I& Location)
{
        return  Location.X < Bound.Min.X ||
                Location.X > Bound.Max.X ||
                Location.Y < Bound.Min.Y ||
                Location.Y > Bound.Max.Y;
}
