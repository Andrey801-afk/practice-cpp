#pragma once

#include "CarDriver.h"

class ServiceCarDriver : public CarDriver {
    private:
        std::string _department;    
        std::string _vehicleType;   

    public:
        ServiceCarDriver();
        ServiceCarDriver(const std::string& fullName, int age, const std::string& licenseNumber,
                        const std::string& category, int experience,
                        const std::string& brand, const std::string& model, int year,
                        double maxSpeed, int doors, const std::string& color,
                        const std::string& licensePlate,
                        const std::string& employeeId, double rating,
                        const std::string& department, const std::string& vehicleType);
        ServiceCarDriver(const ServiceCarDriver& other);
        ~ServiceCarDriver();

        ServiceCarDriver& operator=(const ServiceCarDriver& other);

        void Print() const override;

        std::string GetDepartment() const;
        std::string GetVehicleType() const;

        void SetDepartment(const std::string& department);
        void SetVehicleType(const std::string& vehicleType);
};
