#pragma once
#include "shape.h"
class Cylinder : public Shape 
{
private:
    int x, y;
    double R, H;

public:
    Cylinder (int x, int y, double R, double H);
    double area() const override;
    double volume() const override;
    void shift (int dx, int dy, int dz) override;
    void scale (double sx, double sy, double sz) override;
};
