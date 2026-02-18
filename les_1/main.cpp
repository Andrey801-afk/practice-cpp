#include <string>
#include <iostream>
#include <vector>

// Пациент, Врач, Прием, Болезнь, Лекарство
class Patient{
    private:
        std::string _id;
        std::string _fullName;
        std::string _birthDate;
};

class Doctor
{
    private: 
        std::string _id;
        std::string _fullName;
        std::string _specialization;
        int _experienceYears;

    public:
        Doctor(std::string name, std::string spec, int exp);

};

class Appointment {
    private:
        string dateTime;
        int durationMinutes;
        string status;

public:
    Appointment(string dt, int duration, string stat);
    void scheduleTime();
    void cancelAppointment();
    void createProtocol();
};

