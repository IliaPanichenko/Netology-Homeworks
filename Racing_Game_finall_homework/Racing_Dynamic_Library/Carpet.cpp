#include "Carpet.h"

double Carpet::Carpet_result(int distance)
{
	double distance_reduction_factor;
	double time_of_route;
	if (distance >= 1000 && distance < 5000)
	{
		distance_reduction_factor = 0.03;
		time_of_route = (static_cast<double>(distance) - (static_cast<double>(distance) * distance_reduction_factor))/ static_cast<double>(speed);
	}
	else if (distance >= 5000 && distance < 10000)
	{
		distance_reduction_factor = 0.1;
		time_of_route = (static_cast<double>(distance) - (static_cast<double>(distance) * distance_reduction_factor)) / static_cast<double>(speed);
	}
	else if (distance < 1000)
	{
		time_of_route = static_cast<double>(distance / static_cast<double>(speed));
	}
	else if (distance >= 10000)
	{
		distance_reduction_factor = 0.1;
		time_of_route = (static_cast<double>(distance) - (static_cast<double>(distance) * distance_reduction_factor)) / static_cast<double>(speed);
	}
	return time_of_route;
}