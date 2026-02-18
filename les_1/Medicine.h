#pragma once

#include <string>
#include "MedicalTypes.h"

class Medicine {
private:
    std::string _id;
    std::string _tradeName;
    std::string _dosage;
    std::string _manufacturer;
    MedicineType _medType; 
    static int _idCounter;
public:
    Medicine(std::string tradeName, std::string dosage, 
            std::string manufacturer, MedicineType medType);
    std::string GetId() const;
    void CheckExpiration();
    double GetPrice() const;
    void AddToStock(int quantity);
    std::string GetSummary() const;
};

std::string MedTypeToString(MedicineType type);

