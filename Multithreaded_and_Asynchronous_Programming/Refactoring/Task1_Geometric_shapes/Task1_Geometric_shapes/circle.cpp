#include "circle.h"

Circle::Circle (int x, int y, double R) : x(x), y(y), R(R) {}
double Circle::area() const 
{
    return M_PI * R * R;
}
double Circle::volume() const 
{
    return 0;
}
void Circle::shift (int dx, int dy, int dz) {
    x += dx; y += dy;
}
void Circle::scale (double sx, double sy, double sz) 
{
    R *= sx;
}