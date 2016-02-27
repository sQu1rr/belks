#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "belks/soptional.hpp"

using namespace sq::belks;

SCENARIO( "Testing optional methods", "[belks][optional]" ) {
    WHEN( "Default unsigned int optional" ) {
        Soptional<uint> optional;

        THEN( "Value is 'undefined'" ) {
            REQUIRE( *optional == uint(-1) );
            REQUIRE( !optional == true );
            REQUIRE( static_cast<bool>(optional) == false );
        }
    }

    WHEN( "Nullptr unsigned int optional" ) {
        Soptional<uint> optional(nullptr);

        THEN( "Nullptr value is 'undefined'" ) {
            REQUIRE( *optional == uint(-1) );
        }
    }

    WHEN( "Unsigned int optional with value" ) {
        Soptional<uint> optional(42);
        THEN( "Value is preserved" ) {
            REQUIRE( *optional == 42 );
            REQUIRE( !optional == false );
            REQUIRE( static_cast<bool>(optional) == true );
        }
        THEN( "Value can be assigned" ) {
            uint value = optional;
            REQUIRE( value == 42 );
        }
        THEN( "Soptional can be reassigned with another value" ) {
            optional = 43;
            REQUIRE( *optional == 43 );
        }
        THEN( "Soptional can be reassigned with undefined value" ) {
            optional = nullptr;
            REQUIRE( *optional == uint(-1) );
            REQUIRE( static_cast<bool>(optional) == false );
        }
    }

    WHEN( "Soptional with non-standard size" ) {
        Soptional<uint8_t> o8;
        Soptional<uint16_t> o16;
        Soptional<uint32_t> o32;
        Soptional<uint64_t> o64;

        THEN( "Default value is still -1" ) {
            REQUIRE( *o8 == uint8_t(-1) );
            REQUIRE( *o16 == uint16_t(-1) );
            REQUIRE( *o32 == uint32_t(-1) );
            REQUIRE( *o64 == uint64_t(-1) );
        }
    }
}

SCENARIO( "Soptional with non-standard default", "[belks][optional]" ) {
    Soptional<uint, -2> optional;

    THEN( "Value is 'undefined'" ) {
        REQUIRE( *optional == uint(-2) );
    }

    optional = 42;
    WHEN( "Assigned value" ) {
        THEN( "Value is valid" ) {
            REQUIRE( *optional == 42 );
        }
    }

    WHEN( "Assigned nullptr" ) {
        optional = nullptr;
        THEN( "Value is undefined" ) {
            REQUIRE( *optional == uint(-2) );
        }
    }
}
