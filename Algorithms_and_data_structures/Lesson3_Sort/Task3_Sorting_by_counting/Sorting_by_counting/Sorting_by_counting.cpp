#include <iostream>
#include <iterator>
void count_sort(int* arr, int size)
{
    int* counts = new int[size]{};
    for (int i = 0; i < size; i++)
    {
        counts [arr[i]]++;
    }
    int c = 0; 
    for (int i = 0; i < size; i++)
    {
        while (counts[c] == 0)
        {
            c++;
        }
        arr[i] = c;
        counts[c] --;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    delete [] counts;
}
void print_arr(int* arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}
int main(int argc, char** argv)
{
    int arr1[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    int size1 = std::size(arr1);
    int arr2[] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
    int size2 = std::size(arr2);
    int arr3[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };
    int size3 = std::size(arr3);

    std::cout << "1) Origin array: ";
    print_arr(arr1, size1);
    std::cout << "\n";
    std::cout << "1) Sorted array: ";
    count_sort(arr1, size1);
    std::cout << "\n\n";

    std::cout << "2) Origin array: ";
    print_arr(arr2, size2);
    std::cout << "\n";
    std::cout << "2) Sorted array: ";
    count_sort(arr2, size2);
    std::cout << "\n\n";

    std::cout << "3) Origin array: ";
    print_arr(arr3, size3);
    std::cout << "\n";
    std::cout << "3) Sorted array: ";
    count_sort(arr3, size3);
    std::cout << "\n\n";
    return 0;
}
