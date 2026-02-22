#include "CarDriver.h"
#include <iomanip>

CarDriver::CarDriver() : Driver(), Automobile() {
    std::cout << ">>> Вызван конструктор по умолчанию" << std::endl;
    _employeeId = "Unknown";
    _rating = 0.0;
}

CarDriver::CarDriver(const std::string& fullName, int age, const std::string& licenseNumber,
                     const std::string& category, int experience,
                     const std::string& brand, const std::string& model, int year,
                     double maxSpeed, int doors, const std::string& color,
                     const std::string& licensePlate,
                     const std::string& employeeId, double rating)
    : Transport(brand, model, year, maxSpeed),
      Driver(fullName, age, licenseNumber, category, experience),
      Automobile(brand, model, year, maxSpeed, doors, color, licensePlate) {
    std::cout << ">>> Вызван конструктор с параметрами" << std::endl;
    _employeeId = employeeId;
    _rating = rating;
}

CarDriver::CarDriver(const CarDriver& other) 
    : Transport(other), Driver(other), Automobile(other) {
    std::cout << ">>> Вызван конструктор копирования" << std::endl;
    _employeeId = other._employeeId;
    _rating = other._rating;
}

CarDriver::~CarDriver() {
    std::cout << ">>> Удаление водителя автомобиля (" 
              << _fullName << ")" << std::endl;
}

CarDriver& CarDriver::operator=(const CarDriver& other) {
    std::cout << ">>> Вызван оператор присваивания" << std::endl;
    
    if (this == &other) {
        return *this;
    }
    
    Transport::operator=(other);
    Driver::operator=(other);
    Automobile::operator=(other);
    _employeeId = other._employeeId;
    _rating = other._rating;
    
    return *this;
}

void CarDriver::Print() const {
    std::cout << ">>> Информация о водителе автомобиля" << std::endl;
    std::cout << std::endl;
    
    std::cout << "  === ИНФОРМАЦИЯ О ВОДИТЕЛЕ ===" << std::endl;
    std::cout << "  ФИО: " << _fullName << std::endl;
    std::cout << "  Возраст: " << _age << " лет" << std::endl;
    std::cout << "  Номер прав: " << _licenseNumber << std::endl;
    std::cout << "  Категория: " << _category << std::endl;
    std::cout << "  Стаж вождения: " << _experience << " лет" << std::endl;
    std::cout << std::endl;
    
    std::cout << "  === ИНФОРМАЦИЯ ОБ АВТОМОБИЛЕ ===" << std::endl;
    std::cout << "  Марка: " << _brand << std::endl;
    std::cout << "  Модель: " << _model << std::endl;
    std::cout << "  Год выпуска: " << _year << std::endl;
    std::cout << "  Максимальная скорость: " << _maxSpeed << " км/ч" << std::endl;
    std::cout << "  Количество дверей: " << _doors << std::endl;
    std::cout << "  Цвет: " << _color << std::endl;
    std::cout << "  Номерной знак: " << _licensePlate << std::endl;
    std::cout << std::endl;
    
    std::cout << "  === ДОПОЛНИТЕЛЬНАЯ ИНФОРМАЦИЯ ===" << std::endl;
    std::cout << "  Табельный номер: " << _employeeId << std::endl;
    std::cout << "  Рейтинг водителя: " << std::fixed << std::setprecision(1) << _rating << std::endl;
    std::cout << "  -----------------------------------" << std::endl;
}

// ============================================================
// ГЕТТЕРЫ
// ============================================================
std::string CarDriver::GetEmployeeId() const {
    return _employeeId;
}

double CarDriver::GetRating() const {
    return _rating;
}

// ============================================================
// СЕТТЕРЫ
// ============================================================
void CarDriver::SetEmployeeId(const std::string& employeeId) {
    _employeeId = employeeId;
}

void CarDriver::SetRating(double rating) {
    _rating = rating;
}