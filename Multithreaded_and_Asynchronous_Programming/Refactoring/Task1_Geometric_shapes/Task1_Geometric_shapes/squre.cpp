#include "square.h"
Square::Square(const std::vector<int>& x_coords, const std::vector<int>& y_coords)
    : x_coords(x_coords), y_coords(y_coords) {};

double Square::area() const 
{
    int side = std::abs(x_coords[0] - x_coords[1]);
    return side * side;
}

double Square::volume() const 
{
    return 0;
}

void Square::shift(int dx, int dy, int dz) 
{
    for (auto& x : x_coords) x += dx;
    for (auto& y : y_coords) y += dy;
}

void Square::scale(double sx, double sy, double sz) 
{
    for (auto& x : x_coords) x *= sx;
    for (auto& y : y_coords) y *= sy;
}