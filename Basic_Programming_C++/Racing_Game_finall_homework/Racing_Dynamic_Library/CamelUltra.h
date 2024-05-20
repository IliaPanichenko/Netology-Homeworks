#pragma once
#include "Ground.h"
#include "Air.h"

class CamelUltra :Ground
{
public:
	CamelUltra()
	{
		this->speed = 40;
		this->time_to_rest = 10;
	}
	double RACING_DYNAMIC_LIBRARY_API CamelUltra_result(int distance);
};