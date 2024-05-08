#pragma once
#include "Quadrangle.h"
#include "Figure.h"

class Rhombus:public Quadrangle
{
public:
	MAINDLLLIB_API bool Check() override;
	MAINDLLLIB_API Rhombus(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD);
};