#pragma once
#include "Triangle.h"
//#ifdef MATHPOWERLIBRARYDYNAMIC_EXPORTS
//#define MATHPOWERLIBRARY_API __declspec(dllexport)
//#else
//#define MATHPOWERLIBRARY_API __declspec(dllimport)
//#endif
class right_triangle : public Triangle
{
public:
	bool Check() override;
	MAINDLLLIB_API
	right_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC);
};
