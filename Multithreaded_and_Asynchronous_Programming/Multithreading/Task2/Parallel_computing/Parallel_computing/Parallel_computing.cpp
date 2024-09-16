#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <functional>
#include <iomanip>
#include <cmath>
#include <random>

class VectorAdder {
private:
    std::vector<int> firstVec;
    std::vector<int> secondVec;
    std::vector<int> result;
    void sumVectorpartial(int start, int end) {
        for (int i = start; i < end; i++) {
            result[i] = firstVec[i] + secondVec[i];
        }
    }
public:
    VectorAdder(const std::vector<int>& firstVec, const std::vector<int>& secondVec):firstVec(firstVec), secondVec(secondVec), result(firstVec.size(), 0) {};
    void parallelSum(int threadQtt)
    {
        std::vector<std::thread> threads;
        int size = firstVec.size();
        int partSize = std::ceil(static_cast<double> (size) / threadQtt);
        for (int i = 0; i < threadQtt; i++)
        {
            int start = i * partSize;
            int end = std::min(partSize + start, size);
            threads.push_back(std::thread(&VectorAdder::sumVectorpartial,this, start, end));
            for (auto& t : threads)
            {
                if (t.joinable())
                {
                    t.join();
                }
            }
            
        }
    }
    double measureTime(int threadQtt)
    {
        auto start = std::chrono::steady_clock::now();
        parallelSum(threadQtt);
        auto end = std::chrono::steady_clock::now();
        double duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        return duration;
    }
    static void displayResults(const std::vector<int>& sizes, const std::vector<int>& thread_counts)
    {
        std::cout << "Quantity of threas: " << std::thread::hardware_concurrency() << "\n";
        std::cout << std::setw(12) << "Threads";
        for (int size : sizes)
            std::cout << std::setw(12) << size;
        std::cout << "\n\n";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, 99);

        for (int threadQtt : thread_counts)
        {
            std::cout << std::setw(12) << threadQtt;

            for (int size : sizes)
            {
                std::vector<int> firstVec(size);
                std::vector<int> secondVec(size);

                for (int& elem : firstVec) elem = dist(gen);
                for (int& elem : secondVec) elem = dist(gen);

                VectorAdder adder(firstVec, secondVec);
                double duration = adder.measureTime(threadQtt);
                std::cout << std::setw(12) << duration;
            }
            std::cout << "\n";
        }
    }
};


int main() {
    std::vector<int> sizes = { 1000, 10000, 100000, 1000000 };
    std::vector<int> thread_counts = { 1, 2, 4, 8, 16 };
    VectorAdder::displayResults(sizes, thread_counts);

    return 0;
}
