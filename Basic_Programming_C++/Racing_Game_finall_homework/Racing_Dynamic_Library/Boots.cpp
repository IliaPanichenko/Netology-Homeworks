#include "Boots.h"

double Boots::Boots_result(int distance)
{
	double time_of_route;
	double first_time_to_rest = 10;
	double second_time_to_rest = 5;
	int count_of_rest = distance / time_to_rest;
	if (count_of_rest <= 1)
	{
		time_of_route = first_time_to_rest + (static_cast<double>(distance) / static_cast<double>(speed));
	}
	if (count_of_rest > 1 )
	{
		time_of_route = first_time_to_rest + (second_time_to_rest* (count_of_rest - 1)) + (static_cast<double>(distance) / static_cast<double>(speed));
	}
	return time_of_route;
}