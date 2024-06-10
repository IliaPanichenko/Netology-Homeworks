#include <iostream>
#include <string>

int* remove_dynamic_array_head(int* arr, int* logical_size, int* actual_size)
{
    if (*logical_size - 1 <= *actual_size / 3)
    {
        for (int i = 0; i < (*logical_size - 1); i++)
        {
            arr[i] = arr[i + 1];
        }
        *logical_size -= 1;
        return arr;
    }
    else if (*logical_size == 0) 
    {
        return arr;
    }
    else
    {
        int* arr_next = new int[*actual_size /= 3];
        for (int i = 0; i < *logical_size; i++)
        {
            arr_next[i] = arr[i];
        };
        *logical_size -= 1;
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
        std::string answer;
        do
        {
            std::cout << "\n";
            std::cout << "Remove first element?: ";
            std::cin >> answer;
            if (answer == "yes" && logical_size > 0)
            {
                *cache = remove_dynamic_array_head(arr, &logical_size, &actual_size);
                std::cout << "Dynamic array: ";
                print_dynamic_array(*cache, logical_size, actual_size);
            }
        } while (answer != "no" && logical_size != 0);
        if (answer == "no")
        {
            std::cout << "Thank you. Finall array: ";
            print_dynamic_array(*cache, logical_size, actual_size);
        }
        else if (logical_size == 0)
        {
            std::cout << "The first element cannot be removed because the array is empty.Goodbye!";
        }
        delete[] arr;
    }
    return 0;
}