#include <iostream>
#include <set>

int main()
{
	int quantity;
	std::cout << "[IN]: \n";
	std::cin >> quantity;
	std::set<int> numbers;
	for (auto i = 0; i < quantity; i++)
	{
		int number;
		std::cin >> number;
		numbers.insert(number);
	}
	std::cout << "[OUT]: \n";
	for (auto i = numbers.rbegin(); i != numbers.rend(); i++)
	{
		std::cout << *i << "\n";
	}
	return 0;
}