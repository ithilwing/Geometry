// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef TESTS_H
#define TESTS_H

#include "Vector.h"
#include "Segment.h"
#include "Circle.h"
#include "Line.h"
#include "Shape.h"


class Tests
{
    public:
        Tests() {}
        void TestVector ();
        void TestSegment ();
        void TestSegmentIntersection ();
        void TestCirclesIntersection ();

};

void Tests::TestVector () {
    //test constructors and getX getY
    Vector<double> null_vector;
    Vector<double> my_vector(1,1);
    Vector<double> copied_vector(my_vector);

    assert(my_vector.getX() == 1 && my_vector.getY() == 1);
    assert(copied_vector.getX() == my_vector.getX() && copied_vector.getY() == my_vector.getY());
    assert(null_vector.getX() == 0 && null_vector.getY() == 0);

    //test setValue
    my_vector.setValue(2,2);
    assert(my_vector.getX() == 2 && my_vector.getY() == 2);

    //test unary + -
    assert(+my_vector.getX() == 2 && +my_vector.getY() == 2);
    assert(-my_vector.getX() == -2 && -my_vector.getY() == -2);

    //test binary + - *
    assert((my_vector+null_vector).getX() == 2 && (my_vector+null_vector).getY() == 2);
    assert((my_vector-null_vector).getX() == 2 && (my_vector-null_vector).getY() == 2);

    assert((my_vector+copied_vector).getX() == 3 && (my_vector+copied_vector).getY() == 3);
    assert((my_vector-copied_vector).getX() == 1 && (my_vector-copied_vector).getY() == 1);

    assert((my_vector*0.0).getX() == 0 && (my_vector*0.0).getY() == 0);
    assert((0.0*my_vector).getX() == 0 && (0.0*my_vector).getY() == 0);
    assert((my_vector*1.0).getX() == 2 && (my_vector*1.0).getY() == 2);
    assert((1.0*my_vector).getX() == 2 && (1.0*my_vector).getY() == 2);
    assert((my_vector*2.0).getX() == 4 && (my_vector*2.0).getY() == 4);
    assert((2.0*my_vector).getX() == 4 && (2.0*my_vector).getY() == 4);

    //test += -= *=
    my_vector+=null_vector;
    assert(my_vector.getX() == 2 && my_vector.getY() == 2);
    my_vector-=null_vector;
    assert(my_vector.getX() == 2 && my_vector.getY() == 2);
    my_vector+=copied_vector;
    assert(my_vector.getX() == 3 && my_vector.getY() == 3);
    my_vector-=copied_vector;
    assert(my_vector.getX() == 2 && my_vector.getY() == 2);

    my_vector*=1;
    assert(my_vector.getX() == 2 && my_vector.getY() == 2);
    my_vector*=2;
    assert(my_vector.getX() == 4 && my_vector.getY() == 4);
    my_vector*=0;
    assert(my_vector.getX() == 0 && my_vector.getY() == 0);

    //test getLength, getScalarMult
    my_vector.setValue(3,4);
    assert(my_vector.getLength() == 5);
    assert(null_vector.getLength() == 0);

    assert(my_vector.getScalarMult(null_vector) == 0);
    assert(my_vector.getScalarMult(copied_vector) == 7);

    //test == !=
    assert(my_vector != copied_vector);
    copied_vector.setValue(3,4);
    assert(my_vector == copied_vector);

    std::cout << "All tests on vectors passed successfully!" << std::endl;
    std:: cout << "my_vector: " << my_vector << std::endl;
    std:: cout << "copied_vector: " << copied_vector << std::endl;
    std:: cout << "null_vector: " << null_vector << std::endl;
    std::cout << std::endl;

}

void Tests::TestSegment () {

    //test constructors & getValues
    Vector<double> copied_vector(1,1);
    Vector<double> my_vector(4,5);

    Segment<double> null_segment;
    Segment<double> my_segment(copied_vector, my_vector);
    Segment<double> new_segment(2,2,5,6);

    assert(null_segment.getOneX() == 0 && null_segment.getOneY()== 0 && null_segment.getTwoX()== 0 && null_segment.getTwoY()== 0);
    assert(my_segment.getOneX() == 1 && my_segment.getOneY() == 1 && my_segment.getTwoX() == 4 && my_segment.getTwoY() == 5);
    assert(new_segment.getOneX() == 2 && new_segment.getOneY() == 2 && new_segment.getTwoX() == 5 && new_segment.getTwoY() == 6);

    //test getLength
    assert(my_segment.getLength() == 5);
    assert(new_segment.getLength() == 5);
    assert(null_segment.getLength() == 0);

    std::cout << "All tests on segments passed successfully!" << std::endl;
    std:: cout << "my_segment: " << my_segment << std::endl;
    std:: cout << "new_segment: " << new_segment << std::endl;
    std:: cout << "null_segment: " << null_segment << std::endl;
    std::cout << std::endl;
}

void Tests::TestSegmentIntersection() {
    Segment<double> one(2,3,2,4);
    Segment<double> two(1,3,3,1);
    Segment<double> three(1,1,3,3);
    Segment<double> four(1.5,1.5,2.5,2.5);
    Segment<double> five(2,0.5,2,1.5);
    Segment<double> six(2,1,2,3);
    Segment<double> seven(3,3,6,1);
    Segment<double> eight(3,1,6,3);
    Segment<double> nine(1.5,0,4.5,2);
    Segment<double> ten(2,0,2,1);
    assert((*dynamic_cast<NullShape<double>*>(GetIntersection(two,one))) == NullShape<double>()); //делаем из указателя на shape(getIntersection) укказатель на nullShape
    assert((*dynamic_cast<Vector<double>*>(GetIntersection(six,one))) == Vector<double>(2,3));
    assert((*dynamic_cast<Vector<double>*>(GetIntersection(two,three))) == Vector<double>(2,2));
    assert((*dynamic_cast<Segment<double>*>(GetIntersection(three,four))) == Segment<double>(1.5,1.5,2.5,2.5));
    assert((*dynamic_cast<Vector<double>*>(GetIntersection(two,four))) == Vector<double>(2,2));
    assert((*dynamic_cast<Vector<double>*>(GetIntersection(two,six))) == Vector<double>(2,2));
    assert((*dynamic_cast<Vector<double>*>(GetIntersection(three,six))) == Vector<double>(2,2));
    assert((*dynamic_cast<Segment<double>*>(GetIntersection(five,six))) == Segment<double>(2,1,2,1.5));
    assert((*dynamic_cast<Vector<double>*>(GetIntersection(two,eight))) == Vector<double>(3.0,1.0));
    assert((*dynamic_cast<Vector<double>*>(GetIntersection(three,seven))) == Vector<double>(3,3));
    assert((*dynamic_cast<Vector<double>*>(GetIntersection(seven,eight))) == Vector<double>(4.5,2));
    assert((*dynamic_cast<Segment<double>*>(GetIntersection(eight,nine))) == Segment<double>(3,1,4.5,2)); //память освобожу позжу

    std::cout << "All tests on sector intersections passed successfully!" << std::endl;
}

void Tests::TestCirclesIntersection() {
    Circle<double> one (0,0,2);
    Circle<double> two (1,0,1);
    Circle<double> three (4,4,sqrt(2));
    Circle<double> four (0,3,1);
    Circle<double> five (3,1,sqrt(2));

    assert((*dynamic_cast<NullShape<double>*>(GetIntersection(one,three))) == NullShape<double>());
    assert((*dynamic_cast<NullShape<double>*>(GetIntersection(four,five))) == NullShape<double>());
    assert((*dynamic_cast<Vector<double>*>(GetIntersection(four,one))) == Vector<double>(0,2));
    assert((*dynamic_cast<Vector<double>*>(GetIntersection(two,one))) == Vector<double>(2,0));
    assert((*dynamic_cast<Segment<double>*>(GetIntersection(one,five))) == Segment<double>(2,0,1.6,1.2) ||
           (*dynamic_cast<Segment<double>*>(GetIntersection(one,five))) == Segment<double>(1.6,1.2,2,0));
    assert((*dynamic_cast<Segment<double>*>(GetIntersection(two,five))) == Segment<double>(2,0,1.6,0.8) ||
           (*dynamic_cast<Segment<double>*>(GetIntersection(two,five))) == Segment<double>(1.6,0.8,2,0));

    std::cout << "All tests on circle intersections passed successfully!" << std::endl;

}

#endif // TESTS_H
