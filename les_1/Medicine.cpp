#include "Medicine.h"
#include <iostream>

int Medicine::_idCounter = 1;

std::string MedTypeToString(MedicineType type) {
    switch(type) {
        case MedicineType::Free: return "По ОМС";
        case MedicineType::Quota: return "По квоте";
        case MedicineType::Paid: return "Платно";
        case MedicineType::Preferential: return "Льготное";
        default: return "Неизвестно";
    }
}

Medicine::Medicine(std::string tradeName, std::string dosage, 
                  std::string manufacturer, MedicineType medType)
    : _id("M" + std::to_string(_idCounter++)),
      _tradeName(tradeName),
      _dosage(dosage),
      _manufacturer(manufacturer),
      _medType(medType) {}

std::string Medicine::GetId() const { return _id; }

void Medicine::CheckExpiration() {
    std::cout << "[Лекарство " << _id << "] Срок проверен.\n";
}

double Medicine::GetPrice() const {
    if (_medType == MedicineType::Paid) return 250.0;
    return 0.0;
}

void Medicine::AddToStock(int quantity) {
    std::cout << "[Лекарство " << _id << "] " << _tradeName 
              << " добавлено: " << quantity << " шт.\n";
}

std::string Medicine::GetSummary() const {
    return "Лекарство: " + _tradeName + " (" + MedTypeToString(_medType) + ")";
}