#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <random>//for random_device

float getFloat(const std::string& prompt){//from assignment 3
    
    float input;
    
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
	float avgPrice {getFloat("Enter the average house price: ")};
	float standardDeviation {getFloat("Enter the standard deviation: ")};
	
	std::random_device seed;//makes it random each run
	std::default_random_engine engine(seed());
	
	std::normal_distribution normDistro(avgPrice, standardDeviation);
	//(mean, standard deviation)
	
	for(int i{0}; i < 10; ++i){
	    std::cout << "House price: $" 
	    << (int)(normDistro(engine) * 100 + 0.5) / 100.0 << '\n';
	    //setprecision() rounds but it was bugging out
	}
	return 0;
}
