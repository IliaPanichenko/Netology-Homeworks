#pragma once
#include "Quadrangle.h"

class Square:public Quadrangle
{
public:
	bool Check() override;
	MAINDLLLIB_API
	Square(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD);
};