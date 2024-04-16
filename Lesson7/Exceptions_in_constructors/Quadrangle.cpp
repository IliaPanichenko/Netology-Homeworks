#include "Quadrangle.h"
#include <iostream>
#include "Exception.h"
	Quadrangle::Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD)
	{
		name = "Quadrangle";
		this->sideA = sideA;
		this->sideB = sideB;
		this->sideC = sideC;
		this->sideD = sideD;
		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
		this->angleD = angleD;
		if (angleA + angleB + angleC + angleD != 360)
		{
			throw Exception("Sum of angles does not equal 360");
		}
	}

	void Quadrangle::print_metod()
	{
		Figure::print_metod();
		std::cout << "(" << "Sides ";
		std::cout << sideA << ", " << sideB << ", " << sideC << ", " << sideD<< "; ";
		std::cout << "Angles ";
		std::cout << angleA << ", " << angleB << ", " << angleC << ", " << angleD << ")" << " ";
		std::cout << "\n\n";
	}
