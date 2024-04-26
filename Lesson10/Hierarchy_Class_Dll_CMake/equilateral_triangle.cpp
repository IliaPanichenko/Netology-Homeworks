#include "equilateral_triangle.h"

	bool equilateral_triangle:: Check()
	{
		if (Triangle::Check() && sideA == sideC && sideC == sideB && angleA == 60 && angleC == 60 && angleB == 60)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	equilateral_triangle::equilateral_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : Triangle(sideA, sideB, sideC, angleA, angleB, angleC)
	{
		Triangle::name = "Equilateral triangle";
	};
