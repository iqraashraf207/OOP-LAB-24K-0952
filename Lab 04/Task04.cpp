//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Car{
    private:
    string brand;
    string model;
    float price;
    bool availability;
    double totalRevenue;

    public:
    Car() {
        brand = "Unknown";
        model = "Generic";
        price = 0.0;
        availability = true;
        totalRevenue = 0.0;
    }

    Car(string br, string mdl, float pr, bool available){
        brand = br;
        model = mdl;
        price = pr;
        availability = available;
        totalRevenue = 0.0;
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

    double applyDiscount(int days) {
        if (days>5) {
            return price * 0.95;
        } else if (days>10) {
            return price * 0.90;
        }
        return price;
    }

    void rentCar(int days) {
        if(availability) {
            availability = false;
            double finalPrice = applyDiscount(days);
            double revenue = finalPrice*days;
            totalRevenue += revenue;
            cout << "The car " << brand << " " << model << " has been rented for " << days << " days at a price of " << applyDiscount(days) << endl;
            cout << "Total revenue generated is " << totalRevenue << endl;
        } else {
            cout << "The car " << brand << " " << model << " is already rented"<< endl;
        }
    }

    void display(){
        cout << "Brand: " << brand << ", Model: " << model << ", Price: " << price << ", Availability: " << availability << endl;
    }
};

int main () {
    Car car1("Toyota", "Corolla", 3000.0, true);
    car1.display();
    Car car2("Honda", "Civic", 5000.0, true);
    car2.display();
    car1.rentCar(12);
    car1.display();

    return 0;
}