#include <iostream>
#include <mutex>

class Data
{
public:
    std::mutex mutex;
    int value;
    Data(int val) : value(val) {};

    static void swap_lock  (Data& firstData, Data& secondData)
    {
        std::lock(firstData.mutex, secondData.mutex);
        std::lock_guard<std::mutex> lock1(firstData.mutex, std::adopt_lock);
        std::lock_guard<std::mutex> lock2(secondData.mutex, std::adopt_lock);
        std::swap(firstData.value, secondData.value);
    }
    static void swap_scoped_lock(Data& firstData, Data& secondData)
    {
        std::scoped_lock(firstData.mutex, secondData.mutex);
        std::swap(firstData.value, secondData.value);

    }
    static void swap_unique_lock(Data& firstData, Data & secondData)
    {
        std::unique_lock<std::mutex> lock1 (firstData.mutex, std::defer_lock);
        std::unique_lock<std::mutex> lock2(secondData.mutex, std::defer_lock);
        std::lock(lock1, lock2);
        std::swap(firstData.value, secondData.value);

    }
};
int main()
{
    Data D1(10);
    Data D2(20);
    Data D3(30);
    Data::swap_lock (D1, D2);
    std::cout << "After swap_lock: D1 = " << D1.value << ", D2 = " << D2.value << "\n";
    Data::swap_scoped_lock(D2, D3);
    std::cout << "After swap_scoped_lock: D2 = " << D2.value << ", D3 = " << D3.value << "\n";
    Data::swap_unique_lock(D3, D1);
    std::cout << "After swap_unique_lock: D3 = " << D3.value << ", D1 = " << D1.value << "\n";
    return 0;
}