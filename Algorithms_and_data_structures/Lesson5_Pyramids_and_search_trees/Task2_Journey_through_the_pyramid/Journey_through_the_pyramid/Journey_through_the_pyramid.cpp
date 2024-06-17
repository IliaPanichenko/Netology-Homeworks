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

void get_pyramid_position(int& index, int& level, std::string& child, std::string command, int size)
{
    if (command == "up")
    {
        if (index == 0)
        {
            std::cout << "\nError! There is no parent.";
            return;
        }
        index = (index - 1) / 2;
    }
    else if (command == "left")
    {
        if ((index * 2 + 1) >= size)
        {
            std::cout << "\nError! Left child missing.";
            return;
        }
        index = index * 2 + 1;
    }
    else if (command == "right")
    {
        if ((index * 2 + 2) >= size)
        {
            std::cout << "\nError! Right child missing.";
            return;
        }
        index = index * 2 + 2;
    }

    int sum = 0, z = 1;
    level = 0;
    while (sum < index)
    {
        level++;
        z *= 2;
        sum += z;
    }
    if (index % 2 == 0)
    {
        child = "left";
    }
    else
    {
        child = "right";
    }
}

void walking_pyramid(int* arr, int size)
{
    std::string command;
    bool exit = true;
    int index = 0, parent = 0;
    int level = 0;
    std::string child;
    std::cout << "\nYour are here: 0" << " root " << arr[index];
    while (exit)
    {
        std::cout << "\nChoose command: ";
        std::cin >> command;
        if (command == "up" || command == "left" || command == "right")
        {
            get_pyramid_position(index, level, child, command, size);
            if (index >= 0 && index < size)
            {
                parent = (index - 1) / 2;
                if (index == 0)
                {
                    std::cout << "\nOK.\nYour are here: 0" << " root " << arr[index];
                }
                else
                {
                    std::cout << "\nOK.\nYour are here: " << level << " " << child << "(" << arr[parent] << ") " << arr[index];
                }
            }
        }
        else if (command == "exit")
        {
            exit = false;
            std::cout << "\nOK, good bye.";
            return;
        }
        else
        {
            std::cout << "\ncommand not defined, please enter up, left, right, exit";
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
    //int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    //int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    print_origin_arr(arr1, std::size(arr1));
    std::cout << "Pyramid: " << "\n";
    print_pyramid(arr1, std::size(arr1));
    std::cout << "\n";
    walking_pyramid(arr1, std::size(arr1));
    //print_origin_arr(arr2, std::size(arr2));
    //std::cout << "Pyramid: " << "\n";
    //print_pyramid(arr2, std::size(arr2));
    //std::cout << "\n";
    //print_origin_arr(arr3, std::size(arr3));
    //std::cout << "Pyramid: " << "\n";
    //print_pyramid(arr3, std::size(arr3));
    return 0;
}

