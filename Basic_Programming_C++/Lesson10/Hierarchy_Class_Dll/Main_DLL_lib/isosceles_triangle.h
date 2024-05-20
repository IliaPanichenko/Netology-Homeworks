#pragma once
#include "Triangle.h"
#include "Figure.h"

class isosceles_triangle : public Triangle
{
public:
	MAINDLLLIB_API bool Check() override;
	MAINDLLLIB_API isosceles_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC);
};