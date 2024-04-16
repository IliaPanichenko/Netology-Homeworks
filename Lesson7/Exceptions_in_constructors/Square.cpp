#include "Square.h"
#include "Exception.h"
	Square::Square(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : Quadrangle(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
	{
		Square::name = "Square";
		if (sideA != sideC && sideC != sideB && sideB != sideD)
		{
			throw Exception("Sides not equal");
		}
		if (angleA != 90 && angleB != 90 && angleC != 90 && angleD != 90)
		{
			throw Exception("Angles not equal");
		}
		if (sideA != sideC && sideC != sideB && sideB != sideD && (angleA != 90 && angleB != 90 && angleC != 90 && angleD != 90))
		{
			throw Exception("Angles and sides not equal");
		}
	};
