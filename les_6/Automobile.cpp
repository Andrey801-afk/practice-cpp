#include "Automobile.h"

Automobile::Automobile() : Transport() {
    std::cout << ">>> Вызван конструктор по умолчанию" << std::endl;
    _doors = 0;
    _color = "Unknown";
    _licensePlate = "Unknown";
}

Automobile::Automobile(const std::string& brand, const std::string& model, int year,
                       double maxSpeed, int doors, const std::string& color, const std::string& licensePlate)
    : Transport(brand, model, year, maxSpeed) {
    std::cout << ">>> Вызван конструктор с параметрами" << std::endl;
    _doors = doors;
    _color = color;
    _licensePlate = licensePlate;
}

Automobile::Automobile(const Automobile& other) : Transport(other) {
    std::cout << ">>> Вызван конструктор копирования" << std::endl;
    _doors = other._doors;
    _color = other._color;
    _licensePlate = other._licensePlate;
}

Automobile::~Automobile() {
    std::cout << ">>> Удаление автомобиля (" 
              << _brand << " " << _model << ")" << std::endl;
}

Automobile& Automobile::operator=(const Automobile& other) {
    std::cout << ">>> Вызван оператор присваивания" << std::endl;
    
    if (this == &other) {
        return *this;
    }
    
    Transport::operator=(other);
    _doors = other._doors;
    _color = other._color;
    _licensePlate = other._licensePlate;
    
    return *this;
}

void Automobile::Print() const {
    std::cout << ">>> Информация об автомобиле" << std::endl;
    std::cout << "  Марка: " << _brand << std::endl;
    std::cout << "  Модель: " << _model << std::endl;
    std::cout << "  Год выпуска: " << _year << std::endl;
    std::cout << "  Максимальная скорость: " << _maxSpeed << " км/ч" << std::endl;
    std::cout << "  Количество дверей: " << _doors << std::endl;
    std::cout << "  Цвет: " << _color << std::endl;
    std::cout << "  Номерной знак: " << _licensePlate << std::endl;
    std::cout << "  -----------------------------------" << std::endl;
}

int Automobile::GetDoors() const {
    return _doors;
}

std::string Automobile::GetColor() const {
    return _color;
}

std::string Automobile::GetLicensePlate() const {
    return _licensePlate;
}

void Automobile::SetDoors(int doors) {
    _doors = doors;
}

void Automobile::SetColor(const std::string& color) {
    _color = color;
}

void Automobile::SetLicensePlate(const std::string& licensePlate) {
    _licensePlate = licensePlate;
}