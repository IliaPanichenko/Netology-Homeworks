#pragma once
#include "Figure.h"

 class Triangle : public Figure
{
protected:
	int sideA = 0;
	int sideB = 0;
	int sideC = 0;
	int angleA = 0;
	int angleB = 0;
	int angleC = 0;
	MAINDLLLIB_API bool Check() override;
	
public:
	MAINDLLLIB_API Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC);
	MAINDLLLIB_API void  print_metod() override;
};