//
// Created by Junior Trust on 3/5/2020.
//

#include "SkeletonMinutia.h"
#include "SkeletonRidge.h"
#include "Utils/bridges/helpers.h"

void SkeletonMinutia::attachStart(SkeletonRidge *ridge) {
    if (!ridges->contains(ridge)) {
        ridges->add(ridge);
        ridge->start(this);
    }
}

void SkeletonMinutia::detachStart(SkeletonRidge *ridge) {
    if (ridges->contains(ridge)) {
        ridges->remove(ridge);
        if (ridge->start() == this)
            ridge->start(nullptr);
    }
}

void SkeletonMinutia::write(HeapByteBuffer *buffer) {
    for (SkeletonRidge *ridge : *ridges) {
        if (instanceof<CircularList<IntPoint>>(ridge->points.get())) {
            ridge->write(buffer);
        }
    }

}

long SkeletonMinutia::serializedSize() {
    long sum = 0;
    for (SkeletonRidge *ridge : *ridges) {
        if (instanceof<CircularList<IntPoint>>(ridge->points.get())) {
            sum += ridge->serializedSize();
        }
    }
        return sum;
}
