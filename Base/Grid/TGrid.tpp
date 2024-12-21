//
// Created by mathm on 21/12/2024.
//


#include "Base/Vector2D/Vector2D.h"

namespace KT {

template <typename T>
LengthType TGrid<T>::GetMaxLength() const
{
	return m_Grid.size();
}

template <typename T>
const T& TGrid<T>::At(const Math::SVector2I& Vector) const
{
	return m_Grid[Vector.Y][Vector.X];
}
} // KT