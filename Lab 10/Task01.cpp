//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <fstream>
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
        cout << line << endl;
    }

    file.close();
    return 0;
}