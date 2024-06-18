#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Product 
{
	public:
    Product(const string& name, double price) : name(name), price(price) {}
    virtual double calculateCost(int quantity) = 0;
    string getName() const 
    {
        return name;
    }

	protected:
    string name;
    double price;
};

class Electronics : public Product 
{
public:
    Electronics(const string& name, double price) : Product(name, price) {}
    double calculateCost(int quantity) override 
    {
        return price * quantity;
    }
};

class Clothing : public Product 
{
public:
    Clothing(const string& name, double price) : Product(name, price) {}
    double calculateCost(int quantity) override 
    {
        return price * quantity;
    }
};

class ShoppingCart 
{
public:
    void addToCart(shared_ptr<Product> product, int quantity) 
    {
        cartItems.push_back({ product, quantity });
    }

    double calculateTotalCost() 
    {
        double totalCost = 0.0;
        for (const auto& item : cartItems) 
        {
            totalCost += item.first->calculateCost(item.second);
        }
        return totalCost;
    }

    void placeOrder() 
    {
        if (cartItems.empty()) 
        {
            cout << "Your cart is empty" << endl;
        } else 
        {
            cout << "Order placed successfully. Total cost $: " << calculateTotalCost() << endl;
        }
    }

	private:
    vector<pair<shared_ptr<Product>, int>> cartItems;
};

int main() 
{
    ShoppingCart cart;

    Electronics phone("Smartphone", 349.99);
    Electronics tv("Television", 499.99);
    Electronics laptop("Laptop", 359.99);
    Electronics headphones("Headphones", 99.99);

    Clothing tshirt("T-shirt", 6.99);
    Clothing jeans("Jeans", 10.99);
    Clothing dress("Dress", 7.99);
    Clothing shirt("Shirt", 4.99);

    while (true) {
        cout << "CATEGORIES" << endl;
        cout << "1. Electronics" << endl;
        cout << "2. Clothing" << endl;
        cout << "3. Checkout" << endl;
        cout << "Enter your option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Choose Electronics Product" << endl;
            cout << "1. Smartphone ($349.99)" << endl;
            cout << "2. Television ($499.99)" << endl;
            cout << "3. Laptop ($359.99)" << endl;
            cout << "4. Headphones ($99.99)" << endl;
            cout << "Enter your choice: ";
            int electronicsChoice;
            cin >> electronicsChoice;
            int quantity;
            cout << "Enter quantity: ";
            cin >> quantity;

            if (electronicsChoice == 1) {
                cart.addToCart(make_shared<Electronics>(phone), quantity);
            } else if (electronicsChoice == 2) {
                cart.addToCart(make_shared<Electronics>(tv), quantity);
            } else if (electronicsChoice == 3) {
                cart.addToCart(make_shared<Electronics>(laptop), quantity);
            } else if (electronicsChoice == 4) {
                cart.addToCart(make_shared<Electronics>(headphones), quantity);
            } else {
                cout << "Invalid choice" << endl;
            }
        } else if (choice == 2) {
            cout << "Choose Clothing Product" << endl;
            cout << "1. T-shirt ($6.99)" << endl;
            cout << "2. Jeans ($10.99)" << endl;
            cout << "3. Dress ($7.99)" << endl;
            cout << "4. Shirt ($4.99)" << endl;
            cout << "Enter your choice: ";
            int clothingChoice;
            cin >> clothingChoice;
            int quantity;
            cout << "Enter quantity: ";
            cin >> quantity;

            if (clothingChoice == 1) {
                cart.addToCart(make_shared<Clothing>(tshirt), quantity);
            } else if (clothingChoice == 2) {
                cart.addToCart(make_shared<Clothing>(jeans), quantity);
            } else if (clothingChoice == 3) {
                cart.addToCart(make_shared<Clothing>(dress), quantity);
            } else if (clothingChoice == 4) {
                cart.addToCart(make_shared<Clothing>(shirt), quantity);
            } else {
                cout << "Invalid choice" << endl;
            }
        } else if (choice == 3) {
            cart.placeOrder();
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}


