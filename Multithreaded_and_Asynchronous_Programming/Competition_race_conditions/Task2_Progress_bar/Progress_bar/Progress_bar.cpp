#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <iomanip>

#include <windows.h>

class consol_parameter {
public:
    static void SetColor(int text, int background) {
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }

    static void SetPosition(int x, int y) {
        COORD point;
        point.X = x;
        point.Y = y;
        SetConsoleCursorPosition(hStdOut, point);
    }

private:
    static HANDLE hStdOut;
};

HANDLE consol_parameter::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);


std::mutex console_mutex;
void calculate(int thread_num, int calc_length)
{
	auto start_time = std::chrono::steady_clock::now();
	std::thread::id thread_id = std::this_thread::get_id();
	int progress_bar = 50;
	for (int i = 0; i < progress_bar; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(calc_length / progress_bar));
		{
			std::lock_guard<std::mutex> lock(console_mutex);
            consol_parameter::SetPosition(0, thread_num + 2);
			std::cout  << std::setw(2) << thread_num << "  " << std::setw(5) << thread_id << "  [";

			for (int j = 0; j <= i; j++) {
				std::cout << char(219);
			}
			for (int j = i + 1; j < progress_bar; j++) {
				std::cout << " "; 
			}
			std::cout << "]" << std::flush;
		}
	}
	auto end_time = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end_time - start_time;
	std::lock_guard<std::mutex> lock(console_mutex);
	std::cout << " " << std::fixed << std::setprecision(5) << elapsed_seconds.count() << "s\n";
}
int main()
{
	int thread_num = std::thread::hardware_concurrency();
	int calc_length = 2000;
	std::vector<std::thread> threads;
	std::cout << "#   id                    Progress Bar                            Time\n";
	std::cout << "----------------------------------------------------------------\n";
	for (int i = 0; i < thread_num; ++i) 
	{
		threads.emplace_back(calculate, i, calc_length);
	}
	for (auto& thread : threads) 
	{
		thread.join();
	}
	consol_parameter::SetPosition(0, thread_num + 1);
	return 0;
}
