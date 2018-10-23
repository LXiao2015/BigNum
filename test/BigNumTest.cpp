#include "BigNumTest.h"
#include "cppunit/TestAssert.h"

void BigNumTest::setUp() {
    num1 = 2;
    num2 = 5;
}

void BigNumTest::testAdd() {
    BigNum result = num1 + num2;
    CPPUNIT_ASSERT( result == BigNum("7") );
}
