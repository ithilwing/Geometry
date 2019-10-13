#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

#include "Vector.h"
#include "Segment.h"
#include "Circle.h"
#include "Line.h"
#include "Tests.h"




int main(int argc, char **argv) {

    Tests myTest;
    myTest.TestVector();
    myTest.TestSegment();

    Segment<double> one (6,2,8,5);
    Segment<double> two (7,3.5,10,8);

    CheckIfIntersect(two,one);

    return 0;
}
