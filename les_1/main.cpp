#include <string>
#include <iostream>
#include <vector>

enum class Specialization {
    Therapist,      // Терапевт
    Surgeon,        // Хирург
    Ophthalmologist,// Окулист
    Pediatrician,   // Педиатр
    Neurologist,    // Невролог
    Cardiologist,   // Кардиолог
    ENT             // ЛОР
}; 

enum class AppointmentStatus {
    Scheduled,   // Запланирован
    InProgress,  // Идет сейчас
    Completed,   // Завершен
    Cancelled,   // Отменен
    Waiting      // Ожидание
};

enum class UrgencyLevel {
    Routine,       // Плановый (2-4 недель)
    Urgent,        // Срочный (в течение дня)
    Emergency,     // Экстренный (1-2 часа)
    Critical       // Реанимация (сейчас)
};

enum class MedicineType {
    Free,          // по ОМС
    Quota,         // По квоте 
    Paid,          // Платно 
    Preferential  // Льготное
};

// Пациент, Врач, Прием, Болезнь, Лекарство
class Patient{
    private:
        std::string _id;
        std::string _fullName;
        std::string _birthDate;
        std::string _policyNumber;
    public:
        Patient(std::string fullName, std::string birthDate, std::string numberPolicy);
        int getId() const;
        int registerPatient();
        void bookAppointment();
        void getMedicalHistory();
};

class Doctor
{
    private: 
        std::string _id;
        std::string _fullName;
        Specialization _specialization;
        int _experienceYears;

    public:
        std::string GetId();
        Doctor(std::string fullName, std::string specialization, int experienceYears);
};

class Appointment {
    private:
        std::string _id;
        std::string _dateTime;
        int _durationMinutes;
        AppointmentStatus _status;
        UrgencyLevel _urgency; 

    public:
        Appointment(std::string dateTime, int durationMinutes, AppointmentStatus status, UrgencyLevel urgecny);
        std::string GetId();
        int GetScheduleTime(); // Запросить время приема
        int SetScheduleTime(); // Устоновить время приема
        void CancelAppointment();
        void CreateProtocol();
};

class Disease {
    private:
        std::string _id;
        std::string _name;
        std::string _mkbCode; // МКБ-10 (международная классификация болезней)
    public:
        Disease(std::string name, std::string mkdCode);
        std::string GetId() const;
        void AddSymptom(std::string symptom);
        void AssignTreatment(std::string treatment); 
        std::string GetRecommendations();
};

class Medicine {
    private:
        std::string _id;
        std::string _tradeName;
        std::string _dosage;
        std::string _manufacturer;
        MedicineType _medType; 
    public:
        Medicine(std::string tradeName, std::string dosege, std::string manufacturer, MedicineType medType);
        std::string GetId() const;
};