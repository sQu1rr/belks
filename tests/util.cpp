#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "belks/util.hpp"

namespace sq {

namespace belks {

SCENARIO( "Testing underlying cast" ) {
    enum class A : int { a = 0 };
    enum class B : uint { b = -1u };
    REQUIRE( underlying_cast(A::a) == 0 );
    REQUIRE( underlying_cast(B::b) == -1u );
}

SCENARIO( "Testing ceil to mod" ) {
    REQUIRE( ceilToMod(2, 4) == 4 );
    REQUIRE( ceilToMod(4, 4) == 4 );
    REQUIRE( ceilToMod(6, 4) == 8 );
}

} // \belks

} // \sq
