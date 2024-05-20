#pragma once
#include "Air.h"

class FlightShip :Air
{
public:
	FlightShip()
	{
		this->speed = 5;
	}
	double RACING_DYNAMIC_LIBRARY_API FlightShip_result(int distance);
};