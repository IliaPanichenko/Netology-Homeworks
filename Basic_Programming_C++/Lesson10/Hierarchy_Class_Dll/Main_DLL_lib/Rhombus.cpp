#include "Rhombus.h"
	bool Rhombus::Check()
	{
		if (sideA == sideC && sideC == sideD && sideB == sideD && Quadrangle::Check() && angleA == angleC && angleB == angleD)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	Rhombus::Rhombus(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : Quadrangle(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
	{
		Rhombus::name = "Rhombus";
	};