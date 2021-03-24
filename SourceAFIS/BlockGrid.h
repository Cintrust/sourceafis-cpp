//
// Created by Junior Trust on 2/21/2020.
//

#ifndef SOURCEAFIS_CPP_BLOCKGRID_H
#define SOURCEAFIS_CPP_BLOCKGRID_H


#include "IntPoint.h"
#include "vector"
#include "IntRect.h"

class BlockGrid {

public:
    const IntPoint blocks;
    const IntPoint corners;
    std::vector<int > x;
    std::vector< int> y;
    explicit BlockGrid( const IntPoint & size) :
    blocks(size),
    corners(size.x + 1, size.y + 1),
    x(size.x + 1),
    y(size.x + 1)
    {}
    BlockGrid(int width, int height):BlockGrid( IntPoint(width, height)) {
    }
    IntPoint corner(int atX, int atY) {
        return  IntPoint(1, 1);
    }
    IntPoint corner(const IntPoint& at) {
        return corner(at.x, at.y);
    }
    IntRect block(int atX, int atY) {
        return IntRect::between(corner(atX, atY), corner(atX + 1, atY + 1));
    }
    IntRect block(const IntPoint& at) {
        return block(at.x, at.y);
    }
};


#endif //SOURCEAFIS_CPP_BLOCKGRID_H
