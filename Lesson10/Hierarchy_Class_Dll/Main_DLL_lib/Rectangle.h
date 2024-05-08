#pragma once
#include "Quadrangle.h"
#include "Figure.h"

class Rectangle:public Quadrangle
{
public:
	MAINDLLLIB_API  bool Check() override;
	MAINDLLLIB_API  Rectangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD);
};
