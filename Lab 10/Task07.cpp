//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream sensorFile("sensor_log.txt");
    if (!sensorFile) {
        cerr << "Error opening file for writing" << endl;
        return 1;
    }

    sensorFile << "First Sensor Input ";
    streampos pos1 = sensorFile.tellp();
    cout << "Position after first write: " << pos1 << endl;

    sensorFile << "Second Sensor Input";
    streampos pos2 = sensorFile.tellp();
    cout << "Position after second write: " << pos2 << endl;

    sensorFile.close();

    return 0;
}