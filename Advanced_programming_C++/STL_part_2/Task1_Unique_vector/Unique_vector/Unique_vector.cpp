#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

void uniqueVector(std::vector<int>& vec)
{
 
    std::unordered_set<int> seen;
    std::vector<int> unique;
    for (const int& num : vec)
    {
        if (seen.find(num) == seen.end())
        {
            seen.insert(num);
            unique.push_back(num);
        }
    }
    std::sort(unique.begin(), unique.end());
    vec = std::move(unique);
}

int main()
{
	std::vector<int> vec;
    int values;
    std::cout << "[IN]: ";
    while (std::cin >> values)
    {
        vec.push_back(values);
        if (std::cin.peek() == '\n')
        {
            break;
        }
    }
    std::cout << "[OUT]: ";
    uniqueVector(vec);
    for (const int& num:vec)
    {
        std::cout << num << " ";
    }
	return 0;
}
