#include <pqxx/pqxx>
#include <iostream>
#include <string>
#include <stdexcept>
#include <regex>

class DatabaseManager {
private:
    pqxx::connection conn;

public:
    DatabaseManager(const std::string &host, int port, const std::string & dbname,
        const std::string& user, const std::string& password)
        : conn("host=" + host + " port=" + std::to_string(port) + " dbname=" + dbname + " user=" + user + " password=" + password) 
    {
        if (!conn.is_open()) {
            throw std::runtime_error("Error: Can't connect to DB!");
        }
    }

    bool createTables() {
            pqxx::work tr(conn);
            tr.exec("CREATE TABLE IF NOT EXISTS Clients("
                " id SERIAL PRIMARY KEY,"
                " name VARCHAR(60) NOT NULL,"
                " surname VARCHAR(60) NOT NULL,"
                " email VARCHAR(60) UNIQUE"
                ");");

            tr.exec("CREATE TABLE IF NOT EXISTS Numbers("
                " id SERIAL PRIMARY KEY,"
                " number VARCHAR(60) UNIQUE,"
                " client_id INTEGER REFERENCES Clients(id) ON DELETE CASCADE"
                ");");

            tr.commit();
            return true;

    }

    bool insertClient(const std::string& name, const std::string& surname, const std::string& email) 
    {

            pqxx::work wc(conn);
            std::string query = "INSERT INTO Clients (name, surname, email) VALUES ($1, $2, $3)";
            wc.exec_params(query, name, surname, email);
            wc.commit();
            return true;
    }
    bool insertNumber(const std::string& number, const int id) {
            pqxx::work wc(conn);
            std::string query = "INSERT INTO Numbers (number, client_id) VALUES ($1, $2)";
            wc.exec_params(query, number, id);
            wc.commit();
            return true;
    }

    bool updateClient(int id, const std::string& name, const std::string& surname, const std::string& email) {
            pqxx::work wc(conn);
            std::string query = "UPDATE Clients SET name = $1, surname = $2, email = $3 WHERE id = $4";
            pqxx::result result = wc.exec_params(query, name, surname, email, id);
            if (result.affected_rows() == 0)
            {
                std::cerr << "There is no this ID" << "\n";
                return false;
            };
            wc.commit();
            return true;
    }

    bool updateNumber(const std::string& number, int client_id) {
            pqxx::work wc(conn);
            std::string query = "UPDATE Numbers SET number = $1 WHERE client_id = $2";
            
            pqxx::result result = wc.exec_params(query, number, client_id);
            if (result.affected_rows() == 0)
            {
                std::cerr << "There is no this ID" << "\n";
                return false;
            }
            wc.commit();
            return true;
    }

    bool deleteClient(int id) {
            pqxx::work wc(conn);
            std::string query = "DELETE FROM Clients WHERE id = $1";
            wc.exec_params(query, id);
            wc.commit();
            return true;
    }

    bool deleteTable(const std::string& tableName) {
            pqxx::work wc(conn);
            std::string query = "DROP TABLE IF EXISTS " + tableName;
            wc.exec(query);
            wc.commit();
            return true;
    }

    void searchClients(const std::string& searchText) {
            pqxx::work wc(conn);
            std::string query = "SELECT * FROM Clients WHERE name LIKE $1 OR surname LIKE $1 OR email LIKE $1";
            pqxx::result result = wc.exec_params(query, "%" + searchText + "%");

            if (result.empty()) {
                std::cout << "No clients were found." << "\n";
            }
            else {
                std::cout << "Found clients:" << "\n";
                for (const auto& row : result) {
                    std::cout << "ID: " << row["id"].as<int>() << ", Name: " << row["name"].as<std::string>()
                        << ", Surname: " << row["surname"].as<std::string>()
                        << ", Email: " << row["email"].as<std::string>() << "\n";
                }
            }
    }
};

int main()
{
    try {
        DatabaseManager db("localhost", 5432, "Client", "postgres", "1234");
        db.createTables();

        std::cout << "Welcome to the database management console application!" << "\n";

        while (true) {
            std::cout << "\nSelect an action:" << "\n";
            std::cout << "1. Add a client" << "\n";
            std::cout << "2. Add a number" << "\n";
            std::cout << "3. Update client data" << "\n";
            std::cout << "4. Update number data" << "\n";
            std::cout << "5. Delete a row from table" << "\n";
            std::cout << "6. Delete a table" << "\n";
            std::cout << "7. Search clients" << "\n";
            std::cout << "0. Exit" << "\n";

            int choice;
            std::cin >> choice;

            try {
                switch (choice) {
                case 1: {
                    std::string name, surname, email;
                    std::cout << "Enter name: ";
                    std::cin >> name;
                    std::cout << "Enter surname: ";
                    std::cin >> surname;
                    std::cout << "Enter email: ";
                    std::cin >> email;

                    if (db.insertClient(name, surname, email)) {
                        std::cout << "Client added." << "\n";
                    }
                    else {
                        std::cout << "Error adding client." << "\n";
                    }
                    break;
                }
                case 2: {
                    std::string number;
                    int client_id;
                    std::cout << "Enter client_id: ";
                    std::cin >> client_id;
                    std::cout << "Enter number: ";
                    std::cin >> number;

                    if (db.insertNumber(number, client_id)) {
                        std::cout << "Number added." << "\n";
                    }
                    else {
                        std::cout << "Error adding number." << "\n";
                    }
                    break;
                }
                case 3: {
                    int id;
                    std::string name, surname, email;
                    std::cout << "Enter client ID: ";
                    std::cin >> id;
                    std::cout << "Enter name: ";
                    std::cin >> name;
                    std::cout << "Enter surname: ";
                    std::cin >> surname;
                    std::cout << "Enter email: ";
                    std::cin >> email;

                    if (db.updateClient(id, name, surname, email)) {
                        std::cout << "Client data updated." << "\n";
                    }
                    else {
                        std::cout << "Error updating client data." << "\n";
                    }
                    break;
                }

                case 4: {
                    std::string number;
                    int client_id;
                    std::cout << "Enter client_id: ";
                    std::cin >> client_id;
                    std::cout << "Enter number: ";
                    std::cin >> number;
                    if (db.updateNumber(number, client_id)) {
                        std::cout << "Number data updated." << "\n";
                    }
                    else {
                        std::cout << "Error updating number data." << "\n";
                    }
                    break;
                }
                case 5: {
                    int id;
                    std::cout << "Enter client ID to delete: ";
                    std::cin >> id;

                    if (db.deleteClient(id)) {
                        std::cout << "Client deleted." << "\n";
                    }
                    else {
                        std::cout << "Error deleting client." << "\n";
                    }
                    break;
                }
                case 6: {
                    std::string tableName;
                    std::cout << "Enter table name to delete: ";
                    std::cin >> tableName;

                    if (db.deleteTable(tableName)) {
                        std::cout << "Table deleted." << "\n";
                    }
                    else {
                        std::cout << "Error deleting table." << "\n";
                    }
                    break;
                }
                case 7: {
                    std::string searchTerm;
                    std::cout << "Enter search term: ";
                    std::cin >> searchTerm;

                    db.searchClients(searchTerm);
                    break;
                }
                case 0:
                    std::cout << "Good bye." << "\n";
                    return 0;
                default:
                    std::cout << "Invalid choice." << "\n";
                }
            }
            catch (const std::exception & e) 
            {
                std::cerr << "An error occurred processing the request: " << e.what() << "\n";
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Critical error: " << e.what() << "\n";
    }
    return 0;
}
