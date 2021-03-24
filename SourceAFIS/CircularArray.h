//
// Created by Junior Trust on 2/22/2020.
//

#ifndef SOURCEAFIS_CPP_CIRCULARARRAY_H
#define SOURCEAFIS_CPP_CIRCULARARRAY_H

#include <deque>
#include <stdexcept>
#include "IntPoint.h"

template<class Object = IntPoint>
class CircularArray {
    std::deque<Object> array;
    int head;

public:
    CircularArray(): array(),head(0)
    {}
    void validateItemIndex(int index) const {
        if (index < 0 || index >= array.size())
     throw std::range_error("index out of range");

    }
    void validateCursorIndex(int index) const {
        if (index < 0 || index > array.size())
            throw std::range_error("index out of range");

    }
    int location(int index) const {
        return head + index < array.size() ? head + index : head + index - array.size();
    }
    int size() const {
        return  array.size();
    }

    Object const & get(int index)   const {
        validateItemIndex(index);
        return array.at(location(index));
    }
    Object  & get(int index)  {
        validateItemIndex(index);
        return array.at(location(index));
    }
    void set(int index, const Object & item) {
        validateItemIndex(index);
        array.at(location(index)) = item;
    }
    void insert(const Object & item) {
        insert(array.size(),item);
    }
    void insert( const int index, const Object & item) {

        validateCursorIndex(index);
        if ((2u * index )>= array.size()) {
            array.insert(array.end() - (array.size() - index ), item);
        }else {
            array.insert(array.begin() + index, item);
        }

    }

    void remove(int index, int amount) {
        validateCursorIndex(index);
        validateCursorIndex(amount-1);
        if ((2u * index) >= array.size() - amount) {
            array.erase(array.end() - (array.size() - index), array.end() - ((array.size() - index) - amount));
        } else {
            array.erase(array.begin() + index, array.begin() + (amount+index));
        }

    }
};


#endif //SOURCEAFIS_CPP_CIRCULARARRAY_H
