#include <iostream>
#include <string>
#include <vector>

template <typename T >
void move_vectors(std::vector<T>& lhs, std::vector<T>& rhs)
{
    rhs.insert(rhs.end(), std::make_move_iterator(lhs.begin()), std::make_move_iterator(lhs.end()));
    lhs.clear();
    /*std::vector<T> tmp = std::move(lhs);
    lhs = std::move(rhs);
    rhs = std::move(tmp);*/
}
int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    std::cout << "First vector before moving: ";
    for (auto& vec : one)
    {
        std::cout << vec << " ";
    }
    std::cout << "\n";
    std::cout << "Second vector before moving: ";
    for (auto& vec : two)
    {
        std::cout << vec << " ";
    }
    std::cout << "\n";
    move_vectors(one,two);
    std::cout << "Second vector after moving: ";
    for (auto& vec : two)
    {
        std::cout << vec << " ";
    }
    std::cout << "\n";
    std::cout << "First vector after moving: ";
    for (auto& vec : one)
    {
        std::cout << vec << " ";
    }
    return 0;
}
