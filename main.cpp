#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
    Product(const string &n, double p, int q) : name(n), price(p), qty(q) {}

    string getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }

    int getQty() const
    {
        return qty;
    }

    void setQty(int newQty)
    {
        qty = newQty;
    }

private:
    string name;
    double price;
    int qty;
};

class CartItem
{
public:
    CartItem(const string &n, double p, int q) : name(n), price(p), qty(q) {}

    string getName() const
    {
        return name;
    }

    void setName(const string &n)
    {
        name = n;
    }

    double getPrice() const
    {
        return price;
    }

    void setPrice(double p)
    {
        price = p;
    }

    int getQty() const
    {
        return qty;
    }

    void setQty(int q)
    {
        qty = q;
    }

private:
    string name;
    double price;
    int qty;
};

class Cart
{
private:
    vector<CartItem> cartItems;

public:
    void addToCart(const Product &product)
    {
        for (CartItem &item : cartItems)
        {
            if (item.getName() == product.getName())
            {
                item.setQty(item.getQty() + 1);
                return;
            }
        }

        cartItems.push_back(CartItem(product.getName(), product.getPrice(), 1));
    }

    vector<CartItem> getCartItems() const
    {
        return cartItems;
    }

    void viewCart() const
    {
        cout << "Items in Cart:" << endl;
        for (int i = 0; i < cartItems.size(); i++)
        {
            const CartItem &item = cartItems[i];
            cout << i + 1 << ". "
                 << "Name: " << item.getName() << ", Price: Rs. " << item.getPrice() << ", Quantity: " << item.getQty() << endl;
        }
    }

    void updateQtyInCart(const string &productName, int newQty)
    {
        for (CartItem &item : cartItems)
        {
            if (item.getName() == productName)
            {
                item.setQty(newQty);
                return;
            }
        }
        cout << "Item not found in the cart." << endl;
    }

    void removeItem(const string &productName)
    {
        for (auto it = cartItems.begin(); it != cartItems.end(); ++it)
        {
            if (it->getName() == productName)
            {
                cartItems.erase(it);
                cout << productName << " has been removed from the cart." << endl;
                return;
            }
        }
        cout << "Item not found in the cart." << endl;
    }

    double calculateBill() const
    {
        double total = 0;
        for (CartItem item : cartItems)
        {
            total += item.getPrice() * item.getQty();
        }
        return total;
    }
};

class Shop
{
private:
    Cart cart;
    vector<Product> inventory;

public:
    void addProductToInventory(Product product)
    {
        inventory.push_back(product);
    }

    void buyItem()
    {
        cout << "Select the item you want to add to cart: " << endl;
        cout << "Items in Shop:" << endl;
        for (int i = 0; i < inventory.size(); i++)
        {
            const Product &item = inventory[i];
            cout << i + 1 << ". "
                 << "Name: " << item.getName() << ", Price: Rs. " << item.getPrice() << ", Quantity: " << item.getQty() << endl;
        }
        int index;
        cin >> index;
        cart.addToCart(inventory[index - 1]);
        cout << inventory[index - 1].getName() << " added" << endl;
    }

    void viewCart() const
    {
        cart.viewCart();
    }

    void updateItemQty()
    {
        cout << "Select the item you want to update: " << endl;
        cart.viewCart();
        int index;
        cin >> index;
        cout << "Enter the new quantity: " << endl;
        int newQty;
        cin >> newQty;
        cart.updateQtyInCart(cart.getCartItems()[index - 1].getName(), newQty);
        if (cart.getCartItems()[index - 1].getQty() <= 0)
        {
            cart.removeItem(cart.getCartItems()[index - 1].getName());
        }
        cout << "Quantity updated successfully." << endl;
    }

    void removeItem()
    {
        cout << "Select the item you want to remove: " << endl;
        cart.viewCart();
        int index;
        cin >> index;
        cart.removeItem(cart.getCartItems()[index - 1].getName());
    }

    void calculateBill()
    {
        cout << "Total bill: Rs. " << cart.calculateBill() << endl;
    }
};

void displayMenu()
{
    cout << "\n1. Add to Cart\n"
         << "2. View Cart\n"
         << "3. Update Item Quantity\n"
         << "4. Remove Item\n"
         << "5. Calculate Bill\n"
         << "0. Exit\n\n";
}

int main()
{
    Shop shop;
    shop.addProductToInventory(Product("Laptop",10000,2));
    shop.addProductToInventory(Product("Headphone", 100, 5));
    shop.addProductToInventory(Product("Pen", 30, 20));
    shop.addProductToInventory(Product("Table", 150, 5));
    shop.addProductToInventory(Product("Chair", 1000, 50));

    int choice;
    while (choice != 0)
    {
        displayMenu();
        cout<< " Select choice:" << " ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            shop.buyItem();
            break;
        }
        case 2:
        {
            shop.viewCart();
            break;
        }
        case 3:
        {
            shop.updateItemQty();
            break;
        }
        case 4:
        {
            shop.removeItem();
            break;
        }
        case 5:
        {
            shop.calculateBill();
            break;
        }
        case 0:
        {
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}