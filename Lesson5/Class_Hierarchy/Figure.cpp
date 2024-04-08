#include "Figure.h"
#include <iostream>

	//virtual 
		bool Figure::Check()
	{
		if (number_sides == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	std::string Figure::get_name()
	{
		return name;
	}
	//virtual 
		void Figure::print_metod()
	{
		std::cout << name << ": \n";
		if (Check() == true)
		{
			std::cout << "True \n";
		}
		else
		{
			std::cout << "False \n";
		}
		std::cout << "Numbers of sides: " << number_sides << "\n";
	}
	void Figure::print_enter()
	{
		std::cout << "\n";
	}
