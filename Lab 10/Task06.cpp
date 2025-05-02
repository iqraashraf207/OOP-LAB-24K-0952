//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main() {
    InventoryItem item1;
    item1.itemID = 101;
    strcpy(item1.itemName, "Wireless Mouse");

    ofstream outfile("inventory.dat", ios::binary);
    if (!outfile) {
        cout << "Error opening file for writing." << endl;
        return 1;
    }
    outfile.write(reinterpret_cast<char*>(&item1), sizeof(item1));
    outfile.close();

    InventoryItem item2;
    ifstream inFile("inventory.dat", ios::binary);
    if (!inFile) {
        cout << "Error opening file for reading." << endl;
        return 1;
    }
    inFile.read(reinterpret_cast<char*>(&item2), sizeof(item2));
    inFile.close();

    cout << "Loaded Item ID: " << item2.itemID << endl;
    cout << "Loaded Item Name: " << item2.itemName << endl;

    return 0;
}