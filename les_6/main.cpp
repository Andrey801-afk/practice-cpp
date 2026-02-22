#include <iostream>
#include "TaxiDriver.h"

int main() {
    setlocale(LC_ALL, "Russian");
    
    std::cout << "\n>>> Создание водителя такси (Comfort+):" << std::endl;
    TaxiDriver td1("Иванов Иван Иванович", 35, "1234567890", "B", 10,
                   "Hyundai", "Solaris", 2023, 190, 4, "Yellow", "T111TT777",
                   "TAXI001", 4.9, "Яндекс.Такси", CarClass::ComfortPlus, 1500);
    td1.Print();
    
    std::cout << "\n>>> Получение класса автомобиля:" << std::endl;
    std::cout << "  Enum значение: " << static_cast<int>(td1.GetCarClass()) << std::endl;
    std::cout << "  Строковое значение: " << td1.GetCarClassString() << std::endl;
    
    std::cout << "\n>>> Изменение класса автомобиля на Business:" << std::endl;
    td1.SetCarClass(CarClass::Business);
    std::cout << "  Новый класс: " << td1.GetCarClassString() << std::endl;
    
    std::cout << "\n>>> Установка класса из строки \"Комфорт\":" << std::endl;
    td1.SetCarClassFromString("Комфорт");
    std::cout << "  Новый класс: " << td1.GetCarClassString() << std::endl;
    
    std::cout << "\n>>> Все доступные классы автомобилей:" << std::endl;
    std::cout << "  " << CarClassToString(CarClass::Economy) << std::endl;
    std::cout << "  " << CarClassToString(CarClass::Comfort) << std::endl;
    std::cout << "  " << CarClassToString(CarClass::ComfortPlus) << std::endl;
    std::cout << "  " << CarClassToString(CarClass::Business) << std::endl;
    std::cout << "  " << CarClassToString(CarClass::Van) << std::endl;
    
    return 0;
}