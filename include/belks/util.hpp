/** 
 * @file util.hpp
 * @brief Uncategorised utilities
 */
#ifndef SQ_BELKS_UTIL_HPP
#define SQ_BELKS_UTIL_HPP

#include "base.hpp"

namespace sq {

namespace belks {


/** 
 * @brief Converts enum class value to a variable of an underlying type
 * 
 * @param e enum class
 * 
 * @return Underlying type value
 */
template<typename E>
constexpr auto underlying_cast(E e) -> typename std::underlying_type<E>::type 
{
    return static_cast<typename std::underlying_type<E>::type>(e);
}


/** 
 * @brief Increments the number until its divisible by mod
 * 
 * @param value initial number
 * @param mod divisor
 * 
 * @return next number divisible by divisor or initial if already is
 */
template <typename T>
T ceilToMod(T value, uint mod)
{
    const auto offset = value % mod;
    return offset ? value + (mod - offset) : value;
}

} // \belks

} // \sq

#endif
