#pragma once//avoids multiple inclusions of rectangle once
//not good for old or unusual compilters
class Rectangle {
private:
    double height;
    double width;
    static double maxDimension; // Maximum allowed height or width
    
public:
    Rectangle(double h, double w); // Constructor
    
    //another constructor
    Rectangle();
    
    // Getters
    double getHeight() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;

    // Setters
    void setHeight(double h);
    void setWidth(double w);
    static void setMaxDimension(double maxDim);
    void scale(double factor);
};