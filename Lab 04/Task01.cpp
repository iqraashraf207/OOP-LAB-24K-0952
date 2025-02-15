//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
    string brand;
    string model;
    float price;
    bool availability;

    public:
    Car() {
        brand = "Unknown";
        model = "Generic";
        price = 0.0;
        availability = true;
    }
    void updateDetails(string br, string mdl, float pr, bool available) {
        brand = br;
        model = mdl;
        price = pr;
        availability = available;
    }

    bool checkAvailability() {
        if(availability) {
            cout << "The car " << brand << " " << model << " ia available"<< endl;
        } else {
            cout << "The car " << brand << " " << model << " is not available"<< endl;
        }
    }

    void rentCar() {
        if(availability) {
            availability = false;
            cout << "The car " << brand << " " << model << " has been rented"<< endl;
        } else {
            cout << "The car " << brand << " " << model << " is already rented"<< endl;
        }
    }

    void display(){
        cout << "Brand: " << brand << ", Model: " << model << ", Price: " << price << ", Availability: " << availability << endl;
    }
};

int main () {
    Car car1;
    car1.display();
    car1.updateDetails("Toyota", "Corolla", 3000.0, true);
    car1.display();
    car1.checkAvailability();
    car1.rentCar();
    car1.checkAvailability();
    
    return 0;
}