#include <iostream>

template<typename T>
class Vector_Trial
{
private:
    T* vector;
    int vec_size;
    int vec_capacity;
public:
    Vector_Trial() : vector(nullptr), vec_size(0), vec_capacity(0) {};
    Vector_Trial(int initialCapacity) : vec_capacity(initialCapacity), vec_size(0)
    {
        vector = new T[vec_capacity];
    }
    ~Vector_Trial()
    {
        delete[] vector;
    }
    T& at(int index)
    {
        if (index < 0 || index >= vec_size)
        {
            throw std::out_of_range("Index out of range");
        }
        return vector[index];
    }
    void resize(int newCapacity)
    {
        T* newVector = new T[newCapacity];
        for (int i = 0; i < vec_size; i++)
        {
            newVector[i] = vector[i];
        }
        delete[] vector;
        vector = newVector;
        vec_capacity = newCapacity;
    }
    void push_back(const T& value)
    {
        if (vec_size == vec_capacity)
        {
            resize(vec_capacity * 2 + 1);
        }
        vector[vec_size] = value;
        vec_size++;
    }
    int size() const
    {
        return vec_size;
    }
    int capacity() const
    {
        return vec_capacity;
    }
};

int main()
{
    Vector_Trial<int> vec(5);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    std::cout << "Size: " << vec.size() << "\n";
    std::cout << "Capacity: " << vec.capacity() << "\n";
    std::cout << "Element at index 2: " << vec.at(2) << "\n";
    //std::cout << "Element at index 2: " << vec.at(5) << "\n";
    //std::cout << "Element at index 2: " << vec.at(-1) << "\n";
    vec.push_back(4);
    std::cout << "Element at index 3: " << vec.at(3) << "\n";
    vec.push_back(5);
    std::cout << "Size: " << vec.size() << "\n";
    std::cout << "Capacity: " << vec.capacity() << "\n";
    vec.push_back(5);
    std::cout << "Size: " << vec.size() << "\n";
    std::cout << "Capacity: " << vec.capacity() << "\n";
    return 0;
}