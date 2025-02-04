//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

struct Employee{
    string name;
    int hoursWorked;
    double hourlyRate;
};

void employeesInput(Employee* employees, int numEmployees){
    for (int i = 0; i < numEmployees; i++) {
        cout << "Enter details for Employee " << i+1 << ":" << endl;
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Hours Worked: ";
        cin >> employees[i].hoursWorked;
        cout << "Hourly Rate: ";
        cin >> employees[i].hourlyRate;
    }
}

void displayEmployees(Employee* employees, int numEmployees){
    cout << "Employee Salary Details: " << endl;
    for (int i = 0; i < numEmployees; i++)
    {
        double totalSalary = employees[i].hoursWorked*employees[i].hourlyRate;
        cout << "Name: " << employees[i].name << endl << "Hours Worked: " << employees[i].hoursWorked << endl << "Hourly Rate: " << employees[i].hourlyRate<< endl << "Total Salary: " << totalSalary << endl;
    }
}

int main() {
    int numofEmployees;

    cout << "Enter the number of employees: ";
    cin >> numofEmployees;

    Employee* employees = new Employee[numofEmployees];

    employeesInput(employees, numofEmployees);
    displayEmployees(employees, numofEmployees);

    delete[] employees;

    return 0;
}
