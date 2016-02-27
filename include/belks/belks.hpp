#ifndef SQ_BELKS_BELKS_HPP
#define SQ_BELKS_BELKS_HPP

#include "gsl.h"
#include <string>
#include <type_traits>

namespace sq {

using namespace std::string_literals;

using real = float;
using uint = uint32_t;
using byte = uint8_t;

using gsl::span;
using gsl::narrow_cast;

using String = std::string;
using StringSpan = gsl::string_span<>;

template<typename E>
constexpr auto underlying_cast(E e) -> typename std::underlying_type<E>::type 
{
    return static_cast<typename std::underlying_type<E>::type>(e);
}

} // \sq

#endif
