#include <iostream>
int main() {
    int x = 5;
    std::cout << x << std::endl;
    std::cout << &x << std::endl;
    int& refX = x; // Reference to x
    std::cout << refX << std::endl;
    std::cout << &refX<< std::endl;
    int y = 11;
    std::cout << y << std::endl;
    std::cout << &y << std::endl;
    int z = y;     // Regular variable, copy of y
    std::cout << z << std::endl;
    std::cout << &z << std::endl;
}
