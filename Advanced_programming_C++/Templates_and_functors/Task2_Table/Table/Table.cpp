#include <iostream>
template <class T>
class table
{
private:
    T** elements;
    int row;
    int col;
public:
    table(int row_count, int col_count) : row(row_count), col(col_count)
    {
        elements = new T* [row_count];
        for (int i = 0; i < row_count; i++)
        {
            elements[i] = new T[col_count];
        }
    }

    ~table()
    {
        for (int i = 0; i < row; i++)
        {
            delete[] elements[i];
        }
        delete[] elements;
    }
    
    const T* operator[](int row_index) const 
    {
        return elements[row_index];
    }
    
    T* operator[](int row_index) 
    {
        return elements[row_index];
    }

    int Size() const
    {
        return row * col; 
    }
};

int main()
{
    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0];
    int size = test.Size();
    std::cout << "\n";
    std::cout << "Size: " << size << "\n";
    return 0;
}
