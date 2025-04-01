//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

class Account {
private:
    int accountNumber;
    double balance;

public:
    Account(int accnum, double bal) : accountNumber(accnum), balance(bal) {}

    friend class Manager;

    friend void transferFunds(Account& from, Account& to, double amount);
};

class Manager {
public:
    void displayAccount(const Account& acc) {
        cout << "Account Number: " << acc.accountNumber << endl;
        cout <<  "Balance: " << acc.balance << endl;
    }

    void deposit(Account& acc, double amount) {
        if (amount > 0) {
            acc.balance += amount;
            cout << amount << " deposited to account " << acc.accountNumber << "." << endl;
            cout << "New Balance: " << acc.balance << endl;
        } else {
            cout << "Amount Invalid." << endl;
        }
    }

    void withdraw(Account& acc, double amount) {
        if (amount > 0 && acc.balance >= amount) {
            acc.balance -= amount;
            cout << amount << " withdrawn from account " << acc.accountNumber << "." << endl;
            cout << "New Balance: " << acc.balance << endl;
        } else {
            cout << "Insufficient Balance or Amount Invalid." << endl;
        }
    }
};

void transferFunds(Account& from, Account& to, double amount) {
    if (amount > 0 && from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << amount << " transferred from account " << from.accountNumber << " to account " << to.accountNumber << endl;
    } else {
        cout << "Transfer Unsuccessful." << endl;
    }
}

int main() {
    Account a1(123, 6000);
    Account a2(145, 2000);
    Manager manager;

    manager.displayAccount(a1);
    manager.displayAccount(a2);

    manager.deposit(a1, 2000);
    manager.withdraw(a2, 400);

    transferFunds(a1, a2, 1900);

    manager.displayAccount(a1);
    manager.displayAccount(a2);

    return 0;
}