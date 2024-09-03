#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

class Publisher {
public:
    std::string name;

    template <class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, name, "name");
    }
};

class Book {
public:
    std::string title;
    Wt::Dbo::ptr<Publisher> publisher;

    template <class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher, "id_publisher");
    };
};

class Shop {
public:
    std::string name;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, name, "name");
    }
};

class Stock
{
public:
    int count;
    Wt::Dbo::ptr<Book> book;
    Wt::Dbo::ptr<Shop> shop;
    template<class Action>

    void persist(Action& a) {
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, book, "id_book");
        Wt::Dbo::belongsTo(a, shop, "id_shop");
    }
};

class Sale {
public:
    double price;
    int count;
    std::string date_sale;
    Wt::Dbo::ptr<Stock> id_stock;
    template<class Action>
    void persist(Action& a)
    {
    Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, date_sale, "date_sale");
        Wt::Dbo::belongsTo(a, id_stock, "id_stock");
        Wt::Dbo::field(a, count, "count");
    }
};
int main()
{
    std::cout << "Hello_Wt::Dbo" << "\n";
}