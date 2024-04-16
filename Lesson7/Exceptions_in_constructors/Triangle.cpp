#include "Triangle.h"
#include <iostream>
#include "Exception.h"

	Triangle::Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC)
	{
		name = "Triangle";
		this->sideA = sideA;
		this->sideB = sideB;
		this->sideC = sideC;
		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
		if ((angleA + angleB + angleC) != 180)
		{
			throw Exception("Sum of angles does not equal 180");
		}
	}
	void Triangle::print_metod()
	{
		Figure::print_metod();
		std::cout << "(" << "Sides ";
		std::cout << sideA << ", " << sideB << ", " << sideC << "; ";
		std::cout << "Angles ";
		std::cout << angleA << ", " << angleB << ", " << angleC << ")" << " ";
		std::cout << "\n\n";
	}