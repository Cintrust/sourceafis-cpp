//
// Created by Junior Trust on 2/24/2020.
//

#ifndef SOURCEAFIS_CPP_DOUBLES_H
#define SOURCEAFIS_CPP_DOUBLES_H

#include <cmath>

class Doubles {
public:
    constexpr static  const double PI = 3.14159265358979323846;

    static double sq(double value) {
        return value * value;
    }
    static double interpolate(double start, double end, double position) {
        return start + position * (end - start);
    }
    static double interpolate(double bottomleft, double bottomright, double topleft, double topright, double x, double y) {
        double left = interpolate(topleft, bottomleft, y);
        double right = interpolate(topright, bottomright, y);
        return interpolate(left, right, x);
    }
    static double interpolateExponential(double start, double end, double position) {
        return std::pow(end / start, position) * start;
    }

    constexpr static double toRadians(double angdeg) {
        return angdeg / 180.0 * PI;
    }
    static double cos(double angle) {
        return std::cos(angle);
    }
    static double sin(double angle) {
        return std::sin(angle);
    }
    static double atan2(double y,double x) {
        return std::atan2(y,x);
    }

    static  double  abs(double number){
        return std::abs(number);
    }
    static  double  sqrt(double number){
        return std::sqrt(number);
    }
};


#endif //SOURCEAFIS_CPP_DOUBLES_H
