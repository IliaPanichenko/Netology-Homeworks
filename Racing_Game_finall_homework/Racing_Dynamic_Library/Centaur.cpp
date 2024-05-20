#include "Centaur.h"

double Centaur::Centaur_result(int distance)
{
	double time_of_route;
	double second_time_to_rest = 2;
	int count_of_rest = distance / time_to_rest;
	time_of_route = (second_time_to_rest * count_of_rest) + (static_cast<double>(distance) / static_cast<double>(speed));
	return time_of_route;
}