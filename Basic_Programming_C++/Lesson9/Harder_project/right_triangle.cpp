#include "right_triangle.h"

	bool right_triangle::Check()
	{
		if (Triangle::Check() && angleC == 90)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	right_triangle::right_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : Triangle(sideA, sideB, sideC, angleA, angleB, angleC)
	{
		Triangle::name = "Right triangle";
	};