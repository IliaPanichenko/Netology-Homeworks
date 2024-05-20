#pragma once
#include "Triangle.h"
class right_triangle : public Triangle
{
public:
	bool Check() override;
	right_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC);
};
