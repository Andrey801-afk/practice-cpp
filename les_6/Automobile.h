#pragma once

#include "Transport.h"

class Automobile : virtual public Transport {
    protected:
        int _doors;            
        std::string _color;    
        std::string _licensePlate; 

    public:
        Automobile();
        Automobile(const std::string& brand, const std::string& model, int year, 
                double maxSpeed, int doors, const std::string& color, const std::string& licensePlate);
        Automobile(const Automobile& other);
        ~Automobile();

        Automobile& operator=(const Automobile& other);

        void Print() const override;

        int GetDoors() const;
        std::string GetColor() const;
        std::string GetLicensePlate() const;

        void SetDoors(int doors);
        void SetColor(const std::string& color);
        void SetLicensePlate(const std::string& licensePlate);
};
