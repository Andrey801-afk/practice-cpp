#include "Driver.h"

Driver::Driver() {
    std::cout << ">>> Вызван конструктор по умолчанию" << std::endl;
    _fullName = "Unknown";
    _age = 0;
    _licenseNumber = "Unknown";
    _category = "Unknown";
    _experience = 0;
}

Driver::Driver(const std::string& fullName, int age, const std::string& licenseNumber,
               const std::string& category, int experience) {
    std::cout << ">>> Вызван конструктор с параметрами" << std::endl;
    _fullName = fullName;
    _age = age;
    _licenseNumber = licenseNumber;
    _category = category;
    _experience = experience;
}

Driver::Driver(const Driver& other) {
    std::cout << ">>> Вызван конструктор копирования" << std::endl;
    _fullName = other._fullName;
    _age = other._age;
    _licenseNumber = other._licenseNumber;
    _category = other._category;
    _experience = other._experience;
}

Driver::~Driver() {
    std::cout << ">>> Удаление водителя (" 
              << _fullName << ")" << std::endl;
}

Driver& Driver::operator=(const Driver& other) {
    std::cout << ">>> Вызван оператор присваивания" << std::endl;
    
    if (this == &other) {
        return *this;
    }
    
    _fullName = other._fullName;
    _age = other._age;
    _licenseNumber = other._licenseNumber;
    _category = other._category;
    _experience = other._experience;
    
    return *this;
}

void Driver::Print() const {
    std::cout << ">>> Информация о водителе" << std::endl;
    std::cout << "  ФИО: " << _fullName << std::endl;
    std::cout << "  Возраст: " << _age << " лет" << std::endl;
    std::cout << "  Номер прав: " << _licenseNumber << std::endl;
    std::cout << "  Категория: " << _category << std::endl;
    std::cout << "  Стаж вождения: " << _experience << " лет" << std::endl;
    std::cout << "  -----------------------------------" << std::endl;
}

std::string Driver::GetFullName() const {
    return _fullName;
}

int Driver::GetAge() const {
    return _age;
}

std::string Driver::GetLicenseNumber() const {
    return _licenseNumber;
}

std::string Driver::GetCategory() const {
    return _category;
}

int Driver::GetExperience() const {
    return _experience;
}

void Driver::SetFullName(const std::string& fullName) {
    _fullName = fullName;
}

void Driver::SetAge(int age) {
    _age = age;
}

void Driver::SetLicenseNumber(const std::string& licenseNumber) {
    _licenseNumber = licenseNumber;
}

void Driver::SetCategory(const std::string& category) {
    _category = category;
}

void Driver::SetExperience(int experience) {
    _experience = experience;
}