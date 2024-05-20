#include "Figure.h"
#include <iostream>
 
	std::string Figure::get_name()
	{
		return name;
	}
		void Figure::print_metod()
	{
		std::cout << "\n";
		std::cout << name << ": \n";
	}

