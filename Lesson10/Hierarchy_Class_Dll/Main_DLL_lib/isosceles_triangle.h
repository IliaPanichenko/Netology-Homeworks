#pragma once
#include "Triangle.h"

class isosceles_triangle : public Triangle
{
public:
	bool Check() override;
	MAINDLLLIB_API
	isosceles_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC);
};