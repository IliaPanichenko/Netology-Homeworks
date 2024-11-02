#include <iostream>
#include "line.h"
#include "square.h"
#include "cube.h"
#include "circle.h"
#include "cilinder.h"

int main()
{
    Line line (0, 0, 10, 10);
    line.shift (5, 5, 0);
    std::cout << "Line Area: " << line.area() << ", Volume: " << line.volume() << "\n";
    Square square({ 0, 5, 5, 0 }, { 0, 0, 5, 5 });
    square.scale (2, 2, 1);
    std::cout << "Square Area: " << square.area() << ", Volume: " << square.volume() << "\n";
    Cube cube({ 0, 3, 3, 0, 0, 3, 3, 0 }, { 0, 0, 3, 3, 0, 0, 3, 3 }, { 0, 0, 0, 0, 3, 3, 3, 3 });
    cube.scale (2, 2, 2);
    std::cout << "Cube Area: " << cube.area() << ", Volume: " << cube.volume() << "\n";
    Circle circle(0, 0,5);
    circle.scale (1.5, 1.5, 1);
    std::cout << "Circle Area: " << circle.area() << ", Volume: " << circle.volume() << "\n";
    Cylinder cilinder(0, 0, 3, 7);
    cilinder.scale (1, 1, 1.5);
    std::cout << "Cilinder Area: " << cilinder.area() << ", Volume: " << cilinder.volume() << "\n";
    return 0;
}