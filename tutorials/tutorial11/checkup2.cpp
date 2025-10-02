#include <iostream>
#include "Rectangle.h"
#include "Rectangle.cpp" //needed for codebin but not in general
 
int main() {
    // Step 4: Test Default maxDimension with Setters
    Rectangle rect1;
    Rectangle::setMaxDimension(100.0); // Set default max dimension to 100.0
    
    rect1.setHeight(150.0); // Should be capped at maxDimension (100.0)
    rect1.setWidth(50.0);   // Within maxDimension, should set to 50.0
 
    std::cout << "Rectangle 1 Height: " << rect1.getHeight() << " (Expected: 100.0)" << std::endl;
    std::cout << "Rectangle 1 Width: " << rect1.getWidth() << " (Expected: 50.0)" << std::endl;
 
    // Step 5: Test Negative Dimension Prevention
    rect1.setHeight(-20.0); // Should set to 0
    rect1.setWidth(-10.0);  // Should set to 0
 
    std::cout << "Rectangle 1 Height after setting negative: " << rect1.getHeight() << " (Expected: 0.0)" << std::endl;
    std::cout << "Rectangle 1 Width after setting negative: " << rect1.getWidth() << " (Expected: 0.0)" << std::endl;
 
    // Step 6: Test Changing maxDimension
    Rectangle::setMaxDimension(60.0);  // Update max dimension to 60.0
    rect1.setHeight(70.0);             // Should be capped at 60.0
    rect1.setWidth(60.0);              // Should set to 60.0
 
    std::cout << "Rectangle 1 Height with new maxDimension: " << rect1.getHeight() << " (Expected: 60.0)" << std::endl;
    std::cout << "Rectangle 1 Width with new maxDimension: " << rect1.getWidth() << " (Expected: 60.0)" << std::endl;
}