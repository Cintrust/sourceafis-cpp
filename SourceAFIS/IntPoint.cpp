//
// Created by Junior Trust on 2/18/2020.
//

#include "IntPoint.h"

IntPoint IntPoint::negate() const { return IntPoint(-x, -y); }

IntPoint IntPoint::minus(const IntPoint &other) const { return IntPoint(x - other.x, y - other.y); }

IntPoint IntPoint::plus(const IntPoint &other) const { return IntPoint(x + other.x, y + other.y); }

DoublePoint IntPoint::toPoint() const { return DoublePoint(x, y); }

std::deque<IntPoint > *IntPoint::lineTo(const IntPoint &to) const {
    std::deque<IntPoint > *result;
    IntPoint relative = to - (*this);
    if (std::abs(relative.x) >= std::abs(relative.y)) {
//        result = new std::vector<IntPoint >(std::abs(relative.x) + 1);
        result = new std::deque<IntPoint >();
        if (relative.x > 0) {
            for (int i = 0; i <= relative.x; ++i)
                result->push_back(
                        IntPoint(x + i, y + (int) std::round(i * (relative.y / (double) relative.x)))
                        );
        } else if (relative.x < 0) {
            for (int i = 0; i <= -relative.x; ++i)
                result->push_back(
                        IntPoint(x - i, y - (int) std::round(i * (relative.y / (double) relative.x)))
                );
        } else
            result->push_back( *this);
    } else {
//        result = new std::vector<IntPoint >(std::abs(relative.y) + 1);
        result = new std::deque<IntPoint >();
        if (relative.y > 0) {
            for (int i = 0; i <= relative.y; ++i)
                result->push_back(  IntPoint(x + (int) std::round(i * (relative.x / (double) relative.y)), y + i)
                );
        } else if (relative.y < 0) {
            for (int i = 0; i <= -relative.y; ++i)
                result->push_back(   IntPoint(x - (int) std::round(i * (relative.x / (double) relative.y)), y - i));
        } else
            result->push_back( *this);
    }
    return result;


}

IntPoint IntPoint::operator-() const { return negate(); }

IntPoint IntPoint::operator+(const IntPoint &other) const { return plus(other); }

IntPoint::IntPoint(const int &x, const int &y) noexcept : x(x), y(y) {
}

IntPoint::IntPoint(const IntPoint &other) noexcept : IntPoint(other.x,other.y) {

}

IntPoint IntPoint::operator-(const IntPoint &other) const { return minus(other); }

IntPoint::operator DoublePoint() const { return toPoint(); }

bool IntPoint::equals(const IntPoint &other) const {

    return (this == &other) || ((x == other.x) && (other.y == y));
}

const IntPoint IntPoint::zero = IntPoint(0, 0);

const std::vector<IntPoint> IntPoint::edgeNeighbors =  {
        IntPoint(0, -1),
        IntPoint(-1, 0),
        IntPoint(1, 0),
        IntPoint(0, 1)
};
const std::vector<IntPoint> IntPoint::cornerNeighbors =  {
        IntPoint(-1, -1),
        IntPoint(0, -1),
        IntPoint(1, -1),
        IntPoint(-1, 0),
        IntPoint(1, 0),
        IntPoint(-1, 1),
        IntPoint(0, 1),
        IntPoint(1, 1)
};



std::string IntPoint::toString() const {
    return R"({ "x": )"+std::to_string(x)+R"(, "y": )"+std::to_string(y)+R"(, "type:" "IntPoint" } )";
}





