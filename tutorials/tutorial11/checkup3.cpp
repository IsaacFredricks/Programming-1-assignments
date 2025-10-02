#include <iostream>
#include "Rectangle.h"
#include "Rectangle.cpp" //needed for codebin but not in general
 
int main() {
    Rectangle::setMaxDimension(100.0);
    
    
    Rectangle rect(75.0, 30.0);
    //rect.maxDimension = 50; //doesn't work
    std::cout << "Area: " << rect.area() << std::endl;
    std::cout << "Perimeter: " << rect.perimeter() << std::endl;
 
    rect.scale(2.0);
    std::cout << "Scaled Height: " << rect.getHeight() << std::endl;
    std::cout << "Scaled Width: " << rect.getWidth() << std::endl;
 
    return 0;
}
