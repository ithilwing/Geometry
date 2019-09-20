#pragma once

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>

class Vector {
    public:
        Vector();
        Vector(const int& newBegin_x, const int& newBegin_y, const int& newEnd_x, const int& newEnd_y) {
            Begin_x = newBegin_x;
            Begin_y = newBegin_y;
            End_x = newEnd_x;
            End_y = newEnd_y;
        }
        Vector(const Vector& new_vector) {
            Begin_x = new_vector.Begin_x;
            Begin_y = new_vector.Begin_y;
            End_x = new_vector.End_x;
            End_y = new_vector.End_y;
        }
        ~Vector();

        /*Vector getValue() const {

        }*/
        void setValue(const int& newBegin_x, const int& newBegin_y, const int& newEnd_x, const int& newEnd_y) {
            Begin_x = newBegin_x;
            Begin_y = newBegin_y;
            End_x = newEnd_x;
            End_y = newEnd_y;
        }

        void printCoordinates () {
            std::cout << "(" << Begin_x << ", " << Begin_y << "), (" << End_x << ", " << End_y << ")" << std::endl;
        }

    protected:
        int Begin_x;
        int Begin_y;
        int End_x;
        int End_y;
    private:
};

#endif // VECTOR_H
