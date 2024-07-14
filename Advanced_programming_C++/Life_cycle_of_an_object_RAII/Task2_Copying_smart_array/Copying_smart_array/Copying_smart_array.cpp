#include <iostream>
#include <stdexcept>

class smart_array
{
private:
    int* arr;
    int curent_size;
    int size;
public:
    smart_array(int size)
    {
        curent_size = 0;
        this->size = size;
        arr = new int[size];
    }

    void add_element(int value)
    {
        if (size == curent_size)
        {
            int* arr_new = new int[curent_size + 1];
            for (int i = 0; i < curent_size; i++)
            {
                arr_new[i] = arr[i];
            }
            delete[] arr;
            arr = arr_new;
            size = curent_size + 1;
        }
        arr[curent_size] = value;
        //std::cout << arr[curent_size] << " ";
        curent_size++;

    }

    int get_element(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    smart_array& operator=(smart_array& other) 
    {
        if (this != &other) 
        {
            delete[] arr;
            size = other.size;
            curent_size = other.curent_size;
            arr = new int[size];
            for (int i = 0; i < curent_size; i++) 
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    smart_array(smart_array& other)
    {
        size = other.size;
        curent_size = other.curent_size;
        arr = new int[size];
        for (int i = 0; i < curent_size; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    void print_arr_debug(int number) 
    {
        std::cout << "Array" << number <<  ": ";
        for (int i = 0; i < curent_size; i++) 
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    ~smart_array()
    {
        delete[] arr;
    }
    
};

int main()
{
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(arr);
    new_array.add_element(44);
    new_array.add_element(34);

    new_array.print_arr_debug(1);

    smart_array new_array2(5);
    new_array2 = arr;
    new_array2.add_element(8);
    new_array2.print_arr_debug(2);
    return 0;
}