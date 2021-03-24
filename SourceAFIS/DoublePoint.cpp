//
// Created by Junior Trust on 2/18/2020.
//




#include "DoublePoint.h"

const DoublePoint DoublePoint::zero = DoublePoint(0, 0);

DoublePoint DoublePoint::add(const DoublePoint &other) const { return DoublePoint(x + other.x, y + other.y); }

DoublePoint DoublePoint::negate() const { return DoublePoint(-x, -y); }

IntPoint DoublePoint::round() { return IntPoint((int) std::round(x), (int) std::round(y)); }

DoublePoint DoublePoint::multiply(const double &factor) const { return DoublePoint(factor * x, factor * y); }

DoublePoint::operator IntPoint() { return round(); }

bool DoublePoint::equals(const DoublePoint &other) const {
    return (std::abs(other.x - x) < tolerance) && (std::abs(other.y - y) < tolerance);
}


