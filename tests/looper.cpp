#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "belks/looper.hpp"

#include <functional>

using namespace sq::belks;

template <uint Sleep=0>
class LooperWrapper : public Looper<Sleep> {
public:
    void service(uint64_t) override
    {
        times--;
        if (!times) this->stop();
        if (func) func(times);
    }

    std::function<void (uint)> func;

    uint times = 10;
};

SCENARIO( "Testing looper sleeping", "[belks][looper]" ) {
    using namespace std::chrono;
    const auto time = high_resolution_clock::now();

    WHEN( "Sleeping = 0" ) {
        LooperWrapper<> looper;
        THEN( "No sleeping" ) {
            looper.start();
            const auto now = high_resolution_clock::now();
            const auto elapsed = duration_cast<milliseconds>(now - time);
            REQUIRE( elapsed < milliseconds(10) );
        }
    }

    WHEN( "Sleeping = 30hz" ) {
        LooperWrapper<16> looper;
        THEN( "No sleeping" ) {
            looper.start();
            const auto now = high_resolution_clock::now();
            const auto elapsed = duration_cast<milliseconds>(now - time);
            REQUIRE( elapsed < milliseconds(200) );
            REQUIRE( elapsed >= milliseconds(160) );
        }
    }

    WHEN( "Sleeping = 60hz" ) {
        LooperWrapper<33> looper;
        THEN( "No sleeping" ) {
            looper.start();
            const auto now = high_resolution_clock::now();
            const auto elapsed = duration_cast<milliseconds>(now - time);
            REQUIRE( elapsed < milliseconds(400) );
            REQUIRE( elapsed >= milliseconds(330) );
        }
    }

    WHEN( "Force stopping" ) {
        LooperWrapper<> looper;
        looper.func = [&looper](uint times) {
            if (times == 5) looper.stop();
        };
        looper.start();
        REQUIRE( looper.times == 5 );
    }
}
