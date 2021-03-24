//
// Created by Junior Trust on 3/5/2020.
//

#ifndef SOURCEAFIS_CPP_FOREIGNMINUTIATYPE_H
#define SOURCEAFIS_CPP_FOREIGNMINUTIATYPE_H


#include <Utils/logs/Logger.h>
#include "ForeignFormat.h"
#include "MinutiaType.h"
#include <stdexcept>


class ForeignMinutiaType {

    enum class InnerEnum {
        ENDING,
        BIFURCATION,
        EITHER,
        OTHER
    };


    static const Logger logger;

    const InnerEnum enum_value;

    explicit ForeignMinutiaType(const InnerEnum &anEnum) noexcept;


public:

    static const ForeignMinutiaType ENDING;
    static const ForeignMinutiaType BIFURCATION;
    static const ForeignMinutiaType EITHER;
    static const ForeignMinutiaType OTHER;

    inline operator InnerEnum() const {

        return enum_value;
    }

    static ForeignMinutiaType decode(int code, ForeignFormat format) {
        switch (code) {
            case 0:
                if (format == ForeignFormat::ANSI_378_2004 || format == ForeignFormat::ISO_19794_2_2005)
                    return OTHER;
                else
                    return EITHER;
            case 1:
                return ENDING;
            case 2:
                return BIFURCATION;
            default:
                logger.warn("Bad template: minutia type code must be one of 01, 10, or 00");
                return ENDING;
        }
    }

    int encode(ForeignFormat format) {
        switch (this->enum_value) {
            case InnerEnum::ENDING:
                return 1;
            case InnerEnum::BIFURCATION:
                return 2;
            case InnerEnum::EITHER:
                if (format == ForeignFormat::ANSI_378_2004)
                    throw std::runtime_error(
                            "Cannot create template: cannot encode 'either' minutia in format supporting only 'other' type");
                return 0;
            case InnerEnum::OTHER:
                if (format != ForeignFormat::ANSI_378_2004)
                    throw std::runtime_error(
                            "Cannot create template: cannot encode 'other' minutia in format supporting only 'either' type");
                return 0;
            default:
                throw std::range_error("format out of range");
        }
    }

    static ForeignMinutiaType convert(const MinutiaType &type) {
        switch (type) {
            case MinutiaType::InnerEnum::ENDING:
                return ENDING;
            case MinutiaType::InnerEnum::BIFURCATION:
                return BIFURCATION;
            default:
                throw std::range_error("format out of range");
        }
    }

    MinutiaType convert() {
        switch (this->enum_value) {
            case InnerEnum::ENDING:
                return MinutiaType::ENDING;
            case InnerEnum::BIFURCATION:
                return MinutiaType::BIFURCATION;
            case InnerEnum::EITHER:
            case InnerEnum::OTHER:
                logger.debug("Imperfect template import: changing 'either' or 'other' minutia type to 'ending'");
                return MinutiaType::ENDING;
            default:
                throw std::range_error("format out of range");

        }
    }


};


#endif //SOURCEAFIS_CPP_FOREIGNMINUTIATYPE_H
