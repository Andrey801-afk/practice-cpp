#pragma once

#include <iostream>
#include <string>

class Driver {
    protected:
        std::string _fullName;    
        int _age;                  
        std::string _licenseNumber;
        std::string _category;     
        int _experience;           

    public:
        Driver();
        Driver(const std::string& fullName, int age, const std::string& licenseNumber,
            const std::string& category, int experience);
        Driver(const Driver& other);
        virtual ~Driver();

        Driver& operator=(const Driver& other);

        virtual void Print() const;

        std::string GetFullName() const;
        int GetAge() const;
        std::string GetLicenseNumber() const;
        std::string GetCategory() const;
        int GetExperience() const;

        void SetFullName(const std::string& fullName);
        void SetAge(int age);
        void SetLicenseNumber(const std::string& licenseNumber);
        void SetCategory(const std::string& category);
        void SetExperience(int experience);
};
