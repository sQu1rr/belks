/** 
 * @file mpl.hpp
 * @brief Metaprogramming compile-time utilities
 */
#ifndef SQ_BELKS_MPL_HPP
#define SQ_BELKS_MPL_HPP

#include <functional>

namespace sq {

namespace belks {

namespace lambda_type_detail {

template <typename F>
struct FunctionTraits : public FunctionTraits<decltype(&F::operator())> { };

template <typename ClassType, typename ReturnType, typename... Args>
struct FunctionTraits<ReturnType (ClassType::*)(Args...) const> {
    using function = const std::function<ReturnType (Args...)>;
};

template <typename Function>
auto extract(Function& lambda) {
    return static_cast<typename FunctionTraits<Function>::function>(lambda);
}

template <class Lambda>
struct Partial : Lambda {
    Partial(Lambda lambda) : Lambda(lambda) { }
    auto convert() { return extract(*reinterpret_cast<Lambda*>(this)); }
};

} // \lambda_type_detail


/** 
 * @brief Converts lambda to std::function if possible
 *
 * Original implementation is taken from the following link
 * http://stackoverflow.com/a/21266968/1842900
 * 
 * @param lambda lambda to convert
 * 
 * @return Labda converted to std::function
 */
template <class Lambda>
auto toFunction(Lambda lambda)
{
    using namespace lambda_type_detail;
    return Partial<Lambda>(lambda).convert();
}

} // \belks

} // \sq

#endif
