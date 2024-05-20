#pragma once
#include <string>
class Figure
{
protected:
	std::string name = "Figure";
	bool check = false;
	int number_sides = 0;
	virtual bool Check();
public:
	std::string get_name();
	virtual void print_metod();
	void print_enter();
};
