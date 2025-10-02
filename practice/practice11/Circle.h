#pragma once//reused from tutorial 11
//avoids multiple inclusions of rectangle once
//not good for old or unusual compilters

class Circle {
private: //not entirely needed here. class is private by default
    double radius;
    static double maxRadius;//static gives global scope
    
public:
    
    //default constructor
    Circle();
    
    //we want getters const to make sure variables aren't modified
    //getters
    double getRadius() const;
    static double getMaxRadius();
    double area() const;
    double perimeter() const;
    
    //setters
    void setRadius(double rad);
    static void setMaxRadius(double maxRad);
    void scale(double factor);
};