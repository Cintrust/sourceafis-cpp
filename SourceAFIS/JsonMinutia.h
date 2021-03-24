//
// Created by Junior Trust on 2/24/2020.
//

#ifndef SOURCEAFIS_CPP_JSONMINUTIA_H
#define SOURCEAFIS_CPP_JSONMINUTIA_H

#include <string>
#include <stdexcept>
#include "DoubleAngle.h"
#include "Integers.h"

class ImmutableMinutia;

class JsonMinutia {
public:
    const int x;
    const int y;
    double direction;
    const std::string type;
    explicit JsonMinutia(const ImmutableMinutia& minutia);
    void validate();
};


#endif //SOURCEAFIS_CPP_JSONMINUTIA_H
