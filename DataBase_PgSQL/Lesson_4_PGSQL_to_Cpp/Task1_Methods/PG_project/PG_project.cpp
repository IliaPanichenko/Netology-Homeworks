#include <pqxx/pqxx>
#include <iostream>
#include <string>
#include <stdexcept>
#include <regex>

class DatabaseManager {
private:
    pqxx::connection conn;

    void validateName(const std::string& tableName) {
        std::regex pattern("^[A-Za-z_][A-Za-z0-9_]*$");
        if (!std::regex_match(tableName, pattern)) {
            throw std::invalid_argument("Invalid table name format.");
        }
    }

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
        try {
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
        catch (const std::exception& e) {
            std::cerr << "Error creat tables: " << e.what() << "\n";
            return false;
        }
    }

    bool insertClient(const std::string& tableName, const std::string& name, const std::string& surname, const std::string& email) 
    {
        try {
            validateName(tableName);
            pqxx::work wc(conn);
            std::string query = "INSERT INTO " + tableName + " (name, surname, email) VALUES ($1, $2, $3)";
            wc.exec_params(query, name, surname, email);
            wc.commit();
            return true;
        }
        catch (const std::exception& e) {
            std::cerr << "Error inserting client: " << e.what() << "\n";
            return false;
        }
    }
    bool insertNumber(const std::string& tableName, const std::string& number, const int id) {
        try {
            validateName(tableName);
            pqxx::work wc(conn);
            std::string query = "INSERT INTO " + tableName + " (number, client_id) VALUES ($1, $2)";
            wc.exec_params(query, number, id);
            wc.commit();
            return true;
        }
        catch (const std::exception& e) {
            std::cerr << "Error inserting number: " << e.what() << "\n";
            return false;
        }
    }

    bool updateClient(const std::string& tableName, int id, const std::string& name, const std::string& surname, const std::string& email) {
        try {
            validateName(tableName);
            pqxx::work wc(conn);
            std::string query = "UPDATE " + tableName + " SET name = $1, surname = $2, email = $3 WHERE id = $4";
            pqxx::result result = wc.exec_params(query, name, surname, email, id);
            if (result.affected_rows() == 0)
            {
                std::cerr << "There is no this ID" << "\n";
                return false;
            };
            wc.commit();
            return true;
        }
        catch (const std::exception& e) {
            std::cerr << "Error updating client: " << e.what() << "\n";
            return false;
        }
    }

    bool updateNumber(const std::string& tableName, const std::string& number, int client_id) {
        try {
            validateName(tableName);
            pqxx::work wc(conn);
            std::string query = "UPDATE " + tableName + " SET number = $1 WHERE client_id = $2";
            
            pqxx::result result = wc.exec_params(query, number, client_id);
            if (result.affected_rows() == 0)
            {
                std::cerr << "There is no this ID" << "\n";
                return false;
            }
            wc.commit();
            return true;
        }
        catch (const std::exception& e) {
            std::cerr << "Error updating number: " << e.what() << "\n";
            return false;
        }
    }

    bool deleteClient(const std::string& tableName, int id) {
        try {
            validateName(tableName);
            pqxx::work wc(conn);
            std::string query = "DELETE FROM " + tableName + " WHERE id = $1";
            wc.exec_params(query, id);
            wc.commit();
            return true;
        }
        catch (const std::exception& e) {
            std::cerr << "Error deleting: " << e.what() << "\n";
            return false;
        }
    }

    bool deleteTable(const std::string& tableName) {
        try {
            validateName(tableName);
            pqxx::work wc(conn);
            std::string query = "DROP TABLE IF EXISTS " + tableName;
            wc.exec(query);
            wc.commit();
            return true;
        }
        catch (const std::exception& e) {
            std::cerr << "Error deleting table: " << e.what() << "\n";
            return false;
        }
    }

    void searchClients(const std::string& tableName, const std::string& searchText) {
        try {
            validateName(tableName);
            pqxx::work wc(conn);
            std::string query = "SELECT * FROM " + tableName + " WHERE name LIKE $1 OR surname LIKE $1 OR email LIKE $1";
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
        catch (const std::exception& e) {
            std::cerr << "Error searching clients: " << e.what() << "\n";
        }
    }

    void DBMode() {
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

            switch (choice) {
            case 1: {
                std::string tableName, name, surname, email;
                std::cout << "Enter table name: ";
                std::cin >> tableName;
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter surname: ";
                std::cin >> surname;
                std::cout << "Enter email: ";
                std::cin >> email;

                if (insertClient(tableName, name, surname, email)) {
                    std::cout << "Client added." << "\n";
                }
                else {
                    std::cout << "Error adding client." << "\n";
                }
                break;
            }
            case 2: {
                std::string tableName, number;
                int client_id;
                std::cout << "Enter table name: ";
                std::cin >> tableName;
                std::cout << "Enter number: ";
                std::cin >> number;
                std::cout << "Enter client_id: ";
                std::cin >> client_id;

                if (insertNumber(tableName, number, client_id)) {
                    std::cout << "Number added." << "\n";
                }
                else {
                    std::cout << "Error adding number." << "\n";
                }
                break;
            }
            case 3: {
                std::string tableName;
                int id;
                std::string name, surname, email;
                std::cout << "Enter table name: ";
                std::cin >> tableName;
                std::cout << "Enter client ID: ";
                std::cin >> id;
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter surname: ";
                std::cin >> surname;
                std::cout << "Enter email: ";
                std::cin >> email;

                if (updateClient(tableName, id, name, surname, email)) {
                    std::cout << "Client data updated." << "\n";
                }
                else {
                    std::cout << "Error updating client data." << "\n";
                }
                break;
            }

            case 4: {
                std::string tableName, number;
                int client_id;
                std::cout << "Enter table name: ";
                std::cin >> tableName;
                std::cout << "Enter number: ";
                std::cin >> number;
                std::cout << "Enter client_id: ";
                std::cin >> client_id;

                if (updateNumber(tableName, number, client_id)) {
                    std::cout << "Number data updated." << "\n";
                }
                else {
                    std::cout << "Error updating number data." << "\n";
                }
                break;
            }
            case 5: {
                std::string tableName;
                int id;
                std::cout << "Enter table name: ";
                std::cin >> tableName;
                std::cout << "Enter client ID to delete: ";
                std::cin >> id;

                if (deleteClient(tableName, id)) {
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

                if (deleteTable(tableName)) {
                    std::cout << "Table deleted." << "\n";
                }
                else {
                    std::cout << "Error deleting table." << "\n";
                }
                break;
            }
            case 7: {
                std::string tableName, searchTerm;
                std::cout << "Enter table name: ";
                std::cin >> tableName;
                std::cout << "Enter search term: ";
                std::cin >> searchTerm;

                searchClients(tableName, searchTerm);
                break;
            }
            case 0:
                std::cout << "Good bye." << "\n";
                return;
            default:
                std::cout << "Invalid choice." << "\n";
            }
        }
    }
};

int main() 
{
    DatabaseManager db("localhost", 5432, "Client", "postgres", "1234");
    db.createTables();
    db.DBMode();
    return 0;
}
