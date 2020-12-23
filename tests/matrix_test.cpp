//
// Created by dvshapkin on 22.12.2020.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"
#include "matrix.h"

TEST_CASE( "Matrix equality", "[matrix_test]" ) {
    Matrix m1(2,3);
    Matrix m2(3,3);
    REQUIRE( m1 == m2 );
}
