//
// Created by Junior Trust on 2/24/2020.
//

#ifndef SOURCEAFIS_CPP_SKELETONTYPE_H
#define SOURCEAFIS_CPP_SKELETONTYPE_H

#include <string>

class SkeletonType {

    const static  SkeletonType  RIDGES;
    const static  SkeletonType VALLEYS;
    const std::string prefix;
    explicit SkeletonType( std::string prefix) noexcept :prefix(std::move(prefix))  {
    }
    std::string toString()const {
        return R"({ "prefix": ")"+prefix+R"(", "type:" "SkeletonType" } )";

    }
    explicit operator std::string () const {
        return toString();
    }
};

const SkeletonType SkeletonType::RIDGES("ridges-");
const SkeletonType SkeletonType::VALLEYS("valleys-");

#endif //SOURCEAFIS_CPP_SKELETONTYPE_H
