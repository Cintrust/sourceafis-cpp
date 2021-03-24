//
// Created by Junior Trust on 3/1/2020.
//

#include "ByteBufferAsIntBufferB.h"

ByteBufferAsIntBufferB &ByteBufferAsIntBufferB::put(const std::vector<int> &src, int offset, int length) {
    checkBounds(offset, length, src.size());
    if (length > remaining())
        throw std::overflow_error("buffer overflow");
    int end = offset + length;
    for (int i = offset; i < end; i++)
        put(src[i]);
    return *this;
}
