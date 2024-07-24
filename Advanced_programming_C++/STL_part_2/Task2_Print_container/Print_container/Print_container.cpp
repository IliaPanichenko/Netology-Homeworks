#include <iostream>
#include <set>
#include <vector>
#include <list>

template<typename Container>
void print_container(const Container& container)
{
    if (container.empty())
    {
        std::cout << "Container is empty!\n";
        return;
    }
    std::cout << '{';
    for (auto i = container.begin(); i != std::prev(container.end()); i++)
    {
        std::cout << '"' << *i << '"' << ",";
    }
    std::cout << '"' << *std::prev(container.end());
    std::cout << '"' << '}';
    std::cout << '\n';
}
int main() 
{
    std::set<std::string> empty = {};
    std::cout << "Empty container: ";
    print_container(empty);
    std::set<std::string> test_set = { "one", "two", "three", "four", "seven", "six"};
    std::cout << "test_set: ";
    print_container(test_set); // four one three two. помните почему такой порядок? Выводит в лексическом порядке, а не в порядке ввода:)
    std::list<std::string> test_list = { "one", "two", "three", "four" };
    std::cout << "test_list: ";
    print_container(test_list); // one, two, three, four
    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    std::cout << "test_vector: ";
    print_container(test_vector); // one, two, three, four

    return 0;
}