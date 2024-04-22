#include "Rectangle.h"
	bool Rectangle::Check()
	{
		if (sideA == sideC && sideB == sideD && Quadrangle::Check() && angleA == 90 && angleB == 90 && angleC == 90 && angleD == 90)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	Rectangle::Rectangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : Quadrangle(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
	{
		Quadrangle::name = "Rectangle";
	};
