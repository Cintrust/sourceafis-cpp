//
// Created by Junior Trust on 2/22/2020.
//

#include "catch.hpp"
#include "BooleanMatrix.h"
#include "IntPoint.h"


TEST_CASE( "Check BooleanMatrix Class ", "[BooleanMatrixTest]" ) {


    SECTION( "BooleanMatrix(int x,int x)" ) {

        BooleanMatrix t(2,4);
        CHECK(t.size().x==2);
        CHECK(t.size().y==4);

    }
    SECTION( "BooleanMatrix(int x,int x)" ) {

        IntPoint r(2,5);
        BooleanMatrix t(r);

        CHECK(t.size()==r);


    }
    SECTION( "BooleanMatrix.set() && BooleanMatrix.invert() " ) {

        IntPoint r(2,5);
        BooleanMatrix t(r);

        for (const auto && c:r){
            t.set(c, true);
        }

        for (const auto && c:r){
            CHECK(t.get(c));
        }
        t.invert();
        for (const auto && c:r){
            CHECK_FALSE(t.get(c));
        }


    }
    SECTION( "BooleanMatrix.merge(const BooleanMatrix &other) " ) {

        IntPoint r(2,5);
        BooleanMatrix t(r);
        BooleanMatrix f(r);

        t.merge(f);

        for (const auto && c:r){
            CHECK_FALSE(t.get(c));
        }
        f.invert();
        t.merge(f);

        for (const auto && c:r){
            CHECK(t.get(c));
        }

    }

}