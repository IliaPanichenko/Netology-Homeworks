#pragma once
#include "Air.h"

class Carpet:Air
{
public:
	Carpet()
	{
		this->speed = 10;
	}
	double RACING_DYNAMIC_LIBRARY_API Carpet_result(int distance);
};