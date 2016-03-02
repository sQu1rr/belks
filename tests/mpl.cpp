#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "belks/mpl.hpp"

namespace sq {

namespace belks {

void r(bool& w) { w = true; }

SCENARIO( "Testing lamda to function" ) {
    bool works = false;
    auto f = toFunction([&works]() { works = true; });
    auto t = std::is_same<decltype(f), std::function<void ()>>::value; 
    WHEN( "Converting lambda" ) {
        f();
        REQUIRE( t );
        REQUIRE( works );
    }
    WHEN( "Converting std::function" ) {
        toFunction(f)();
        REQUIRE( works );
    }
    WHEN( "Converting real function" ) {
        toFunction(r)(works);
        REQUIRE( works );
    }
}

} // \belks

} // \sq
