//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Device {

protected:
    int deviceID;
    bool status;

public:
    Device(int id, bool stat) : deviceID(id), status(stat) {}

    void displayDetails() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : virtual public Device {

protected:
    float screenSize;

public:
    SmartPhone(int id, bool stat, float s) 
        : Device(id, stat), screenSize(s) {}

    void displayDetails() {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize  << endl;
    }
};

class SmartWatch : virtual public Device {

protected:
    bool heartRateMonitor;

public:
    SmartWatch(int id, bool stat, bool monitor) 
        : Device(id, stat), heartRateMonitor(monitor) {}

    void displayDetails() {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {

private:
    int stepCounter;

public:
    SmartWearable(int id, bool stat, float s, bool monitor, int step) 
        : Device(id, stat), SmartPhone(id, stat, s), SmartWatch(id, stat, monitor), stepCounter(step) {}

    void displayDetails() {
        SmartPhone::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
        cout << "Step Counter: " << stepCounter << endl;
    }
};

int main() {

    SmartWearable smart(011, 1, 7, 1, 60);

    cout << "Smart Wearable Device Details:" << endl;
    smart.displayDetails();

    return 0;
}