//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    friend double magnitude(const Complex& c);

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << "(" << c.real << (c.imag >= 0 ? " + " : " - ") << fabs(c.imag) << "i)";
        return os;
    }
};

double magnitude(const Complex& c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

int main() {
    Complex c1(8, -3);
    Complex c2(-2, 5);

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    cout << "Addition: " << c1 + c2 << endl;
    cout << "Subtraction: " << c1 - c2 << endl;
    cout << "Multiplication: " << c1 * c2 << endl;
    cout << "Division: " << c1 / c2 << endl;
    cout << "Magnitude of c1: " << magnitude(c1) << endl;

    return 0;
}