//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}

    friend class InventoryManager;

    friend void comparePrice(const Car& c1, const Car& c2);
};

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice) {
        car.price = newPrice;
        cout << "Updated price of " << car.model << " is " << car.price << endl;
    }

    void displayCar(const Car& car) {
        cout << "Model: " << car.model << endl;
        cout << "Price: " << car.price << endl;
    }
};

void comparePrice(const Car& c1, const Car& c2) {
    if (c1.price > c2.price) {
        cout << c1.model << " is more expensive than " << c2.model << endl;
    } else if (c1.price < c2.price) {
        cout << c2.model << " is more expensive than " << c1.model << endl;
    } else {
        cout << "Both cars have the same price." << endl;
    }
}

int main() {
    Car c1("Toyota Corolla", 24000);
    Car c2("KIA Sportage", 29000);
    InventoryManager manager;

    manager.displayCar(c1);
    manager.displayCar(c2);

    manager.updatePrice(c1, 27000);

    comparePrice(c1, c2);

    return 0;
}