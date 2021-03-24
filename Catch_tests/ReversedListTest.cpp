//
// Created by Junior Trust on 2/23/2020.
//





#include "catch.hpp"
#include "ReversedList.h"
#include "CircularList.h"
#include "IntPoint.h"


TEST_CASE("Check ReversedList Class ", "[ReversedListTest]") {




    SECTION("ReversedList()") {
        CircularList<IntPoint> f;
        ReversedList<IntPoint> r(f);
        CHECK(r.size() == 0);
        CHECK(r.isEmpty());
        CHECK_THROWS(r.get(0));
        CHECK_THROWS(r.remove(0));
        CHECK_THROWS(r.add(5, IntPoint(5, 5)));


    }

    SECTION("ReversedList.add() &&ReversedList.get() ") {

        CircularList<IntPoint> f;

        ReversedList<IntPoint> r(f);

        r.add(0, IntPoint(6, 9));//2
        r.add(0, IntPoint(3, 5)); //0
        r.add(1, IntPoint(4, 2));//1
        r.add(IntPoint(1, 9));//3


        CHECK(r.size() == 4);
        CHECK(!r.isEmpty());

        CHECK(r.get(0) == IntPoint(3, 5));
        CHECK(r.get(1) == IntPoint(4, 2));
        CHECK(r.get(2) == IntPoint(6, 9));
        CHECK(r.get(3) == IntPoint(1, 9));

        CHECK(r.get(0) == f.get(3));
        CHECK(r.get(1) == f.get(2));
        CHECK(r.get(2) == f.get(1));
        CHECK(r.get(3) == f.get(0));

    }
    SECTION("ReversedList.add(index) &&ReversedList.remove(index) ") {

        CircularList<IntPoint> f;

        ReversedList<IntPoint> r(f);

        r.add(0, IntPoint(6, 9));//2
        r.add(0, IntPoint(3, 5)); //0
        r.add(1, IntPoint(4, 2));//1
        r.add(IntPoint(1, 9));//3


        CHECK(r.size() == 4);
        CHECK(!r.isEmpty());

        int c = 0;
        for (const IntPoint& d:r){
            CHECK(r.get(c++) == d);
        }
        CHECK(c==r.size());
        CHECK(r.get(0) == IntPoint(3, 5));
        CHECK(r.get(1) == IntPoint(4, 2));

        CHECK(r.remove(2) == IntPoint(6, 9));

        CHECK(r.get(2) == IntPoint(1, 9));

        CHECK(r.size() == 3);

    }

}
