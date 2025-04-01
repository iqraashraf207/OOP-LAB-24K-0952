//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

class Matrix2x2 {
private:
    int e1, e2, e3, e4;

public:
    Matrix2x2(int e1 = 0, int e2 = 0, int e3 = 0, int e4 = 0) : e1(e1), e2(e2), e3(e3), e4(e4) {}

    Matrix2x2 operator+(const Matrix2x2& other) {
        return Matrix2x2(e1 + other.e1, e2 + other.e2, e3 + other.e3, e4 + other.e4);
    }

    Matrix2x2 operator-(const Matrix2x2& other) {
        return Matrix2x2(e1 - other.e1, e2 - other.e2, e3 - other.e3, e4 - other.e4);
    }

    Matrix2x2 operator*(const Matrix2x2& other) {
        return Matrix2x2(
            e1 * other.e1 + e2 * other.e3, e1 * other.e2 + e2 * other.e4, e3 * other.e1 + e4 * other.e3, e3 * other.e2 + e4 * other.e4
        );
    }

    friend int determinant(const Matrix2x2& matrix);

    friend class MatrixHelper;

    friend ostream& operator<<(ostream& os, const Matrix2x2& matrix) {
        os << "|" << matrix.e1 << "|" << matrix.e2 << "|" << endl;
        os << "|" << matrix.e3 << "|" << matrix.e4 << "|" << endl;
        return os;
    }
};

int determinant(const Matrix2x2& matrix) {
    return (matrix.e1 * matrix.e4) - (matrix.e2 * matrix.e3);
}

class MatrixHelper {
public:
    void updateElement(Matrix2x2& matrix, int row, int col, int value) {
        if (row == 0 && col == 0) {
            matrix.e1 = value;
        }
        else if (row == 0 && col == 1) {
            matrix.e2 = value;
        }
        else if (row == 1 && col == 0) {
            matrix.e3 = value;
        }
        else if (row == 1 && col == 1) {
            matrix.e4 = value;
        }
        else cout << "Invalid Index." << endl;
    }
};

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);
    
    cout << "Sum: " << endl << m1 + m2 << endl;
    cout << "Difference: " << endl << m1 - m2 << endl;
    cout << "Product: " << endl << m1 * m2 << endl;
    cout << "Determinant of m1: " << determinant(m1) << endl;

    MatrixHelper helper;
    helper.updateElement(m1, 0, 1, 10);
    cout << "Updated m1:" << endl << m1 << endl;
    
    return 0;
}