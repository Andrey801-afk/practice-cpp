#include <iostream>
#include "Triangle.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "=== Демонстрация работы класса Triangle ===" << endl << endl;

    Triangle tr1;
    cout << "1. Попытка создать невозможный треугольник (1, 2, 10):" << endl;
    tr1.SetSides(1, 2, 10);
    cout << endl;

    cout << "2. Установка корректных сторон (3, 4, 5):" << endl;
    if (tr1.SetSides(3, 4, 5)) {
        cout << "Треугольник создан." << endl;
        tr1.PrintInfo();
    }
    cout << endl;

    cout << "3. Чтение свойств через метод GetSides:" << endl;
    double x, y, z;
    tr1.GetSides(x, y, z);
    cout << "Полученные значения: " << x << ", " << y << ", " << z << endl;
    cout << endl;

    cout << "4. Увеличение размера сторон в 2 раза:" << endl;
    if (tr1.Scale(2.0)) {
        tr1.PrintInfo();
    }
    cout << endl;

    cout << "5. Уменьшения с некорректным коэффициентом (-1):" << endl;
    tr1.Scale(-1);
    cout << endl;

    cout << "6. Создание треугольника через конструктор (10, 10, 10):" << endl;
    Triangle tr2(10, 10, 10);
    tr2.PrintInfo();

    return 0;
}