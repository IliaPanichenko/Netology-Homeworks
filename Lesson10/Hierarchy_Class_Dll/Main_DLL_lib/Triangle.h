#pragma once
#include "Figure.h"

#ifdef MAINDLLLIBDYNAMIC_EXPORTS
#define MAINDLLLIB_API __declspec(dllexport)
#else
#define MAINDLLLIB_API __declspec(dllimport)
#endif
class Triangle : public Figure
{
protected:
	int sideA = 0;
	int sideB = 0;
	int sideC = 0;
	int angleA = 0;
	int angleB = 0;
	int angleC = 0;
	bool Check() override;
	
public:MAINDLLLIB_API
	Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC);
	void  print_metod() override;
};