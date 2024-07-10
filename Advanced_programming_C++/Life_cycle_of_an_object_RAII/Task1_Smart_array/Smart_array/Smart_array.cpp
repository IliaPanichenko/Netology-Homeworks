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
        curent_size=0;
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

    ~smart_array() 
    {
        delete[] arr;
    }
};

int main() 
{
    try 
    {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(-90);
        arr.add_element(156);
        arr.add_element(125);
        std::cout << arr.get_element(8) <<"\n";
    }
    catch (const std::out_of_range& ex) 
    {
        std::cerr << ex.what() << "\n";
    }
    return 0;
}
