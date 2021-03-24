//
// Created by Junior Trust on 3/1/2020.
//

#ifndef SOURCEAFIS_CPP_BYTEBUFFERASINTBUFFERB_H
#define SOURCEAFIS_CPP_BYTEBUFFERASINTBUFFERB_H

#include <vector>
#include "ByteBuffer.h"
#include "HeapByteBuffer.h"

class ByteBufferAsIntBufferB : public ByteBuffer {

    HeapByteBuffer *const bb;

public:
    ByteBufferAsIntBufferB(HeapByteBuffer *bb,
                           int mark, int pos, int lim, int cap,
                           int off) : ByteBuffer(mark, pos, lim, cap, off), bb(bb) {

    }

    inline ByteBufferAsIntBufferB &put(const std::vector<int> &src) {
        return put(src, 0, src.size());
    }



    ByteBufferAsIntBufferB &put(const std::vector<int> &src, int offset, int length);

    inline ByteBufferAsIntBufferB &put(int x) {
        bb->putIntB(ix(nextPutIndex()), x);
        return *this;
    }


protected:
    inline int ix(int i) override {
        return (i << 2) + _offset;
    }

    void inline _put(int i, _byte b) override{
        bb->_put(i, b);

    }


};


#endif //SOURCEAFIS_CPP_BYTEBUFFERASINTBUFFERB_H
