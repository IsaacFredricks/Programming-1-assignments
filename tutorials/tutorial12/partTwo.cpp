#include <iostream>
int main() {
    int x = 10;
    int* y = nullptr;
    
    // Check if y is nullptr
    if (y == nullptr) {
        std::cout << "y is nullptr before assignment." << std::endl;
    }
 
    // Alternative check
    if (!y) {
        std::cout << "y is nullptr (using !y) before assignment." << std::endl;
    }
    std::cout << y << '\n';
    std::cout << x << '\n';
    std::cout << &x << '\n';
    std::cout << *y << '\n';
    // Assign y to the address of x
    y = &x;
 
    // Check if y is still nullptr
    if (y) {
        std::cout << "y is now assigned to x's address." << std::endl;
    }
    std::cout << y << '\n';
    std::cout << *y << '\n';
    std::cout << &x << '\n';
    return 0;
}
