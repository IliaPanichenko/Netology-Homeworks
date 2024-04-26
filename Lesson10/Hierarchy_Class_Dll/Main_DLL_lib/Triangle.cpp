#include "Triangle.h"
#include <iostream>

	bool Triangle :: Check() 
	{
		if (angleA + angleB + angleC == 180)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	Triangle::Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC)
	{
		number_sides = 3;
		name = "Triangle";
		Check();
		this->sideA = sideA;
		this->sideB = sideB;
		this->sideC = sideC;
		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
	}
	void Triangle::print_metod()
	{
		Figure::print_metod();
		std::cout << "Sides: ";
		std::cout << "a = " << sideA << ", b = " << sideB << ", c = " << sideC << "\n";
		std::cout << "Angles: ";
		std::cout << "A = " << angleA << ", B = " << angleB << ", C = " << angleC << "\n";
		std::cout << "\n";
	}