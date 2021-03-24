//
// Created by Junior Trust on 2/24/2020.
//

#include "EdgeShape.h"
#include "utility"
#include "DoubleAngle.h"

EdgeShape::EdgeShape(int length, double referenceAngle, double neighborAngle)
        : length(length), referenceAngle(referenceAngle), neighborAngle(neighborAngle) {

}


std::vector<int> EdgeShape::polarDistance(Integers::sq(EdgeShape::polarCacheRadius));
std::vector<double> EdgeShape::polarAngle(Integers::sq(EdgeShape::polarCacheRadius));

EdgeShape::EdgeShape(const std::tuple<int, double, double> &init)
        :
        EdgeShape(
                std::get<0>(init),
                std::get<1>(init),
                std::get<2>(init)
        ) {

}

EdgeShape::EdgeShape(const ImmutableMinutia &reference, const ImmutableMinutia &neighbor)
        : EdgeShape(polarInit(reference, neighbor)) {


}

EdgeShape::PolarInit::PolarInit() noexcept {

    for (int y = 0; y < EdgeShape::polarCacheRadius; ++y)
        for (int x = 0; x < EdgeShape::polarCacheRadius; ++x) {
            polarDistance.at(y * polarCacheRadius + x) = (int) Integers::round(
                    Integers::sqrt(Integers::sq(x) + Integers::sq(y)));

            if (y > 0 || x > 0)
                polarAngle.at(y * polarCacheRadius + x) = DoubleAngle::atan(DoublePoint(x, y));
            else
                polarAngle.at(y * polarCacheRadius + x) = 0;
        }
}

std::tuple<int, double, double>
EdgeShape::PolarInit::operator()(const ImmutableMinutia &reference, const ImmutableMinutia &neighbor) const {

//   helper function to help initialize EdgeShape instance const member variables
// inspired by  https://stackoverflow.com/a/36151851
// and of course this comment
// https://stackoverflow.com/questions/36151463/c-const-initialize-multiple-data-members-from-one-initializer-function/36151851#comment59940796_36151851
/// Brilliant! Add another example to the (long) list of
/// "All problems in Computer Science can be solved by adding another layer of indirection
/// (except too many layers of indirection)."
// :):):):):):):):):):):):):):) :D:D:D:D:D:D:D:D:D:D:D:D
// ps: the whole fuss is to keep in close range with the java implementation as tight as possible
// in this case the aim is to ensure that edgeShape.length, edgeShape.referenceAngle,edgeShape.neighborAngle
// all maintain the const qualifier.
// note: when this port of the lib becomes independent of the main lib(java implementation) this hack is bound to be removed.
    IntPoint vector = neighbor.position.minus(reference.position);
    double quadrant = 0;
    int x = vector.x;
    int y = vector.y;
    if (y < 0) {
        x = -x;
        y = -y;
        quadrant = Doubles::PI;
    }
    if (x < 0) {
        int tmp = -x;
        x = y;
        y = tmp;
        quadrant += DoubleAngle::halfPI;
    }
    int shift = 32 - Integers::numberOfLeadingZeros(unsigned(x | y) >> polarCacheBits);
    int offset = (y >> shift) * polarCacheRadius + (x >> shift);
    int _length = polarDistance.at(offset) << shift;
    double angle = polarAngle.at(offset) + quadrant;
    double _referenceAngle = DoubleAngle::difference(reference.direction, angle);
    double _neighborAngle = DoubleAngle::difference(neighbor.direction, DoubleAngle::opposite(angle));

    return std::make_tuple(_length, _referenceAngle, _neighborAngle);
}

EdgeShape::PolarInit EdgeShape::polarInit;

