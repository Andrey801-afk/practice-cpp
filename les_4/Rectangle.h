#pragma once



class Rectangle {
private:
    double _x;       
    double _y;       
    double _width;   
    double _height;  

public:
    Rectangle();
    Rectangle(double x, double y, double width, double height);
    Rectangle(const Rectangle& other);
    ~Rectangle();

    Rectangle& operator=(const Rectangle& other);

    Rectangle operator+(const Rectangle& other) const;  
    Rectangle operator-(const Rectangle& other) const;  
    Rectangle operator-() const;                        

    void Print() const;
    bool IsEmpty() const;
    
    double GetX() const;
    double GetY() const;
    double GetWidth() const;
    double GetHeight() const;
    double GetArea() const;
};
