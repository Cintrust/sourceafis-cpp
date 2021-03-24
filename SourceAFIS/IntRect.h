//
// Created by Junior Trust on 2/21/2020.
//

#ifndef SOURCEAFIS_CPP_INTRECT_H
#define SOURCEAFIS_CPP_INTRECT_H


#include "IntPoint.h"
#include "algorithm"

class IntRect {
public:
    const int x;
    const int y;
    const int width;
    const int height;
    IntRect(int x, int y, int width, int height) noexcept : x(x), y(y),
                                                            width(width), height(height) {

    }

    explicit IntRect(const IntPoint &size) noexcept: IntRect(0, 0, size.x, size.y) {

    }

     IntRect(const IntRect &size) noexcept: IntRect(size.x, size.y, size.width, size.height) {

    }

    int left() const {
        return x;
    }

    int top() const {
        return y;
    }

    int right() const {
        return x + width;
    }

    int bottom() const {
        return y + height;
    }

    int area() const {
        return width * height;
    }

    static IntRect between(int startX, int startY, int endX, int endY) {
        return IntRect(startX, startY, endX - startX, endY - startY);
    }

    static IntRect between(const IntPoint &start, const IntPoint &end) {
        return between(start.x, start.y, end.x, end.y);
    }

    static IntRect around(int x, int y, int radius) {
        return between(x - radius, y - radius, x + radius + 1, y + radius + 1);
    }

    static IntRect around(const IntPoint &center, int radius) {
        return around(center.x, center.y, radius);
    }

    IntPoint center() const {
        return IntPoint((right() + left()) / 2, (top() + bottom()) / 2);
    }

    IntRect intersect(const IntRect &other) const {
        return between(
                IntPoint(std::max(left(), other.left()), std::max(top(), other.top())),
                IntPoint(std::min(right(), other.right()), std::min(bottom(), other.bottom())));
    }

    IntRect move(const IntPoint &delta) const {
        return IntRect(x + delta.x, y + delta.y, width, height);
    }

    bool equals(const IntRect &obj) const {
        return (&obj == this) || (obj.height == height && obj.width == width && obj.x == x && obj.y == y);
    }

    bool operator==(const IntRect &obj) const {
        return equals(obj);
    }

    bool operator!=(const IntRect &obj) const {
        return !equals(obj);
    }

    template<class Value, class IterValue>
    class my_iterator {
        typedef my_iterator self_type;
        typedef IterValue value_type;
        typedef IterValue &reference;
        typedef IterValue *pointer;
        typedef std::input_iterator_tag iterator_category;
        typedef std::ptrdiff_t difference_type;

        Value parent;
        int atY;
        int atX;


        bool hasNext() const {
            return atY < parent.height && atX < parent.width;
        }

        bool hasNext(const my_iterator &other) const {
            return atY < other.height && atX < other.width;
        }

    public:
        explicit my_iterator(Value &par, int x = 0, int y = 0) : parent(par), atY(y), atX(x) {}

        self_type &operator++() {

            ++atX;
            if (atX >= parent.width) {
                atX = 0;
                ++atY;
            }

            if (!hasNext()) {
                atY = parent.height;
                atX = parent.width;
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

        value_type operator*() const { return value_type(atX + parent.x, atY + parent.y); }

//        pointer operator->() const {return &cur_point;}

    };

    typedef my_iterator<const IntRect, const IntPoint> const_iterator;
    typedef my_iterator<IntRect, IntPoint> iterator;

    iterator begin() { return iterator(*this); }

    iterator end() { return iterator(*this, this->width, this->height); }

    const_iterator begin() const { return const_iterator(*this); }

    const_iterator end() const { return const_iterator(*this, this->width, this->height); }

    const_iterator cbegin() { return const_iterator(*this); }

    const_iterator cend() { return const_iterator(*this, this->width, this->height); }


};


#endif //SOURCEAFIS_CPP_INTRECT_H
