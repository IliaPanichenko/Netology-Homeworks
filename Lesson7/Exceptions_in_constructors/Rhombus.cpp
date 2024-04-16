#include "Rhombus.h"

	Rhombus::Rhombus(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : Quadrangle(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
	{
		Rhombus::name = "Rhombus";
		if (sideA != sideC && sideC != sideD && sideB != sideD)
		{
			throw Exception("One of sides not equal");
		}
		if (angleA != angleC && angleB != angleD)
		{
			throw Exception("Angle A not equal Angle C and Angle B not equal Angle D");
		}
		if ((sideA != sideC && sideC != sideD && sideB != sideD) && angleA != angleC && angleB != angleD)
		{
			throw Exception("One of sides not equal and Angle A not equal Angle C and Angle B not equal Angle D");
		}
	};