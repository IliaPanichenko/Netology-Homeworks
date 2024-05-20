#pragma once
#include "Air.h"

class Pegasus:Air
{
public:
	Pegasus()
	{
		this->speed = 25;
	}
	double RACING_DYNAMIC_LIBRARY_API Pegasus_result(int distance);
};