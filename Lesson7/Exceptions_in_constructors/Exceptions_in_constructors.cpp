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
#include "Exception.h"

int main(int argc, char** argv)
{
	try
	{
		Triangle Triangle(10, 20, 30, 50, 60, 70);
		Figure* Inp_Triangle = &Triangle;
		Inp_Triangle->print_metod();
	}
	catch (const std::exception& Tr)
	{
		std::cout << "\n";
		std::cout << "Triangle not made. " << "\n" << "Reason: ";
		std::cout << Tr.what() << "\n";
	}
	try
	{
	    right_triangle right_triangle1(10, 20, 30, 50, 60, 70);
	    Figure* Inp_RightTriangle = &right_triangle1;
	    Inp_RightTriangle->print_metod();
	}
	catch (const std::exception& Rt)
	{
		std::cout << "\n";
		std::cout << "Right triangle not made. " << "\n" << "Reason: ";
		std::cout << Rt.what() << "\n";
	}
	try
	{
	    right_triangle right_triangle2(10, 20, 30, 50, 50, 90);
	    Figure* Inp_RightTriangle2 = &right_triangle2;
	    Inp_RightTriangle2->print_metod();
	}
	catch (const std::exception& Rt)
	{
		std::cout << "\n";
		std::cout << "Right triangle not made. " << "\n" << "Reason: ";
		std::cout << Rt.what() << "\n";
	}
	try
	{
		isosceles_triangle isosceles_triangle(10, 20, 10, 50, 70, 60);
		Figure* Inp_IsoTriangle = &isosceles_triangle;
		Inp_IsoTriangle->print_metod();
	}
	catch (const std::exception& It)
	{
		std::cout << "\n";
		std::cout << "Isosceles triangle not made. " << "\n" << "Reason: ";
		std::cout << It.what() << "\n";
	}
	try
	{
		equilateral_triangle equilateral_triangle(30, 30, 20, 70, 50, 60);
		Figure* Inp_EquiTriangle = &equilateral_triangle;
		Inp_EquiTriangle->print_metod();
	}
	catch (const std::exception& Et)
	{
		std::cout << "\n";
		std::cout << "Equilateral triangle not made. " << "\n" << "Reason: ";
		std::cout << Et.what() << "\n";
	}
	try
	{
		Quadrangle Quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
		Figure* InpQuadrangle = &Quadrangle;
		InpQuadrangle->print_metod();
	}
	catch (const std::exception& Qd)
	{
		std::cout << "\n";
		std::cout << "Quadrangle not made. " << "\n" << "Reason: ";
		std::cout << Qd.what() << "\n";
	}
	try
	{
		Rectangle Rectangle(10, 20, 10, 20, 90, 90, 90, 90);
		Figure* InpRectangle = &Rectangle;
		InpRectangle->print_metod();
	}
	catch (const std::exception& Rl)
	{
		std::cout << "\n";
		std::cout << "Rectangle not made. " << "\n" << "Reason: ";
		std::cout << Rl.what() << "\n";
	}
	try
	{
		Square Square(20, 20, 20, 20, 90, 90, 90, 90);
		Figure* InpSquare = &Square;
		InpSquare->print_metod();
	}
	catch (const std::exception& Sq)
	{
		std::cout << "\n";
		std::cout << "Square not made. " << "\n" << "Reason: ";
		std::cout << Sq.what() << "\n";
	}
	try
	{
		Parallelogram Parallelogram(20, 30, 20, 30, 30, 40, 30, 40);
		Figure* InpParallelogram = &Parallelogram;
		InpParallelogram->print_metod();
	}
	catch (const std::exception& Pl)
	{
		std::cout << "\n";
		std::cout << "Parallelogram not made. " << "\n" << "Reason: ";
		std::cout << Pl.what() << "\n";
	}
	try
	{
		Rhombus Rhombus(30, 30, 30, 30, 80, 140, 60, 80);
		Figure* InpRhombus = &Rhombus;
		InpRhombus->print_metod();
	}
	catch (const std::exception& Rs)
	{
		std::cout << "\n";
		std::cout << "Rhombus not made. " << "\n" << "Reason: ";
		std::cout << Rs.what() << "\n";
	}
	return 0;
}