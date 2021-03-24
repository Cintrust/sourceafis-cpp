//
// Created by Junior Trust on 2/18/2020.
//

#ifndef SOURCEAFIS_CPP_DOUBLEPOINT_H
#define SOURCEAFIS_CPP_DOUBLEPOINT_H


#include "IntPoint.h"
#include <cmath>
class IntPoint;

class DoublePoint {

    constexpr static double const tolerance= 0.000001/2;
public:
    double x;
    double y;
    DoublePoint(double x, double y) noexcept :x(x),y(y) {

    }
    DoublePoint add(const DoublePoint & other) const;

    bool equals(const DoublePoint & other) const;
    DoublePoint negate() const;
    DoublePoint multiply(const double &factor) const;
    IntPoint round();
    static const  DoublePoint zero;


    inline bool operator ==(const DoublePoint & other) const  {return  equals(other);}
    inline DoublePoint operator +(const DoublePoint & other) const  {return  add(other);}

    inline DoublePoint operator -() const  {return  negate();}

    inline DoublePoint operator *(const double factor) const  {return  multiply(factor);}
    explicit operator IntPoint ();
};

#endif //SOURCEAFIS_CPP_DOUBLEPOINT_H
