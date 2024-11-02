#pragma once
#include "shape.h"
class Circle : public Shape 
{
private:
    int x, y;
    double R;
public:
    Circle(int x, int y, double R);
    double area() const override;
    double volume() const override;
    void shift(int dx, int dy, int dz) override;
    void scale(double sx, double sy, double sz) override;
};