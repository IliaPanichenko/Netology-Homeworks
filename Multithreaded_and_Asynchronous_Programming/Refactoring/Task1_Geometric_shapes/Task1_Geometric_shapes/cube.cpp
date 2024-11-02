#include "cube.h"
#include <iostream>
Cube::Cube(const std::vector<int> & x_coords, const std::vector<int>& y_coords, const std::vector<int>& z_coords)
    : x_coords(x_coords), y_coords(y_coords), z_coords(z_coords) {};

double Cube::area() const 
{
    int a = std::abs(x_coords[0] - x_coords[1]);
    int b = std::abs(y_coords[0] - y_coords[2]);
    int c = std::abs(z_coords[0] - z_coords[4]);
    return 2 * (a * b + a * c + b * c);
}
double Cube::volume() const 
{
    int a = std::abs(x_coords[0] - x_coords[1]);
    int b = std::abs(y_coords[0] - y_coords[2]);
    int c = std::abs(z_coords[0] - z_coords[4]);
    return a * b * c;
}
void Cube::shift (int dx, int dy, int dz) 
{
    for (auto& x : x_coords) x += dx;
    for (auto& y : y_coords) y += dy;
    for (auto& z : z_coords) z += dz;
}
void Cube::scale(double sx, double sy, double sz) 
{
    for (auto& x : x_coords) x *= sx;
    for (auto& y : y_coords) y *= sy;
    for (auto& z : z_coords) z *= sz;
}
