#include <iostream>
#include <vector>

std::vector<long long> fibonacci_cache;

long long Fiba(long long Value)
{
	if (Value == 0)
	{
		return 0;
	};
	if (Value == 1)
	{
		return 1;
	}
	if (Value < fibonacci_cache.size() && fibonacci_cache[Value] != 0)
	{
		return fibonacci_cache[Value];
	}
	long long result = Fiba(Value - 1) + Fiba(Value - 2);

	fibonacci_cache.resize(Value + 1);
	fibonacci_cache[Value] = result;
	return result;
}

int main(int argc, char** argv)
{
	int Value;
	std::cout << "Enter Fibonacci number: ";
	std::cin >> Value;
	if (Value < 0)
	{
		std::cout << "Wrong value!";
		return 0;
	}
	std::cout << "Fibonacci sequency: ";
	for (int i = 0; i <= Value; i++)
	{
		std::cout << Fiba(i) << " ";
	}
	return 0;
}