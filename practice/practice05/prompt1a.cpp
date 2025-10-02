#include <iostream>
#include <vector>
#include <limits>

void printForward(std::vector<int> vect){ //prints vector in forward order
    for(int i = 0; i < vect.size(); i++){
        if(i == vect.size() - 1){
            std::cout << vect.at(i) << '\n';
        }
        
        else{
        std::cout << vect.at(i) << ", ";
        }
    }
}

void printBackward(std::vector<int> vect){ //prints vector in reverse order
    for(int i = vect.size() - 1; i >= 0; i--){
        if(i == 0){
            std::cout << vect.at(i) << '\n';
        }
        
        else{
        std::cout << vect.at(i) << ", ";
        }
    }
}

int main() {
    std::vector<int> nums(4);//makes a vector with 4 variables init to 0
    char fOrR;
	std::cout << "Enter 4 integers: ";
	std::cin >> nums.at(0) >> nums.at(1) >> nums.at(2) >> nums.at(3);
	//I would normally not do this but I wanted to follow the example
	
	if(std::cin.fail()){
	    std::cout << "Inproper input. Please restart to try again.\n";
	}
	
	else{
         std::cout << "Do you want to print them in forward or reverse order? (f/r): ";
         std::cin >> fOrR;
         
        if(std::cin.fail()){
	        std::cout << "Inproper input. Please restart to try again.\n";
	    }
	    
	        if(fOrR == 'f'){
	            std::cout << "The values in forward order are: ";
	            printForward(nums);
	        }
	        
	        else if(fOrR == 'r'){
	            std::cout << "The values in reverse order are: ";
	            printBackward(nums);
	        }
	        
	        else{
	            std::cout << "Inproper input. Please restart to try again.\n";
	        }
	}
	return 0;
}
