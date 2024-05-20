#pragma once
#include "Air.h"

class Broom : Air {
public:
	Broom()
	{
		this->speed = 20;
	}
	double RACING_DYNAMIC_LIBRARY_API Broom_result(int distance);
};
