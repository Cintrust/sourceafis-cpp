//
// Created by Junior Trust on 2/18/2020.
//

#include "HeapByteBuffer.h"
#include "ByteBufferAsDoubleBufferB.h"
#include "ByteBufferAsIntBufferB.h"




HeapByteBuffer::HeapByteBuffer(int cap, int lim) : ByteBuffer(-1, 0, lim, cap, 0), hb(nullptr) {
//    if (cap < 0)
//        throw std::invalid_argument("Negative capacity: " + std::to_string(cap));

    hb = new std::vector<_byte>(_capacity);

//    setLimit(lim);
//    setPosition(0);


}


void HeapByteBuffer::putIntB(int bi, int x) {
    _put(bi, int3(x));
    _put(bi + 1, int2(x));
    _put(bi + 2, int1(x));
    _put(bi + 3, int0(x));
}

void HeapByteBuffer::putAsIntBuffer(const std::vector<int> &int_buf) {
    int size = remaining() >> 2;
    int off = _offset + position();

    ByteBufferAsIntBufferB temp(this,
                                -1,
                                0,
                                size,
                                size,
                                off);
    temp.put(int_buf);
}

void HeapByteBuffer::putAsDoubleBuffer(const std::vector<double> &double_buf) {
    int size = remaining() >> 3;
    int off = _offset + position();
    ByteBufferAsDoubleBufferB temp(this,
                                   -1,
                                   0,
                                   size,
                                   size,
                                   off);
    temp.put(double_buf);
}
