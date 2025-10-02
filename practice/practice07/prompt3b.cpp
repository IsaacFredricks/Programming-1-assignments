#include <iostream>
#include <limits>

float getFloat(const std::string& prompt){//reused from assignment 3
    
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


float multiplyTwoNumbers(float num1, float num2){
    return (num1 * num2);
}
int main() {
    
	float floaty1 {getFloat("Enter float number 1: ")};
	float floaty2 {getFloat("Enter float number 2: ")};
	
	std::cout << "Multiplying these two numbers yields "
	<< multiplyTwoNumbers(floaty1, floaty2) << '\n';
	
	return 0;
}
