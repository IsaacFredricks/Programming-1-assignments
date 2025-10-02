#include <iostream>


int main() {
    
    while(true){//makes intentional infinite loop
        std::cout << "Do you like sit down restaurants? (y or n): ";
        char answer {};
        std::cin >> answer;
        
        if(std::cin.fail()){
            std::cin.clear(); //clears the error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That wasn't a y or n. Please try again.\n";
            continue;//goes to next iteration
        }
        
        if(answer == 'y' || answer == 'Y'){
            std::cout << "That's cool.\n";
            break;//break out of loop
        }
        
        else if(answer == 'n' || answer == 'N'){
            std::cout << "That's cool.\n";
            break;//break out of loop
        }
        
        else{
            std::cout << "That wasn't a y or n. Please try again.\n";
        }
        
    }
    
    std::cout << "You successfully exited the loop\n";
	return 0;
}
