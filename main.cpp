#include <iostream>
#include <vector>
#include <string>

#include "Vector.h"
#include "Segment.h"
#include "Circle.h"
#include "Line.h"


int main(int argc, char **argv) {

    Vector<double> my_vector; // empty constructor
    Vector<double> new_vector(1,2); // ordinary constructor
    Vector<double> copied_vector(my_vector); // copy constructor
    my_vector.setValue(3, 4);
 //   copied_vector = 5.0*my_vector;
    copied_vector = new_vector -  my_vector;
    copied_vector.printCoordinates();
    if (copied_vector != new_vector) {
        std::cout << true << std::endl;
    } else {
        std::cout << false << std::endl;
    }
//    copied_vector.printCoordinates();
    my_vector.printCoordinates();
    new_vector.printCoordinates();

    std::cout << my_vector.getLength() << std::endl;

    Segment<double> my_segment (my_vector, new_vector);
    my_segment.printCoordinates();
    std::cout << my_segment.getLength() << std::endl;
    std::cout << my_vector.getScalarMult(new_vector) << std::endl;


    return 0;
}
