#pragma once

#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>

#include "Vector.h"


class Segment
{
    public:
        Segment() {
            x1 = x2 = y1 = y2 = 0;
        }
        Segment (const Vector& one, const Vector& two) {
            x1 = one.getX();
            x2 = two.getX();
            y1 = one.getY();
            y2 = two.getY();
        }

        Segment (const double& newx1, const double& newx2, const double& newy1, const double& newy2) {
            x1 = newx1;
            x2 = newx2;
            y1 = newy1;
            y2 = newy2;
        }

        void printCoordinates () {
            std::cout << "(" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")" << std::endl;
        }

    protected:
        double x1;
        double x2;
        double y1;
        double y2;
    private:
};

#endif // SEGMENT_H
