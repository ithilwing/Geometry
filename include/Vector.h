#pragma once

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <math.h>

class Vector {
    public:
        Vector() {
            x = 0;
            y = 0;
        }
        Vector(const double& new_x, const double& new_y) {
            x = new_x;
            y = new_y;
        }
        Vector(const Vector& new_vector) {
            x = new_vector.x;
            y = new_vector.y;
        }

        double getX() const {
            return x;
        }

        double getY() const {
            return y;
        }
        void setValue(const double& new_x, const double& new_y) {
            x = new_x;
            y = new_y;
        }

        Vector operator+ (const Vector& another) const {
            Vector tmp;
            tmp.x = x + another.x;
            tmp.y = y + another.y;
            return tmp;
        }

        double getAbsValue () const {
            return sqrt(x*x + y*y);
        }

        friend Vector operator* (const double& a, const Vector& v);

        Vector operator- (const Vector& another) const {
            return *this + (-1)*another;
        }

        void printCoordinates () {
            std::cout << "(" << x << ", " << y << ")" << std::endl;
        }

    protected:
        double x;
        double y;
    private:
};

Vector operator* (const double& a, const Vector& v) {
    Vector tmp;
    tmp.x = v.x * a;
    tmp.y = v.y * a;
    return tmp;
}

#endif // VECTOR_H
