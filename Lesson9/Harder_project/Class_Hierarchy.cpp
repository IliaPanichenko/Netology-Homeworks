#include <iostream>
#include <string>
#include "Figure.h"
#include "Triangle.h"
#include "right_triangle.h"
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"
#include "Quadrangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"

int main(int argc, char** argv)
{
	Figure figure;
	figure.print_metod();
	figure.print_enter();

	Triangle Triangle(10, 20, 30, 50, 60, 70);
	Figure* Inp_Triangle = &Triangle;
	Inp_Triangle->print_metod();

	right_triangle right_triangle1(10, 20, 30, 50, 60, 90);
	Figure* Inp_RightTriangle = &right_triangle1;
	Inp_RightTriangle->print_metod();

	right_triangle right_triangle2(10, 20, 30, 50, 40, 90);
	Figure* Inp_RightTriangle2 = &right_triangle2;
	Inp_RightTriangle2->print_metod();

	isosceles_triangle isosceles_triangle(10, 20, 10, 50, 60, 50);
	Figure* Inp_IsoTriangle = &isosceles_triangle;
	Inp_IsoTriangle->print_metod();

	equilateral_triangle equilateral_triangle(30, 30, 30, 60, 60, 60);
	Figure* Inp_EquiTriangle = &equilateral_triangle;
	Inp_EquiTriangle->print_metod();

	Quadrangle Quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Figure* InpQuadrangle = &Quadrangle;
	InpQuadrangle->print_metod();

	Rectangle Rectangle(10, 20, 10, 20, 90, 90, 90, 90);
	Figure* InpRectangle = &Rectangle;
	InpRectangle->print_metod();

	Square Square(20, 20, 20, 20, 90, 90, 90, 90);
	Figure* InpSquare = &Square;
	InpSquare->print_metod();

	Parallelogram Parallelogram(20, 30, 20, 30, 30, 40, 30, 40);
	Figure* InpParallelogram = &Parallelogram;
	InpParallelogram->print_metod();

	Rhombus Rhombus(30, 30, 30, 30, 30, 40, 30, 40);
	Figure* InpRhombus = &Rhombus;
	InpRhombus->print_metod();
	return 0;
}