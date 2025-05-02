//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("config.txt");
    if (!outFile) {
        cerr << "Error creating the file" << endl;
        return 1;
    }
    outFile << "AAAAABBBBBCCCCC";
    outFile.close();

    fstream file("config.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Error opening file for updating" << endl;
        return 1;
    }

    file.seekp(5);

    file << "XXXXX";

    file.close();

    ifstream inFile("config.txt");
    if (!inFile) {
        cerr << "Error opening file for reading" << endl;
        return 1;
    }

    string content;
    getline(inFile, content);
    cout << "Updated file content: " << content << endl;

    inFile.close();

    return 0;
}