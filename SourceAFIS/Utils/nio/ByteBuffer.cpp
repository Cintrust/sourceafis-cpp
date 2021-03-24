//
// Created by Junior Trust on 3/1/2020.
//

#include "ByteBuffer.h"

ByteBuffer::ByteBuffer(int mark, int pos, int lim, int cap, int off) : _mark(mark), _position(pos), _limit(lim), _capacity(cap), _offset(off) {
    if (cap < 0)
        throw std::invalid_argument("Negative capacity: " + std::to_string(cap));

    setLimit(lim);
    setPosition(pos);

    if (mark >= 0) {
        if (mark > pos)
            throw std::invalid_argument("mark > position: ("
                                        + std::to_string(mark) + " > " + std::to_string(pos) + ")");
        this->_mark = mark;
    }
}

void ByteBuffer::setLimit(const int &newLimit) {
    if ((newLimit > _capacity) || (newLimit < 0))
        throw std::invalid_argument("new limit must be less than capacity and greater than -1");
    _limit = newLimit;
    if (_position > _limit) _position = _limit;
    if (_mark > _limit) _mark = -1;

}

void ByteBuffer::setPosition(const int &newPosition) {
    if ((newPosition > _limit) || (newPosition < 0))
        throw std::invalid_argument("new position must be less than limit and greater than -1");
    _position = newPosition;
    if (_mark > _position) _mark = -1;

}

int ByteBuffer::nextPutIndex(int nb) {
    if (_limit - _position < nb)
        throw std::overflow_error("buffer overflow");
    int p = _position;
    _position += nb;
    return p;
}
