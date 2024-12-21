//
// Created by mathm on 21/12/2024.
//

#pragma once


namespace KT
{
class TGrid;
}

namespace Math
{
struct SVector2I;
}


namespace KT::GridUtility {

template<typename T>
bool IsLocationOutOfBounds(const TGrid<T>& Grid, const Math::SVector2I& Location);

}

#include "GridUtility.tpp"
