#include "Patient.h"
#include <iostream>

int Patient::_idCounter = 1;

Patient::Patient(std::string fullName, std::string birthDate, std::string policyNumber)
    : _id("P" + std::to_string(_idCounter++)), 
      _fullName(fullName), 
      _birthDate(birthDate), 
      _policyNumber(policyNumber) {}

std::string Patient::GetId() const { return _id; }

int Patient::RegisterPatient() {
    std::cout << "[Пациент " << _id << "] " << _fullName << " зарегистрирован.\n";
    return 0;
}

void Patient::BookAppointment() {
    std::cout << "[Пациент " << _id << "] Запись создана.\n";
}

void Patient::GetMedicalHistory() {
    std::cout << "[Пациент " << _id << "] История получена.\n";
}

std::string Patient::GetSummary() const {
    return "Пациент: " + _fullName + " (ДР: " + _birthDate + ")";
}