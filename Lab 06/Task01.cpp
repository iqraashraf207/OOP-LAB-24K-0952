//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Employee {

protected:
    string name;
    float salary;

public:
    Employee(string n, float s) {
        name = n;
        salary = s;
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : public Employee {

private:
    float bonus;

public:
    Manager(string n, float s, float b) : Employee(n, s) {
        bonus = b;
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
    }
};

int main() {

    Manager m1("Ahmed", 5000.0, 450.0);

    cout << "Manager Details: " << endl;
    m1.displayDetails();

    return 0;
}