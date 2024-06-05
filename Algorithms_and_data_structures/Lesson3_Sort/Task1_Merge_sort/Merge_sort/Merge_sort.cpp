#include <iostream>
#include <iterator>

void merge_sort(int* arr, int size)
{
    int middle_size = size / 2;
    for (int i = 0; i < middle_size - 1; i++)
    {
        for (int j = 0; j < middle_size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int cache = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = cache ;
            }
        }
    }

    for (int i = middle_size; i < size - 1; i++)
    {
        for (int j = middle_size; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int cache = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = cache;
            }
        }
    }

    int ia = 0; // Индекс для массива A
    int ib = middle_size; // Индекс для массива B
    int ic = 0; // Индекс для массива C
    int* ArrC = new int [size];

    while (ia < middle_size && ib < size)
    {
        if (arr[ia] == middle_size)
        {
            ArrC[ic] = arr[ib];
            ib++;
        }
        else if (arr[ib] == size)
        {
            ArrC[ic] = arr[ia];
            ia++;
        }
        else
        {
            if (arr[ia] < arr[ib])
            {
                ArrC[ic] = arr[ia];
                ia++;
            }
            else
            {
                ArrC[ic] = arr[ib];
                ib++;
            }
        }
        ic++;
       
    }
    while (ia < middle_size) 
    {
        ArrC[ic] = arr[ia];
        ia++;
        ic++;
    }

    while (ib < size) 
    {
        ArrC[ic] = arr[ib];
        ib++;
        ic++;
    }

    for (int i = 0; i < size ; i++)
    {
        std::cout << ArrC[i] << "\t";
    }
    delete[]ArrC;
}
void Orig_arr_print(int* arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << "\t";
    }
}

int main(int argc, char** argv)
{
    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int size1 = std::size(arr1);
    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int size2 = std::size(arr2);
    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size3 = std::size(arr3);

    std::cout << "1) Original array:\t";
    Orig_arr_print(arr1, size1);
    std::cout << "\n";
    std::cout << "Sorted array:\t";
    merge_sort(arr1, size1);
    std::cout << "\n\n";

    std::cout << "2) Original array:\t";
    Orig_arr_print(arr2, size2);
    std::cout << "\n";
    std::cout << "Sorted array:\t";
    merge_sort(arr2, size2);
    std::cout << "\n\n";

    std::cout << "3) Original array:\t";
    Orig_arr_print(arr3, size3);
    std::cout << "\n";
    std::cout << "Sorted array:\t";
    merge_sort(arr3, size3);
    std::cout << "\n\n";
    return 0;
}