#include <iostream>
#define SUB(a,b) ((a)-(b))


int main(int argc, char** argv)
{
	int a = 6;
	int b = 5;
	int c = 2;
	std::cout << SUB(a, b) << "\n";
	std::cout << SUB(a, b) * c << "\n";
	std::cout << SUB(a, b + c) * c << "\n";
	return 0;
}