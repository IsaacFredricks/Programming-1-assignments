#include <iostream>

//this function doesn't return anything
void biggerNum(int numOne, int numTwo){
    std::cout << "Calculating results now: \n";
    
    if(numOne > numTwo){
        std::cout << numOne << " is the bigger number.\n";
    }
    
    else if(numTwo > numOne){
        std::cout << numTwo << " is the bigger number.\n";
    }
    
    else{
        std::cout << "Both numbers are the same, or there was an improper" 
        << " value input.\n";
    }
}

int main() {
    //comparing floating point values is finicky in c++ so i decided not to.
    int firstNumber {};
    int secondNumber {};
    
	std::cout << "Enter a number:\n";
	
	std::cin >> firstNumber;
	
	std::cout << "Enter another number:\n";
	
	std::cin >> secondNumber;
	
	biggerNum(firstNumber, secondNumber);
	    
	return 0;
}
