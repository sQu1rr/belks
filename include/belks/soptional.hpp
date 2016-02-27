#ifndef SQ_BELKS_OPTIONAL_HPP
#define SQ_BELKS_OPTIONAL_HPP

#include "belks.hpp"

namespace sq {

namespace belks {

namespace soptional_details {

template <typename T,
          typename std::enable_if_t<std::is_unsigned<T>::value>* = nullptr>
struct SoptionalDefault {
    constexpr static T value = static_cast<T>(-1);
};

} // \soptional_detail

template <typename T, T V=soptional_details::SoptionalDefault<T>::value>
class Soptional {
public:
    Soptional() noexcept = default;
    Soptional(std::nullptr_t) noexcept { };
    Soptional(T value) noexcept : value_(value) { }

    T operator = (T value) noexcept { value_ = value; return value_; }
    T operator = (std::nullptr_t) noexcept { value_ = V; return value_; }

    operator T () const noexcept { return value_; }
    T operator * () const noexcept { return value_; }

    operator bool () const noexcept { return value_ != V; }
    bool operator ! () const noexcept { return value_ == V; }

private:
    T value_ = V;
};

} // \belks

} // \sq

#endif
