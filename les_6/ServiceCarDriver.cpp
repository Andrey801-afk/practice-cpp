#include "ServiceCarDriver.h"
#include <iomanip>

ServiceCarDriver::ServiceCarDriver() : CarDriver() {
    std::cout << ">>> Вызван конструктор по умолчанию" << std::endl;
    _department = "Unknown";
    _vehicleType = "Unknown";
}

ServiceCarDriver::ServiceCarDriver(const std::string& fullName, int age, const std::string& licenseNumber,
                                   const std::string& category, int experience,
                                   const std::string& brand, const std::string& model, int year,
                                   double maxSpeed, int doors, const std::string& color,
                                   const std::string& licensePlate,
                                   const std::string& employeeId, double rating,
                                   const std::string& department, const std::string& vehicleType)
    : CarDriver(fullName, age, licenseNumber, category, experience,
                brand, model, year, maxSpeed, doors, color, licensePlate,
                employeeId, rating) {
    std::cout << ">>> Вызван конструктор с параметрами" << std::endl;
    _department = department;
    _vehicleType = vehicleType;
}

ServiceCarDriver::ServiceCarDriver(const ServiceCarDriver& other) : CarDriver(other) {
    std::cout << ">>> Вызван конструктор копирования" << std::endl;
    _department = other._department;
    _vehicleType = other._vehicleType;
}

ServiceCarDriver::~ServiceCarDriver() {
    std::cout << ">>> Удаление водителя служебного автомобиля (" 
              << _fullName << ")" << std::endl;
}

ServiceCarDriver& ServiceCarDriver::operator=(const ServiceCarDriver& other) {
    std::cout << ">>> Вызван оператор присваивания" << std::endl;
    
    if (this == &other) {
        return *this;
    }
    
    CarDriver::operator=(other);
    _department = other._department;
    _vehicleType = other._vehicleType;
    
    return *this;
}

void ServiceCarDriver::Print() const {
    std::cout << ">>> Информация о водителе служебного автомобиля" << std::endl;
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
    
    std::cout << "  === СЛУЖЕБНАЯ ИНФОРМАЦИЯ ===" << std::endl;
    std::cout << "  Табельный номер: " << _employeeId << std::endl;
    std::cout << "  Рейтинг водителя: " << std::fixed << std::setprecision(1) << _rating << std::endl;
    std::cout << "  Отдел: " << _department << std::endl;
    std::cout << "  Тип транспорта: " << _vehicleType << std::endl;
    std::cout << "  -----------------------------------" << std::endl;
}

std::string ServiceCarDriver::GetDepartment() const {
    return _department;
}

std::string ServiceCarDriver::GetVehicleType() const {
    return _vehicleType;
}

void ServiceCarDriver::SetDepartment(const std::string& department) {
    _department = department;
}

void ServiceCarDriver::SetVehicleType(const std::string& vehicleType) {
    _vehicleType = vehicleType;
}