#include "cilinder.h"

Cylinder::Cylinder(int x, int y, double radius, double height)
    : x(x), y(y), R(radius), H(height) {};

double Cylinder::area() const 
{
    return 2 * M_PI * R * (R + H);
}
double Cylinder::volume() const 
{
    return M_PI * R * R * H;
}
void Cylinder::shift(int dx, int dy, int dz) 
{
    x += dx; y += dy;
}
void Cylinder::scale(double sx, double sy, double sz) {
    R *= sx;
    H *= sz;
}