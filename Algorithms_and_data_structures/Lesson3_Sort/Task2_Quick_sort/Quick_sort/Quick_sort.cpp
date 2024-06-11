#include <iostream>

void quick_sort(int* arr, int size)
{
    int left = 0;
    int right = size - 1;
    size_t pivot = arr[size/2];
    while (left <= right)
    {
        while (arr[left] < pivot)
        {
            left++;
        }
        while (arr[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
        std::swap(arr[left], arr[right]);
        left++;
        right--;
        }
    }
    if (size <= 1)
        {
            return;
        }
    if (right > 0)
    {
        quick_sort(arr, right + 1);
    }
    if (left < size)
    {
        quick_sort(&arr[left], size - left);
    }
}
void print_orig_arr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    
}
int main(int argc, char** argv)
{
    int arr1 [] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int size1 = std::size(arr1);
    int arr2[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int size2 = std::size(arr2);
    int arr3[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    int size3 = std::size(arr3);
    std::cout << "1) Origin array: ";
    print_orig_arr(arr1, size1);
    std::cout << "\n";
    std::cout << "1) Sorted array: ";
    quick_sort(arr1, size1);
    print_orig_arr(arr1, size1);
    std::cout << "\n\n";

    std::cout << "2) Origin array: ";
    print_orig_arr(arr2, size2);
    std::cout << "\n";
    std::cout << "2) Sorted array: ";
    quick_sort(arr2, size2);
    print_orig_arr(arr2, size2);
    std::cout << "\n\n";

    std::cout << "3) Origin array: ";
    print_orig_arr(arr3, size3);
    std::cout << "\n";
    std::cout << "3) Sorted array: ";
    quick_sort(arr3, size3);
    print_orig_arr(arr3, size3);
    std::cout << "\n\n";

    return 0;
}






//#include <iostream>
//void print_orig_arr(int* arr, int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        std::cout << arr[i] << " ";
//    }
//}
//
//void quick_sort(int* arr, int size)
//{
//    int left = 0;
//    int right = size - 1;
//    size_t pivot = arr[size / 2];
//
//    while (left <= right)
//    {
//        std::cout << "    left: " << left << ", right: " << right << ", pivot: " << pivot << "\n";
//
//        while (arr[left] < pivot)
//        {
//            std::cout << "      arr[left] (" << arr[left] << ") < pivot (" << pivot << "), increasing left" << "\n";
//            left++;
//        }
//        while (arr[right] > pivot)
//        {
//            std::cout << "      arr[right] (" << arr[right] << ") > pivot (" << pivot << "), decreasing right" << "\n";
//            right--;
//        }
//
//        if (left <= right)
//        {
//            std::cout << "      Swapping arr[left] (" << arr[left] << ") and arr[right] (" << arr[right] << ")" << "\n";
//            std::swap(arr[left], arr[right]);
//            left++;
//            right--;
//            std::cout << "      left: " << left << ", right: " << right << "\n";
//        }
//    }
//
//    if (size <= 1)
//    {
//        return;
//    }
//
//    std::cout << "    Sorting left part: ";
//    print_orig_arr(arr, right + 1);
//    std::cout << std::endl;
//    if (right > 0)
//    {
//        quick_sort(arr, right + 1);
//    }
//
//    std::cout << "    Sorting right part: ";
//    print_orig_arr(&arr[left], size - left);
//    std::cout << std::endl;
//    if (left < size)
//    {
//        quick_sort(&arr[left], size - left);
//    }
//}
// 
//int main(int argc, char** argv)
//{
//    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
//    int size1 = std::size(arr1);
//    std::cout << "1) Origin array: ";
//    print_orig_arr(arr1, size1);
//    std::cout << "\n";
//    std::cout << "1) Sorted array: ";
//    quick_sort(arr1, size1);
//    print_orig_arr(arr1, size1);
//    std::cout << "\n\n";
//
//    return 0;
//}