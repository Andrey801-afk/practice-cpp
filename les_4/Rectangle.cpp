#include "Rectangle.h"
#include <iostream>
#include <algorithm>

Rectangle::Rectangle() {
    std::cout << ">>>Вызван конструктор по умолчанию" << std::endl;
    _x = 0;
    _y = 0;
    _width = 0;
    _height = 0;
}

Rectangle::Rectangle(double x, double y, double width, double height) {
    std::cout << ">>>Вызван конструктор с параметрами" << std::endl;
    
    if (width <= 0 || height <= 0) {
        std::cout << "Размеры не могут быть <= 0" << std::endl;
        _x = 0;
        _y = 0;
        _width = 1.0;
        _height = 1.0;
    } else {
        _x = x;
        _y = y;
        _width = width;
        _height = height;
    }
}


Rectangle::Rectangle(const Rectangle& other) {
    std::cout << ">>>Вызван конструктор копирования" << std::endl;
    _x = other._x;
    _y = other._y;
    _width = other._width;
    _height = other._height;
}

Rectangle::~Rectangle() {
    std::cout << ">>> прямоугольника (" 
              << _width << "x" << _height << ")" << std::endl;
}


Rectangle& Rectangle::operator=(const Rectangle& other) {
    std::cout << ">>>Вызван оператор присваивания" << std::endl;
    
    if (this == &other) {
        return *this;
    }
    
    _x = other._x;
    _y = other._y;
    _width = other._width;
    _height = other._height;
    
    return *this;
}

Rectangle Rectangle::operator+(const Rectangle& other) const {
    std::cout << ">>>Сложение двух прямоугольников" << std::endl;
    
    if (this->IsEmpty()) {
        return Rectangle(other._x, other._y, other._width, other._height);
    }
    
    if (other.IsEmpty()) {
        return Rectangle(this->_x, this->_y, this->_width, this->_height);
    }
    
    double newWidth = this->_width + other._width;
    double newHeight = this->_height + other._height;
    
    std::cout << "Новые размеры: " << newWidth << "x" << newHeight << std::endl;
    
    return Rectangle(this->_x, this->_y, newWidth, newHeight);
}


Rectangle Rectangle::operator-(const Rectangle& other) const {
    std::cout << ">>>Бинарная разность прямоугольников" << std::endl;
    
    if (this->IsEmpty() || other.IsEmpty()) {
        std::cout << "Один из прямоугольников пустой" << std::endl;
        return Rectangle(this->_x, this->_y, this->_width, this->_height);
    }
    
    double thisLeft = this->_x;
    double thisRight = this->_x + this->_width;
    double thisBottom = this->_y;
    double thisTop = this->_y + this->_height;
    
    double otherLeft = other._x;
    double otherRight = other._x + other._width;
    double otherBottom = other._y;
    double otherTop = other._y + other._height;
    
    bool noIntersection = (thisRight <= otherLeft) || 
                          (thisLeft >= otherRight) || 
                          (thisTop <= otherBottom) || 
                          (thisBottom >= otherTop);
    
    if (noIntersection) {
        return Rectangle(this->_x, this->_y, this->_width, this->_height);
    }
    
    double intersectLeft = std::max(thisLeft, otherLeft);
    double intersectRight = std::min(thisRight, otherRight);
    double intersectBottom = std::max(thisBottom, otherBottom);
    double intersectTop = std::min(thisTop, otherTop);
    
    double intersectWidth = intersectRight - intersectLeft;
    double intersectHeight = intersectTop - intersectBottom;
    
    if (intersectWidth >= this->_width && intersectHeight >= this->_height) {
        return Rectangle();
    }
    
    double newArea = this->GetArea() - (intersectWidth * intersectHeight);
    
    if (newArea <= 0) {
        return Rectangle();
    }
    
    return Rectangle(this->_x, this->_y, 
                     std::max(0.0, this->_width - intersectWidth),
                     std::max(0.0, this->_height - intersectHeight));
}

Rectangle Rectangle::operator-() const {
    std::cout << ">>>Унарное отображение прямоугольника" << std::endl;
    
    if (this->IsEmpty()) {
        return Rectangle();
    }
    
    double newX = -_x - _width;
    double newY = -_y - _height;
    
    std::cout << "Отображение: (" << _x << "," << _y << ") -> (" 
              << newX << "," << newY << ")" << std::endl;
    
    return Rectangle(newX, newY, _width, _height);
}

void Rectangle::Print() const {
    std::cout << ">>>Информация о прямоугольнике" << std::endl;
    
    if (this->IsEmpty()) {
        std::cout << "Прямоугольник: ПУСТОЙ" << std::endl;
        std::cout << "Площадь: 0" << std::endl;
    } else {
        std::cout << "Левый нижний угол: (" << _x << ", " << _y << ")" << std::endl;
        std::cout << "Ширина: " << _width << std::endl;
        std::cout << "Высота: " << _height << std::endl;
        std::cout << "Правый верхний угол: (" << (_x + _width) << ", " << (_y + _height) << ")" << std::endl;
        std::cout << "Площадь: " << this->GetArea() << std::endl;
        std::cout << "Периметр: " << (2 * (_width + _height)) << std::endl;
    }
}

bool Rectangle::IsEmpty() const {
    return (_width <= 0 || _height <= 0);
}

double Rectangle::GetX() const {
    return _x;
}

double Rectangle::GetY() const {
    return _y;
}

double Rectangle::GetWidth() const {
    return _width;
}

double Rectangle::GetHeight() const {
    return _height;
}

double Rectangle::GetArea() const {
    return _width * _height;
}