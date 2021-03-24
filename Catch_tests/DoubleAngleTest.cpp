//
// Created by Junior Trust on 2/23/2020.
//

//
// Created by Junior Trust on 2/23/2020.
//





#include "catch.hpp"
#include "DoubleAngle.h"
#include "DoublePoint.h"
#include "IntPoint.h"


TEST_CASE("Check DoubleAngle Class ", "[DoubleAngleTest]") {



    SECTION("DoubleAngle::toVector(double)") {


        CHECK(DoublePoint(1, 0)== DoubleAngle::toVector(-DoubleAngle::PI2));
        CHECK(DoublePoint(0, 1)== DoubleAngle::toVector(-1.5 * Doubles::PI));


        CHECK( DoublePoint(-1, 0)== DoubleAngle::toVector(-Doubles::PI));
        CHECK( DoublePoint(0, -1)== DoubleAngle::toVector(-0.5 * Doubles::PI));
        CHECK( DoublePoint(1, 0)== DoubleAngle::toVector(0));
        CHECK( DoublePoint(Doubles::sqrt(2) / 2, Doubles::sqrt(2) / 2)== DoubleAngle::toVector(Doubles::PI / 4));
        CHECK( DoublePoint(0, 1)== DoubleAngle::toVector(Doubles::PI / 2));
        CHECK( DoublePoint(-1, 0)== DoubleAngle::toVector(Doubles::PI));
        CHECK( DoublePoint(0, -1)== DoubleAngle::toVector(1.5 * Doubles::PI));
        CHECK( DoublePoint(1, 0)== DoubleAngle::toVector(DoubleAngle::PI2));
        CHECK( DoublePoint(0, 1)== DoubleAngle::toVector(2.5 * Doubles::PI));
        CHECK( DoublePoint(-1, 0)== DoubleAngle::toVector(3 * Doubles::PI));
        CHECK( DoublePoint(0, -1)== DoubleAngle::toVector(3.5 * Doubles::PI));
        CHECK( DoublePoint(1, 0)== DoubleAngle::toVector(2 * DoubleAngle::PI2));



    }
    SECTION("DoubleAngle::atanPoint)") {

        CHECK(Approx(0).margin(0.001)== DoubleAngle::atan( DoublePoint(5, 0)));
        CHECK(Approx(0.25 * Doubles::PI).margin(0.001) == DoubleAngle::atan( DoublePoint(1, 1)));
        CHECK(Approx(0.5 * Doubles::PI).margin(0.001)== DoubleAngle::atan( DoublePoint(0, 3)));
        CHECK(Approx(Doubles::PI).margin(0.001)== DoubleAngle::atan( DoublePoint(-0.3, 0)));
        CHECK(Approx(1.5 * Doubles::PI).margin(0.001)== DoubleAngle::atan( DoublePoint(0, -1)));
        CHECK(Approx(1.75 * Doubles::PI).margin(0.001)== DoubleAngle::atan( DoublePoint(1, -1)));


    }
    SECTION("DoubleAngle::atanCell()") {

        CHECK(Approx(0.5 * Doubles::PI).margin(0.001)== DoubleAngle::atan( IntPoint(0, 2)));

    }
    SECTION("DoubleAngle::atanCell()") {

        CHECK(Approx(0.25 * Doubles::PI).margin(0.001)== DoubleAngle::atan( IntPoint(2, 3),  IntPoint(4, 5)));

    }
    SECTION("DoubleAngle::toOrientation()") {

        CHECK(Approx(0).margin(0.001)== DoubleAngle::toOrientation(0));
        CHECK(Approx(0.5 * Doubles::PI).margin(0.001)== DoubleAngle::toOrientation(0.25 * Doubles::PI));
        CHECK(Approx(Doubles::PI).margin(0.001)== DoubleAngle::toOrientation(0.5 * Doubles::PI));
        CHECK(Approx(2 * Doubles::PI).margin(0.001)== DoubleAngle::toOrientation(Doubles::PI - 0.000001));
        CHECK(Approx(0).margin(0.001)== DoubleAngle::toOrientation(Doubles::PI + 0.000001));
        CHECK(Approx(Doubles::PI).margin(0.001)== DoubleAngle::toOrientation(1.5 * Doubles::PI));
        CHECK(Approx(1.5 * Doubles::PI).margin(0.001)== DoubleAngle::toOrientation(1.75 * Doubles::PI));
        CHECK(Approx(2 * Doubles::PI).margin(0.001)== DoubleAngle::toOrientation(2 * Doubles::PI - 0.000001));

    }
    SECTION("DoubleAngle::add()") {
        CHECK(Approx(0).margin(0.001)== DoubleAngle::add(0, 0));
        CHECK(Approx(0.75 * Doubles::PI).margin(0.001)== DoubleAngle::add(0.25 * Doubles::PI, 0.5 * Doubles::PI));
        CHECK(Approx(1.75 * Doubles::PI).margin(0.001)== DoubleAngle::add(Doubles::PI, 0.75 * Doubles::PI));
        CHECK(Approx(0.25 * Doubles::PI).margin(0.001)==DoubleAngle::add(Doubles::PI, 1.25 * Doubles::PI));
        CHECK( Approx(1.5 * Doubles::PI).margin(0.001)== DoubleAngle::add(1.75 * Doubles::PI, 1.75 * Doubles::PI));
    }
    SECTION("DoubleAngle::opposite()") {
        CHECK( Approx(Doubles::PI).margin(0.001)== DoubleAngle::opposite(0));
        CHECK( Approx(1.25 * Doubles::PI).margin(0.001)== DoubleAngle::opposite(0.25 * Doubles::PI));
        CHECK( Approx(1.5 * Doubles::PI).margin(0.001)== DoubleAngle::opposite(0.5 * Doubles::PI));
        CHECK( Approx(2 * Doubles::PI).margin(0.001)== DoubleAngle::opposite(Doubles::PI - 0.000001));
        CHECK(Approx(0).margin(0.001)== DoubleAngle::opposite(Doubles::PI + 0.000001));
        CHECK( Approx(0.5 * Doubles::PI).margin(0.001)== DoubleAngle::opposite(1.5 * Doubles::PI));
        CHECK(Approx( Doubles::PI).margin(0.001)== DoubleAngle::opposite(2 * Doubles::PI - 0.000001));
    }

    SECTION("DoubleAngle::distance()") {
        CHECK( Approx(Doubles::PI).margin(0.001)== DoubleAngle::distance(0, Doubles::PI));
        CHECK(Approx(Doubles::PI).margin(0.001)== DoubleAngle::distance(1.5 * Doubles::PI, 0.5 * Doubles::PI));
        CHECK(  Approx(0.75 *Doubles::PI).margin(0.001)== DoubleAngle::distance(0.75 * Doubles::PI, 1.5 * Doubles::PI));
        CHECK( Approx(0.5 * Doubles::PI).margin(0.001)== DoubleAngle::distance(0.25 * Doubles::PI, 1.75 * Doubles::PI));
    }


    SECTION("DoubleAngle::difference()") {
        CHECK(Approx(Doubles::PI).margin(0.001)== DoubleAngle::difference(0, Doubles::PI));
        CHECK(Approx(Doubles::PI).margin(0.001)== DoubleAngle::difference(1.5 * Doubles::PI, 0.5 * Doubles::PI));
        CHECK( Approx(1.25 * Doubles::PI).margin(0.001)== DoubleAngle::difference(0.75 * Doubles::PI, 1.5 * Doubles::PI));
        CHECK(Approx(0.5 * Doubles::PI).margin(0.001)== DoubleAngle::difference(0.25 * Doubles::PI, 1.75 * Doubles::PI));
    }


    SECTION("DoubleAngle::complementary()") {
        CHECK(Approx(0).margin(0.001)== DoubleAngle::complementary(0));
        CHECK( Approx(1.5 * Doubles::PI).margin(0.001)== DoubleAngle::complementary(0.5 * Doubles::PI));
        CHECK(Approx( Doubles::PI).margin(0.001)== DoubleAngle::complementary(Doubles::PI - 0.0000001));
        CHECK(Approx( Doubles::PI).margin(0.001)== DoubleAngle::complementary(Doubles::PI + 0.0000001));
        CHECK( Approx(0.5 * Doubles::PI).margin(0.001)== DoubleAngle::complementary(1.5 * Doubles::PI));
        CHECK(Approx(0).margin(0.001)== DoubleAngle::complementary(2 * Doubles::PI - 0.0000001));
    }

    SECTION("DoubleAngle::bucketCenter()") {
        CHECK(Approx(0.25 * Doubles::PI).margin(0.001)== DoubleAngle::bucketCenter(0, 4));
        CHECK( Approx(0.75 * Doubles::PI).margin(0.001)== DoubleAngle::bucketCenter(1, 4));
        CHECK( Approx(1.25 * Doubles::PI).margin(0.001)== DoubleAngle::bucketCenter(2, 4));
        CHECK( Approx(1.75 * Doubles::PI).margin(0.001)== DoubleAngle::bucketCenter(3, 4));
    }

    SECTION("DoubleAngle::quantize()") {
        CHECK(0== DoubleAngle::quantize(-0.0001, 4));
        CHECK(0== DoubleAngle::quantize(0, 4));
        CHECK(0== DoubleAngle::quantize(0.25 * Doubles::PI, 4));
        CHECK(2== DoubleAngle::quantize(Doubles::PI, 5));
        CHECK(6== DoubleAngle::quantize(1.75 * Doubles::PI, 7));
        CHECK(9== DoubleAngle::quantize(DoubleAngle::PI2 - 0.001, 10));
        CHECK(9== DoubleAngle::quantize(DoubleAngle::PI2 + 0.001, 10));
    }

}
