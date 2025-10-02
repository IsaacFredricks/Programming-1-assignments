#include <iostream>
int main() {
	std::cout << "Multiplication table! Enter a number to make a table" 
	<< " up to 10x the number: ";
	int num{};
	std::cin >> num;
	
	if(std::cin.fail()){
	    std::cout << "Invalid input. Restart to try again.\n";
	}
	
	else{
    	for(int i = 1; i <= 10; ++i){
	        std::cout << (num * i) << ' ';
	    }
	}
	std::cout << '\n';
	return 0;
}
