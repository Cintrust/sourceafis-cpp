//
// Created by Junior Trust on 2/24/2020.
//

#ifndef SOURCEAFIS_CPP_INTMATRIX_H
#define SOURCEAFIS_CPP_INTMATRIX_H


#include "IntPoint.h"
#include <vector>

class IntMatrix {
    const int width;
    const int height;
    int offset(int x, int y) {
        return y * width + x;
    }
  std::vector<int> array;
public:
    IntMatrix(int width, int height):width(width),height(height),array(width*height) {

    }
    explicit IntMatrix(const IntPoint& size):IntMatrix(size.x, size.y) {
    }
    IntPoint size() const {
        return  IntPoint(width, height);
    }
    int get(int x, int y) {
        return array.at(offset(x, y));
    }
    int get(const IntPoint& at) {
        return get(at.x, at.y);
    }
    void set(int x, int y, int value) {
        array.at(offset(x, y)) = value;
    }
    void set(const IntPoint& at, int value) {
        set(at.x, at.y, value);
    }

};


#endif //SOURCEAFIS_CPP_INTMATRIX_H
