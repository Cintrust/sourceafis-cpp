//
// Created by Junior Trust on 2/24/2020.
//

#include "ImmutableMinutia.h"
#include "JsonMinutia.h"

ImmutableMinutia::ImmutableMinutia(const IntPoint &position, double direction, MinutiaType type) : direction(direction),position(position),type(std::move(type)) {

}

ImmutableMinutia::ImmutableMinutia(const JsonMinutia &json)
        :direction(json.direction),position(json.x, json.y),
         type(MinutiaType::BIFURCATION.json==(json.type) ? MinutiaType::BIFURCATION : MinutiaType::ENDING)
{


}
