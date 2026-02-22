#pragma once

#include "Driver.h"
#include "Automobile.h"

class CarDriver : virtual public Driver, virtual public Automobile {
    protected:
        std::string _employeeId;   
        double _rating;            

    public:
        CarDriver();
        CarDriver(const std::string& fullName, int age, const std::string& licenseNumber,
                const std::string& category, int experience,
                const std::string& brand, const std::string& model, int year,
                double maxSpeed, int doors, const std::string& color, 
                const std::string& licensePlate,
                const std::string& employeeId, double rating);
        CarDriver(const CarDriver& other);
        ~CarDriver();

        CarDriver& operator=(const CarDriver& other);

        void Print() const override;

        std::string GetEmployeeId() const;
        double GetRating() const;

        void SetEmployeeId(const std::string& employeeId);
        void SetRating(double rating);
};
