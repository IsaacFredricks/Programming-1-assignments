#include <iostream>
#include "Rectangle.h"
#include "Rectangle.cpp" //needed for codebin but not in general
 
int main() {
    // Step 1: Test Getter and Setter Methods
    Rectangle rect1;
    rect1.setHeight(10.5);
    rect1.setWidth(20.0);
 
    std::cout << "Rectangle 1 Height: " << rect1.getHeight() << " (Expected: 10.5)" << std::endl;
    std::cout << "Rectangle 1 Width: " << rect1.getWidth() << " (Expected: 20.0)" << std::endl;
 
    // Step 2: Test Constructor Initialization
    Rectangle rect2(15.0, 25.0);
 
    std::cout << "Rectangle 2 Height: " << rect2.getHeight() << " (Expected: 15.0)" << std::endl;
    std::cout << "Rectangle 2 Width: " << rect2.getWidth() << " (Expected: 25.0)" << std::endl;
 
    return 0;
}