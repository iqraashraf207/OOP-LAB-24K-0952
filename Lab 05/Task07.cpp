//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    int ID;
    string name;
    int quantity;

    Product(int id, string n, int q) : ID(id), name(n), quantity(q) {}

    void display() {
        cout << "Product ID: " << ID << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};

class Warehouse {
public:
    Product* inventory[100];
    int productCount;

    Warehouse() {
        productCount = 0;
    }

    void addProduct(int id, string name, int quantity) {
        inventory[productCount++] = new Product(id, name, quantity);
    }

    void sortProducts() {
        for (int i = 0; i < productCount - 1; i++)
        {
            for (int j = 0; j < productCount - i - 1; j++)
            {
                if (inventory[j]->name > inventory[j + 1]->name) {
                    swap(inventory[j], inventory[j + 1]);
                }
            }
        }
    }

    void searchByID(int id) {
        for (int i = 0; i < productCount; i++)
        {
            if (inventory[i]->ID == id) {
                cout << "Product Found." << endl;
                inventory[i]->display();
                return;
            }
        }
        cout << "Product with ID " << id << " not found." << endl;
    }

    void displayAll() {
        cout << "Inventory List:" << endl;
        for (int i = 0; i < productCount; i++)
        {
            inventory[i]->display();
        }
    }

    ~Warehouse() {
        for (int i = 0; i < productCount; i++)
        {
            delete inventory[i];
        }
    }
};

int main() {
    Warehouse warehouse;
    warehouse.addProduct(100, "Side Table", 7);
    warehouse.addProduct(101, "Laptop", 3);
    warehouse.addProduct(102, "Oranges", 40);
    warehouse.addProduct(103, "Chair", 12);

    cout << "Before Sorting:" << endl;
    warehouse.displayAll();

    warehouse.sortProducts();
    cout << "After Sorting Alphabetically:" << endl;
    warehouse.displayAll();

    int searchID;
    cout << "Enter Product ID to Search: ";
    cin >> searchID;
    warehouse.searchByID(searchID);

    return 0;
}