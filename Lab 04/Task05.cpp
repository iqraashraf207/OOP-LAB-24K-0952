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
    string carID;

    public:

    Car() : brand("Unknown"), model("Generic"), price(0.0), availability(true), totalRevenue(0.0), carID("000000") {}

    Car(string br, string mdl, double pr, bool available, string id) : brand(br), model(mdl), price(pr), availability(available), totalRevenue(0.0), carID(id) {}
    

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
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
        cout << "Availability Status: " << availability << endl;
        cout << "Total Revenue: " << totalRevenue << endl;
    }
};

int main () {
    Car car1("Toyota", "Corolla", 3000.0, true, "123abc");
    cout << "Car 1 Details" << endl;
    car1.display();
    Car car2("Honda", "Civic", 5000.0, true, "567def");
    cout << "Car 2 Details" << endl;
    car2.display();
    car1.rentCar(12);
    cout << "Car 1 Details" << endl;
    car1.display();

    return 0;
}