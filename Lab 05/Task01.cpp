//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <cstring>
using namespace std;

class Apartment {
public:
    int ID;
    string address;
    char* ownerName;

    Apartment(int id, string add, char* name) {
        ID = id;
        address = add;
        ownerName = new char[strlen(name) + 1];
        strcpy(ownerName, name);
    }

    Apartment(const Apartment &obj) {
        ID = obj.ID;
        address = obj.address;
        ownerName = obj.ownerName;
    }

    void display() {
        cout << "Apartment ID: " << ID << ", Address: " << address << ", Owner name: " << ownerName << endl;
    }

    ~Apartment() {
        delete[] ownerName;
    }
};

int main() {
    Apartment apt1(100, "Main Road", "Hina");
    cout << "Original Apartment:" << endl;
    apt1.display();

    Apartment apt2(apt1);
    cout << "Copied Apartment:" << endl;
    apt2.display();

    return 0;
}