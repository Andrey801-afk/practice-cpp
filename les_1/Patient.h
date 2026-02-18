#include <string>
#include "MedicalTypes.h"

class Patient{
    private:
        std::string _id;
        std::string _fullName;
        std::string _birthDate;
        std::string _policyNumber;
        static int _idCounter;
    public:
        Patient(std::string fullName, std::string birthDate, std::string policyNumber);
        std::string GetId() const;
        int RegisterPatient();
        void BookAppointment();
        void GetMedicalHistory();
        std::string GetSummary() const;
};