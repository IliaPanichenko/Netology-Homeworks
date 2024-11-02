#pragma once
#include "shape.h"

class Line : public Shape 
{
private:
    std::vector<int> x_coords = { 0, 0 };
    std::vector<int> y_coords = { 0, 0 };
public:
    Line(int x1, int y1, int x2, int y2);
    double area() const override;
    double volume() const override;
    void shift(int dx, int dy, int dz) override;
    void scale(double sx, double sy, double sz) override;


};