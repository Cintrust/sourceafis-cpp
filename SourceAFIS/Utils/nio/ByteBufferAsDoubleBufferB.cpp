//
// Created by Junior Trust on 2/24/2020.
//

#include "ByteBufferAsDoubleBufferB.h"



ByteBufferAsDoubleBufferB::ByteBufferAsDoubleBufferB(HeapByteBuffer *bb, int mark, int pos, int lim, int cap,
                                                     int off) :ByteBuffer(mark,pos,lim,cap,off), bb(bb)  {
//    if (cap < 0)
//        throw std::invalid_argument("Negative capacity: " + std::to_string(cap));
//
//    setLimit(lim);
//    setPosition(pos);
//
//    if (mark >= 0) {
//        if (mark > pos)
//            throw std::invalid_argument("mark > position: ("
//                                        + std::to_string(mark) + " > " + std::to_string(pos) + ")");
//        this->_mark = mark;
//    }


}

ByteBufferAsDoubleBufferB &ByteBufferAsDoubleBufferB::put(const std::vector<double> &src, int offset, int length) {
    checkBounds(offset, length, src.size());
    if (length > remaining())
        throw std::overflow_error("buffer overflow");
    int end = offset + length;
    for (int i = offset; i < end; i++)
        put(src[i]);
    return *this;
}


void ByteBufferAsDoubleBufferB::putLongB(int bi, int64_t x) {
    _put(bi, long7(x));
    _put(bi + 1, long6(x));
    _put(bi + 2, long5(x));
    _put(bi + 3, long4(x));
    _put(bi + 4, long3(x));
    _put(bi + 5, long2(x));
    _put(bi + 6, long1(x));
    _put(bi + 7, long0(x));
}
