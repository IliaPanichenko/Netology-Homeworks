#pragma once
#include "Ground.h"
#include "Air.h"

class Camel:Ground
{
public:
	Camel()
	{
		this->speed = 10;
		this->time_to_rest = 30;
	}
	double RACING_DYNAMIC_LIBRARY_API Camel_result(int distance);
};