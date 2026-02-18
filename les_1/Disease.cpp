#include "Disease.h"
#include <iostream>

int Disease::_idCounter = 1;

Disease::Disease(std::string name, std::string mkbCode)
    : _id("DS" + std::to_string(_idCounter++)),
      _name(name),
      _mkbCode(mkbCode) {}

std::string Disease::GetId() const { return _id; }

void Disease::AddSymptom(std::string symptom) {
    std::cout << "[Болезнь " << _id << "] Симптом: " << symptom << "\n";
}

void Disease::AssignTreatment(std::string treatment) {
    std::cout << "[Болезнь " << _id << "] Лечение: " << treatment << "\n";
}

std::string Disease::GetRecommendations() {
    return "Рекомендации: покой, контроль.";
}

std::string Disease::GetSummary() const {
    return "Болезнь: " + _name + " (МКБ: " + _mkbCode + ")";
}