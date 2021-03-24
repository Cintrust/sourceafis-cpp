//
// Created by Junior Trust on 2/24/2020.
//

#ifndef SOURCEAFIS_CPP_INTRANGE_H
#define SOURCEAFIS_CPP_INTRANGE_H


class IntRange {
public:
    static const IntRange zero;

    const int start;
    const int end;
    IntRange(int start, int end) noexcept :start(start),end(end) {

    }
    inline int length() {
        return end - start;
    }
};


#endif //SOURCEAFIS_CPP_INTRANGE_H
