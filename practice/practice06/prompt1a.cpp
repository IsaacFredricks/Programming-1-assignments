#include <iostream>
#include <limits>

int main() {
    
    int num {};
    
    while(num < 1 || num > 100){
        
	    std::cout << "Pick a number between 1 and 100 (inclusive): ";
	    std::cin >> num;
	    
	    if(std::cin.fail()){
	        std::cin.clear(); //clears the error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	        std::cout << "Invalid input. Please try again.\n";
	        continue;
	    }
	    
	    if(num < 1 || num > 100){
	        std::cout << "Not within range. Try again.\n";
	    }
    }
    
    std::cout << "That number is within range\n";
    
	return 0;
}
