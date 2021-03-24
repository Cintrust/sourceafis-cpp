//
// Created by Junior Trust on 3/1/2020.
//

#ifndef SOURCEAFIS_CPP_BYTEBUFFER_H
#define SOURCEAFIS_CPP_BYTEBUFFER_H


#include <stdexcept>

class ByteBuffer {

public:
    //    typedef unsigned char _byte;
    typedef char _byte;

    ByteBuffer(
            int mark, int pos, int lim, int cap,
            int off);

    void setLimit(const int &newLimit);

    void setPosition(const int &newPosition);


protected:
    // Invariants: mark <= position <= limit <= capacity
    int _mark;
    int _position;
    int _limit;
    int _capacity;
    int _offset;

    virtual inline int ix(int i) = 0;

    virtual inline void _put(int i, _byte b) = 0;


    int nextPutIndex(int nb = 1);

    inline static void checkBounds(int off, int len, int size) { // package-private
        if ((off | len | (off + len) | (size - (off + len))) < 0)
            throw std::overflow_error("buffer overflow");
    }

    inline int remaining() {
        return _limit - _position;
    }

    inline int position() {
        return _position;
    }
};


#endif //SOURCEAFIS_CPP_BYTEBUFFER_H
