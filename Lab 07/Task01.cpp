//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    int deviceID;
    string deviceName;
    bool status;
    string location;

public:
    Device(int id, string name, string loc) : deviceID(id), deviceName(name), location(loc), status(false) {}
    virtual void turnOn() {
        status = true;
    }
    virtual void turnOff() {
        status = false;
    }
    virtual void getStatus() {
        cout << deviceName << " is " << (status ? "On" : "Off") << endl;
    }
    virtual void displayInfo() const {
        cout << "Device ID: " << deviceID << endl;
        cout << "Name: " << deviceName << endl;
        cout << "Location: " << location << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};

class Light : public Device {
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(int id, string name, string loc, int brightness, string color) : Device(id, name, loc), brightnessLevel(brightness), colorMode(color) {}

    void displayInfo() {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel << endl;
        cout << "Color Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device {
private:
    float temperature;
    string mode;
    float targetTemperature;

public:
    Thermostat(int id, string name, string loc, float temp, string m, float target) : Device(id, name, loc), temperature(temp), mode(m), targetTemperature(target) {}

    void getStatus() {
        cout << deviceName << " is " << (status ? "On" : "Off") << endl;
        cout << "Current Temperature: " << temperature << endl;
    }
};

class SecurityCamera : public Device {
private:
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(int id, string name, string loc, string res, bool night) : Device(id, name, loc), resolution(res), nightVisionEnabled(night), recordingStatus(false) {}

    void turnOn() {
        status = true;
        recordingStatus = true;
        cout << deviceName << " is now recording." << endl;
    }
};

class SmartPlug : public Device {
private:
    float powerConsumption;
    int timerSetting;

public:
    SmartPlug(int id, string name, string loc, float power, int timer) : Device(id, name, loc), powerConsumption(power), timerSetting(timer) {}

    void turnOff() {
        status = false;
        cout << deviceName << " turned off. Power usage logged: " << powerConsumption  << endl;
    }
};

int main() {
    Light light1(23, "Light Bulb", "Bedroom", 75, "Yellow Light");
    Thermostat therm1(45, "Home Thermostat", "Drawing Room", 23.4, "Cooling", 26);
    SecurityCamera camera1(67, "Main Gate Cam", "Entrance", "1080p", true);
    SmartPlug plug1(89, "Room Plug", "Main Room", 59.9, 25);

    light1.displayInfo();
    therm1.getStatus();
    camera1.turnOn();
    plug1.turnOff();

    return 0;
}