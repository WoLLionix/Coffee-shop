#include <iostream>
#include <vector>

// Ієрархія продуктів
class Product 
{
public:
    virtual void display() = 0;
    virtual ~Product() {}
};

// Класи для конкретних продуктів
class Coffee : public Product 
{
public:
    void display() override 
    {
        std::cout << "Coffee" << std::endl;
    }
};

class Tea : public Product 
{
public:
    void display() override 
    {
        std::cout << "Tea" << std::endl;
    }
};

class Cookie : public Product 
{
public:
    void display() override 
    {
        std::cout << "Cookie" << std::endl;
    }
};

// Паттерн Фабричний метод
class ProductFactory 
{
public:
    virtual Product* createProduct() = 0;
    virtual ~ProductFactory() {}
};

// Конкретні фабрики для створення конкретних продуктів
class CoffeeFactory : public ProductFactory 
{
public:
    Product* createProduct() override 
    {
        return new Coffee();
    }
};

class TeaFactory : public ProductFactory 
{
public:
    Product* createProduct() override 
    {
        return new Tea();
    }
};

class CookieFactory : public ProductFactory 
{
public:
    Product* createProduct() override 
    {
        return new Cookie();
    }
};

// Клієнт
class Client 
{
public:
    // Метод для розміщення замовлення
    void placeOrder(ProductFactory* factory) 
    {
        Product* product = factory->createProduct();
        orders.push_back(product);
    }

    // Метод для виведення історії замовлень
    void displayOrderHistory() 
    {
        for (Product* product : orders) 
        {
            product->display();
        }
    }

private:
    std::vector<Product*> orders; // Замовлення клієнта
};


// Паттерн Посередник
class Mediator 
{
public:
    // Метод для сповіщення про оплату замовлення
    void notifyPayment(Client* client) 
    {
        std::cout << "Order has been paid by the client" << std::endl;
    }

    // Метод для сповіщення про відправку замовлення
    void notifyShipment(Client* client) 
    {
        std::cout << "Order has been shipped to the client" << std::endl;
    }
};

int main() 
{
    // Створення фабрик продуктів
    ProductFactory* coffeeFactory = new CoffeeFactory();
    ProductFactory* teaFactory = new TeaFactory();
    ProductFactory* cookieFactory = new CookieFactory();

    // Створення клієнта
    Client client;

    // Розміщення замовлень
    client.placeOrder(teaFactory);
    client.placeOrder(cookieFactory);

    // Виведення історії замовлень
    std::cout << "Order history:" << std::endl;
    client.displayOrderHistory();

    // Симуляція оплати та відправки замовлення
    Mediator mediator;
    mediator.notifyPayment(&client);
    mediator.notifyShipment(&client);

    // Звільнення пам'яті
    delete coffeeFactory;
    delete teaFactory;
    delete cookieFactory;

    return 0;
}
