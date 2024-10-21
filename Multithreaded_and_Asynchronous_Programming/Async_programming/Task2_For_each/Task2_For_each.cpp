#include <iostream>
#include <vector>
#include <future>
#include <algorithm>

template<typename Iterator, typename Func>
void parallelFor_each(Iterator begin, Iterator end, Func func)
{
    int distance = std::distance(begin, end);
    if (distance <= 1)
    {
        if (begin != end)
        {
            func(*begin);
        }
        return;
    }
    Iterator mid = std::next(begin, distance / 2);
    auto future = std::async(std::launch::async, parallelFor_each<Iterator, Func>, begin, mid, func);
    parallelFor_each(mid, end, func);
    future.get();
}

int main()
{
    std::vector<int> vec(10, 1);
    auto increment = [](int& x) {x += 1; };
    parallelFor_each(vec.begin(), vec.end(), increment);
    std::cout << "After increment: ";
    for (const auto elem : vec)
    {
        std::cout << elem << " ";
    }
    return 0;
}