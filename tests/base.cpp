#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "belks/base.hpp"

namespace sq {

SCENARIO( "Testing asTemp() for gsl::span" ) {
    WHEN( "Span is constructed from a temporary" ) {
        THEN( "It just works" ) {
            cstring_span<>{asTemp("test"s)};
        }
    }
}

} // \sq
