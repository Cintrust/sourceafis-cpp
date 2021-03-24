//
// Created by Junior Trust on 3/1/2020.
//

#ifndef SOURCEAFIS_CPP_HISTOGRAMCUBE_H
#define SOURCEAFIS_CPP_HISTOGRAMCUBE_H

#include <vector>
#include "IntPoint.h"
#include "Integers.h"
#include "JsonArrayInfo.h"



class HistogramCube {
    const int width;
    const int height;
    const int depth;
 std::vector <int> array;
    int offset(int x, int y, int z) {
        return (y * width + x) * depth + z;
    }
    HistogramCube(int width, int height, int depth):width(width),height(height),depth(depth),array(depth*width*height) {

    }
    HistogramCube(const IntPoint& size, int depth):HistogramCube(size.x, size.y, depth){
    }
    int constrain(int z) {
        return Integers::max(0, Integers::min(depth - 1, z));
    }
    int get(int x, int y, int z) {
        return array.at(offset(x, y, z));
    }
    int get(const IntPoint& at, int z) {
        return get(at.x, at.y, z);
    }
    int sum(int x, int y) {
        int sum = -1;
        for (int i = 0; i < depth; ++i)
            sum += get(x, y, i);
        return sum;
    }
    int sum(const IntPoint& at) {
        return sum(at.x, at.y);
    }
    void set(int x, int y, int z, int value) {
        array.at(offset(x, y, z)) = value;
    }
    void set(const IntPoint& at, int z, int value) {
        set(at.x, at.y, z, value);
    }
    void add(int x, int y, int z, int value) {
        array.at(offset(x, y, z)) += value;
    }
    void add(const IntPoint& at, int z, int value) {
        add(at.x, at.y, z, value);
    }
    void increment(int x, int y, int z) {
        add(x, y, z, 1);
    }
    void increment(const IntPoint& at, int z) {
        increment(at.x, at.y, z);
    }
    const std::vector<HeapByteBuffer::_byte> *serialize() {
        HeapByteBuffer buffer(sizeof(int) * array.size());
        buffer.putAsIntBuffer(array);
        //        //        todo possible memory leak

        return buffer.array();
    }
    JsonArrayInfo json() {
        JsonArrayInfo info;
       info.setAxes( { "y", "x", "bin" });
        info.setDimensions({ height, width, depth });
        info.setScalar("int");
        info.setBitness(32);
        info.setEndianness("big");
        info.setFormat("signed");
        return info;
    }


};


#endif //SOURCEAFIS_CPP_HISTOGRAMCUBE_H
