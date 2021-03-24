//
// Created by Junior Trust on 2/24/2020.
//

#ifndef SOURCEAFIS_CPP_BYTEBUFFERASDOUBLEBUFFERB_H
#define SOURCEAFIS_CPP_BYTEBUFFERASDOUBLEBUFFERB_H


#include "ByteBuffer.h"
#include "HeapByteBuffer.h"
#include <stdexcept>
#include <string>
#include <vector>
#include <cstdint>

class ByteBufferAsDoubleBufferB : public ByteBuffer{

    typedef union {
        int64_t bits;
        double d;
    } Double;


    inline static _byte long7(int64_t x) { return (_byte) (x >> 56); }

    inline static _byte long6(int64_t x) { return (_byte) (x >> 48); }

    inline static _byte long5(int64_t x) { return (_byte) (x >> 40); }

    inline static _byte long4(int64_t x) { return (_byte) (x >> 32); }

    inline static _byte long3(int64_t x) { return (_byte) (x >> 24); }

    inline static _byte long2(int64_t x) { return (_byte) (x >> 16); }

    inline static _byte long1(int64_t x) { return (_byte) (x >> 8); }

    inline static _byte long0(int64_t x) { return (_byte) (x); }

    HeapByteBuffer *const bb;
    // Invariants: mark <= position <= limit <= capacity


    inline int ix(int i) override {
        return (i << 3) + _offset;
    }

protected:
    void inline _put(int i, _byte b) override{
        bb->_put(i, b);

    }

public:
    ByteBufferAsDoubleBufferB(HeapByteBuffer *bb,
                              int mark, int pos, int lim, int cap,
                              int off);


    inline ByteBufferAsDoubleBufferB &put(const std::vector<double> &src) {
        return put(src, 0, src.size());
    }



    ByteBufferAsDoubleBufferB &put(const std::vector<double> &src, int offset, int length);



    inline void putDoubleB(int bi, double x) {
        putLongB(bi, doubleToRawLongBits(x));
    }

    ByteBufferAsDoubleBufferB &put(double x) {
        putDoubleB(ix(nextPutIndex()), x);
        return *this;
    }

    void putLongB(int bi, int64_t x);

    inline static int64_t doubleToRawLongBits(double x) {
#ifdef LucenePlusPlus
        //        https://github.com/luceneplusplus/LucenePlusPlus/blob/692390d6ceb2ddaa34e4e4f3b9e409e155769b81/src/core/util/MiscUtils.cpp#L101
                int64_t longValue = x;
                memcpy(&longValue, &value, sizeof(double));
                return longValue;
#elif defined Stack_Stephen_Canon
        //        https://stackoverflow.com/questions/7955933/c-c-equivalent-to-javas-doubletorawlongbits
        //        https://stackoverflow.com/a/7956112
                int64_t bits;
                memcpy(&bits, &x, sizeof bits);
                return bits;
#else
        //     https://android.googlesource.com/platform/libcore/+/9acacc36bafda869c6e9cc63786cdddd995ca96a/luni/src/main/native/java_lang_Double.cpp#42
        Double d;
        d.d = x;
        return d.bits;
#endif
    }


};


#endif //SOURCEAFIS_CPP_BYTEBUFFERASDOUBLEBUFFERB_H
