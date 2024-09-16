#include <iostream>
#include <thread>
#include <chrono>

class QueueSimulator {
public:
    int max_clients;
    int clients_count;
    bool all_clients_done;
    QueueSimulator(int max_clients):max_clients(max_clients), clients_count(0), all_clients_done(false) {};
    void addClient()
    {
        while (clients_count < max_clients)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (clients_count < max_clients)
            {
                clients_count++;
                std::cout << "First thread" << "\n" << "Client added.Quantity: " << clients_count << "\n";
            }
        }
    }
    void Queue()
    {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            if (clients_count > 0)
            {
                
                clients_count--;
                std::cout << "Second thread" << "\n" << "Client done. Quantity: " << clients_count << '\n';
            }
            else
            {
                all_clients_done = true;
                break;
            }
        }

    }
    void Run()
    {
        std::thread client(&QueueSimulator::addClient, this);
        std::thread queue(&QueueSimulator::Queue, this);
        client.join();
        all_clients_done = false;
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