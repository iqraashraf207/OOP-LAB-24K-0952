//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x1 = 0, double y1 = 0) : x(x1), y(y1) {}

    Vector2D operator+(const Vector2D& other) {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar) {
        return Vector2D(x * scalar, y * scalar);
    }

    friend double dotProduct(const Vector2D& v1, const Vector2D& v2);

    friend ostream& operator<<(ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

double dotProduct(const Vector2D& v1, const Vector2D& v2) {
    return (v1.x * v2.x) + (v1.y * v2.y);
}

int main() {
    Vector2D v1(3, 6);
    Vector2D v2(1, 5);

    cout << "Sum: " << v1 + v2 << endl;
    cout << "Difference: " << v1 - v2 << endl;
    cout << "Scalar Multiplication of v1: " << v1 * 2 << endl;
    cout << "Dot Product: " << dotProduct(v1, v2) << endl;

    return 0;
}