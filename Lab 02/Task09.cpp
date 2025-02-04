//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

struct Product{
    int productID;
    string name;
    int quantity;
    double price;
};

int main(){
    int numofProducts;
    double totalValue = 0;

    cout << "Enter the number of products: ";
    cin >> numofProducts;

    Product* inventory = new Product[numofProducts];

    for (int i = 0; i < numofProducts; i++) {
        cout << "Enter " << i+1 << " product details "<< ":" << endl;
        cout << "Product ID: ";
        cin >> inventory[i].productID;
        cout << "Product Name: ";
        cin >> inventory[i].name;
        cout << "Quantity: ";
        cin >> inventory[i].quantity;
        cout << "Price: ";
        cin >> inventory[i].price;

        totalValue += (inventory[i].quantity*inventory[i].price);
    }

    cout << "Total value of inventory: " << totalValue << endl;

    delete[] inventory;

    return 0;
}