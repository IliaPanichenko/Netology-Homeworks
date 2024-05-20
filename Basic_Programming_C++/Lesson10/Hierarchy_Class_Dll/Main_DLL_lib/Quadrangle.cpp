#include "Quadrangle.h"
#include <iostream>
	bool Quadrangle:: Check()
	{
		if (angleA + angleB + angleC + angleD == 360)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	Quadrangle::Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD)
	{
		number_sides = 4;
		name = "Quadrangle";
		Check();
		this->sideA = sideA;
		this->sideB = sideB;
		this->sideC = sideC;
		this->sideD = sideD;
		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
		this->angleD = angleD;
	}

	void Quadrangle::print_metod()
	{
		Figure::print_metod();
		std::cout << "Sides: ";
		std::cout << "a = " << sideA << ", b = " << sideB << ", c = " << sideC << ", d = " << sideD << "\n";
		std::cout << "Angles: ";
		std::cout << "A = " << angleA << ", B = " << angleB << ", C = " << angleC << ", D = " << angleD << "\n";
		std::cout << "\n";
	}