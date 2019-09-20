#pragma once

#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include <math.h>

#include "Vector.h"


class Segment
{
    public:
        Segment();
        Segment (const Vector& new_one, const Vector& new_two) {
            one = new_one;
            two = new_two;
        }

        Segment (const double& newx1, const double& newx2, const double& newy1, const double& newy2) {
            one.setValue(newx1, newy1);
            two.setValue(newx2, newy2);
        }

        void printCoordinates () {
            std::cout << "(" << one.getX() << ", " << one.getY() << "), (" << two.getX() << ", " << two.getY() << ")" << std::endl;
        }

        double getLength () {
            Vector tmp;
            tmp = two - one;
            return tmp.getLength();
        }

    protected:
        Vector one;
        Vector two;
    private:
};

#endif // SEGMENT_H
