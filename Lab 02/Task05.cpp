//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

int main(){
    int numofElements;

    cout << "Enter the number of elements: ";
    cin >> numofElements;

    int* array = new int[numofElements];

    for (int i = 0; i < numofElements; i++)
    {
        cout << "Enter "<< i+1 << " element: ";
        cin >> *(array+i);
    }

    cout << "Array elements: ";
    for (int i = 0; i < numofElements; i++)
    {
        cout << *(array+i) << " ";
    }
    cout << endl;

    int sum = 0;
    int* ptr = array;
    for (int i = 0; i < numofElements; i++)
    {
        sum += *(ptr+i);
    }

    cout << "Sum of array elements: " << sum << endl;

    delete[] array;

    return 0;
}
