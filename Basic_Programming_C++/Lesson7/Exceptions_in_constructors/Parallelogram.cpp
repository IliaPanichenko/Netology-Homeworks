#include "Parallelogram.h"
	void Parallelogram::Check()
	{
		
	};
	Parallelogram::Parallelogram(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : Quadrangle(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
	{
		Parallelogram::name = "Parallelogram";
		if ((sideA != sideC || sideB != sideD)
			&& (angleA != angleC || angleB != angleD))
		{
			throw Exception("Side A not equal Side C and Side B not equal Side D or Angle A not equal Angle C and Angle B not equal Angle D");
		}

		if (sideA != sideC || sideB != sideD)
		{
			throw Exception("Side A not equal Side C and Side B not equal Side D ");
		}

		if (angleA != angleC || angleB != angleD)
		{
			throw Exception("Angle A not equal Angle C and Angle B not equal Angle D");
		}

	};