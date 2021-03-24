//
// Created by Junior Trust on 3/7/2020.
//


#include "catch.hpp"
#include "SkeletonRidge.h"
#include "IntPoint.h"

TEST_CASE( "Check SkeletonRidge Class ", "[SkeletonRidgeTest]" ) {



    SECTION( "SkeletonRidge()" ) {

        SkeletonRidge s;
//        SkeletonRidge d(&s);


    }
    SECTION( "SkeletonRidge.points &&SkeletonRidge.reversed " ) {

        SkeletonRidge x;
//        CircularArray<IntPoint> r;

//        CircularList<IntPoint> f;

//        ReversedList<IntPoint> r(f);

        x.reversed->points->add(0, IntPoint(6, 9));//2
         x.reversed->points->add(0, IntPoint(3, 5)); //0
        x.reversed->points->add(1, IntPoint(4, 2));//1
        x.reversed->points->add(IntPoint(1, 9));//3


        CHECK( x.reversed->points->size() == 4);
        CHECK(!x.reversed->points->isEmpty());

        CHECK( x.reversed->points->get(0) == IntPoint(3, 5));
        CHECK( x.reversed->points->get(1) == IntPoint(4, 2));
        CHECK( x.reversed->points->get(2) == IntPoint(6, 9));
        CHECK( x.reversed->points->get(3) == IntPoint(1, 9));

        CHECK( x.reversed->points->get(0) ==  x.points->get(3));
        CHECK( x.reversed->points->get(1) == x.points->get(2));
        CHECK( x.reversed->points->get(2) == x.points->get(1));
        CHECK( x.reversed->points->get(3) == x.points->get(0));

    }
//    SECTION( "CircularArray.insert && CircularArray.remove" ) {
//
//        IntPoint r(2,5);
//        IntPoint c(20,52);
//        CircularArray<IntPoint> h;
//        int s=0;
//        for (auto&& f :r){
//            h.insert(s,f);
//            CHECK(f==h.get(s));
//            ++s;
//        }
//        h.insert(h.size(),r);
//        h.insert(0,c);
//        CHECK(c==h.get(0));
//        CHECK(r==h.get(h.size()-1));
//
//        h.remove(1,s);
//
//        CHECK(c==h.get(0));
//        CAPTURE(h.get(1),r,h.size(),s);
//        CHECK(r==h.get(1));
//
//        CircularArray<IntPoint> y;
//
//        y.insert(0,r);
//        y.insert(0,c);
//
//        CHECK(c==y.get(0));
//        CHECK(r==y.get(1));
//
//        y.remove(0,1);
//        CHECK(r==y.get(0));
//
//
//    }

}
