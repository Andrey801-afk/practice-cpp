#pragma once

#include <string>
#include "MedicalTypes.h"

class Doctor {
private: 
    std::string _id;
    std::string _fullName;
    Specialization _specialization;
    int _experienceYears;
    static int _idCounter;
public:
    Doctor(std::string fullName, Specialization specialization, int experienceYears);
    std::string GetId() const;
    void ConductExam();
    void WritePrescription();
    void OpenSickLeave();
    std::string GetSummary() const;
};

std::string SpecToString(Specialization spec);
