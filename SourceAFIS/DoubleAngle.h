//
// Created by Junior Trust on 2/23/2020.
//

#ifndef SOURCEAFIS_CPP_DOUBLEANGLE_H
#define SOURCEAFIS_CPP_DOUBLEANGLE_H


#include "DoublePoint.h"
#include "Doubles.h"

class DoubleAngle {
public:
     constexpr static const double PI2 = 2 * Doubles::PI;
    constexpr static const double invPI2 = 1.0 / PI2;
    constexpr static const double halfPI = 0.5 * Doubles::PI;
    static DoublePoint  toVector(double angle) {
        return  DoublePoint(Doubles::cos(angle), Doubles::sin(angle));
    }
    static double atan( const DoublePoint & vector) {
        double angle = Doubles::atan2(vector.y, vector.x);
        return angle >= 0 ? angle : angle + PI2;
    }
    static double atan(const IntPoint &vector ) {
        return atan(vector.toPoint());
    }
    static double atan(const IntPoint & center,const IntPoint & point) {
        return atan(point.minus(center));
    }
    static double toOrientation(double angle) {
        return angle < Doubles::PI ? 2 * angle : 2 * (angle - Doubles::PI);
    }
    static double fromOrientation(double angle) {
        return 0.5 * angle;
    }
    static double add(double start, double delta) {
        double angle = start + delta;
        return angle < PI2 ? angle : angle - PI2;
    }
    static double bucketCenter(int bucket, int resolution) {
        return PI2 * (2 * bucket + 1) / (2 * resolution);
    }
    static int quantize(double angle, int resolution) {
        int result = (int)(angle * invPI2 * resolution);
        if (result < 0)
            return 0;
        else if (result >= resolution)
            return resolution - 1;
        else
            return result;
    }
    static double opposite(double angle) {
        return angle < Doubles::PI ? angle + Doubles::PI : angle - Doubles::PI;
    }
    static double distance(double first, double second) {
        double delta = Doubles::abs(first - second);
        return delta <= Doubles::PI ? delta : PI2 - delta;
    }
    static double difference(double first, double second) {
        double angle = first - second;
        return angle >= 0 ? angle : angle + PI2;
    }
    static double complementary(double angle) {
        double complement = PI2 - angle;
        return complement < PI2 ? complement : complement - PI2;
    }
    static bool normalized(double angle) {
        return angle >= 0 && angle < PI2;
    }
};


#endif //SOURCEAFIS_CPP_DOUBLEANGLE_H
