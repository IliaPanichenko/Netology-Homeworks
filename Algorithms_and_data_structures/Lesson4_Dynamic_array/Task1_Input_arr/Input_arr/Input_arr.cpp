#include <iostream>
void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    for (int i = 0; i < logical_size; i++)
    {
        std::cout << arr[i] << " ";

    }
    for (int i = logical_size; i < actual_size; i++)
    {
        std::cout << "_ ";
    }
}

int main()
{
    int actual_size = 0;
    int logical_size = 0;
    std::cout << "Input actual array size: ";
    std::cin >> actual_size;
    std::cout << "Input logical array size: ";
    std::cin >> logical_size;
    if (logical_size > actual_size)
    {
        std::cout << "Error! The logical size of the array cannot exceed the actual size!" << "\n";
    }
    else if (logical_size <= 0 || actual_size <= 0)
    {
        std::cout << "Error! The logical size or the actual size of the array cannot be less than 0!" << "\n";
    }
    else
    {
        int* arr = new int[actual_size];
        for (int i = 0; i < logical_size; i++)
        {
            std::cout << "arr[" << i << "]: ";
            std::cin >> arr[i];
        }
        std::cout << "Dynamic array: ";
        print_dynamic_array(arr, logical_size, actual_size);
        delete[] arr;
    }
    return 0;
}