#include "Rectangle.h"
	void Rectangle::Check()
	{
		if (sideA != sideC && sideB != sideD)
		{
			throw Exception("Side A not equal Side C or Side B not equal Side D");
		}
		if (angleA != 90 && angleB != 90 && angleC != 90 && angleD != 90)
		{
			throw Exception("No one of angles not equal 90");
		}
		if (sideA != sideC && sideB != sideD && (angleA != 90 && angleB != 90 && angleC != 90 && angleD != 90))
		{
			throw Exception("Side A not equal Side C or Side B not equal Side D and no one of angles not equal 90");
		}
	};
	Rectangle::Rectangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : Quadrangle(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
	{
		Quadrangle::name = "Rectangle";
	};
