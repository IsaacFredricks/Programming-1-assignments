#include <iostream>
#include <limits>
#include <cmath>

int getInt(const std::string& prompt){//reused from assignment 3
    
    int input;
    
    while (true){
        std::cout << prompt;
        std::cin >> input;
    
        if(std::cin.fail()){
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
}
    
    void squareValue(int& num){
        //pass by ref function
        //not recommended unless the parameters are constant and/or
        //you are passing an array
        //it changes the original value being passed, unlike pass by value
        num = pow(num, 2);
    }

int main() {
	int num{getInt("Enter an integer: ")};
	
	std::cout << num << " squared is ";//before squaring
	squareValue(num);
	
	std::cout << num << '\n';//after squaring
	return 0;
}
