#include <iostream>
int main() {
    //the program finds the difference between two points on a graph
    double xOne {}; //makes the x variables
    double yOne {};
    double xTwo {}; //makes the y variables
    double yTwo {};
    
	std::cout << "Enter the x variable of the first coordinate: \n";
	
	std::cin >> xOne; //the user assigns the variables values
	
	std::cout << "Enter the y variable of the first coordinate: \n";
	
	std::cin >> yOne;
	
	std::cout << "Enter the x variable of the second coordinate: \n";
	
	std::cin >> xTwo;
	
	std::cout << "Enter the y variable of the second coordinate: \n";
	
	std::cin >> yTwo;
	
	double pointDifference {(yOne - yTwo) 
	/ (xOne - xTwo)}; // still works since the operator starts a new line
	
	std::cout << "The difference between (" << xOne << ", " << yOne << ") and (" 
	<< xTwo << ", " << yTwo << ") is " << pointDifference << "." << std::endl;
	return 0;
}
