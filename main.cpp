#include <iostream>
#include <vector>

#define SPDLOG_COMPILED_LIB

#include "Integers.h"
#include <ctime>
#include <chrono>
#include <Utils/logs/Logger.h>
#include "IntPoint.h"


using namespace std;

typedef union {
    uint64_t bits;
    double d;
} Double;

int numberOfLeadingZeros(unsigned int i) {
    // HD, Figure 5-6
    if (i == 0)
        return 32;
    int n = 1;
    if (i >> 16 == 0) {
        n += 16;
        i <<= 16;
    }
    if (i >> 24 == 0) {
        n += 8;
        i <<= 8;
    }
    if (i >> 28 == 0) {
        n += 4;
        i <<= 4;
    }
    if (i >> 30 == 0) {
        n += 2;
        i <<= 2;
    }
    n -= i >> 31;
    return n;
}

int numberOfLeadingZeros2(uint32_t value) {
    unsigned __LONG32 leading_zero = 0;

    if (_BitScanReverse(&leading_zero, value))

        return 31 - leading_zero;

    // Same remarks as above
    return 32;

}

template <class T>
std::function< T ()> maker( T & d) {
    return [&d]() ->T { return d; };
}

void addDivisorFilter(std::vector<std::function<int(int)>>& filters)
{
    int divisor = 5;
    filters.emplace_back(
            [&](int value) { return value % divisor == 0; }
    );
}
int main() {
//-std=c++11 -Wall -Wextra -pedantic-errors
    std::vector<std::function<int(int)>> filters;
    addDivisorFilter(filters);
    std::cout << std::boolalpha << filters[0](10) << std::endl;
    int gh =90;
    std::function< int ()> c =maker(gh);
    std::function< IntPoint ()> dz;
    std::function< string ()> p;
    {
        string v ="i hate seen";
        p = maker(v);
        IntPoint c(3,6);
        dz=maker(c);

    }

    std::cout << "Hello, World ! " << (c()) << std::endl;
    std::cout << "Hello, World ! " << (dz()) << std::endl;
    std::cout << "Hello, World ! " << (p()) << std::endl;


    Double d;
    d.d = 3.94;
    int max = 2000000000;



//    std::cout << "Hello, World! " <<  (d.bits)<<"  "<< sizeof(double)<< std::endl;
//    std::cout << "Hello, World! " <<  (d.bits)<<"  "<< sizeof(uint64_t)<< std::endl;
//    std::cout << "Hello, World! " <<  (d.bits)<<"  "<< sizeof(uint32_t )<< std::endl;
//    std::cout << "Hello, World! " <<  (d.bits)<<"  "<< sizeof(int64_t )<< std::endl;
//    std::cout << "Hello, World! " <<  (d.bits)<<"  "<< sizeof(long )<< std::endl;


    return 0;
}
