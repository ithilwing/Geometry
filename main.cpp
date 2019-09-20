#include <iostream>
#include <vector>
#include <string>

#include "Vector.h"
#include "Segment.h"
#include "Circle.h"
#include "Line.h"


int main(int argc, char **argv) {

    Vector my_vector; // empty constructor
    Vector new_vector(1,2); // ordinary constructor
    Vector copied_vector(my_vector); // copy constructor
    my_vector.setValue(3, 4);
 //   copied_vector = 5.0*my_vector;
    copied_vector = new_vector -  my_vector;
    my_vector.printCoordinates();
    new_vector.printCoordinates();
    copied_vector.printCoordinates();

    std::cout << my_vector.getLength() << std::endl;

    Segment my_segment (my_vector, new_vector);
    my_segment.printCoordinates();
    std::cout << my_segment.getLength() << std::endl;
    std::cout << my_vector.getScalarMult(new_vector) << std::endl;


    return 0;
}
