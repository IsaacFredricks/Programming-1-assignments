#include <iostream>
#include <limits>

float getFloat(const std::string& prompt);

int main() {
    float* sallysAllowance{new float {0.0f}};  // Sally's initial allowance. new alocates memory on heap
    float *johnsAllowance{new float {0.0f}};   // John's initial allowance
    float* dad{nullptr};          // Dad's pointer, initialized to nullptr
	
	while(true){
	    std::cout << "Who will you give allowance to? Sally or John? ";
	    std::string choice {};
	    getline(std::cin, choice);
	    
	    if(choice == "Sally" || choice == "sally"){
	        float amount = getFloat("How much allowance do you want to give to Sally? ");
	        dad = sallysAllowance;
	        *dad += amount;
	    }
	    else if(choice == "John" || choice == "john"){
	        float amount = getFloat("How much allowance do you want to give to John? ");
	        dad = johnsAllowance;//points to address of amount. can be changed
	        *dad += amount;
	    }
	    else{
	        std::cout << "That isn't one of the options!\n";
	    }
	    
	    std::cout << "Sally's Allowance: " << *sallysAllowance << '\n';
	    std::cout << "John's Allowance: " << *johnsAllowance << '\n';
	    
	    std::cout << "Do you want to give more allowance away? y or n: ";
	    char c {};
	    std::cin >> c;
	    
	    if(c == 'y' || c == 'Y'){
	        std::cout << "Alright then.\n";
	    }
	    else if(c == 'n' || c == 'N'){
	        std::cout << "Ok. Exiting program.\n";
	        break;
	    }
	    else{
	       std::cout << "That isn't one of the options!\n";
	    }
	    std::cin.ignore();
	}
	return 0;
}

float getFloat(const std::string& prompt){
    
    float result {};
    
    while (true){
        std::cout << prompt;
        std::cin >> result;
        
        if(std::cin.fail() || result < 0){
            std::cin.clear(); //clears the error
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //discards invalid input
        
           std::cout << "Inproper input. please try again.\n";
        }
        else{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return result;
            //discards any extra input
            break;//exits loop
        }
    }
}