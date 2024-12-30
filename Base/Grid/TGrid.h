//
// Created by mathm on 21/12/2024.
//

#pragma once
#include <format>
#include <vector>
#include <cassert>
#include <algorithm>
#include <Base/Vector2D/Vector2D.h>

// namespace Math
// {
// struct SVector2I;
// }

namespace KT
{
// Y
// ^
// | -> X
template <typename T>
class TGrid
{
public:
          using LengthType = uint32_t;
          using RowType = std::vector<T>;
          using GridType = std::vector<RowType>;

          TGrid() = delete;

          // TGrid(const GridType& Grid) : m_Grid(Grid) {} // good enough for now, maybe we can use std::move in the future.
          explicit TGrid(const GridType& Grid)
          {
                    assert(!Grid.empty());

                    const std::size_t RowLength = Grid[0].size();

                    std::for_each(++Grid.begin(), Grid.end(), [&RowLength](const RowType& Row)
                    {
                              assert(Row.size() == RowLength);
                    });

                    m_Grid = std::move(Grid);
          } // good enough for now, maybe we can use std::move in the future.

          [[nodiscard]] std::size_t GetRowLength() const
          {
                    return m_Grid[0].size();
          }

          [[nodiscard]] std::size_t GetColumnLength() const
          {
                    return m_Grid.size();
          }


          [[nodiscard]] const T& At(const Math::SVector2I& Vector) const
          {
                    if (Vector.X < 0 || Vector.Y < 0 || Vector.X >= GetRowLength() || Vector.Y >= GetColumnLength())
                    {
                              StringType Error = std::format("Out of Range: X: {} Y: {}", Vector.X, Vector.Y);
                              throw std::out_of_range(Error);
                    }
                    return m_Grid[Vector.Y][Vector.X];
          }

          [[nodiscard]] const T& At(const std::size_t X, const std::size_t Y)
          {
                    return At({(int16_t)X, (int16_t)Y});
          }


          GridIterator*




private:
          GridType m_Grid;


          friend std::ostream& operator<<(std::ostream& Os, const TGrid& Grid)
          {
                    for (const RowType& Row : Grid.m_Grid)
                    {
                              for (const T& Element : Row)
                              {
                                        Os << std::format("{:3}", Element);
                              }
                              Os << '\n';
                    }
                    return Os;
          }
};

template <typename TGridValue>
class GridIterator
{
public:
          using iterator_category = std::forward_iterator_tag;
          using value_type = TGrid<TGridValue>;
          using difference_type = std::ptrdiff_t;
          using pointer = TGrid<TGridValue>*;
          using reference = TGrid&;

          GridIterator(pointer Ptr, TGridType& Grid) : m_Ptr(Ptr)
          {

          }

private:
          pointer m_Ptr;
};
}

#include "TGrid.tpp"
