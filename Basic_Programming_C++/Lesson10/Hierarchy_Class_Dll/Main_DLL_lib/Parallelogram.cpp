#include "Parallelogram.h"
	bool Parallelogram::Check()
	{
		if (sideA == sideC && sideB == sideD && Quadrangle::Check() && angleA == angleC && angleB == angleD)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	Parallelogram::Parallelogram(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : Quadrangle(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
	{
		Parallelogram::name = "Parallelogram";
	};