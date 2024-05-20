#pragma once
#include "Ground.h"
#include "Air.h"
class Car :Ground
{
public:
	Car()
	{
		this->speed = 100;
		this->time_to_rest = 500;
	}
	double RACING_DYNAMIC_LIBRARY_API Car_result(int distance);
};
