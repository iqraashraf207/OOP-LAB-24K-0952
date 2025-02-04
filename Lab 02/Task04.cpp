//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

void bubbleSort(string* arr, int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                string temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int numofStrings;

    cout << "Enter the number of strings: ";
    cin >> numofStrings;

    string* array = new string[numofStrings];

    cout << "Enter " << numofStrings << " strings:\n";
    for (int i = 0; i < numofStrings; i++)
    {
        cout << "String " << i+1 << ": ";
        cin >> array[i];
    }

    bubbleSort(array, numofStrings);

    cout << "Sorted Strings:" << endl;
    for (int i = 0; i < numofStrings; i++)
    {
        cout << array[i] << endl;
    }

    delete[] array;

    return 0;
}
