#pragma once

#include <iostream>

class Square {
    protected:
        double _side;  

    public:
        Square();
        Square(double side);
        Square(const Square& other);
        virtual ~Square();

        Square& operator=(const Square& other);

        virtual double GetDiagonal() const;
        virtual double GetPerimeter() const;
        virtual double GetArea() const;

        virtual void Print() const;

        double GetSide() const;
        void SetSide(double side);
};
