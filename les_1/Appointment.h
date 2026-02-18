#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "MedicalTypes.h"

class Appointment {
private:
    std::string _id;
    std::string _dateTime;
    int _durationMinutes;
    AppointmentStatus _status;
    UrgencyLevel _urgency; 
    static int _idCounter;
public:
    Appointment(std::string dateTime, int durationMinutes, 
               AppointmentStatus status, UrgencyLevel urgency);
    std::string GetId() const;
    void SetScheduleTime(std::string newTime);
    std::string GetScheduleTime() const;
    void CancelAppointment();
    void CreateProtocol();
    std::string GetSummary() const;
};

std::string StatusToString(AppointmentStatus status);
std::string UrgencyToString(UrgencyLevel urgency);

#endif