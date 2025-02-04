//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

int** dma(int rows, int cols){
    int **matrix = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i]=new int[cols];
    }
    return matrix;
}

void matrixInput(int **ptr, int rows, int cols, const string& name){
    cout << "Enter the " << name << " matrix" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter the element for row "<< i+1 << " and col " << j+1 << ":";
            cin >> ptr[i][j];
        } 
    }
}

void displayMatrix(int **ptr, int rows, int cols, const string& name){
    cout << name << " matrix"<< endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "|";
        for (int j = 0; j < cols; j++)
        {
         cout << ptr[i][j] << "|";
        }
        cout << endl;
    }
}

int** addMatrices(int** first, int** second, int rows, int cols){
    int** result = dma(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
    return result;
}

int** subtractMatrices(int** first, int** second, int rows, int cols){
    int** result = dma(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = first[i][j] - second[i][j];
        }
    }
    return result;
}

void freeMemory(int **ptr, int rows){
    for (int i = 0; i < rows; i++)
    {
       delete[] ptr[i];
    }
    delete[] ptr;
}

int main(){

    int rows;
    int cols;
    cout << "Enter the number of rows:";
    cin >> rows;

    cout << "Enter the number of cols:";
    cin >> cols;

    int** first = dma(rows,cols);
    int** second = dma(rows,cols);

    matrixInput(first, rows, cols, "first");
    matrixInput(second, rows, cols, "second");

    int** sumMatrix = addMatrices(first, second, rows, cols);
    int** diffMatrix = subtractMatrices(first, second, rows, cols);

    displayMatrix(first, rows, cols, "First");
    displayMatrix(second, rows, cols, "Second");
    displayMatrix(sumMatrix, rows, cols, "Sum");
    displayMatrix(diffMatrix, rows, cols, "Difference");

    freeMemory(first, rows);
    freeMemory(second, rows);
    freeMemory(sumMatrix, rows);
    freeMemory(diffMatrix, rows);

    return 0;
}