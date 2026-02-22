#include "TaxiDriver.h"
#include <iostream>
#include <iomanip>

std::string CarClassToString(CarClass carClass) {
    switch (carClass) {
        case CarClass::Economy:      return "Эконом";
        case CarClass::Comfort:      return "Комфорт";
        case CarClass::ComfortPlus:  return "Комфорт+";
        case CarClass::Business:     return "Бизнес";
        case CarClass::Van:          return "Минивэн";
        default:                     return "Неизвестный";
    }
}

CarClass StringToCarClass(const std::string& carClassStr) {
    if (carClassStr == "Эконом" || carClassStr == "Economy") {
        return CarClass::Economy;
    } else if (carClassStr == "Комфорт" || carClassStr == "Comfort") {
        return CarClass::Comfort;
    } else if (carClassStr == "Комфорт+" || carClassStr == "ComfortPlus") {
        return CarClass::ComfortPlus;
    } else if (carClassStr == "Бизнес" || carClassStr == "Business") {
        return CarClass::Business;
    } else if (carClassStr == "Минивэн" || carClassStr == "Van") {
        return CarClass::Van;
    }
    return CarClass::Unknown;
}

TaxiDriver::TaxiDriver() : CarDriver() {
    std::cout << ">>> Вызван конструктор по умолчанию" << std::endl;
    _taxiCompany = "Unknown";
    _carClass = CarClass::Unknown;
    _totalTrips = 0;
}

TaxiDriver::TaxiDriver(const std::string& fullName, int age, const std::string& licenseNumber,
                       const std::string& category, int experience,
                       const std::string& brand, const std::string& model, int year,
                       double maxSpeed, int doors, const std::string& color,
                       const std::string& licensePlate,
                       const std::string& employeeId, double rating,
                       const std::string& taxiCompany, CarClass carClass, int totalTrips)
    : CarDriver(fullName, age, licenseNumber, category, experience,
                brand, model, year, maxSpeed, doors, color, licensePlate,
                employeeId, rating) {
    std::cout << ">>> Вызван конструктор с параметрами" << std::endl;
    _taxiCompany = taxiCompany;
    _carClass = carClass;
    _totalTrips = totalTrips;
}

TaxiDriver::TaxiDriver(const TaxiDriver& other) : CarDriver(other) {
    std::cout << ">>> Вызван конструктор копирования" << std::endl;
    _taxiCompany = other._taxiCompany;
    _carClass = other._carClass;
    _totalTrips = other._totalTrips;
}

TaxiDriver::~TaxiDriver() {
    std::cout << ">>> Удаление водителя такси (" 
              << _fullName << ")" << std::endl;
}

TaxiDriver& TaxiDriver::operator=(const TaxiDriver& other) {
    std::cout << ">>> Вызван оператор присваивания" << std::endl;
    
    if (this == &other) {
        return *this;
    }
    
    CarDriver::operator=(other);
    _taxiCompany = other._taxiCompany;
    _carClass = other._carClass;
    _totalTrips = other._totalTrips;
    
    return *this;
}

void TaxiDriver::Print() const {
    std::cout << ">>> Информация о водителе такси" << std::endl;
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
    
    std::cout << "  === ИНФОРМАЦИЯ О ТАКСИ ===" << std::endl;
    std::cout << "  Табельный номер: " << _employeeId << std::endl;
    std::cout << "  Рейтинг водителя: " << std::fixed << std::setprecision(1) << _rating << std::endl;
    std::cout << "  Таксопарк: " << _taxiCompany << std::endl;
    std::cout << "  Класс автомобиля: " << CarClassToString(_carClass) << std::endl;
    std::cout << "  Всего поездок: " << _totalTrips << std::endl;
    std::cout << "  -----------------------------------" << std::endl;
}

std::string TaxiDriver::GetTaxiCompany() const {
    return _taxiCompany;
}

CarClass TaxiDriver::GetCarClass() const {
    return _carClass;
}

std::string TaxiDriver::GetCarClassString() const {
    return CarClassToString(_carClass);
}

int TaxiDriver::GetTotalTrips() const {
    return _totalTrips;
}

void TaxiDriver::SetTaxiCompany(const std::string& taxiCompany) {
    _taxiCompany = taxiCompany;
}

void TaxiDriver::SetCarClass(CarClass carClass) {
    _carClass = carClass;
}

void TaxiDriver::SetCarClassFromString(const std::string& carClassStr) {
    _carClass = StringToCarClass(carClassStr);
}

void TaxiDriver::SetTotalTrips(int totalTrips) {
    _totalTrips = totalTrips;
}