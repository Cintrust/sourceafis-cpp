//
// Created by Junior Trust on 2/18/2020.
//

#include "catch.hpp"
#include "IntPoint.h"

TEST_CASE( "Check Int Class ", "[IntPointTest]" ) {

    SECTION( "IntPoint(int x,int x)" ) {
        IntPoint t(2,4);
        CHECK(t.x==2);
        CHECK(t.y==4);
    }
    SECTION( "IntPoint(IntPoint s)" ) {
        IntPoint t(2,4);
        IntPoint s(t);
        CHECK(t.x==s.x);
        CHECK(t.y==s.y);
    }

    SECTION( "IntPoint.area() && IntPoint.lengthSq()" ) {
        IntPoint t(4,4);

        CHECK(t.area()==16);
        CHECK(t.lengthSq()==32);
    }

    SECTION( "IntPoint.contains(IntPoint)" ) {
        IntPoint t(4,4);
        IntPoint w(2,3);

        CHECK(true==t.contains(w));
        CHECK(false==t.contains(t));
        CHECK(false==w.contains(t));
        CHECK(false==w.contains(w));
    }

    SECTION( "IntPoint.plus(IntPoint)" ) {
        IntPoint t(2,4);
        IntPoint f(3,5);
        IntPoint s = t+f;
        IntPoint a = t.plus(f);
        CHECK(s.x==5);
        CHECK(s.y==9);
        CHECK(s.y==a.y);
        CHECK(s.x==a.x);

    }
    SECTION( "IntPoint.minus(IntPoint)" ) {
        IntPoint t(2,8);
        IntPoint f(3,5);
        IntPoint s = t-f;
        IntPoint a = t.minus(f);
        CHECK(s.x==-1);
        CHECK(s.y==3);
        CHECK(s.y==a.y);
        CHECK(s.x==a.x);

    }
    SECTION( "IntPoint.negate()" ) {
        IntPoint t(2,8);
        IntPoint s = -t;
        IntPoint a = t.negate();
        CHECK(s.x==-2);
        CHECK(s.y==-8);
        CHECK(s.y==a.y);
        CHECK(s.x==a.x);

    }
    SECTION( "IntPoint.ToPoint()" ) {
        IntPoint t(2,8);
        DoublePoint s = t.toPoint();
        DoublePoint a = (DoublePoint)t;
        CHECK(s.x==2.0);
        CHECK(s.y==8.0);
        CHECK(s.y==a.y);
        CHECK(s.x==a.x);
    }
    SECTION( "IntPoint.equals()" ) {
        IntPoint t(2,8);
        IntPoint s = t;
        const IntPoint& a = t;
        CHECK(s.x==2.0);
        CHECK(s.y==8.0);
        CHECK(s==a);
        CHECK(a.equals(t));
        CHECK(t!=(IntPoint(2,4)));
    }

    SECTION( "IntPoint.RangeIterator" ) {
        IntPoint t(2,8);
        auto it = t.begin();
        auto ir = t.begin();
        auto ed = t.end();
        CAPTURE((*it).x,(*it).y,(*ed).x,(*ed).y);
        CHECK(it==ir);
        CHECK(++it!=ir);
        CHECK(it==++ir);
        CHECK(it!=ed);

       const IntPoint c(2,8);
        int i=0;
        for (IntPoint item: t){
            ++i;
            UNSCOPED_INFO("value of y is "<<item.y<<" and x is "<<item.x
            <<" and i is "<<i<<" \n");
            if (i>30){
                CAPTURE(item.x,item.y);
                CHECK(false);
                break;
            }
        }

        CHECK(i==2*8);

    }
}