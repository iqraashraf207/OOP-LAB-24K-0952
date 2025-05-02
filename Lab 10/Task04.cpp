//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream file("vehicles.txt");

    if (!file.is_open()) {
        cout << "Error: Unable to open vehicles.txt" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        if (line[0] == '#') {
            continue;
        }

        istringstream iss(line);
        string type, id, name, yearStr, extraData, certification;

        getline(iss, type, ',');
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, yearStr, ',');
        getline(iss, extraData, ',');
        getline(iss, certification, ',');

        if (type == "AutonomousCar") {
            size_t colonPos = extraData.find(':');
            if (colonPos != string::npos) {
                string versionStr = extraData.substr(colonPos + 1);
                float softwareVersion = stof(versionStr);
                cout << "Vehicle ID: " << id << " | Software Version: " << softwareVersion << endl;
            } else {
                cout << "':' not found in ExtraData for AutonomousCar with ID " << id << endl;
            }
        }
        else if (type == "Electric Vehicle") {
            size_t colonPos = extraData.find(':');
            if (colonPos != string::npos) {
                string batteryStr = extraData.substr(colonPos + 1);
                int batteryCapacity = stoi(batteryStr);
                cout << "Vehicle ID: " << id << " | Battery Capacity: " << batteryCapacity << endl;
            } else {
                cout << "':' not found in ExtraData for Electric Vehicle with ID " << id << endl;
            }
        }
    }

    file.close();
    return 0;
}
