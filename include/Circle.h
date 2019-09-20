#pragma once

#ifndef  CIRCLE_H
#define  CIRCLE_H


class  Circle
{
    public:
        Circle();
        Circle(const Vector& p, const Vector& r) {
            point = p;
            radius = r.getLength();
        }

    protected:
        Vector point;
        double radius;
    private:
};

#endif //  CIRCLE_
