//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("large_log.txt");
    if (!outFile) {
        cerr << "Error creating the file" << endl;
        return 1;
    }
    outFile << "This is the first part of the file." << endl;
    outFile << "This is the second part of the file." << endl;
    outFile << "This is the third part of the sentence." << endl;
    outFile.close();

    ifstream inFile("large_log.txt");
    if (!inFile) {
        cerr << "Error opening file for reading" << endl;
        return 1;
    }

    char buffer[11];
    buffer[10] = '\0';

    inFile.read(buffer, 10);
    cout << "First 10 characters: " << buffer << endl;
    cout << "Position after first read: " << inFile.tellg() << endl;

    inFile.read(buffer, 10);
    cout << "Next 10 characters: " << buffer << endl;
    cout << "Position after second read: " << inFile.tellg() << endl;

    inFile.close();
    return 0;
}