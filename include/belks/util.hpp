#ifndef SQ_BELKS_UTIL_HPP
#define SQ_BELKS_UTIL_HPP

#include "belks.hpp"

namespace sq {

namespace belks {

template <typename T>
T ceilToMod(T value, uint mod)
{
    const auto offset = value % mod;
    return offset ? value + (mod - offset) : value;
}

} // \belks

} // \sq

#endif
