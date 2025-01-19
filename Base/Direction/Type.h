//
// Created by mathm on 19/01/2025.
//


#pragma once
#include <cstdint>

#include "Base/Vector2D/Vector2D.h"

namespace Direction
{
enum class Type : uint8_t
{
        NONE = 0, // Indicates invalid or none
        Up = 1,
        First = Up,
        Down,
        Left,
        Right,
        Last = Right
};

inline Type operator+(Type lhs, Type rhs)
{
        return (Type)((uint8_t)lhs + (uint8_t)rhs);
}
template<typename TArithmetic>
typename std::enable_if<std::is_arithmetic_v<TArithmetic>, Type>::type operator+(Type Lhs, TArithmetic Rhs)
{
        return Lhs + (Type)(Rhs);
}

// template<typename TArithmetic>
// typename std::enable_if<std::is_arithmetic_v<TArithmetic>, Type>::type operator++(Type& Direction)
// {
//         Direction = Direction + 1;
//         return Direction;
// }
Type operator++(Type& Direction)
{
        Direction = Direction + 1;
        return Direction;
}

inline Type GetDirection(const Math::SVector2I& From, const Math::SVector2I& To)
{
        if (From.X < To.X)
        {
                return Type::Right;
        }
        if (From.X > To.X)
        {
                return Type::Left;
        }
        if (From.Y < To.Y)
        {
                return Type::Up;
        }
        if (From.Y > To.Y)
        {
                return Type::Down;
        }
        return Type::Right;
}

inline Math::SVector2I GetDirection(const Type Direction)
{
        switch (Direction)
        {
        case Type::NONE:
                throw std::out_of_range("Value: NONE, Not Expected");
        case Type::Up:
                return {0, 1};
        case Type::Down:
                return {0, -1};
        case Type::Left:
                return {-1, 0};
        case Type::Right:
                return {1, 0};
        default:
                throw std::out_of_range("Value: default, Not Expected");
        }
}

}
