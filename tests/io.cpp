#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "belks/io.hpp"

namespace sq {

namespace belks {

SCENARIO( "Testing user-friendly size output" ) {
    REQUIRE( bitsToString(0) == "0 bits"s );
    REQUIRE( bitsToString(1) == "1 bit"s );
    REQUIRE( bitsToString(7) == "7 bits"s );
    REQUIRE( bitsToString(8) == "1.00b"s );

    REQUIRE( sizeToString<SizeType::b>(1) == "1.00b"s );
    REQUIRE( sizeToString<SizeType::mb>(1) == "1.00mb"s );

    REQUIRE( sizeToString<SizeType::b>(1024) == "1.00kb"s );
}

} // \belks

} // \sq
