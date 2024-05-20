#include "isosceles_triangle.h"

	bool isosceles_triangle :: Check()
	{
		if (Triangle::Check() && sideA == sideC && angleA == angleC)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
        isosceles_triangle::isosceles_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : Triangle(sideA, sideB, sideC, angleA, angleB, angleC)
	{
		Triangle::name = "Isosceles triangle";
	};