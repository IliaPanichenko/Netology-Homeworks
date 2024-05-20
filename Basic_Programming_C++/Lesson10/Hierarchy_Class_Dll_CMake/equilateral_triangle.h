#pragma once
#include "Triangle.h"
class equilateral_triangle : public Triangle
{
public:
	bool Check() override;
	equilateral_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC);
};
