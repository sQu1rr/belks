#ifndef SQ_BELKS_IO_HPP
#define SQ_BELKS_IO_HPP

#include "belks.hpp"
#include "util.hpp"

#include <sstream>
#include <iomanip>

namespace sq {

namespace belks {

enum class SizeType { b, kb, mb, gb, tb };

namespace size_to_string_detail {

constexpr const char* names[] = { "b", "kb", "mb", "gb", "tb" };

std::string sizeToString(float size, int n=0)
{
    if (size >= 1023.999f) return sizeToString(size / 1024.0f, n + 1);

    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << size << names[n];

    return ss.str();
}

} // \size_to_string_detail

template <typename T>
auto bitsToString(T bits)
{
    if (bits == 1) return "1 bit"s;
    if (bits < 8) return std::to_string(bits) + " bits"s;

    return size_to_string_detail::sizeToString(ceilToMod(bits, 8) / 8);
}

template <SizeType Type, typename T>
auto sizeToString(T size)
{
    return size_to_string_detail::sizeToString(size, underlying_cast(Type));
}

} // \belks

} // \sq

#endif
