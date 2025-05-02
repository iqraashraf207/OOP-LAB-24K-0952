//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <sstream>
#include <exception>

using namespace std;

class DimensionMismatchException : public exception {
    string message;
public:
    DimensionMismatchException(int r1, int c1, int r2, int c2) {
        stringstream ss;
        ss << "DimensionMismatchException: (" << r1 << "x" << c1 << ") + (" << r2 << "x" << c2 << ")!";
        message = ss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class Matrix {
private:
    int rows, cols;
    T** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols];
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    void inputMatrix() {
        cout << "Enter elements for a " << rows << "x" << cols << " matrix:" << endl;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                cin >> data[i][j];
    }

    void display() const {
        cout << "Matrix (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);

        cout << "Matrix A" << endl;
        A.inputMatrix();
        cout << "Matrix B" << endl;
        B.inputMatrix();

        Matrix<int> C = A + B;
        C.display();
    }
    catch (const DimensionMismatchException& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}