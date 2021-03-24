//
// Created by Junior Trust on 2/24/2020.
//

#ifndef SOURCEAFIS_CPP_NEIGHBOREDGE_H
#define SOURCEAFIS_CPP_NEIGHBOREDGE_H

#include "EdgeShape.h"
#include <vector>

class NeighborEdge: public EdgeShape {
public:
    const int neighbor;
    NeighborEdge(const std::vector<ImmutableMinutia>& minutiae, int reference, int neighbor)
    :EdgeShape(minutiae[reference], minutiae[neighbor]),neighbor (neighbor) {
    }
};


#endif //SOURCEAFIS_CPP_NEIGHBOREDGE_H
