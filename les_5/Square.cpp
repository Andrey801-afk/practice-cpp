#include "Square.h"
#include <cmath>
#include <iomanip>

Square::Square() {
    std::cout << ">>> Вызван конструктор по умолчанию" << std::endl;
    _side = 0;
}

Square::Square(double side) {
    std::cout << ">>> Вызван конструктор с параметром" << std::endl;
    
    if (side < 0) {
        std::cout << "Cторона не может быть отрицательной" << std::endl;
        _side = 0;
    } else {
        _side = side;
    }
}

Square::Square(const Square& other) {
    std::cout << ">>> Вызван конструктор копирования" << std::endl;
    _side = other._side;
}

Square::~Square() {
    std::cout << ">>> Удаление квадрата, сторона которового равняется: " 
              << _side << std::endl;
}

Square& Square::operator=(const Square& other) {
    std::cout << ">>> Вызван оператор присваивания" << std::endl;
    
    if (this == &other) {
        return *this;
    }
    
    _side = other._side;
    return *this;
}

double Square::GetDiagonal() const {
    return _side * std::sqrt(2);
}

double Square::GetPerimeter() const {
    return 4 * _side;
}

double Square::GetArea() const {
    return _side * _side;
}

void Square::Print() const {
    std::cout << ">>> Информация о квадрате" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "  Сторона: " << _side << std::endl;
    std::cout << "  Диагональ: " << this->GetDiagonal() << std::endl;
    std::cout << "  Периметр: " << this->GetPerimeter() << std::endl;
    std::cout << "  Площадь: " << this->GetArea() << std::endl;
    std::cout << "  -----------------------------------" << std::endl;
}

double Square::GetSide() const {
    return _side;
}

void Square::SetSide(double side) {
    if (side < 0) {
        std::cout << "Сторона не может быть отрицательной" << std::endl;
    } else {
        _side = side;
    }
}