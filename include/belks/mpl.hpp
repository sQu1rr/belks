/** 
 * @file mpl.hpp
 * @brief Metaprogramming compile-time utilities
 */
#ifndef SQ_BELKS_MPL_HPP
#define SQ_BELKS_MPL_HPP

#include <functional>

namespace sq {

namespace belks {

namespace to_function_detail {

template <typename Callable>
struct Trait : public Trait<decltype(&Callable::operator ())> { };

template <typename Class, typename Ret, typename... Args>
struct Trait<Ret (Class::*)(Args...)> { using Type = Ret (Args...); };

template <typename Class, typename Ret, typename... Args>
struct Trait<Ret (Class::*)(Args...) const> { using Type = Ret (Args...); };

} // \to_function_detail

/** 
 * @brief Wraps callable into std::function if needed
 *
 * Inspired by http://stackoverflow.com/a/21266968/1842900
 * 
 * @param callable Callable to convert
 * 
 * @return Callable converted to std::function
 */
template <typename Callable>
constexpr auto toFunction(Callable&& callable)
{
    using T = typename to_function_detail::Trait<std::decay_t<Callable>>::Type;
    return std::function<T>{callable};
}

/** 
 * @brief Wraps function pointer into std::function
 *
 * @param callable Callable to convert
 * 
 * @return Callable converted to std::function
 */
template <typename Ret, typename... Args>
constexpr auto toFunction(Ret (*callable)(Args...))
{
    return std::function<Ret (Args...)>{callable};
}

} // \belks

} // \sq

#endif
