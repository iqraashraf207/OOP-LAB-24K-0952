//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Employee{
public:
    string name;
    string designation;

    Employee(string n, string d) : name(n), designation(d) {}

    void display() {
        cout << "Employee Name: " << name << ", Designation: " << designation << endl;
    }
};

class Project{
public:
    string title;
    string deadline;
    Employee* employees[10];
    int employeeCount = 0;

    Project(string t, string d) : title(t), deadline(d) {}

    void addEmployee(Employee* e) {
        if (employeeCount < 10) {
            employees[employeeCount++] = e;
        } else {
            cout << "More employees cannot be added" << endl;
        }
    }

    void display() {
        cout << "Project Title: " << title << endl << "Deadline: " << deadline << endl << "Assigned Employees: " << endl;
        if (employeeCount == 0) {
            cout << "No employees assigned.";
        } else {
            for (int i = 0; i < employeeCount; i++)
            {
                employees[i]->display();
            }
        }
        cout << endl;
    }
};

int main() {
    Employee e1("Amir", "Manager"), e2("Hina", "Executive"), e3("Kiran", "Worker");

    Project p1(" Building Construction", "2025-02-22"), p2("Software Development", "2025-04-30");

    p1.addEmployee(&e1);
    p1.addEmployee(&e2);
    p2.addEmployee(&e2);
    p2.addEmployee(&e3);

    cout << "Project 1 Details:" << endl;
    p1.display();

    cout << "Project 2 Details:" << endl;
    p2.display();

    return 0;
}
