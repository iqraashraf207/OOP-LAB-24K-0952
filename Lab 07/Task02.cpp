//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id, string name, double pr, int stock) : productID(id), productName(name), price(pr), stockQuantity(stock) {}
    
    virtual void applyDiscount(double percent) {
        price -= price * (percent / 100);
    }
    
    virtual double calculateTotalPrice(int quantity) {
        return price * quantity;
    }
    
    virtual void displayProductInfo() {
        cout << "Product ID: " << productID << endl;
        cout << "Name: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stockQuantity << endl;
    }
    
};

class Electronics : public Product {
private:
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id, string name, double pr, int stock, int warranty, string br) : Product(id, name, pr, stock), warrantyPeriod(warranty), brand(br) {}
    
    void displayProductInfo() {
        Product::displayProductInfo();
        cout << "Brand: " << brand << endl;
        cout << "Warranty: " << warrantyPeriod << endl;
    }
};

class Clothing : public Product {
private:
    string size;
    string color;
    string fabricMaterial;

public:
    Clothing(int id, string name, double pr, int stock, string s, string c, string fabric) : Product(id, name, pr, stock), size(s), color(c), fabricMaterial(fabric) {}
    
    void applyDiscount(double percentage) {
        if (percentage > 20) {
            percentage = 20;
        }
        Product::applyDiscount(percentage);
    }
};

class FoodItem : public Product {
private:
    string expirationDate;
    int calories;

public:
    FoodItem(int id, string name, double pr, int stock, string expire, int cal) : Product(id, name, pr, stock), expirationDate(expire), calories(cal) {}
    
    double calculateTotalPrice(int quantity) {
        double total = Product::calculateTotalPrice(quantity);
        if (quantity > 10) {
            total *= 0.9;
        }
        return total;
    }
};

class Book : public Product {
private:
    string author;
    string genre;

public:
    Book(int id, string name, double pr, int stock, string auth, string gen) : Product(id, name, pr, stock), author(auth), genre(gen) {}
    
    void displayProductInfo() {
        Product::displayProductInfo();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    Electronics tablet(12, "Samsung Tablet", 2700, 07, 3, "Samsung");
    Clothing shoes(34, "Samba Shoes", 700, 45, "Medium", "White", "Cotton");
    FoodItem egg(56, "Quail Eggs", 15, 50, "2025-06-10", 70);
    Book novel(78, "Thriller Novel", 1200, 16, "Dan Brown", "Thriller");

    tablet.displayProductInfo();
    shoes.applyDiscount(25);
    cout << "Total Price for eggs: " << egg.calculateTotalPrice(6) << endl;
    novel.displayProductInfo();
    
    return 0;
}