//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Vehicle {

protected:
    string brand;
    int speed;

public:
    Vehicle(string b, int spd) : brand(b), speed(spd) {}

    void displayDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << endl;
    }
};

class Car : public Vehicle {

protected:
    int seats;

public:
    Car(string b, int spd, int s) : Vehicle(b, spd), seats(s) {}

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car {
    
private:
    int batteryLife;

public:
    ElectricCar(string b, int spd, int s, int bl) : Car(b, spd, s), batteryLife(bl) {}

    void displayDetails() {
        Car::displayDetails();
        cout << "Battery Life: " << batteryLife << endl;
    }
};

int main() {

    ElectricCar e1("Ferrari", 200, 4, 9);

    cout << "Electric Car Details:" << endl;
    e1.displayDetails();

    return 0;
}