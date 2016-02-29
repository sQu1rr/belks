#ifndef SQ_BELKS_UTIL_HPP
#define SQ_BELKS_UTIL_HPP

#include "belks.hpp"

namespace sq {

namespace belks {

// http://stackoverflow.com/a/21266968/1842900
namespace lambda_type_detail {

template <typename F>
struct FunctionTraits : public FunctionTraits<decltype(&F::operator())> { };

template <typename ClassType, typename ReturnType, typename... Args>
struct FunctionTraits<ReturnType(ClassType::*)(Args...) const> {
    typedef ReturnType (*pointer)(Args...);
    typedef const std::function<ReturnType(Args...)> function;
};

template <typename F>
typename FunctionTraits<F>::function toFunction (F& lambda) {
    return static_cast<typename FunctionTraits<F>::function>(lambda);
}

template <class L>
struct Partial : L {
    Partial(L l) : L(l) { }
    auto convert() { return toFunction(*reinterpret_cast<L*>(this)); }
};

} // \lambda_type_detail

template <class L>
auto toFunction(L l)
{
    using namespace lambda_type_detail;
    return Partial<L>(l).convert();
}

} // \belks

} // \sq

#endif
