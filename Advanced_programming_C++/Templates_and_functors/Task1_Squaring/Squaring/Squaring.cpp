#include <iostream>
#include <vector>


template <typename T>
T square(T value)
{
    return value * value;
}
template <typename T>
std::vector<T> square(std::vector<T>& vec)
{
    std::vector <T> result(vec.size());
    for (size_t i = 0; i < vec.size(); i++)
    {
        result[i] = vec[i] * vec[i];
    }
    return result;
}

int main()
{
    double num;
    std::cout << "[IN]: ";
    std::cin >> num;
    std::cout << "[OUT]: " << square(num) << "\n";

    std::vector<double> vec;
    double value;
    std::cout << "[IN]: ";
    while (std::cin >> value)
    {
        vec.push_back(value);
        if (std::cin.peek() == '\n')
        {
            break;
        }
    }
    std::vector<double> squaredVec = square(vec);
    std::cout << "[OUT]: ";
    for (size_t i = 0; i < squaredVec.size(); ++i)
    {
        std::cout << squaredVec[i] << " ";
    }
    std::cout << "\n";
    return 0;
}