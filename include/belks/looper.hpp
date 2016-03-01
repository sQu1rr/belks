#ifndef SQ_BELKS_LOOPER_HPP
#define SQ_BELKS_LOOPER_HPP

#include "base.hpp"

#include <chrono>
#include <thread>

namespace sq {

namespace belks {

template <uint Sleep=0>
class Looper {
public:
    virtual ~Looper() = default;

    void start();
    void stop() noexcept { work_ = false; }

protected:
    virtual void service(uint64_t time) = 0;

private:
    bool work_ = false;
};

template <uint Sleep>
void Looper<Sleep>::start()
{
    using namespace std::chrono;

    work_ = true;
    constexpr auto sleep = milliseconds(Sleep);

    while (work_) {
        const auto time = high_resolution_clock::now();

        service(duration_cast<milliseconds>(time.time_since_epoch()).count());

        if (Sleep) { // optimise away if no sleep
            const auto now = high_resolution_clock::now();
            const auto wait = duration_cast<milliseconds>(now - time);
            if (wait < sleep) std::this_thread::sleep_for(sleep - wait);
        }
    }
}

} // \belks

} // \sq

#endif
