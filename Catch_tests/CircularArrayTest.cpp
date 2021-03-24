//
// Created by Junior Trust on 2/22/2020.
//

#include "catch.hpp"
#include "CircularArray.h"
#include "IntPoint.h"


TEST_CASE( "Check CircularArray Class ", "[CircularArrayTest]" ) {



    SECTION( "CircularArray()" ) {

        CircularArray<IntPoint> r;
        CHECK_THROWS(r.validateItemIndex(0));
        CHECK_THROWS(r.validateCursorIndex(1));
        CHECK_THROWS(r.get(0));


    }
    SECTION( "CircularArray.set() &&CircularArray.get() " ) {

        CircularArray<IntPoint> r;

        r.insert(0,IntPoint(6,9));

        r.set(0,IntPoint(3,5));
        IntPoint t = r.get(0);
        CHECK(t==IntPoint(3,5));

    }
    SECTION( "CircularArray.insert && CircularArray.remove" ) {

        IntPoint r(2,5);
        IntPoint c(20,52);
        CircularArray<IntPoint> h;
        int s=0;
        for (auto&& f :r){
            h.insert(s,f);
            CHECK(f==h.get(s));
            ++s;
        }
        h.insert(h.size(),r);
        h.insert(0,c);
        CHECK(c==h.get(0));
        CHECK(r==h.get(h.size()-1));

        h.remove(1,s);

        CHECK(c==h.get(0));
        CAPTURE(h.get(1),r,h.size(),s);
        CHECK(r==h.get(1));

        CircularArray<IntPoint> y;

        y.insert(0,r);
        y.insert(0,c);

        CHECK(c==y.get(0));
        CHECK(r==y.get(1));

        y.remove(0,1);
        CHECK(r==y.get(0));


    }

}
