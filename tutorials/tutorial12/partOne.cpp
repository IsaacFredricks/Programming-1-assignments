#include <iostream>
int main() {
    int x = 10; // Declare an integer variable and assign it a value.
    int* y = nullptr; // Declare a pointer and initialize it to nullptr.
    
    // Assign the address of x to y
    y = &x;
    
    // Print x, y, *y, and &x
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "*y: " << *y << std::endl;
    std::cout << "&x: " << &x << std::endl;
    
    return 0;
}