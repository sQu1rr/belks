#ifndef SQ_BELKS_BASE_HPP
#define SQ_BELKS_BASE_HPP

#include "gsl.h"
#include <string>
#include <type_traits>

namespace sq {

using namespace std::string_literals;

using real = float;
using uint = uint32_t;
using byte = uint8_t;

using gsl::span;
using gsl::string_span;
using gsl::cstring_span;
using gsl::narrow_cast;

} // \sq

#endif
