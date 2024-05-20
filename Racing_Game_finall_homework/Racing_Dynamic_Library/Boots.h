#pragma once
#include "Ground.h"
#include "Air.h"

class Boots:Ground
{
public:
	Boots()
	{
		this->speed = 6;
		this->time_to_rest = 60;
	}
	double RACING_DYNAMIC_LIBRARY_API Boots_result(int distance);
};