#include "right_triangle.h"

	right_triangle::right_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : Triangle(sideA, sideB, sideC, angleA, angleB, angleC)
	{
		Triangle::name = "Right triangle";
		if (angleC != 90 || angleA != 90 || angleB != 90)
		{
			throw Exception("No one of angles not equal 90");
		}
	};