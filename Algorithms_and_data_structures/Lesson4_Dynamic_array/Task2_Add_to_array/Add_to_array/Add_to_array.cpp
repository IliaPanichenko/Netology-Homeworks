#include <iostream>

int* append_to_dynamic_array(int* arr, int* logical_size, int* actual_size, int* append)
{
    if (*logical_size < *actual_size)
    {
        *logical_size+=1;
        arr[*logical_size-1] = *append;
        return arr;
    }
    else
    {
        int* arr_next = new int[*actual_size *= 2];
        for (int i = 0; i < *logical_size; i++)
        {
            arr_next[i] = arr[i];
        };
        *logical_size += 1;
        arr_next[*logical_size - 1] = *append;
        delete[] arr;
        return arr_next;
    }
    
}
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
        std::cout << "Error! The logical size or the actual size of the array cannot be less or equal than 0!" << "\n";
    }
    else
    {
        int* arr = new int[actual_size];
        int** cache = &arr;
        for (int i = 0; i < logical_size; i++)
        {
            std::cout << "arr[" << i << "]: ";
            std::cin >> arr[i];
        }
        std::cout << "Dynamic array: ";
        print_dynamic_array(arr, logical_size, actual_size);
        int append = 0;
        do 
        {
            std::cout << "\n";
            std::cout << "Input item to add: ";
            std::cin >> append;
            if (append != 0)
            {
                *cache = append_to_dynamic_array(arr, &logical_size, &actual_size, &append);
                std::cout << "Dynamic array: ";
                print_dynamic_array(*cache, logical_size, actual_size);
            }
        } while (append != 0);
        std::cout << "Thank you. Finall array: ";
        print_dynamic_array(*cache, logical_size, actual_size);
        delete[] arr;
    }
    return 0;
}