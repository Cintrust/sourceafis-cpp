//
// Created by Junior Trust on 2/21/2020.
//

#include "BlockMap.h"

BlockMap::BlockMap(int width, int height, int maxBlockSize)
        :pixels(width, height),
         primary(IntPoint(
                 Integers::roundUpDiv(pixels.x, maxBlockSize),
                 Integers::roundUpDiv(pixels.y, maxBlockSize))),
         secondary(primary.corners)

{
    for (int y = 0; y <= primary.blocks.y; ++y)
        primary.y[y] = y * pixels.y / primary.blocks.y;
    for (int x = 0; x <= primary.blocks.x; ++x)
        primary.x[x] = x * pixels.x / primary.blocks.x;

    secondary.y[0] = 0;
    for (int y = 0; y < primary.blocks.y; ++y)
        secondary.y[y + 1] = primary.block(0, y).center().y;
    secondary.y[secondary.blocks.y] = pixels.y;
    secondary.x[0] = 0;
    for (int x = 0; x < primary.blocks.x; ++x)
        secondary.x[x + 1] = primary.block(x, 0).center().x;
    secondary.x[secondary.blocks.x] = pixels.x;
}
