//
// Created by Junior Trust on 2/21/2020.
//

#ifndef SOURCEAFIS_CPP_BOOLEANMATRIX_H
#define SOURCEAFIS_CPP_BOOLEANMATRIX_H

#include <vector>
#include "IntPoint.h"
#include "Utils/nio/HeapByteBuffer.h"
#include "JsonArrayInfo.h"


class BooleanMatrix {
    const int width;
    const int height;
    std::vector<bool> array;
    int offset(int x, int y) const {
        return y * width + x;
    }

public:


    BooleanMatrix(int width, int height) : width(width), height(height), array(width * height) {

    }

    explicit BooleanMatrix(const IntPoint &size) : BooleanMatrix(size.x, size.y) {

    }

    BooleanMatrix(const BooleanMatrix &other) = default;

    IntPoint size() const {
        return IntPoint(width, height);
    }

    bool get(int x, int y) const {
        return array.at(offset(x, y));
    }

    bool get(const IntPoint &at) const {
        return get(at.x, at.y);
    }

    bool get(int x, int y, bool fallback) const {
        if (x < 0 || y < 0 || x >= width || y >= height)
            return fallback;
        return array.at(offset(x, y));
    }

    bool get(const IntPoint &at, bool fallback) const {
        return get(at.x, at.y, fallback);
    }

    void set(int x, int y, bool value) {
        array.at(offset(x, y)) = value;
    }

    void set(const IntPoint &at, bool value) {
        set(at.x, at.y, value);
    }

    void invert() {
        for (auto &&i : array)
            i = !i;
    }

    void merge(const BooleanMatrix &other) {
        if (other.width != width || other.height != height)
            throw std::logic_error("can't merge data");

        for (std::size_t i = 0; i < array.size(); ++i)
            array[i] = array[i] | other.array[i];
    }

    const std::vector<HeapByteBuffer::_byte> * serialize() {
        HeapByteBuffer buffer(size().area());
        for (IntPoint at : size())
            buffer.put(get(at) ? 1 : 0);
/**
 * @todo possible memory leak
 * @see HeapByteBuffer::array
 * */
        return buffer.array();
    }
    JsonArrayInfo json() {
        JsonArrayInfo info;
        info.setAxes( { "y", "x" });
        info.setDimensions({ height, width });
        info.setScalar("boolean")  ;
        info.setBitness(8);
        info.setFormat("false as 0, true as 1")  ;
        return info;
    }
};


#endif //SOURCEAFIS_CPP_BOOLEANMATRIX_H
