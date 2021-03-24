//
// Created by Junior Trust on 2/21/2020.
//



#include "catch.hpp"
#include "IntRect.h"


TEST_CASE( "Check IntRect Class ", "[IntRectTest]" ) {

    SECTION( "IntRect(int x, int y, int width, int height)" ) {
        IntRect t(2,4,6,9);
        CHECK(t.x==2);
        CHECK(t.y==4);
        CHECK(t.width==6);
        CHECK(t.height==9);
    }
    SECTION( "IntRect(IntRect s)" ) {
        IntRect t(2,4,6,9);
        IntRect s(t);
        CHECK(t.x==s.x);
        CHECK(t.y==s.y);
        CHECK(t.width==s.width);
        CHECK(t.height==s.height);
    }
    SECTION( "IntRect(IntPoint s)" ) {
        IntPoint t(4,4);
        IntRect s(t);
        CHECK(0==s.x);
        CHECK(0==s.y);
        CHECK(t.x==s.width);
        CHECK(t.y==s.height);
    }

    SECTION( "IntRect.area() && IntRect.top() && IntRect.left() ..." ) {
        IntRect t(2,4,6,9);

        CHECK(t.area()==6*9);
        CHECK(t.left()==2);
        CHECK(t.top()==4);
        CHECK(t.right()==2+6);
        CHECK(t.bottom()==4+9);
    }


    SECTION( "IntRect.equals()" ) {
        IntRect t(2,4,6,9);
        IntRect s = t;
        const IntRect& a = t;
        CHECK(s.x==2.0);
        CHECK(s.y==4.0);
        CHECK(s==a);
        CHECK(a.equals(t));
        CHECK(t!=(IntRect(2,4,5,7)));
    }

    SECTION( "IntRect.RangeIterator" ) {
        IntRect t(2,4,6,9);;
        auto it = t.begin();
        auto ir = t.begin();
        auto ed = t.end();
        CAPTURE((*it).x,(*it).y,(*ed).x,(*ed).y);
        CHECK(it==ir);
        CHECK(++it!=ir);
        CHECK(it==++ir);
        CHECK(it!=ed);


        int i=0;
        for (IntPoint item: t){
            ++i;
            UNSCOPED_INFO("value of x is "<<item.x<<" and y is "<<item.y
                                          <<" and i is "<<i<<" \n");
            if (i>100){
                CAPTURE(item.x,item.y);
                CHECK(false);
                break;
            }
        }

        CHECK(i==6*9);

    }
}