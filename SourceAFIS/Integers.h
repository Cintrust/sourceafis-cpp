//
// Created by Junior Trust on 2/18/2020.
//

#ifndef SOURCEAFIS_CPP_INTEGERS_H
#define SOURCEAFIS_CPP_INTEGERS_H

#include <intrin.h>
#include <algorithm>

/* Target specific macro replacement for type "long".  In the Windows API,
   the type long is always 32 bit, even if the target is 64 bit (LLP64).
   On 64 bit Cygwin, the type long is 64 bit (LP64).  So, to get the right
   sized definitions and declarations, all usage of type long in the Windows
   headers have to be replaced by the below defined macro __LONG32. */
#ifndef __LONG32
#ifndef __LP64__    /* 32 bit target, 64 bit Mingw target */
#define __LONG32 long
#else			/* 64 bit Cygwin target */
#define __LONG32 int
#endif
#endif

class Integers {


public:
    constexpr static const double PI = 3.14159265358979323846;

    static int sq(int value) {
        return value * value;
    }

    static int roundUpDiv(int dividend, int divisor) {
        return (dividend + divisor - 1) / divisor;
    }

    static double toRadians(int angdeg) {
        return angdeg / 180.0 * PI;
    }

    static double cos(int angle) {
        return std::cos(angle);
    }

    static double sin(int angle) {
        return std::sin(angle);
    }

    static double atan2(int y, double x) {
        return std::atan2(y, x);
    }

    static int abs(int number) {
        return std::abs(number);
    }

    static double sqrt(int number) {
        return std::sqrt(number);
    }

    static inline double round(double val) {
        return std::round(val);
    }

    static inline int max(int a, int b) {
        return std::max(a, b);
    }

    static inline int min(int a, int b) {
        return std::min(a, b);
    }

    inline static int numberOfLeadingZeros(uint32_t value) {

        unsigned __LONG32 leading_zero = 0;

        if (_BitScanReverse(&leading_zero, value)) {
            return 31 - leading_zero;
        } else {
            // Same remarks as above
            return 32;
        }
    }
};


#endif //SOURCEAFIS_CPP_INTEGERS_H
