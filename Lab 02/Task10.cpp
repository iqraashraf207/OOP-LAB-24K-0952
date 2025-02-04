//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

int main(){
    int x, y, z;

    cout << "Enter dimensions for 3D array: " << endl;
    cin >> x >> y >> z;

    int*** array = new int**[x];
    for (int i = 0; i < x; i++)
    {
        array[i] = new int*[y];
        for (int j = 0; j < y; j++)
        {
            array[i][j] = new int[z];
        }
    }

    cout << "Enter " << (x * y * z) << " elements:" << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cin >> array[i][j][k];
            }
        }
    }

    cout << "Elements of 3D array:\n";
    for (int i = 0; i < x; i++)
    {
        cout << "-------" << endl;
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << array[i][j][k] << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
