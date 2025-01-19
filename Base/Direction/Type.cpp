//
// Created by mathm on 19/01/2025.
//

#include "Type.h"

Direction::Type Direction::operator++(Type& Direction)
{
        Direction = Direction + 1;
        return Direction;
}

Direction::Type Direction::GetDirection(const Math::SVector2I& From, const Math::SVector2I& To)
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

Math::SVector2I Direction::GetDirection(const Type Direction)
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
