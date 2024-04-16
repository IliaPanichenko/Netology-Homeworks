#include "isosceles_triangle.h"

        isosceles_triangle::isosceles_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : Triangle(sideA, sideB, sideC, angleA, angleB, angleC)
	{
		Triangle::name = "Isosceles triangle";
		if (sideA != sideC && angleA == angleC)
		{
			throw Exception("Side A and Side C not equal");
		}
		if (angleA != angleC && sideA == sideC)
		{
			throw Exception("Angle A and Angle C not equal");
		}
		if (sideA != sideC && angleA != angleC)
		{
			throw Exception("Side A and Side C not equal and  Angle A and Angle C not equal");
		}
	};