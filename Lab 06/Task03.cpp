//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Person {

protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : virtual public Person {

protected:
    string subject;

public:
    Teacher(string n, int a, string sub) : Person(n, a), subject(sub) {}

    void displayDetails() {
        Person::displayDetails();
        cout << "Subject Expertise: " << subject << endl;
    }
};

class Researcher : virtual public Person {

protected:
    string researchArea;

public:
    Researcher(string n, int a, string ra) : Person(n, a), researchArea(ra) {}

    void displayDetails() {
        Person::displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {

private:
    int publications;

public:
    Professor(string n, int a, string sub, string ra, int pub) 
        : Person(n, a), Teacher(n, a, sub), Researcher(n, a, ra), publications(pub) {}

    void displayDetails() {
        Person::displayDetails();
        cout << "Subject Expertise: " << subject << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main() {

    Professor prof("Hina Ali", 26, "Biology", "Gene Mutation", 07);

    cout << "Professor Details:" << endl;
    prof.displayDetails();

    return 0;
}