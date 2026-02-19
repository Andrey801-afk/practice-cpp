#include "Triangle.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;

Triangle::Triangle() : _a(0), _b(0), _c(0) {}

Triangle::Triangle(double side1, double side2, double side3) {
    if (!SetSides(side1, side2, side3)) {
        _a = _b = _c = 0;
    }
}

bool Triangle::IsValid(double a, double b, double c) const {
    // Все стороны должны быть положительными
    if (a <= 0 || b <= 0 || c <= 0) {
        return false;
    }
    // Неравенство треугольника: сумма любых двух сторон больше третьей
    if ((a + b <= c) || 
        (a + c <= b) || 
        (b + c <= a)) {
        return false;
    }
    return true;
}

bool Triangle::SetSides(double a, double b, double c) {
    if (IsValid(a, b, c)) {
        _a = a;
        _b = b;
        _c = c;
        return true;
    } else {
        cout << "Невозможно установить стороны (" 
             << a << ", " << b << ", " << c 
             << "). Треугольник с такими параметрами не существует." << endl;
        return false;
    }
}

void Triangle::GetSides(double &a, double &b, double &c) const {
    a = _a;
    b = _b;
    c = _c;
}

bool Triangle::Scale(double factor) {
    if (factor <= 0) {
        cout << "Коэффициент масштабирования должен быть положительным числом." << endl;
        return false;
    }
    
    double newA = _a * factor;
    double newB = _b * factor;
    double newC = _c * factor;

    if (IsValid(newA, newB, newC)) {
        _a = newA;
        _b = newB;
        _c = newC;
        return true;
    }
    return false;
}

double Triangle::GetPerimeter() const {
    if (_a == 0 && _b == 0 && _c == 0) return 0;
    return _a + _b + _c;
}

double Triangle::GetArea() const {
    if (_a == 0 && _b == 0 && _c == 0) return 0;
    double p = GetPerimeter() / 2.0;
    double areaSquared = p * (p - _a) * (p - _b) * (p - _c);
    
    if (areaSquared < 0) return 0;
    return sqrt(areaSquared);
}

void Triangle::GetAngles(double &angleA, double &angleB, double &angleC) const {
    angleA = angleB = angleC = 0.0;
    
    if (_a == 0 || _b == 0 || _c == 0) return;

    double cosA = (_b * _b + _c * _c - _a * _a) / (2 * _b * _c);
    double cosB = (_a * _a + _c * _c - _b * _b) / (2 * _a * _c);
    double cosC = (_a * _a + _b * _b - _c * _c) / (2 * _a * _b);

    cosA = max(-1.0, min(1.0, cosA));
    cosB = max(-1.0, min(1.0, cosB));
    cosC = max(-1.0, min(1.0, cosC));

    angleA = acos(cosA) * (180.0 / PI);
    angleB = acos(cosB) * (180.0 / PI);
    angleC = acos(cosC) * (180.0 / PI);
}

void Triangle::PrintInfo() const {
    double p = GetPerimeter();
    double s = GetArea();
    double A, B, C;
    GetAngles(A, B, C);

    cout << fixed << setprecision(2);
    cout << "Стороны: a=" << _a << ", b=" << _b << ", c=" << _c << endl;
    cout << "Периметр: " << p << endl;
    cout << "Площадь: " << s << endl;
    cout << "Углы: A=" << A << "°, B=" << B << "°, C=" << C << "°" << endl;
    cout << "-------------------------" << endl;
}