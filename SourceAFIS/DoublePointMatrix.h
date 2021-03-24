//
// Created by Junior Trust on 2/24/2020.
//

#ifndef SOURCEAFIS_CPP_DOUBLEPOINTMATRIX_H
#define SOURCEAFIS_CPP_DOUBLEPOINTMATRIX_H

#include <vector>
#include "IntPoint.h"
#include "JsonArrayInfo.h"
#include "Utils/nio/HeapByteBuffer.h"
#include "Utils/nio/ByteBufferAsDoubleBufferB.h"

class DoublePointMatrix {
    const int width;
    const int height;
    std::vector<double> array;
    DoublePointMatrix(int width, int height):width(width),height(height),array(2*width*height) {

    }
    explicit DoublePointMatrix(const IntPoint& size):DoublePointMatrix(size.x, size.y) {
    }
    int offset(int x, int y) const {
        return 2 * (y * width + x);
    }
    IntPoint size() const {
        return IntPoint(width, height);
    }
    DoublePoint get(int x, int y) {
        int i = offset(x, y);
        return  DoublePoint(array.at(i), array.at(i + 1));
    }
    DoublePoint get(const IntPoint& at) {
        return get(at.x, at.y);
    }
    void set(int x, int y, double px, double py) {
        int i = offset(x, y);
        array.at(i) = px;
        array.at(i+1) = py;
    }
    void set(int x, int y, const DoublePoint & point) {
        set(x, y, point.x, point.y);
    }
    void set(const IntPoint& at, const DoublePoint & point) {
        set(at.x, at.y, point);
    }
    void add(int x, int y, double px, double py) {
        int i = offset(x, y);
        array.at(i) += px;
        array.at(i+1) += py;
    }
    void add(int x, int y, const DoublePoint & point) {
        add(x, y, point.x, point.y);
    }
    void add(const IntPoint& at, const DoublePoint & point) {
        add(at.x, at.y, point);
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
        JsonArrayInfo info =  JsonArrayInfo();
        info.setAxes({ "y", "x", "axis" });
        info.setDimensions({ height, width, 2 });
        info.setScalar("double")  ;
        info.setBitness(64)  ;
        info.setEndianness("big")  ;
        info.setFormat("IEEE754");
        return info;
    }
};


#endif //SOURCEAFIS_CPP_DOUBLEPOINTMATRIX_H
