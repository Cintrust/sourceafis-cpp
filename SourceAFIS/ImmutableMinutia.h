//
// Created by Junior Trust on 2/24/2020.
//

#ifndef SOURCEAFIS_CPP_IMMUTABLEMINUTIA_H
#define SOURCEAFIS_CPP_IMMUTABLEMINUTIA_H


#include  <string>

#include "IntPoint.h"
#include  "MinutiaType.h"
class JsonMinutia;

class ImmutableMinutia {
public:
    const double direction;
    const IntPoint position;
    const MinutiaType type;
    ImmutableMinutia(const IntPoint& position, double direction, MinutiaType type);
    explicit ImmutableMinutia(const JsonMinutia& json);
    inline std::string toString() const {
        return (type.toString()+" @ "+position.toString()+" angle "+std::to_string(direction) );
    }
    inline explicit operator std::string () const {
        return toString();
    }
};


#endif //SOURCEAFIS_CPP_IMMUTABLEMINUTIA_H
