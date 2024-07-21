#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

int main()
{
	std::string text;
	std::cout << "[IN]: ";
	std::getline(std::cin, text);
	std::map<char, int> frequency;
	for (char symbol : text)
	{
		frequency[symbol]++;
	}
	std::vector<std::pair<char, int>> frequencySort(frequency.begin(), frequency.end());
	std::sort(frequencySort.begin(), frequencySort.end(),
		[](const std::pair<char, int>& prev, const std::pair<char, int> post)
			{
				return prev.second > post.second;
			});
	std::cout << "[OUT]: \n";
	for (const auto& pair : frequencySort)
		{
		std::cout << pair.first << ": " << pair.second << "\n";
		}
	return 0;
}