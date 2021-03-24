//
// Created by Junior Trust on 2/21/2020.
//

#ifndef SOURCEAFIS_CPP_JSONARRAYINFO_H
#define SOURCEAFIS_CPP_JSONARRAYINFO_H

#include <deque>
#include <string>
#include <utility>
#include <initializer_list>

class JsonArrayInfo {
    std::deque<std::string> *axes;
    std::deque<int> *dimensions;
    std::string scalar;
    int bitness;
    std::string endianness;
    std::string format;

public:
    void  setAxes(std::initializer_list<std::string> l){
        axes->clear();
        for (const auto& st :l){
            axes->push_back(st);
        }
    }
    void  setDimensions(std::initializer_list<int> l){
        dimensions->clear();

        for (const auto& st :l){
            dimensions->push_back(st);
        }
    }
    void setScalar(const std::string &sca){
        scalar= sca;
    }
    void setBitness(const int & bit){
        bitness= bit;
    }
    void setEndianness(const std::string &end){
        endianness= end;
    }
    void setFormat(const std::string &form){
        format= form;
    }
    JsonArrayInfo():
    axes(new std::deque<std::string>() ),
    dimensions(new std::deque<int>()),
    scalar(""),
    bitness(0),
    endianness(""),
    format("")
    {}

    JsonArrayInfo( const JsonArrayInfo & other):
            axes(new std::deque<std::string>(*(other.axes)) ),
            dimensions(new std::deque<int>(*(other.dimensions))),
            scalar(other.scalar),
            bitness(other.bitness),
            endianness(other.endianness),
            format(other.format)
    {

    }


    JsonArrayInfo( JsonArrayInfo && other)noexcept:
            axes(other.axes ),
            dimensions(other.dimensions),
            scalar(std::move(other.scalar)),
            bitness(other.bitness),
            endianness(std::move(other.endianness)),
            format(std::move(other.format))
    {

        other.axes= nullptr;
        other.dimensions= nullptr;
    }

    JsonArrayInfo& operator=(JsonArrayInfo) =delete ;
    JsonArrayInfo& operator=( const JsonArrayInfo& other) {
        // check for self-assignment
        if(&other == this)
            return *this;

        delete axes;
        delete dimensions;

        axes = new std::deque<std::string>(*(other.axes));
        dimensions = new std::deque<int>(*(other.dimensions));
        bitness = other.bitness;
        format = other.format;
        scalar = other.scalar;
        endianness = other.endianness;

        return  *this;
    };
    JsonArrayInfo& operator=(  JsonArrayInfo&& other)noexcept {
        // check for self-assignment
        if(&other == this)
            return *this;

        delete axes;
        delete dimensions;

        axes = other.axes;
        dimensions = other.dimensions;
        bitness = other.bitness;
        format = std::move(other.format);
        scalar = std::move(other.scalar);
        endianness = std::move(other.endianness);

        other.axes= nullptr;
        other.dimensions= nullptr;
        return  *this;
    };

    ~JsonArrayInfo(){
        delete axes;
        delete dimensions;
    }

};


#endif //SOURCEAFIS_CPP_JSONARRAYINFO_H
