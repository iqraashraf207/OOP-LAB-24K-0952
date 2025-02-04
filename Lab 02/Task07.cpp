//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

int main(){
    int rowsA;
    int colsA;
    int rowsB;
    int colsB;

    cout << "Enter rows and columns for Matrix A: ";
    cin >> rowsA >> colsA;
    cout << "Enter rows and columns for Matrix B: ";
    cin >> rowsB >> colsB;

    if (colsA != rowsB){
        cout << "Matrix multiplication not possible" << endl;
        return 1;
    }

    int** A = new int*[rowsA];
    int** B = new int*[rowsB];
    int** result = new int*[rowsA];

    for (int i = 0; i < rowsA; i++)
    {
        A[i] = new int[colsA];
    }
    for (int i = 0; i < rowsB; i++)
    {
        B[i] = new int[colsB];
    }
    for (int i = 0; i < rowsA; i++)
    {
        result[i] = new int[colsB];
    }

    cout << "Enter elements of Matrix A: " << endl;
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B: "<< endl;
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    cout << "Multiplication matrix:" << endl;
    for (int i = 0; i < rowsA; i++)
    {
        cout << "|";
        for (int j = 0; j < colsB; j++)
        {
            cout << result[i][j] << "|";
        }
        cout << endl;
    }

    for (int i = 0; i < rowsA; i++)
    {
        delete[] A[i];
    }
    for (int i = 0; i < rowsB; i++)
    {
        delete[] B[i];
    }
    for (int i = 0; i < rowsA; i++)
    {
        delete[] result[i];
    }

    delete[] A;
    delete[] B;
    delete[] result;

    return 0;
}