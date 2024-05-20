#pragma once
#include "Air.h"

class Eagle :Air
{
public:
	Eagle()
	{
		this->speed = 8;
	}
	double RACING_DYNAMIC_LIBRARY_API Eagle_result(int distance);
};
