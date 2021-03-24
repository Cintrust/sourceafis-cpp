//
// Created by Junior Trust on 2/18/2020.
//

#ifndef SOURCEAFIS_CPP_INTPOINT_H
#define SOURCEAFIS_CPP_INTPOINT_H

#include <vector>
#include <ostream>
#include <string>
#include <deque>
#include <stdexcept>
#include "Integers.h"
#include "DoublePoint.h"
#include "Utils/nio/HeapByteBuffer.h"

class DoublePoint;

class IntPoint {

public:
     int x;
     int y;

    IntPoint(const int &x, const int &y) noexcept ;

    IntPoint(const IntPoint &other) noexcept ;

    inline int area() { return x * y; }

    inline int lengthSq() { return Integers::sq(x) + Integers::sq(y); }

    inline bool contains(const IntPoint &other) { return other.x >= 0 && other.y >= 0 && other.x < x && other.y < y; };

    IntPoint plus(const IntPoint &other) const;

    IntPoint minus(const IntPoint &other) const;

    IntPoint negate() const;

    bool equals(const IntPoint &other) const;

    DoublePoint toPoint() const ;

    static int serializedSize() {
        return 8;
    }

    void write(HeapByteBuffer *buffer) {
        buffer->putInt(x);
        buffer->putInt(y);
    }

    std::deque<IntPoint > *lineTo(const IntPoint &to) const ;

    template<class Value>
    class my_iterator {
        typedef my_iterator self_type;
        typedef Value value_type;
        typedef Value &reference;
        typedef Value *pointer;
        typedef std::input_iterator_tag iterator_category;
        typedef std::ptrdiff_t difference_type;

        int atX;
        int atY;

        int refX;
        int refY;


        bool hasNext() const {
            return atY < refY && atX < refX;
        }

        bool hasNext(const my_iterator &other) const {
            return atY < other.atY && atX < other.atX;
        }

    public:
        explicit my_iterator(Value &par, int x = 0, int y = 0) : atX(x), atY(y), refX(par.x), refY(par.y) {}

        self_type &operator++() {

                ++atX;
            if (atX >= refX) {
                atX = 0;
                ++atY;
            }

            if (!hasNext()) {
                atY = refY;
                atX = refX;
//                throw std::overflow_error("iterator buffer overflow");
            }


            return *this;
        }

//        const self_type & operator++(int)  {return ++(*this);}
        self_type operator++(int) {
            my_iterator val = *this;
            ++(*this);
            return val;
        }

        inline bool operator==(const my_iterator &other) const {
            return (this == &other) || (atY == other.atY && atX == other.atX);
        }

        inline bool operator!=(const my_iterator &other) const { return !(*this == other); }

        value_type operator*() const { return value_type(atX, atY); }

//        pointer operator->() const {return &cur_point;}
        friend std::ostream &operator<<(std::ostream &os, self_type &value) {
            os << "[ atX := " << value.atX << ", atY := " << value.atY
               << " ] ( refX := " << value.refX << ", refY := " << value.refY << " )\n";
            return os;
        }
    };

    typedef my_iterator<const IntPoint> const_iterator;
    typedef my_iterator<IntPoint> iterator;

    iterator begin() { return iterator(*this); }

    iterator end() { return iterator(*this, this->x, this->y); }

    const_iterator begin() const { return const_iterator(*this); }

    const_iterator end() const { return const_iterator(*this, this->x, this->y); }

    const_iterator cbegin() { return const_iterator(*this); }

    const_iterator cend() { return const_iterator(*this, this->x, this->y); }

    IntPoint operator-() const;

    IntPoint operator+(const IntPoint &other) const;

    IntPoint operator-(const IntPoint &other) const;

    inline bool operator==(const IntPoint &other) const { return equals(other); };

    inline bool operator!=(const IntPoint &other) const { return !equals(other); };

    std::string toString() const ;
    explicit operator DoublePoint() const;

    inline operator std::string() const {
        return toString();
    };
    friend inline std::ostream &operator<<(std::ostream &os, const IntPoint &value){
        os <<value.toString();
        return  os;
    };
    static const  IntPoint zero;
    static const  std::vector<IntPoint> edgeNeighbors;
    static const  std::vector<IntPoint> cornerNeighbors;
};


#endif //SOURCEAFIS_CPP_INTPOINT_H
