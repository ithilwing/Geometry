#pragma once

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>

class Vector {
    public:
        Vector() {
            x = 0;
            y = 0;
        }
        Vector(const int& new_x, const int& new_y) {
            x = new_x;
            y = new_y;
        }
        Vector(const Vector& new_vector) {
            x = new_vector.x;
            y = new_vector.y;
        }

        /*Vector getValue() const {

        }*/
        void setValue(const int& new_x, const int& new_y) {
            x = new_x;
            y = new_y;
        }

        Vector operator+ (const Vector& another) const {
            Vector tmp;
            tmp.x = x + another.x;
        }

        void printCoordinates () {
            std::cout << "(" << x << ", " << y << ")" << std::endl;
        }

    protected:
        int x;
        int y;
    private:
};

#endif // VECTOR_H
