#include <iostream>

void printWelcomeMessage(){
    std::cout << "Welcome to the program!\n";
}

int main() {
    char yOrN {};
	std::cout << "Would you like a welcome message? y or n: " << std::endl;
	std::cin >> yOrN;
	
	if(std::cin.fail()){
	    std::cout << "Inproper input. Restart to try again.\n";
	}
	else if(yOrN == 'y' || yOrN == 'Y'){
	    printWelcomeMessage();
	}
	else if(yOrN == 'n' || yOrN == 'N'){
	    std::cout << "Alright then.\n";
	}
	else{
	    std::cout << "Inproper input. Restart to try again.\n";
	}
	return 0;
}
