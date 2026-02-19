#pragma once

class Triangle {
    private:
        double _a;
        double _b;
        double _c;

        bool IsValid(double a, double b, double c) const;

    public:
        Triangle();
        Triangle(double a, double b, double c);

        bool SetSides(double a, double b, double c);

        void GetSides(double &a, double &b, double &c) const;

        bool Scale(double factor);
        double GetPerimeter() const;
        double GetArea() const;
        void GetAngles(double &angleA, double &angleB, double &angleC) const;

        void PrintInfo() const;
};
