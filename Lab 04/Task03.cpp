//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include<string>
using namespace std;

class Car{
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

    Car(string br, string mdl, float pr, bool available){
        brand =br;
        model = mdl;
        price = pr;
        availability = available;
    }

    Car(Car &obj){
        brand = obj.brand;
        model = obj.model;
        price = obj.price;
        availability = obj.availability;
    }
    
    void updateDetails(string br, string mdl, float pr, bool available) {
        brand = br;
        model = model;
        price = pr;
        availability = available;
    }

    void display(){
        cout << "Brand: " << brand << ", Model:" << model << ", Price: " << price << ", Availability:" << availability << endl;
    }

    ~Car(){
        cout << "Car " << brand << " " << model << " is destroyed" << endl;
    }

};

int main (){
    Car car1;
    car1.display();
    Car car2(car1);
    car1.updateDetails("Toyota", "Corolla", 80.0, false);
    car1.display();
    car2.display();

    return 0;
}