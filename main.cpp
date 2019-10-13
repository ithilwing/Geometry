#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

#include "Vector.h"
#include "Segment.h"
#include "Circle.h"
#include "Line.h"
#include "Tests.h"
#include "Shape.h"




int main(int argc, char **argv) {

    Tests myTest;
    myTest.TestVector();
    myTest.TestSegment();
    myTest.TestSegmentIntersection();


    return 0;
}
