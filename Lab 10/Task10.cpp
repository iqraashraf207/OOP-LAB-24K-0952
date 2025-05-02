//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("data_records.txt");
    if (!outFile) {
        cerr << "Error creating the file" << endl;
        return 1;
    }
    outFile << "Record 1\n";
    outFile << "Record 2\n";
    outFile << "Record 3\n";
    outFile << "Record 4\n";
    outFile.close();

    ifstream inFile("data_records.txt");
    if (!inFile) {
        cerr << "Error opening file for reading" << endl;
        return 1;
    }

    inFile.seekg(20, ios::beg);

    string record;
    getline(inFile, record);
    cout << "Third record: " << record << endl;

    inFile.close();
    return 0;
}