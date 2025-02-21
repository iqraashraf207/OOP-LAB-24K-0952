//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Doctor {
public:
    string name;
    string specialization;
    int experience;

    Doctor(string n, string s, int e) : name(n), specialization(s), experience(e) {}

    void display() {
        cout << "Doctor Name: " << name << ", Specialization: " << specialization << ", Experience: " << experience << " years" << endl;
    }
};

class Hospital {
public:
    string hospitalName;
    Doctor* doctors[10];
    int doctorCount = 0;

    Hospital(string name) : hospitalName(name) {}

    void addDoctor(Doctor* d) {
        if (doctorCount < 10) {
            doctors[doctorCount++] = d;
        } else {
            cout << "More doctors cannot be added" << endl;
        }
    }

    void display() {
        cout << "Hospital Name: " << hospitalName << endl;
        cout << "Doctors Working:"<< endl;
        if (doctorCount == 0) {
            cout << "No doctors assigned.";
        } else {
            for (int i = 0; i < doctorCount; i++)
            {
                doctors[i]->display();
            }
        }
        cout << endl;
    }
};

int main() {
    Doctor d1("Dr. Ahmar", "Dermatologist", 7);
    Doctor d2("Dr. Hina", "Neurologist", 11);
    Doctor d3("Dr. Kainat", "Heart Surgeon", 8);

    Hospital h1("City Hospital");
    Hospital h2("Liaquat National Hospital");

    h1.addDoctor(&d1);
    h1.addDoctor(&d2);
    h2.addDoctor(&d2);
    h2.addDoctor(&d3);

    h1.display();
    h2.display();

    return 0;
}