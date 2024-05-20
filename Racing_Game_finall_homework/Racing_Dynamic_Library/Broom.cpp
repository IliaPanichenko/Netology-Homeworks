#include "Broom.h"

double Broom::Broom_result(int distance)
{
	int distance_reduction = distance / 1000;
	double distance_reduction_factor = static_cast<double>(distance_reduction) / 100;
	double time_of_route;
	if (distance >= 1000)
	{
		time_of_route = static_cast<double>(distance * (1 - distance_reduction_factor))/ static_cast<double>(speed);
	}
	else
	{
		time_of_route = static_cast<double>(distance) / static_cast<double>(speed);
	}
	return time_of_route;
}