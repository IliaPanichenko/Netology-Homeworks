#include <iostream>
#include <fstream>
#include <string>
class Addres
{
private:
    std::string city;
    std::string street;
    int house_number;
    int appartment_number;
    std::string full_string;
public:
    Addres(std::string city, std::string street, int house_number, int appartment_number)
    {
        this->city = city;
        this->street = street;
        this->house_number = house_number;
        this->appartment_number = appartment_number;
    }

    std::string get_full_addres()
    {
        full_string = city + ", " + street + ", "  + std::to_string(house_number) + ", " + std::to_string(appartment_number);
        return full_string;
    }
};

std::string* create_Addres_arr(int insize)
{
    std::string* Addres_arr = new std::string[insize];
        return Addres_arr;
}

void print_Addres_arr(std::string* Addres_arr, int insize)
{
    std::ofstream put_in_file("out.txt");
    put_in_file << insize << "\n";
    for (int i = insize - 1; i >= 0; i--) 
    {
        put_in_file << Addres_arr[i] << "\n";
    }
    put_in_file.close();
}

void delete_Addres_arr(std::string* Addres_arr, int insize)
{
    for (int i = 0; i < insize; i++)
    {
        delete[] Addres_arr;
        Addres_arr = nullptr;
    }
}


int main(int argc, char** argv)
{
    std::string city;
    std::string street;
    int house_number;
    int appartment_number;
    int insize = 0;
    std::string  size;
    std::fstream get_file("in.txt");
    if (get_file.is_open())
    {
        get_file >> size;
        insize = stoi(size);
        std::string* Addres_arr = create_Addres_arr(insize);
        for (int i = 0; i < insize; i++)
        {
            get_file >> city >> street >> house_number >> appartment_number;
            Addres a (city, street, house_number, appartment_number);
            Addres_arr[i] = a.get_full_addres();
            print_Addres_arr(Addres_arr, insize);
        }   
        delete_Addres_arr(Addres_arr, insize);
    }
    else
    {
        std::cout << "File not found!";
    }
    get_file.close();
    return 0;
}
