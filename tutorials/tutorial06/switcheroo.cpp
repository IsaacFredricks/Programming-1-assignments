#include <iostream>
 
int main() {
    // While loop version
    int i = 0;
    while (i < 5) {
        std::cout << "While loop count: " << i << std::endl;
        ++i;
    }
 
    // For loop version
    for (int j = 0; j < 5; ++j) {
        std::cout << "For loop count: " << j << std::endl;
    }
    
    return 0;
}
