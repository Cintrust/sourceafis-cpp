//
// Created by Junior Trust on 3/5/2020.
//

#ifndef SOURCEAFIS_CPP_SKELETONRIDGE_H
#define SOURCEAFIS_CPP_SKELETONRIDGE_H


#include <memory>
#include "IntPoint.h"
#include "Utils/bridges/JavaList.h"
#include "Utils/nio/HeapByteBuffer.h"
#include <Utils/logs/Logger.h>

#include "CircularList.h"
#include "ReversedList.h"

class SkeletonMinutia;





class SkeletonRidge {
    SkeletonMinutia *startMinutia;
    SkeletonMinutia *endMinutia;
public:
    std::shared_ptr<JavaList<IntPoint>> points;
    std::shared_ptr<SkeletonRidge> reversed;

    SkeletonRidge() noexcept : startMinutia(nullptr), endMinutia(nullptr),
                               points(new CircularList<IntPoint>()),
                               reversed(new SkeletonRidge(this)) {

    }


    explicit SkeletonRidge(SkeletonRidge *reversed) noexcept :
            startMinutia(nullptr), endMinutia(nullptr),
            points(new ReversedList<IntPoint>(*(reversed->points.get()))),
            reversed(reversed,[](auto p){ /*Logger("hate").info("help me {}",(void*)p);*/}) {

    }

    inline SkeletonMinutia * end() {
        return endMinutia;
    }
    void end(SkeletonMinutia * value) {
        if (endMinutia != value) {
            endMinutia = value;
            reversed->start(value);
        }
    }

    inline void detach() {
        start(nullptr);
        end(nullptr);
    }

    void start(SkeletonMinutia *value);
    inline SkeletonMinutia * start() {
        return startMinutia;
    }

    void write(HeapByteBuffer * buffer) {
        for (IntPoint & at : *points){
            at.write(buffer);
        }
    }

    inline int serializedSize() {
        return points->size() * IntPoint::serializedSize();
    }


};


#endif //SOURCEAFIS_CPP_SKELETONRIDGE_H
