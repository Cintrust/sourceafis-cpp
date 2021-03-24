//
// Created by Junior Trust on 2/24/2020.
//

#ifndef SOURCEAFIS_CPP_MINUTIATYPE_H
#define SOURCEAFIS_CPP_MINUTIATYPE_H

#include <string>

struct MinutiaType {
    enum class InnerEnum {
        ENDING,
        BIFURCATION,
    };
    const std::string json;

    const InnerEnum enum_value;

    static const MinutiaType ENDING;
    static const MinutiaType BIFURCATION;
    explicit MinutiaType(std::string  json,const InnerEnum &anEnum) noexcept :json(std::move(json)),enum_value(anEnum) {

    }
    bool operator==(const MinutiaType & other) const{
        return  json== other.json;
    }
    bool operator!=(const MinutiaType & other) const{
        return  *this!=other;
    }
    std::string toString()const {
        return R"({ "json": ")"+json+R"(", "type:" "MinutiaType" } )";

    }
     inline operator InnerEnum() const {
        return enum_value;
    }
    explicit operator std::string () const {
        return toString();
    }

};
const MinutiaType MinutiaType::BIFURCATION("bifurcation",InnerEnum::BIFURCATION);
const MinutiaType MinutiaType::ENDING("ending",InnerEnum::ENDING);

#endif //SOURCEAFIS_CPP_MINUTIATYPE_H
