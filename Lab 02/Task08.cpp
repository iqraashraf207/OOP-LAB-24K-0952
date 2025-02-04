//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

int main(){

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int** array = new int*[size];

    cout << "Enter " << size << " integers" << endl;
    for (int i = 0; i < size; i++)
    {
        array[i] = new int;
        cout << "Enter "<< i+1 << " integer: ";
        cin >> *array[i];
    }

    cout << "Array elements: "<< endl;
    for (int i = 0; i < size; i++) {
        cout << *array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        delete array[i];
    }
    delete[] array;

    return 0;
}