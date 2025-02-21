//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class AlarmSystem {
public:
    string level;

    AlarmSystem(string l) : level(l) {}

    void display() {
        cout << "Security Level: " << level << endl;
    }
};

class SmartHome {
public:
    AlarmSystem alarm;

    SmartHome(string l) : alarm(l) {}

    void display() {
        cout << "Smart Home Security Details:" << endl;
        alarm.display();
    }
};

int main() {
    SmartHome home("High");

    home.display();

    return 0;
}