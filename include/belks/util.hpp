#ifndef SQ_BELKS_UTIL_HPP
#define SQ_BELKS_UTIL_HPP

#include "base.hpp"

namespace sq {

namespace belks {

template<typename E>
constexpr auto underlying_cast(E e) -> typename std::underlying_type<E>::type 
{
    return static_cast<typename std::underlying_type<E>::type>(e);
}

template <typename T>
T ceilToMod(T value, uint mod)
{
    const auto offset = value % mod;
    return offset ? value + (mod - offset) : value;
}

} // \belks

} // \sq

#endif
