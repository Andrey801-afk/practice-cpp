#include "Transport.h"

Transport::Transport() {
    std::cout << ">>> Вызван конструктор по умолчанию" << std::endl;
    _brand = "Unknown";
    _model = "Unknown";
    _year = 0;
    _maxSpeed = 0;
}

Transport::Transport(const std::string& brand, const std::string& model, int year, double maxSpeed) {
    std::cout << ">>> Вызван конструктор с параметрами" << std::endl;
    _brand = brand;
    _model = model;
    _year = year;
    _maxSpeed = maxSpeed;
}

Transport::Transport(const Transport& other) {
    std::cout << ">>> Вызван конструктор копирования" << std::endl;
    _brand = other._brand;
    _model = other._model;
    _year = other._year;
    _maxSpeed = other._maxSpeed;
}

Transport::~Transport() {
    std::cout << ">>> Удаление транспорта (" 
              << _brand << " " << _model << ")" << std::endl;
}

Transport& Transport::operator=(const Transport& other) {
    std::cout << ">>> Вызван оператор присваивания" << std::endl;
    
    if (this == &other) {
        return *this;
    }
    
    _brand = other._brand;
    _model = other._model;
    _year = other._year;
    _maxSpeed = other._maxSpeed;
    
    return *this;
}

void Transport::Print() const {
    std::cout << ">>> Информация о транспорте" << std::endl;
    std::cout << "  Марка: " << _brand << std::endl;
    std::cout << "  Модель: " << _model << std::endl;
    std::cout << "  Год выпуска: " << _year << std::endl;
    std::cout << "  Максимальная скорость: " << _maxSpeed << " км/ч" << std::endl;
    std::cout << "  -----------------------------------" << std::endl;
}

std::string Transport::GetBrand() const {
    return _brand;
}

std::string Transport::GetModel() const {
    return _model;
}

int Transport::GetYear() const {
    return _year;
}

double Transport::GetMaxSpeed() const {
    return _maxSpeed;
}

void Transport::SetBrand(const std::string& brand) {
    _brand = brand;
}

void Transport::SetModel(const std::string& model) {
    _model = model;
}

void Transport::SetYear(int year) {
    _year = year;
}

void Transport::SetMaxSpeed(double maxSpeed) {
    _maxSpeed = maxSpeed;
}