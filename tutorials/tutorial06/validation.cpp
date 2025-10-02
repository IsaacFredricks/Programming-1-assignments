#include <iostream>
 
int main() {
    int num = -1;  // Instantiated out of range (-1 is out of range 1-10)
    while (num < 1 && num > 10); {
        std::cout << "Enter a number between 1 and 10: ";
        std::cin >> num;
    }
    std::cout << "The number is within range: " << num << std::endl;
    return 0;
}