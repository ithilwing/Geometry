#include <iostream>
#include <vector>
#include <string>

#include "Vector.h"
#include "Segment.h"


int main(int argc, char **argv) {

    Vector my_vector;
    Vector new_vector(7,8);
    Vector copied_vector(my_vector);
    my_vector.setValue(3, 4);
 //   copied_vector = 5.0*my_vector;
    copied_vector = new_vector -  my_vector;
    my_vector.printCoordinates();
    new_vector.printCoordinates();
    copied_vector.printCoordinates();

    std::cout << my_vector.getAbsValue() << std::endl;

    Segment my_segment (my_vector, new_vector);
    my_segment.printCoordinates();


    return 0;
}
