#include <iostream>

int count_greater_elements(int* arr, int start_point, /*std::size_t size*/ int size)
{
	int counter = 0;
	int left = 0;
	int right = size - 1;
 	while (left <= right)
	{
		int middle = (right + left) / 2;
		if (arr[middle] > start_point)
		{
			counter += right - middle + 1;
			right = middle - 1;
		}
		else 
		{
			left = middle + 1;
		}
	}
	return counter;
}

int main(int argc, char** argv)
{
	int start_point;
	int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72, 100, 122, 130};
	//std::size_t size = std::size(arr);
	int size = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Input start point: ";
	std::cin >> start_point;
	int counter = count_greater_elements(arr, start_point, size);
	std::cout << "Number of elements greater than " << start_point << ": " << counter << "\n";
	return 0;
}