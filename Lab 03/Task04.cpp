//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

class Car{
private:
    string brand;
    string model;
    float fuelCapacity;
    float currentFuelLevel;
    float fuelConsumptionRate;

public:
    Car(string b, string m, float capacity, float consumption){
        brand = b;
        model = m;
        fuelCapacity = capacity;
        currentFuelLevel = capacity;
        fuelConsumptionRate = consumption;
    }

    void driveCar(float distance){
        float fuelNeeded = distance * fuelConsumptionRate;

        if (fuelNeeded > currentFuelLevel) {
            cout << "Not enough fuel to drive " << distance << " km. Refuel the tank." << endl;
        } else {
            currentFuelLevel -= fuelNeeded;
            cout << "You have driven " << distance << " km. Remaining fuel: " << currentFuelLevel << " liters." << endl;
        }
        checkFuelStatus();
    }

    void refuelTank(float fuelAmount){
        if (fuelAmount <= 0){
            cout << "Fuel amount invalid." << endl;
            return;
        }

        if (currentFuelLevel + fuelAmount > fuelCapacity){
            currentFuelLevel = fuelCapacity;
            cout << "Tank is now full."<< endl;
        } else {
            currentFuelLevel += fuelAmount;
            cout << "Added " << fuelAmount << " liters. Fuel level: " << currentFuelLevel << " liters.\n";
        }
    }

    void checkFuelStatus(){
        if (currentFuelLevel < (fuelCapacity * 0.15)){
            cout << "Warning! Low fuel. Refuel the tank." << endl;
        }
    }

    void displayCarInfo(){
        cout << "Car Details:" << endl;
        cout << "Brand: " << brand << endl << "Model: " << model <<  endl << "Fuel Capacity: " << endl;
        cout << "Current Fuel Level: " << currentFuelLevel << " liters" << endl;
    }
};

int main(){
    Car zoyaCar("Toyota", "Corolla", 50, 0.12);

    zoyaCar.displayCarInfo();

    zoyaCar.driveCar(200);
    zoyaCar.refuelTank(70);
    zoyaCar.driveCar(100);

    return 0;
}
