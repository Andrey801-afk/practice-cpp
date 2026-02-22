#pragma once

#include <iostream>
#include <string>

class Transport {
    protected:
        std::string _brand;     
        std::string _model;      
        int _year;               
        double _maxSpeed;        

    public:
        Transport();
        Transport(const std::string& brand, const std::string& model, int year, double maxSpeed);
        Transport(const Transport& other);
        virtual ~Transport();

        Transport& operator=(const Transport& other);

        virtual void Print() const;

        std::string GetBrand() const;
        std::string GetModel() const;
        int GetYear() const;
        double GetMaxSpeed() const;

        void SetBrand(const std::string& brand);
        void SetModel(const std::string& model);
        void SetYear(int year);
        void SetMaxSpeed(double maxSpeed);
};
