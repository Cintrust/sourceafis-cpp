//
// Created by Junior Trust on 3/5/2020.
//

#include "SkeletonRidge.h"
#include "SkeletonMinutia.h"

void SkeletonRidge::start(SkeletonMinutia *value) {
    if (startMinutia != value) {
        if (startMinutia != nullptr) {
            SkeletonMinutia * detachFrom = startMinutia;
            startMinutia = nullptr;
            detachFrom->detachStart(this);
        }
        startMinutia = value;
        if (startMinutia != nullptr)
            startMinutia->attachStart(this);
        reversed->endMinutia = value;
    }
}
