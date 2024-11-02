#define _USE_MATH_DEFINES
#pragma once
#include <cmath>
#include <vector>

class Shape 
{
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual double volume() const = 0;
    virtual void shift(int dx, int dy, int dz) = 0;
    virtual void scale(double sx, double sy, double sz) = 0;
};
