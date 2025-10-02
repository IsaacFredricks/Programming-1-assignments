#include <iostream>
#include <string>
int main() {
    std:: string name; // makes a string variable
	std::cout << "Whats your name? " << std::endl;
	
	std::cin >> name; // gives string input
	
	std::cout << "Hi, " << name << "! Nice weather today isn't it?" << std::endl; // print string
	return 0;
}
