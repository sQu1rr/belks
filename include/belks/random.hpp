#ifndef SQ_BELKS_SEMVER_HPP
#define SQ_BELKS_SEMVER_HPP

#include <random>

namespace sq {

namespace belks {

template <typename T=std::mt19937>
T& randomDevice()
{
    static std::random_device rd;
    static T mt(rd());
    return mt;
}

auto& drd()
{
    return randomDevice<>();
}

} // \belks

} // \sq

#endif
