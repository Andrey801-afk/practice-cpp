#include "Doctor.h"
#include <iostream>

int Doctor::_idCounter = 1;

std::string SpecToString(Specialization spec) {
    switch(spec) {
        case Specialization::Therapist: return "Терапевт";
        case Specialization::Surgeon: return "Хирург";
        case Specialization::Ophthalmologist: return "Окулист";
        case Specialization::Pediatrician: return "Педиатр";
        case Specialization::Neurologist: return "Невролог";
        case Specialization::Cardiologist: return "Кардиолог";
        case Specialization::ENT: return "ЛОР";
        default: return "Неизвестно";
    }
}

Doctor::Doctor(std::string fullName, Specialization specialization, int experienceYears)
    : _id("D" + std::to_string(_idCounter++)),
      _fullName(fullName),
      _specialization(specialization),
      _experienceYears(experienceYears) {}

std::string Doctor::GetId() const { return _id; }

void Doctor::ConductExam() {
    std::cout << "[Врач " << _id << "] " << _fullName << " проводит осмотр.\n";
}

void Doctor::WritePrescription() {
    std::cout << "[Врач " << _id << "] Рецепт выписан.\n";
}

void Doctor::OpenSickLeave() {
    std::cout << "[Врач " << _id << "] Больничный открыт.\n";
}

std::string Doctor::GetSummary() const {
    return "Врач: " + _fullName + " (" + SpecToString(_specialization) + ")";
}