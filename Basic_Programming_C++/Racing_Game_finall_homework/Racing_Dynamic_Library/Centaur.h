#pragma once
#include "Ground.h"
#include "Air.h"
class Centaur :Ground
{
public:
	Centaur()
	{
		this->speed = 15;
		this->time_to_rest = 8;
	}
	double RACING_DYNAMIC_LIBRARY_API Centaur_result(int distance);
};