//
// Created by Junior Trust on 2/18/2020.
//

#ifndef SOURCEAFIS_CPP_HEAPBYTEBUFFER_H
#define SOURCEAFIS_CPP_HEAPBYTEBUFFER_H

#include <stdexcept>
#include <vector>
#include <string>
#include "ByteBuffer.h"

class ByteBufferAsDoubleBufferB;
class ByteBufferAsIntBufferB;



class HeapByteBuffer : public ByteBuffer {
    friend ByteBufferAsDoubleBufferB;
    friend ByteBufferAsIntBufferB;
public:
    //    typedef unsigned char _byte;
//    typedef char _byte;

    explicit HeapByteBuffer(int cap) : HeapByteBuffer(cap, cap) {}

    HeapByteBuffer(int cap, int lim);


    void putAsIntBuffer(const std::vector<int> & int_buf);
    void putAsDoubleBuffer(const std::vector<double> & double_buf);


    inline HeapByteBuffer &putInt(int x) {
        putIntB(ix(nextPutIndex(4)), x);
        return *this;
    }

    inline HeapByteBuffer &put(_byte x) {
        _put(ix(nextPutIndex()), x);
        return *this;


    }



    const std::vector<_byte> *array() {


//        //        todo possible memory leak
//#ifndef HEAP_LEAK
//#define HEAP_LEAK
//#pragma message ("possible memory leak. fix needed")
//#endif
        return hb;
    }


protected:
    int ix(int i) override  {
        return i + _offset;
    }


private:
    inline void _put(int i, _byte b) override {                  // package-private
        hb->at(i) = b;
    }

    void putIntB(int bi, int x);

    inline static _byte int3(int x) { return (_byte) (x >> 24); }

    inline static _byte int2(int x) { return (_byte) (x >> 16); }

    inline static _byte int1(int x) { return (_byte) (x >> 8); }

    inline static _byte int0(int x) { return (_byte) (x); }


    std::vector<_byte> *hb;


};


#endif //SOURCEAFIS_CPP_HEAPBYTEBUFFER_H
