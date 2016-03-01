#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "belks/mpl.hpp"

namespace sq {

namespace belks {

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
}

} // \belks

} // \sq
