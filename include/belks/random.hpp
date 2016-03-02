/** 
 * @file random.hpp
 * @brief Utilities for random data generation
 */
#ifndef SQ_BELKS_RANDOM_HPP
#define SQ_BELKS_RANDOM_HPP

#include <random>

namespace sq {

namespace belks {

/** 
 * @brief Returns a static random device
 * 
 * @return Static random device of a given type
 * 
 * @warning Initialisation is thread-safe however usage is not
 */
template <typename T=std::mt19937>
inline T& randomDevice()
{
    static std::random_device rd;
    static T mt(rd());
    return mt;
}

/** 
 * @brief Returns an mt199937 static random device
 * 
 * @return Mt19937 static random device of a given type
 * 
 * @warning Initialisation is thread-safe however usage is not
 */
inline auto& drd()
{
    return randomDevice<>();
}

} // \belks

} // \sq

#endif
