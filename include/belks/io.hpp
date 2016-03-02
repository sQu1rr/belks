/** 
 * @file io.hpp
 * @brief Functions for user-friendly output generation
 */
#ifndef SQ_BELKS_IO_HPP
#define SQ_BELKS_IO_HPP

#include "base.hpp"
#include "util.hpp"

#include <sstream>
#include <iomanip>

namespace sq {

namespace belks {

/** Possible size units */
enum class SizeType { b, kb, mb, gb, tb, pb };

namespace size_to_string_detail {

constexpr const char* names[] = { "b", "kb", "mb", "gb", "tb", "pb" };

inline auto sizeToString(float size, int n=0) noexcept
{
    if (size < 1024.f) {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << size << names[n];
        return ss.str();
    }
    return sizeToString(size / 1024.0f, n + 1);
}

} // \size_to_string_detail

/** 
 * @brief Converts bit count to a string representation
 *
 * If more than 7 bits -> automatic conversion to the next unit recursively
 * Possible outputs: 1 bit, 7 bits, or any of sizeToString() outputs
 * 
 * @param bits bit count
 * 
 * @return String representing the bit count
 *
 * @see sizeToString()
 * @see SizeType
 */
template <typename T>
inline auto bitsToString(T bits) noexcept
{
    if (bits == 1) return "1 bit"s;
    if (bits < 8) return std::to_string(bits) + " bits"s;

    return size_to_string_detail::sizeToString(ceilToMod(bits, 8) / 8);
}

/** 
 * @brief Converts size in a specific unit to a string representation
 *
 * Converts to the next unit recursively if possible
 * Possible output: 20.05mb, 80.00gb
 * Precision is always 2 decimal places
 * 
 * @param size given size
 * 
 * @return String representation of size
 *
 * @see bitsToString() if input is bits
 * @see SizeType
 */
template <SizeType Type, typename T>
inline auto sizeToString(T size) noexcept
{
    return size_to_string_detail::sizeToString(size, underlying_cast(Type));
}

} // \belks

} // \sq

#endif
