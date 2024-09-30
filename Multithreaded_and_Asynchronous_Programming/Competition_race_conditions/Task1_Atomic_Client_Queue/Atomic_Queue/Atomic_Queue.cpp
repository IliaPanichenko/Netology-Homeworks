#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

class QueueSimulator {
public:
    std::atomic<int> max_clients;
    std::atomic<int> clients_count;
    std::atomic<bool> all_clients_done;
    QueueSimulator(int max_clients) :max_clients(max_clients), clients_count(0), all_clients_done(false) {};
    void addClient()
    {
        while (clients_count.load(std::memory_order_relaxed) < max_clients.load(std::memory_order_relaxed))
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (clients_count.load(std::memory_order_relaxed) < max_clients.load(std::memory_order_relaxed))
            {
                clients_count.fetch_add(1, std::memory_order_acq_rel);
                std::cout << "First thread" << "\n" << "Client added.Quantity: " << clients_count.load(std::memory_order_relaxed) << "\n";
            }
        }
    }
    void Queue()
    {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            if (clients_count.load(std::memory_order_relaxed) > 0)
            {

                clients_count.fetch_add(-1, std::memory_order_acq_rel);
                std::cout << "Second thread" << "\n" << "Client done. Quantity: " << clients_count.load(std::memory_order_relaxed) << '\n';
            }
            else
            {
                all_clients_done.store(true, std::memory_order_release) ;
                break;
            }
        }

    }
    void Run()
    {
        std::thread client(&QueueSimulator::addClient, this);
        std::thread queue(&QueueSimulator::Queue, this);
        client.join();
        all_clients_done.store(false, std::memory_order_release);
        queue.join();
        std::cout << "All clients are done";
    }
};


int main() {
    int max_clients;
    std::cout << "Input quantity of clients: ";
    std::cin >> max_clients;
    QueueSimulator queue(max_clients);
    queue.Run();
    return 0;
}