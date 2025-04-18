//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string d, double pr) : dishName(d), price(pr) {}

    virtual void showDetails() = 0;
    virtual void prepare() = 0;

    virtual ~MenuItem() {}
};

class Appetizer : public MenuItem {
public:
    Appetizer(string d, double pr) : MenuItem(d, pr) {}

    void showDetails() {
        cout << "Appetizer: " << dishName << " | Price: " << price << endl;
    }

    void prepare() {
        cout << "Preparing " << dishName << ": Slice vegetables, add dressing, and fry." << endl;
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string d, double pr) : MenuItem(d, pr) {}

    void showDetails() override {
        cout << "Main Course: " << dishName << " | Price: " << price << endl;
    }

    void prepare() override {
        cout << "Preparing " << dishName << ": Marinate, grill, and serve hot." << endl;
    }
};

int main() {
    MenuItem* menu[2];

    menu[0] = new MainCourse("Steak", 2700);
    menu[1] = new Appetizer("Fries", 450);

    for (int i = 0; i < 2; i++)
    {
        menu[i]->showDetails();
        menu[i]->prepare();
        cout << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete menu[i];
    }

    return 0;
}