#include <iostream>
#include <vector>
#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"
#include "Disease.h"
#include "Medicine.h"

int main() {
    setlocale(LC_ALL, "Russian");
    
    std::cout << "=== ЗДРАВООХРАНЕНИЕ ===" << std::endl << std::endl;
    
    std::vector<Patient> patients = {
        Patient("Иванов И.И.", "12.05.1980", "1234567890"),
        Patient("Петрова А.С.", "23.08.1995", "0987654321"),
        Patient("Сидоров П.И.", "01.01.1970", "1122334455"),
        Patient("Кузнецова Е.В.", "15.03.2001", "5566778899"),
        Patient("Смирнов А.Д.", "30.11.1988", "6677889900"),
        Patient("Васильев Д.К.", "05.07.1965", "4433221100"),
        Patient("Морозова О.П.", "19.09.1992", "9988776655")
    };

    std::vector<Doctor> doctors = {
        Doctor("Соколов", Specialization::Therapist, 15),
        Doctor("Волкова", Specialization::Surgeon, 8),
        Doctor("Лебедев", Specialization::Ophthalmologist, 20),
        Doctor("Новикова", Specialization::Pediatrician, 5),
        Doctor("Орлов", Specialization::Neurologist, 12),
        Doctor("Зайцева", Specialization::Cardiologist, 10),
        Doctor("Павлов", Specialization::ENT, 7)
    };

    std::vector<Appointment> appointments = {
        Appointment("20.10.2023 09:00", 30, AppointmentStatus::Waiting, UrgencyLevel::Routine),
        Appointment("20.10.2023 09:30", 30, AppointmentStatus::InProgress, UrgencyLevel::Emergency),
        Appointment("20.10.2023 10:00", 30, AppointmentStatus::Waiting, UrgencyLevel::Urgent),
        Appointment("21.10.2023 14:00", 45, AppointmentStatus::Scheduled, UrgencyLevel::Routine),
        Appointment("21.10.2023 14:30", 30, AppointmentStatus::Scheduled, UrgencyLevel::Critical),
        Appointment("22.10.2023 11:00", 30, AppointmentStatus::Scheduled, UrgencyLevel::Urgent),
        Appointment("22.10.2023 11:30", 30, AppointmentStatus::Scheduled, UrgencyLevel::Routine)
    };

    std::vector<Disease> diseases = {
        Disease("Грипп", "J11"),
        Disease("ОРВИ", "J06"),
        Disease("Гипертония", "I10"),
        Disease("Диабет", "E11"),
        Disease("Гастрит", "K29"),
        Disease("Мигрень", "G43"),
        Disease("Пневмония", "J18")
    };

    std::vector<Medicine> medicines = {
        Medicine("Аспирин", "500мг", "Bayer", MedicineType::Free),
        Medicine("Нурофен", "200мг", "Reckitt", MedicineType::Paid),
        Medicine("Амоксициллин", "250мг", "Hemofarm", MedicineType::Quota),
        Medicine("Но-шпа", "40мг", "Sanofi", MedicineType::Preferential),
        Medicine("Супрастин", "25мг", "Egis", MedicineType::Free),
        Medicine("Валерьянка", "20мг", "Фармстандарт", MedicineType::Paid),
        Medicine("Парацетамол", "500мг", "Фармстандарт", MedicineType::Free)
    };

    std::cout << "--- Пациенты ---" << std::endl;
    for(auto& p : patients) p.RegisterPatient();
    
    std::cout << "\n--- Врачи ---" << std::endl;
    doctors[0].ConductExam();
    doctors[1].WritePrescription();
    doctors[2].OpenSickLeave();
    
    std::cout << "\n--- Приемы ---" << std::endl;
    appointments[0].CreateProtocol();
    appointments[4].CancelAppointment();
    
    std::cout << "\n--- Болезни ---" << std::endl;
    diseases[0].AddSymptom("Температура 38.5");
    diseases[0].AssignTreatment("Покой");
    
    std::cout << "\n--- Лекарства ---" << std::endl;
    for(auto& m : medicines) m.AddToStock(50);
    
    std::cout << "\n=== ИТОГО ===" << std::endl;
    std::cout << "Пациентов: " << patients.size() << std::endl;
    std::cout << "Врачей: " << doctors.size() << std::endl;
    std::cout << "Приемов: " << appointments.size() << std::endl;
    std::cout << "Болезней: " << diseases.size() << std::endl;
    std::cout << "Лекарств: " << medicines.size() << std::endl;
    std::cout << "ВСЕГО: " << patients.size() + doctors.size() + appointments.size() 
              + diseases.size() + medicines.size() << " объектов" << std::endl;
    
    return 0;
}