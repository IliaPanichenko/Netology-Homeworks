#include <iostream>
#include <vector>
#include <algorithm>

class simple_functor
{
private:
    int sum;
    int count;
public:
    simple_functor() : sum(0), count(0) {}
    void operator() (int number)
    {
        if (number % 3 == 0)
        {
            count++;
        }
        sum += number;

    }
    int get_sum() const
    {
        return sum;
    }
    int get_count() const
    {
        return count;
    }
};


int main()
{
    std::vector<int> numbers;
    int values;
    std::cout << "[IN]: ";
    while (std::cin >> values)
    {
        numbers.push_back(values);
        if (std::cin.peek() == '\n')
        {
            break;
        }
    }
    simple_functor sf;
    for (int number : numbers) 
    {
        sf(number);
    }
    std::cout << "[OUT]: get_sum() =" << sf.get_sum() << "\n";
    std::cout << "[OUT]: get_count() =" << sf.get_count();
    return 0;
}