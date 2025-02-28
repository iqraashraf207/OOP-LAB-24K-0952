//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Account {

protected:
    int accountNumber;
    float balance;

public:
    Account(int num, float bal) : accountNumber(num), balance(bal) {}

    void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {

private:
    float interestRate;

public:
    SavingsAccount(int num, float bal, float r) 
        : Account(num, bal), interestRate(r) {}

    void displayDetails() {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    CheckingAccount(int num, float bal, float l) 
        : Account(num, bal), overdraftLimit(l) {}

    void displayDetails() {
        Account::displayDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {

    SavingsAccount s(1234, 7000.0, 5);

    CheckingAccount c(1234, 7000.0, 3);

    cout << "Savings Account Details:" << endl;
    s.displayDetails();
    
    cout << "Checking Account Details:" << endl;
    c.displayDetails();

    return 0;
}