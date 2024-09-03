#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
class Publisher {
public:
    std::string name;
    Publisher() = default;

    Publisher(const std::string& name) : name(name) {}
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
    }
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
    try {
        std::string connection_string =
            ("host=localhost "
                "port=5432 "
                "dbname=Books2 "
                "user=postgres "
                "password=1234");

        auto pg = std::make_unique<Wt::Dbo::backend::Postgres>(connection_string);
        Wt::Dbo::Session session;
        session.setConnection(std::move(pg));

        session.mapClass<Publisher>("publisher");
        session.mapClass<Book>("book");
        session.mapClass<Shop>("shop");
        session.mapClass<Stock>("stock");

        session.createTables();

        Wt::Dbo::Transaction transaction(session);

        auto publisher1 = session.add(std::make_unique<Publisher>("Drofa"));
        auto publisher2 = session.add(std::make_unique<Publisher>("Vid"));
        auto publisher3 = session.add(std::make_unique<Publisher>("Buka"));

        auto book1 = session.add(std::make_unique<Book>());
        book1.modify()->title = "AzzzBuka";
        book1.modify()->publisher = publisher1;

        auto book2 = session.add(std::make_unique<Book>());
        book2.modify()->title = "Fun";
        book2.modify()->publisher = publisher1;

        auto book3 = session.add(std::make_unique<Book>());
        book3.modify()->title = "W&P";
        book3.modify()->publisher = publisher2;

        auto shop1 = session.add(std::make_unique<Shop>());
        shop1.modify()->name = "Reader";

        auto shop2 = session.add(std::make_unique<Shop>());
        shop2.modify()->name = "LitRes";

        auto stock1 = session.add(std::make_unique<Stock>());
        stock1.modify()->count = 10;
        stock1.modify()->book = book1;
        stock1.modify()->shop = shop1;

        auto stock2 = session.add(std::make_unique<Stock>());
        stock2.modify()->count = 5;
        stock2.modify()->book = book2;
        stock2.modify()->shop = shop2;

        auto stock3 = session.add(std::make_unique<Stock>());
        stock3.modify()->count = 7;
        stock3.modify()->book = book3;
        stock3.modify()->shop = shop1;

        transaction.commit();

        std::string publisherName;
        std::cout << "Enter publisher name: ";
        std::cin >> publisherName;

        Wt::Dbo::Transaction queryTransaction(session);

        Wt::Dbo::ptr<Publisher> targetPublisher = session.find<Publisher>().where("name = ?").bind(publisherName);
        if (!targetPublisher) {
            std::cout << "Publisher not found.\n";
            return 1;
        }

        Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks = session.query<Wt::Dbo::ptr<Stock>>(
            "select stock from stock "
            "inner join book on stock.id_book_id = book.id "
            "where book.id_publisher_id = ?"
        ).bind(targetPublisher.id());

        std::cout << "Shops selling books by " << publisherName << ":\n";
        for (const auto& stock : stocks) {
            std::cout << stock->shop->name << "\n";
        }

        queryTransaction.commit();
    }
    catch (Wt::Dbo::Exception& ex) {
        std::cerr << "Database error: " << ex.what() << "\n";
    }
    return 0;
}