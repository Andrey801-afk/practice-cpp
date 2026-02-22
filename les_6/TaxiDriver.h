#pragma once

#include "CarDriver.h"

enum class CarClass {
    Economy,        
    Comfort,        
    ComfortPlus,    
    Business,       
    Van,            
    Unknown         
};

std::string CarClassToString(CarClass carClass);
CarClass StringToCarClass(const std::string& carClassStr);

class TaxiDriver : public CarDriver {
    private:
        std::string _taxiCompany;   
        CarClass _carClass;         
        int _totalTrips;            

    public:
        TaxiDriver();
        TaxiDriver(const std::string& fullName, int age, const std::string& licenseNumber,
                const std::string& category, int experience,
                const std::string& brand, const std::string& model, int year,
                double maxSpeed, int doors, const std::string& color,
                const std::string& licensePlate,
                const std::string& employeeId, double rating,
                const std::string& taxiCompany, CarClass carClass, int totalTrips);
        TaxiDriver(const TaxiDriver& other);
        ~TaxiDriver();

        TaxiDriver& operator=(const TaxiDriver& other);

        void Print() const override;

        std::string GetTaxiCompany() const;
        CarClass GetCarClass() const;
        std::string GetCarClassString() const;  
        int GetTotalTrips() const;

        void SetTaxiCompany(const std::string& taxiCompany);
        void SetCarClass(CarClass carClass);
        void SetCarClassFromString(const std::string& carClassStr);
        void SetTotalTrips(int totalTrips);
};
