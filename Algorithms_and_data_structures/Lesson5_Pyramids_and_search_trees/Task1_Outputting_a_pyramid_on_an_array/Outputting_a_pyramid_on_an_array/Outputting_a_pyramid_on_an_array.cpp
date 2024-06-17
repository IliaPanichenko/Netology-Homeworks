#include <iostream>
#include <cmath>

void print_pyramid(int* arr, int size)
{
    int index = 0;
    std::string child;
    int parent = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < pow(2, i) && index < size; j++)
        {
            int level = i;
            if (j % 2 == 0)
            {
                child = "left";
                parent = (index - 1) / 2;
            }
            else
            {
                child = "right";
                parent = (index - 1) / 2;
            }
            if (i == 0)
            {
                std::cout << i << " root " << arr[index] << "\n";
            }
            else
            {
                std::cout << i << " " << child << "(" << arr[parent] << ") " << arr[index] << "\n";
            }
            index++;
        }
    }
}

void print_origin_arr(int* arr, int size)
{
    std::cout << "Origin array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main(int argc, char** argv)
{
    int level = 0; 
    int index = 0;
    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    print_origin_arr(arr1, std::size(arr1));
    std::cout << "Pyramid: " << "\n";
    print_pyramid(arr1, std::size(arr1));
    std::cout << "\n";
    print_origin_arr(arr2, std::size(arr2));
    std::cout << "Pyramid: " << "\n";
    print_pyramid(arr2, std::size(arr2));
    std::cout << "\n";
    print_origin_arr(arr3, std::size(arr3));
    std::cout << "Pyramid: " << "\n";
    print_pyramid(arr3, std::size(arr3));
    return 0;
}

