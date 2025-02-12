//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Wallet{
private:
    string ownerName;
    double totalBalance;
    string transactionHistory[100];
    int transactionCount = 0;

public:
    Wallet(string name, double balance){
        ownerName = name;
        totalBalance = balance;
    }

    void addMoney(double amount){
        if (amount > 0){
            totalBalance += amount;
            cout << "Amount added successfully" << endl;
            transactionHistory[transactionCount++] = "Added: " + to_string(amount);
        } else{
            cout << "Amount invalid" << endl;
        }
    }

    void spendMoney(double amount){
        if (amount > 0 && amount <= totalBalance){
            totalBalance -= amount;
            transactionHistory[transactionCount++] = "Spent: " + to_string(amount);
            cout << "Amount spent successfully" << endl;
        } else if(amount > totalBalance){
            cout << "Insufficient balance" << endl;
        } else{
            cout << "Amount invalid." << endl;
        }
    }

    void displayTransaction(){
        cout << "Transaction History: " << endl;
        if(transactionCount == 0){
            cout << "No transactions."<< endl;
        } else{
            for (int i = 0; i < transactionCount; i++)
        {
            cout << transactionHistory[i] << endl;
        }
        } 
    }
};

int main(){
    Wallet saadWallet("Saad", 7000.0);
    saadWallet.addMoney(4000);
    saadWallet.spendMoney(2500);
    saadWallet.displayTransaction();

    return 0;
}