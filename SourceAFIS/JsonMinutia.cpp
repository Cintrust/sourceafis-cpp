//
// Created by Junior Trust on 2/24/2020.
//

#include "JsonMinutia.h"
#include "ImmutableMinutia.h"


JsonMinutia::JsonMinutia(const ImmutableMinutia &minutia)
        :
         x(minutia.position.x),y(minutia.position.y),
         direction(minutia.direction),
         type(minutia.type.json){

}

void JsonMinutia::validate() {
    if (Integers::abs(x) > 10000 || Integers::abs(y) > 10000)
        throw  std::invalid_argument("Minutia position out of range.");
    if (!DoubleAngle::normalized(direction))
        throw   std::invalid_argument("Denormalized minutia direction.");
    if(type.empty()){
        throw   std::invalid_argument("Null minutia type.");
    }
    if ((type!=MinutiaType::ENDING.json) && (type!=MinutiaType::BIFURCATION.json))
        throw   std::invalid_argument("Unknown minutia type.");
}
