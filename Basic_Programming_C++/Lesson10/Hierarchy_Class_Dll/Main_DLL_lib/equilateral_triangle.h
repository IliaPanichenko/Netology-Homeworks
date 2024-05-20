#pragma once
#include "Triangle.h"
#include "Figure.h"

 class equilateral_triangle : public Triangle
{
public:
	MAINDLLLIB_API bool Check() override;
	MAINDLLLIB_API equilateral_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC);
};
