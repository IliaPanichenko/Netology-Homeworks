#include <iostream>
#include <string>
#include <fstream>

class Addres
{
private:
    std::string city;
    std::string street;
    int houses_number;
    int appartment_number;
    std::string full_string;
public:
    Addres(std::string city, std::string street, int houses_number, int appartment_number)
    {
        this->city = city;
        this->street = street;
        this->houses_number = houses_number;
        this->appartment_number = appartment_number;
    }
    std::string get_Addres_string()
    {
        full_string = city + ", " + street + ", " + std::to_string(houses_number) + ", " + std::to_string(appartment_number);
        return full_string;
    }
};

std::string* create_Addres_arr(int insize)
{
    std::string* Addres_arr = new std::string[insize]{};
    return Addres_arr;
}



void delete_Addres_arr(std::string* Addres_arr, int insize)
{
    for (int i = 0; i < insize; i++)
    {
        delete[] Addres_arr;
        Addres_arr = nullptr;
    }
}

void Sort(std::string* Addres_arr, int insize)
{
    for (int i = 0; i < insize-1; i++)
    {
        if (Addres_arr[i] > Addres_arr[i + 1])
        {
            std::swap(Addres_arr[i], Addres_arr[i+1]);
        }
    }
    
}

void Print_into_file_with_sort(std::string* Addres_arr, int insize)
{
    std::ofstream put_in_file("out.txt");
    put_in_file << insize << "\n";
    for (int i = 0 ; i < insize; i++)
    {
        put_in_file << Addres_arr[i] << "\n";
    }
    put_in_file.close();
}

int main(int argc, char** argv)
{
    std::string city;
    std::string street;
    int houses_number;
    int appartment_number;
    std::string size;
    int insize = 0;
    std::ifstream get_from_file("in.txt");
    if (get_from_file.is_open())
    {
        get_from_file >> size;
        insize = stoi(size);
        std::string* Addres_arr = create_Addres_arr(insize);
        for (int i = 0; i < insize; i++)
        {
            get_from_file >> city >> street >> houses_number >> appartment_number;
            Addres a(city, street, houses_number, appartment_number);
            Addres_arr[i] = a.get_Addres_string();
            
        }
        for (int i = 0; i < insize-1; i++)
        {
            Sort(Addres_arr, insize);
        }
        Print_into_file_with_sort(Addres_arr, insize);
        delete_Addres_arr(Addres_arr, insize);
    }
    else
    {
        std::cout << "File not found!";
    }
    get_from_file.close();
    return 0;
}
