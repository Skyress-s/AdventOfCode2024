//
// Created by mathm on 21/12/2024.
//

#include "Base/Vector2D/Vector2D.h"
#include "Base/Grid/TGrid.h"

namespace KT::GridUtility {

template<typename T>
bool IsLocationOutOfBounds(const TGrid<T>& Grid, const Math::SVector2I& Location)
{
	if (Location.X < 0 || Location.Y < 0)
	{
		return true;
	}

	if (Location.X > Grid.)

}

} // KT