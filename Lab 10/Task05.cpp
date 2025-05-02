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
        cout << "Error opening the file" << endl;
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
        else if (type == "HybridTruck") {
            size_t cargoColonPos = extraData.find(':');
            size_t pipePos = extraData.find('|');
            size_t batteryColonPos = extraData.find(':', pipePos);

            if (cargoColonPos != string::npos && pipePos != string::npos && batteryColonPos != string::npos) {
                string cargoStr = extraData.substr(cargoColonPos + 1, pipePos - cargoColonPos - 1);
                int cargoCapacity = stoi(cargoStr);

                string batteryStr = extraData.substr(batteryColonPos + 1);
                int batteryCapacity = stoi(batteryStr);

                cout << "Vehicle ID: " << id << " | Cargo Capacity: " << cargoCapacity << " | Battery Capacity: " << batteryCapacity << endl;
            } else {
                cout << "Problem parsing ExtraData for HybridTruck with ID " << id << endl;
            }
        }
        else {
            cout << "Unknown vehicle type '" << type << "' for ID " << id << endl;
        }
    }

    file.close();
    return 0;
}