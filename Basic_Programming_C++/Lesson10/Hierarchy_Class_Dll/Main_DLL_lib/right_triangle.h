#pragma once
#include "Triangle.h"
#include "Figure.h"

class right_triangle : public Triangle
{
public:
	MAINDLLLIB_API  bool Check() override;
	MAINDLLLIB_API  right_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC);
};
