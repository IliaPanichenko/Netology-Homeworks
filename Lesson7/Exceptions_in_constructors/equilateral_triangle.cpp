#include "equilateral_triangle.h"

	equilateral_triangle::equilateral_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : Triangle(sideA, sideB, sideC, angleA, angleB, angleC)
	{
		Triangle::name = "Equilateral triangle";
		if (sideA != sideC || sideC != sideB && (angleA == 60 && angleC == 60 && angleB == 60))
		{
			throw Exception("One of sides not equal");
		}
		if (angleA != 60 || angleC != 60 || angleB != 60 && (sideA == sideC && sideC == sideB))
		{
			throw Exception("One of angles not equal 60");
		}
		else if (sideA != sideC || sideC != sideB && (angleA != 60 || angleC != 60 || angleB != 60))
		{
			throw Exception("One of sides not equal and one of angles not equal 60");
		}
	};
