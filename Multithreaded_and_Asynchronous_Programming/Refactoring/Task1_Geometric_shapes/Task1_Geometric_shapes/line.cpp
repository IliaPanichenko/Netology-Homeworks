#include "line.h"

Line::Line(int x1, int y1, int x2, int y2) 
{
    x_coords[0] = x1;
    x_coords[1] = x2;
    y_coords[0] = y1;
    y_coords[1] = y2;
}
double Line::area() const 
{
    return 0;
}
double Line::volume() const 
{
    return 0;
}
void Line::shift (int dx, int dy, int dz) 
{
    for (auto& x : x_coords) x += dx;
    for (auto& y : y_coords) y += dy;
}
void Line::scale (double sx, double sy, double sz) 
{
    for (auto& x : x_coords) x *= sx;
    for (auto& y : y_coords) y *= sy;
}
