/** 
 * @file semver.hpp
 * @brief Samantic Versioning
 */
#ifndef SQ_BELKS_SEMVER_HPP
#define SQ_BELKS_SEMVER_HPP

#include "base.hpp"

namespace sq {

namespace belks {

/** 
 * @brief Semantic Versioning structure
 */
struct SemVer {
    uint major;
    uint minor;
    uint patch;
};

} // \belks

} // \sq

#endif
