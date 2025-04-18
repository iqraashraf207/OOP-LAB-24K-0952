//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor {
private:
    float temperature;

public:
    void readData() {
        temperature = 25.6;
    }

    void displayReport() {
        cout << "Thermometer Reading: " << temperature << endl;
    }
};

class Barometer : public WeatherSensor {
private:
    float pressure;

public:
    void readData() {
        pressure = 1013.7;
    }

    void displayReport() {
        cout << "Barometer Reading: " << pressure << endl;
    }
};

int main() {
    Thermometer t;
    Barometer b;

    WeatherSensor* sensors[2];
    sensors[0] = &t;
    sensors[1] = &b;

    for (int i = 0; i < 2; i++)
    {
        sensors[i]->readData();
        sensors[i]->displayReport();
    }

    for (int i = 0; i < 2; i++)
    {
        delete sensors[i];
    }

    return 0;
}