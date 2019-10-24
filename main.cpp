// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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
    myTest.TestCirclesIntersection();


    return 0;
}
