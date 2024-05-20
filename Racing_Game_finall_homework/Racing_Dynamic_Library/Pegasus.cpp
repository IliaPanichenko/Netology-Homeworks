#include "Pegasus.h"

double Pegasus::Pegasus_result(int distance)
{
	double distance_reduction_factor;
	double time_of_route;
	if (distance < 5000)
	{
		distance_reduction_factor = 0.05;
		time_of_route = (static_cast<double>(distance) - (static_cast<double>(distance) * distance_reduction_factor)) / static_cast<double>(speed);
	}
	
	else if (distance >= 5000)
	{
		distance_reduction_factor = 0.1;
		time_of_route = (static_cast<double>(distance) - (static_cast<double>(distance) * distance_reduction_factor)) / static_cast<double>(speed);
	}
	return time_of_route;
}