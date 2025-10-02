#include <iostream>
 
void increaseByValue(int x);
void increaseByRef(int &x);
void increaseByConstRef(const int &x);
 
int main() {
    int value = 5;
    
    increaseByValue(value);
    std::cout << "After pass by value: " << value << "\n";
 
    increaseByRef(value);
    //increaseByRef(4);//can't do this
    std::cout << "After pass by reference: " << value << "\n";
 
    increaseByConstRef(value);
    std::cout << "After pass by const reference: " << value << "\n";
 
    return 0;
}
 
void increaseByValue(int x) {
    x++;
}
 
void increaseByRef(int &x) {
    x++;
}
 
void increaseByConstRef(const int &x) {
     x++;  // Uncomment to see what happens
}