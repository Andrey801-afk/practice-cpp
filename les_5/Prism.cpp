#include "Prism.h"
#include <iomanip>

Prism::Prism() : Square() {
    std::cout << ">>> Вызван конструктор по умолчанию" << std::endl;
    _height = 0;
}

Prism::Prism(double side, double height) : Square(side) {
    std::cout << ">>> Вызван конструктор с параметрами" << std::endl;
    
    if (height < 0) {
        std::cout << "Высота не может быть отрицательной" << std::endl;
        _height = 0;
    } else {
        _height = height;
    }
}

Prism::Prism(const Prism& other) : Square(other) {
    std::cout << ">>> Вызван конструктор копирования" << std::endl;
    _height = other._height;
}

Prism::~Prism() {
    std::cout << ">>> Удаление призмы, сторона которого равняется: " 
              << _side << ", а высота=" << _height << std::endl;
}

Prism& Prism::operator=(const Prism& other) {
    std::cout << ">>> Вызван оператор присваивания" << std::endl;
    
    if (this == &other) {
        return *this;
    }
    
    Square::operator=(other); 
    _height = other._height;
    
    return *this;
}

double Prism::GetArea() const {
    double baseArea = _side * _side;          
    double sideArea = _side * _height;        
    return 2 * baseArea + 4 * sideArea;       
}

void Prism::Print() const {
    std::cout << ">>> нформация о призме" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "  Сторона основания: " << _side << std::endl;
    std::cout << "  Высота: " << _height << std::endl;
    std::cout << "  Диагональ основания: " << this->GetDiagonal() << std::endl;
    std::cout << "  Периметр основания: " << this->GetPerimeter() << std::endl;
    std::cout << "  Площадь поверхности: " << this->GetArea() << std::endl;
    std::cout << "  Объём: " << this->GetVolume() << std::endl;
    std::cout << "  -----------------------------------" << std::endl;
}

double Prism::GetVolume() const {
    return _side * _side * _height;
}

double Prism::GetHeight() const {
    return _height;
}

void Prism::SetHeight(double height) {
    if (height < 0) {
        std::cout << "Высота не может быть отрицательной" << std::endl;
    } else {
        _height = height;
    }
}