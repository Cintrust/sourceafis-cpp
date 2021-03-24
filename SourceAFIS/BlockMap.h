//
// Created by Junior Trust on 2/21/2020.
//

#ifndef SOURCEAFIS_CPP_BLOCKMAP_H
#define SOURCEAFIS_CPP_BLOCKMAP_H


#include "BlockGrid.h"
#include "IntPoint.h"
#include "Integers.h"

class BlockMap {
    const IntPoint pixels;
     BlockGrid primary;
     BlockGrid secondary;
    BlockMap(int width, int height, int maxBlockSize);
};


#endif //SOURCEAFIS_CPP_BLOCKMAP_H
