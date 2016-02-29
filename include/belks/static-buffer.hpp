#ifndef SQ_BELKS_SEMVER_HPP
#define SQ_BELKS_SEMVER_HPP

#include "belks.hpp"

namespace sq {

namespace belks {

namespace static_buffer_detail {

template <size_t Size>
struct BufferSize {
    enum { Length = Size <= 256 ? 256 : 1024 };
};

template <size_t Size>
byte* getBuffer()
{
    static byte buffer[Size];
    return buffer;
}

} // \static_buffer_detail

template <typename T, size_t Size>
T* getStaticBuffer()
{
    using namespace static_buffer_detail;
    return reinterpret_cast<T*>(getBuffer<BufferSize<Size>::Length>());
}

} // \belks

} // \sq

#endif
