//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    Patient(string n, string i) : name(n), id(i) {}

    virtual void displayTreatment() = 0;
    virtual void calculateCost() = 0;

    virtual ~Patient() {}
};

class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() {
        cout << "InPatient Treatment Plan for " << name << ", ID is " << id << ": Surgery, ICU care, Medication." << endl;
    }

    void calculateCost() {
        cout << "Total cost for InPatient " << name << " is: 5000" << endl;
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() {
        cout << "OutPatient Treatment Plan for " << name << ", ID is " << id << ": Consultation, Medical tests." << endl;
    }

    void calculateCost() {
        cout << "Total cost for OutPatient " << name << " is: 500" << endl;
    }
};

int main() {
    Patient* patients[2];

    patients[0] = new InPatient("Ahmed", "1234");
    patients[1] = new OutPatient("Sarah", "5678");

    for (int i = 0; i < 2; i++)
    {
        patients[i]->displayTreatment();
        patients[i]->calculateCost();
        cout << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete patients[i];
    }

    return 0;
}