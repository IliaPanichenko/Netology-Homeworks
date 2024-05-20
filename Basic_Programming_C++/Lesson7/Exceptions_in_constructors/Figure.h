#pragma once
#include <string>
#include "Exception.h"
class Figure
{
protected:
	std::string name = "Figure";
	bool check = false;
public:
	std::string get_name();
	virtual void print_metod();
};
