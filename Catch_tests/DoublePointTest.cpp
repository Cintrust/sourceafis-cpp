//
// Created by Junior Trust on 2/18/2020.
//
// #define CATCH_CONFIG_MAIN - don't need to repeat this include in more than one cpp file

#include "catch.hpp"
#include "DoublePoint.h"


TEST_CASE( "Check Double Class ", "[DoublePointTest]" ) {


    SECTION( "DoublePoint(double x,double x)" ) {

        DoublePoint t(2.2,4.6);
        CHECK(t.x==2.2);
        CHECK(t.y==4.6);

    }
    SECTION( "DoublePoint.add(DoublePoint)" ) {

        DoublePoint t(2.8,4.6);
        DoublePoint f(3.1,5.7);

        DoublePoint s = t+f;
        DoublePoint a = t.add(f);

        CHECK(s.x==5.9);
        CHECK(s.y==10.3);
        CHECK(s.y==a.y);
        CHECK(s.x==a.x);

    }
    SECTION( "DoublePoint.negate()" ) {

        DoublePoint t(2.8,4.6);
        DoublePoint f = t.negate();
        DoublePoint a = -t;



        CHECK(f.x==-2.8);
        CHECK(f.y==-4.6);
        CHECK(f.x==a.x);
        CHECK(f.y==a.y);


    }
    SECTION( "DoublePoint.Multiply(double)" ) {

        DoublePoint t(2.8,4.6);
        DoublePoint f = t.multiply(0.5);
        DoublePoint s = t *0.5;

        CHECK(f.x==(2.8*0.5));
        CHECK(f.y==(4.6*0.5));
        CHECK(f.x==( s.x));
        CHECK(f.y==( s.y));

    }
    SECTION( "DoublePoint.round()" ) {

        DoublePoint t(2.8,4.2);
       IntPoint s = t.round();
       IntPoint e = (IntPoint) t;

        CHECK(s.x==(3));
        CHECK(s.y==(4));
        CHECK(e.x==( s.x));
        CHECK(e.y==( s.y));

    }
}
