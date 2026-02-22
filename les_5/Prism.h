#pragma once

#include "Square.h"

class Prism : public Square {
    private:
        double _height;  

    public:
        Prism();
        Prism(double side, double height);
        Prism(const Prism& other);
        ~Prism();

        Prism& operator=(const Prism& other);

        double GetArea() const override;     
        void Print() const override;           

        double GetVolume() const;

        double GetHeight() const;
        void SetHeight(double height);
};
