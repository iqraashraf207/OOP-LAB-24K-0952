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

        string type, id, name, year, extraData, certification;

        getline(iss, type, ',');
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, year, ',');
        getline(iss, extraData, ',');
        getline(iss, certification, ',');

        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "Extra Data: (" << extraData << " )" << endl;
        cout << "Certification: " << certification << endl;
        cout << endl;
    }

    file.close();
    return 0;
}