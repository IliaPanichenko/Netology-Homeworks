#include <iostream>
#include <vector>
#include <random>
#include <future>
#include <chrono>

int findMin(std::vector<int>& arr, int start, int end, std::promise<int> promise)
{
	int min_ind = start;
	for (int i = start + 1; i < end; i++)
	{
		if (arr[min_ind] > arr[i])
		{
			min_ind = i;
		}
	}
	promise.set_value(min_ind);
	return min_ind;
}

void sortArray(std::vector<int>& arr)
{
	for (int j = 0; j < arr.size() - 1; j++)
	{
		std::promise<int> promise;
		std::future<int> future = promise.get_future();
		std::async(std::launch::async, findMin, std::ref(arr), j, arr.size(), std::move(promise));
		int min_ind = future.get();
		if (j != min_ind) 
		{
		    std::swap(arr[j], arr[min_ind]);
        }
	}
}

void printArr(std::vector<int>& arr)
{
	for (int ellem : arr)
	{
		std::cout << ellem << " ";
	}
	std::cout << "\n";
}

void fillArr(std::vector<int> & arr, int min_value, int max_value)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min_value, max_value);
	for (int& elem : arr) {
		elem = dist(gen);
	}
}

int main() {
    int size;
        std::cout << "Input array size: ";
        std::cin >> size;
    std::vector<int> arr(size);
	fillArr(arr, 1, 100);
    std::cout << "Origin array: ";
	printArr(arr);
	sortArray(arr);
    std::cout << "Sorted array: ";
	printArr(arr);
    return 0;
}
