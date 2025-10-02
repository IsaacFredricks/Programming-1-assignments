#include <iostream>

//void feedCat(); // forward declaration
void unusedFunction(); // forward declaration for an unused function
void doesntExist();
 void feedCat() {
    std::cout << "You have fed the cat.\n";
}
 
int main() {
    std::cout << "Welcome to the Cat Management System!\n";
    feedCat();
    return 0;
}
 

void unusedFunction() {
    std::cout << "This function is not used.\n";
}
 