#include <iostream>
#include <fstream>
#include <limits>
#include <random>//for the std::mt19937

int getInt(const std::string& prompt){//from assignment 3
    
    int input;
    
    while (true){
        std::cout << prompt;
        std::cin >> input;
    
        if(std::cin.fail() || input <= 0){
            std::cin.clear(); //clears the error
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //discards invalid input
        
             std::cout << "Inproper input. please try again.\n";
        }
        else{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
            //discards any extra input
            break;//exits loop
        }
    }
    
    return input;
}

int main() {
	int numSides{getInt("Enter the number of sides the dice should have: ")};
	
	
	//initializes the mersenne twister
	std::mt19937 mt{std::random_device{}()};
	//makes mt dependant on a random device
	//makes each run different
	
	//the range of what the dice roll can roll
	std::uniform_int_distribution dice{1, numSides};
	
	for(int i{1}; i <= 20; i++){
	    std::cout << dice(mt) << " ";//does a dice roll
	    
	    if(i % 5 == 0){
	        std::cout << '\n';//starts a new line every 5th roll
	    }
	}
	return 0;
}
