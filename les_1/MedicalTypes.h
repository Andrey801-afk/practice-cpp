#pragma once

enum class Specialization {
    Therapist, Surgeon, Ophthalmologist, Pediatrician, 
    Neurologist, Cardiologist, ENT
}; 

enum class AppointmentStatus {
    Scheduled, InProgress, Completed, Cancelled, Waiting
};

enum class UrgencyLevel {
    Routine, Urgent, Emergency, Critical
};

enum class MedicineType {
    Free, Quota, Paid, Preferential
};
