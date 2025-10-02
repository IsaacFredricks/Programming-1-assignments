#include <iostream>
int main() {
    double numOne {}; //value init of two numbers that wil have their values replaced
    double numTwo {}; 
    
    double sum; //default init of sum
    
	std::cout << "Please enter an number: " << std::endl;
	
	std::cin >> numOne;
	
	std::cout << "Please enter another number: " << std::endl;
	
	std::cin >> numTwo;
	
	sum = numOne + numTwo; //sum is initialized as the first entered number + second entered number
	
	std::cout << "The sum of the two numbers is " << sum << std::endl;
	
	return 0;
}
