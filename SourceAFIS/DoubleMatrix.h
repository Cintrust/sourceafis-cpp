//
// Created by Junior Trust on 2/24/2020.
//

#ifndef SOURCEAFIS_CPP_DOUBLEMATRIX_H
#define SOURCEAFIS_CPP_DOUBLEMATRIX_H

#include <vector>
#include "IntPoint.h"
#include "JsonArrayInfo.h"
#include "Utils/nio/HeapByteBuffer.h"

class DoubleMatrix {
    const int width;
    const int height;
    std::vector<double> array;

    DoubleMatrix(int width, int height) : width(width), height(height), array(width * height) {

    }

    explicit DoubleMatrix(const IntPoint &size) : DoubleMatrix(size.x, size.y) {

    }

    IntPoint size() {
        return IntPoint(width, height);
    }

    int offset(int x, int y) {
        return y * width + x;
    }

    double get(int x, int y) {
        return array.at(offset(x, y));
    }

    double get(const IntPoint &at) {
        return get(at.x, at.y);
    }

    void set(int x, int y, double value) {
        array.at(offset(x, y)) = value;
    }

    void set(const IntPoint &at, double value) {
        set(at.x, at.y, value);
    }

    void add(int x, int y, double value) {
        array.at(offset(x, y)) += value;
    }

    void add(const IntPoint &at, double value) {
        add(at.x, at.y, value);
    }

    void multiply(int x, int y, double value) {
        array.at(offset(x, y)) *= value;
    }

    void multiply(const IntPoint &at, double value) {
        multiply(at.x, at.y, value);
    }

    const std::vector<HeapByteBuffer::_byte> *serialize() {
        int D_BYTES;
#ifdef LucenePlusPlus
        D_BYTES = sizeof(double);
#elif defined Stack_Stephen_Canon
        D_BYTES = sizeof(int64_t);
#else
        D_BYTES = sizeof(int64_t) > sizeof(double) ? sizeof(int64_t) : sizeof(double);
#endif
        HeapByteBuffer buffer(D_BYTES * array.size());
        buffer.putAsDoubleBuffer(array);
        /**
 * @todo possible memory leak
 * @see HeapByteBuffer::array
 * */
        return buffer.array();
    }

    JsonArrayInfo json() {
        JsonArrayInfo info = JsonArrayInfo();
        info.setAxes({"y", "x"});
        info.setDimensions({height, width});
        info.setScalar("double");
        info.setBitness(64);
        info.setEndianness("big");
        info.setFormat("IEEE754");
        return info;
    }


};


#endif //SOURCEAFIS_CPP_DOUBLEMATRIX_H
