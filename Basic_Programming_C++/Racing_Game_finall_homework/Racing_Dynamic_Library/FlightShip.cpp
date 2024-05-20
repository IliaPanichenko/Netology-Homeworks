#include "FlightShip.h"

double FlightShip::FlightShip_result(int distance)
{
	double distance_reduction_factor = 0.1;
	double time_of_route;
	time_of_route = (static_cast<double>(distance) - (static_cast<double>(distance) * distance_reduction_factor)) / static_cast<double>(speed);
	return time_of_route;
}