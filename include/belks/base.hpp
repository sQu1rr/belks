/** 
 * @file base.hpp
 * @brief Basic type defines and utils
 */
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

/** 
 * @brief Allows to use temporaries for gsl::span
 *
 * Initial code was taken from https://github.com/Microsoft/GSL/issues/212
 *
 * @param cont container convertible to gsl::span (if not temporary)
 * 
 * @return Span constructed from a temporary
 * 
 * @warning Temporary will auto-destruct after function is executed. Function
 *          must not save this temporary for later reuse
 */

template <typename Cont>
constexpr auto asTemp(Cont &&cont) ->
        std::enable_if_t<!gsl::details::is_span<
            std::decay_t<Cont>>::value, span<std::add_const_t<
                std::remove_reference_t<decltype(cont.size(), *cont.data())>
            >, gsl::dynamic_range>>
{
    return {cont.data(), static_cast<std::ptrdiff_t>(cont.size())};
}

} // \sq

#endif
