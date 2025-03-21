//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n, int a, string contact, string addr) : name(n), age(a), contactNumber(contact), address(addr) {}
    
    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "Address: " << address << endl;
    }
    
    virtual void updateInfo(string Contact2, string Address2) {
        contactNumber = Contact2;
        address = Address2;
    }
    
};

class Patient : public Person {
private:
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string n, int a, string contact, string addr, int id, string history, string doctor) : Person(n, a, contact, addr), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}
    
    void displayInfo() {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << endl;
        cout << "Medical History: " << medicalHistory << endl;
        cout << "Doctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
private:
    string specialization;
    double consultationFee;
    string patientsList;

public:
    Doctor(string n, int a, string contact, string addr, string spec, double fee, string patients) : Person(n, a, contact, addr), specialization(spec), consultationFee(fee), patientsList(patients) {}
    
    void displayInfo() {
        Person::displayInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Consultation Fee: " << consultationFee << endl;
        cout << "Patients List: " << patientsList << endl;
    }
};

class Nurse : public Person {
private:
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n, int a, string contact, string addr, string ward, string shift) : Person(n, a, contact, addr), assignedWard(ward), shiftTimings(shift) {}
    
    void displayInfo(){
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
private:
    string department;
    double salary;

public:
    Administrator(string n, int a, string contact, string addr, string dept, double sal) : Person(n, a, contact, addr), department(dept), salary(sal) {}
    
    void updateInfo(string Contact2, string Address2, double Salary2) {
        Person::updateInfo(Contact2, Address2);
        salary = Salary2;
    }
};

int main() {
    Patient patient("Hamid Sheikh", 40, "123-456-7890", "123 Street", 101, "Diabetes", "Dr. Sana Khan");
    Doctor doctor("Dr. Sana Khan", 55, "987-654-3210", "XYZ Street", "Cardiology", 150.0, "John Doe, Jane Roe");
    Nurse nurse("Khalid", 25, "543-567-1110", "345 Street", "ER", "Night Shift");
    Administrator admin("Ahmar", 40, "166-255-3440", "ABC street", "HR", 5000.0);

    patient.displayInfo();
    cout << endl;
    doctor.displayInfo();
    cout << endl;
    nurse.displayInfo();
    cout << endl;
    
    return 0;
}