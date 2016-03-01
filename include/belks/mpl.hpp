#ifndef SQ_BELKS_UTIL_HPP
#define SQ_BELKS_UTIL_HPP

#include "base.hpp"

#include <functional>

namespace sq {

namespace belks {

// http://stackoverflow.com/a/21266968/1842900
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

template <class Lambda>
auto toFunction(Lambda lambda)
{
    using namespace lambda_type_detail;
    return Partial<Lambda>(lambda).convert();
}

} // \belks

} // \sq

#endif
