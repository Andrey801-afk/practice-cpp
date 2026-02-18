#include "Appointment.h"
#include <iostream>

int Appointment::_idCounter = 1;

std::string StatusToString(AppointmentStatus status) {
    switch(status) {
        case AppointmentStatus::Scheduled: return "Запланирован";
        case AppointmentStatus::InProgress: return "Идет сейчас";
        case AppointmentStatus::Completed: return "Завершен";
        case AppointmentStatus::Cancelled: return "Отменен";
        case AppointmentStatus::Waiting: return "Ожидание";
        default: return "Неизвестно";
    }
}

std::string UrgencyToString(UrgencyLevel urgency) {
    switch(urgency) {
        case UrgencyLevel::Routine: return "Плановый";
        case UrgencyLevel::Urgent: return "Срочный";
        case UrgencyLevel::Emergency: return "Экстренный";
        case UrgencyLevel::Critical: return "Реанимация";
        default: return "Неизвестно";
    }
}

Appointment::Appointment(std::string dateTime, int durationMinutes, 
                        AppointmentStatus status, UrgencyLevel urgency)
    : _id("A" + std::to_string(_idCounter++)),
      _dateTime(dateTime),
      _durationMinutes(durationMinutes),
      _status(status),
      _urgency(urgency) {}

std::string Appointment::GetId() const { return _id; }

void Appointment::SetScheduleTime(std::string newTime) {
    _dateTime = newTime;
    std::cout << "[Прием " << _id << "] Время изменено.\n";
}

std::string Appointment::GetScheduleTime() const { return _dateTime; }

void Appointment::CancelAppointment() {
    _status = AppointmentStatus::Cancelled;
    std::cout << "[Прием " << _id << "] ОТМЕНЕН.\n";
}

void Appointment::CreateProtocol() {
    std::cout << "[Прием " << _id << "] Протокол создан.\n";
}

std::string Appointment::GetSummary() const {
    return "Прием: " + _dateTime + " (" + StatusToString(_status) + ")";
}