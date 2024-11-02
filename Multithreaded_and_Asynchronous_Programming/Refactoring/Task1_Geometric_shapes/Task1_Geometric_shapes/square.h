#pragma once
#include "Shape.h"

class Square : public Shape {
private:
    std::vector<int> x_coords = { 0, 0, 0, 0 };
    std::vector<int> y_coords = { 0, 0, 0, 0 };

public:
    Square(const std::vector<int>& x_coords, const std::vector<int>& y_coords);
    double area() const override;
    double volume() const override;
    void shift(int dx, int dy, int dz) override;
    void scale(double sx, double sy, double sz) override;


};