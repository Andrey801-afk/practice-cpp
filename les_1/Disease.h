#pragma once

#include <string>
#include "MedicalTypes.h"

class Disease {
private:
    std::string _id;
    std::string _name;
    std::string _mkbCode;
    static int _idCounter;
public:
    Disease(std::string name, std::string mkbCode);
    std::string GetId() const;
    void AddSymptom(std::string symptom);
    void AssignTreatment(std::string treatment);
    std::string GetRecommendations();
    std::string GetSummary() const;
};
