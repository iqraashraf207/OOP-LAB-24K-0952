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

        if (!yearStr.empty()) {
            yearStr.erase(0, yearStr.find_first_not_of(" \t"));
            yearStr.erase(yearStr.find_last_not_of(" \t") + 1);

            int year = stoi(yearStr);

            cout << "Type: " << type << endl;
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Year (int): " << year << endl;
            cout << "Extra Data: (" << extraData << " )" << endl;
            cout << "Certification: " << certification << endl;
            cout << endl;
        } else {
            cout << "Year field is empty for line: " << line << endl;
        }
    }

    file.close();
    return 0;
}