#include <iostream>
#include "Air.h"
#include "Broom.h"
#include "Carpet.h"
#include "Eagle.h"
#include "FlightShip.h"
#include "Pegasus.h"
#include "Boots.h"
#include "Camel.h"
#include "CamelUltra.h"
#include "Centaur.h"
#include "Car.h"

int main(int argc, char** argv)
{
	std::cout << "Welcome to racing simulator!\n";
    while (true) 
    {
        int racing_type;
        int distance;
        int transport_counter = 1;
        int action;
        int second_action;
        int transport;
        int sum = 0;
        int out_of_range;
        int const quantity_of_airtype_transports = 5;
        int const quantity_of_groundtype_transports = 5;
        int const quantity_of_transports = quantity_of_airtype_transports + quantity_of_groundtype_transports;
        
        std::string arr_race_type[4] = 
        {
            "null",
            "\nRacing for ground type transports",
            "\nRacing for air type transport",
            "\nRacing for air and ground type transport",
        };
        
        int mass[quantity_of_transports+1] = {};
        double mas_time[quantity_of_transports+1] = {};
        std::string transport_container[quantity_of_transports+1] = {};
        std::string transport_unit[quantity_of_transports+1] =
        {
            "break",
            "Broom \"Nimbus2000\"",
            "Flying carpet" ,
            "Eagle \"Buckbeak\"",
            "FlightShip\"Noah\"",
            "Pegasus \"Herion\"",
            "Allroad boots",
            "Camel \"Vasya\"",
            "CamelUltra \"Vasilevs\"",
            "Centaur \"Firenze\"",
            "Car \"Lighting McQueen\""
        };

        do 
        {
            std::cout << "\n1.Racing for ground type transports\n";
            std::cout << "2.Racing for air type transport\n";
            std::cout << "3.Racing for air and ground type transport\n";
            std::cout << "Choose type of racing: ";
            std::cin >> racing_type;
            if (racing_type <= 0 || racing_type > 3)
            {
                std::cout << "\nWrong value!\n";
            }
        }
        while (racing_type <= 0 || racing_type > 3);
        
        do 
        {
            std::cout << "Input distance of road (must be positive): ";
            std::cin >> distance;
            if (distance <= 0)
            {
                std::cout << "\nWrong value!\n\n";
            }
        }
        while (distance <= 0);

        do 
        {
            do 
            {

                std::cout << "\n1.Registrate transport.\n";
                std::cout << "2.Start the racing.\n";
                std::cout << "Choose an action: ";             
                std::cin >> action;
                if (action <= 0 || action > 2)
                {
                    std::cout << "\nWrong value!\n";
                }
                if (transport_counter < 2 && action == 2) 
                {
                    std::cout << "\nMust be rigistered minimum 2 transports!\n";
                    action++;
                }
            }
            while (action < 1 || action > 2);
            if (action == 1)
            {
                do 
                {
                    std::cout << arr_race_type[racing_type] << ". Distance: " << distance << "\n";
                    if (transport_counter == 1) 
                    { 
                        std::cout << "Transport not registrated.\n"; 
                    }

                    else 
                    {
                        std::cout << "Registrated: ";
                        for (int i = 1; i < transport_counter; ++i) {
                            std::cout << transport_container[i] << ", ";
                        }
                        std::cout << "\n";
                    }
                    std::cout << "\n 1. " << transport_unit[1] <<
                        "\n 2. " << transport_unit[2] <<
                        "\n 3. " << transport_unit[3] <<
                        "\n 4. " << transport_unit[4] <<
                        "\n 5. " << transport_unit[5] <<
                        "\n 6. " << transport_unit[6] <<
                        "\n 7. " << transport_unit[7] <<
                        "\n 8. " << transport_unit[8] <<
                        "\n 9. " << transport_unit[9] <<
                        "\n 10. " << transport_unit[10] <<
                        "\n 0. End registration" <<
                        "\n Choose transport or input 0 for end of registration: ";

                    std::cin >> transport;
                    out_of_range = transport + 1;
                    if (transport == 0) 
                    {
                        break;
                    }
                    if (transport > quantity_of_transports || transport < 0)
                    {
                        std::cout << "\nWrong value!\n";
                        continue;
                    }

                    if (racing_type == 1)
                    {
                        if (transport > quantity_of_groundtype_transports && transport < quantity_of_transports + 1)
                        {
                            for (int i = 0; i < quantity_of_groundtype_transports + 1; ++i)
                            {
                                if (transport_container[i] == transport_unit[transport]) 
                                {
                                    std::cout << "\nTransport already registered\n";
                                    transport = out_of_range;
                                    break;
                                }
                            }

                            if (transport != out_of_range)
                            {
                                mass[transport_counter] = transport;
                                transport_container[transport_counter] = transport_unit[transport];
                                ++transport_counter;
                            }
                        }
                        else 
                        {
                            std::cout << "\nChoos another transport type\n";
                            continue;
                        }
                    }


                    if (racing_type == 2) 
                    {
                        if (transport > 0 && transport < quantity_of_airtype_transports+1)
                        {
                            for (int i = 0; i < quantity_of_airtype_transports + 1; ++i)
                            {
                                if (transport_container[i] == transport_unit[transport]) 
                                {
                                    std::cout << "\nTransport already registered\n";
                                    transport = out_of_range;
                                    break;
                                }
                            }

                            if (transport != out_of_range)
                            {
                                mass[transport_counter] = transport;
                                transport_container[transport_counter] = transport_unit[transport];
                                ++transport_counter;
                            }
                        }

                        else 
                        {
                            std::cout << "\nWrong transport type!\n";
                            continue;
                        }
                    }

                    else 
                    {
                        for (int i = 0; i < quantity_of_transports + 1; ++i)
                        {
                            if (transport_container[i] == transport_unit[transport]) 
                            {
                                std::cout << "\nTransport already registered\n";
                                transport = out_of_range;
                                continue;
                            }
                        }

                        if (transport != out_of_range)
                        {
                            mass[transport_counter] = transport;
                            transport_container[transport_counter] = transport_unit[transport];
                            ++transport_counter;
                        }
                    }
                } while (transport != 0);
            }
        } while (action == 1);

        for (int i = 1; i < quantity_of_transports + 1; ++i)
        {
            if (mass[i] == 1) 
            {
                Broom br;
                mas_time[i] = br.Broom_result(distance);
                ++sum;
            }

            else if (mass[i] == 2) 
            {
                Carpet cr;
                mas_time[i] = cr.Carpet_result(distance);
                ++sum;
            }

            else if (mass[i] == 3) 
            {
                Eagle eg;
                mas_time[i] = eg.Eagle_result(distance);
                ++sum;
            }

            else if (mass[i] == 4) 
            {
                FlightShip fs;
                mas_time[i] = fs.FlightShip_result(distance);
                ++sum;
            }

            else if (mass[i] == 5) 
            {
                Pegasus pg;
                mas_time[i] = pg.Pegasus_result(distance);
                ++sum;
            }

            else if (mass[i] == 6) 
            {
                Boots bs;
                mas_time[i] = bs.Boots_result(distance);
                ++sum;
            }

            else if (mass[i] == 7) 
            {
                Camel cl;
                mas_time[i] = cl.Camel_result(distance);
                ++sum;
            }
            else if (mass[i] == 8) 
            {
                CamelUltra clu;
                mas_time[i] = clu.CamelUltra_result(distance);
                ++sum;
            }
            else if (mass[i] == 9) 
            {
                Centaur cr;
                mas_time[i] = cr.Centaur_result(distance);
                ++sum;
            }
            else if (mass[i] == 10) 
            {
                Car ca;
                mas_time[i] = ca.Car_result(distance);
                ++sum;
            }
        }

        for (int i = 1; i < sum; ++i) 
        { 
            for (int j = 1; j < sum; ++j) 
            {
                if (mas_time[j] > mas_time[j + 1]) 
                {
                    double tmp = mas_time[j];
                    mas_time[j] = mas_time[j + 1];
                    mas_time[j + 1] = tmp;

                    std::string tmp2 = transport_container[j];
                    transport_container[j] = transport_container[j + 1];
                    transport_container[j + 1] = tmp2;
                }
            }
        }
        std::cout << "\nResult of racing: \n";
        for (int i = 1; i < sum + 1; ++i) 
        {
        std::cout << i << ".\t\t" << transport_container[i] << ".\t\tTime: " << mas_time[i] << "\n";
        }
        do
        {
            std::cout << "\n1. One more racing\n2. Exit\nChoose an action:";
            std::cin >> second_action;
            if (second_action == 2)
            {
                return false;
            }
            if (second_action != 1 && second_action != 2)
            {
                std::cout << "\nWrong value!\n";
            }
        } while (second_action != 1 && second_action != 2);
    }
    return 0;
}
	
