//
// Created by Junior Trust on 3/5/2020.
//

#ifndef SOURCEAFIS_CPP_SKELETONMINUTIA_H
#define SOURCEAFIS_CPP_SKELETONMINUTIA_H

#include <memory>
#include <string>
#include "IntPoint.h"
#include "Utils/nio/HeapByteBuffer.h"
#include "Utils/bridges/JavaList.h"
#include "CircularList.h"


class SkeletonRidge;

class SkeletonMinutia {
    const IntPoint position;
    std::shared_ptr<JavaList<SkeletonRidge *>> ridges;


    explicit SkeletonMinutia(const IntPoint &position) :
            position(position),
            ridges(new CircularList<SkeletonRidge *>()) {}

public:
    void detachStart(SkeletonRidge *ridge);

    void attachStart(SkeletonRidge *ridge);

    void write(HeapByteBuffer *buffer);

    long serializedSize();

    inline std::string toString() const {
        std::string temp;
        temp.append("{ \"position\":")
                .append(position.toString())
                .append(", \"ridges_size\":")
                .append(std::to_string(ridges->size()))
                .append(R"(, "type":"SkeletonMinutia" )");
        return temp;
    }

    explicit operator std::string () const { return toString();}
};


#endif //SOURCEAFIS_CPP_SKELETONMINUTIA_H
