#include <iostream>
#include <vector>
#include <string>

#include "Vector.h"

int main(int argc, char **argv) {

    Vector my_vector;
    Vector new_vector(5,6,7,8);
    Vector copied_vector(my_vector);
    my_vector.setValue(7, 2, 3, 4);
    my_vector.printCoordinates();
    new_vector.printCoordinates();
    copied_vector.printCoordinates();

    return 0;
}
