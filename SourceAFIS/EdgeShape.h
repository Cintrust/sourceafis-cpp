//
// Created by Junior Trust on 2/24/2020.
//

#ifndef SOURCEAFIS_CPP_EDGESHAPE_H
#define SOURCEAFIS_CPP_EDGESHAPE_H

#include <vector>
#include <tuple>
#include "Integers.h"
#include "ImmutableMinutia.h"
#include "DoubleAngle.h"


class EdgeShape {
    static const int polarCacheBits = 8;
    static const int polarCacheRadius = 1 << polarCacheBits;
    static std::vector<int> polarDistance;
    static std::vector<double> polarAngle;

    class PolarInit {
        //      helper class to emulate java static class members initialization
// helps ensures EdgeShape::polarDistance && EdgeShape::polarAngle are initialized in same loop
/// ps: the whole fuss is to keep in close range with the java implementation as tight as possible
    public:
        PolarInit() noexcept;


        std::tuple<int, double, double>
        operator()(const ImmutableMinutia &reference, const ImmutableMinutia &neighbor) const;
    };

    friend PolarInit;

    static PolarInit polarInit;
public:
    const int length;
    const double referenceAngle;
    const double neighborAngle;

    EdgeShape(int length, double referenceAngle, double neighborAngle);

    explicit EdgeShape(const std::tuple<int, double, double> &init);

    EdgeShape(const ImmutableMinutia &reference, const ImmutableMinutia &neighbor);
};


#endif //SOURCEAFIS_CPP_EDGESHAPE_H
