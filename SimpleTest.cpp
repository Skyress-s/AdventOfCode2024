//
// Created by mathm on 14/01/2025.
//
#include "Base/Vector2D/Vector2D.h"
#include "catch2/catch_test_macros.hpp"
TEST_CASE("SimpleTest")
{
        SECTION("Wahoo");
        REQUIRE(2 == 2);

        SECTION("VectorTests");
        Math::SVector2I vector = Math::SVector2I(1, 2);
        Math::SVector2I vector2 = Math::SVector2I(1, 2);
        Math::SVector2I vector3 = Math::SVector2I(2, 2);
        Math::SVector2I vector4 = Math::SVector2I(1, 1);

        REQUIRE(vector == vector2);
        REQUIRE((vector3 == vector4 * 2));
}
