#include <iostream>

//switch statement for operations
void operations(char sign, int num1, int num2){ 
    //put it in a function to make it easier to use
    switch(sign){
        case '+':  
        std::cout << num1 << " + " << num2 << " = " << (num1 + num2) << '\n';
        break;
        /*anything under case is implicitly in it
        until end of scope or another case*/
        case '-':  
        std::cout << num1 << " - " << num2 << " = " << (num1 - num2) << '\n';
        break;
        
        case '/':  
        std::cout << num1 << " / " << num2 << " = " << (num1 / num2) << '\n';
        break;
        
        case '*':  
        std::cout << num1 << " * " << num2 << " = " << (num1 * num2) << '\n';
        break;
        
        default:
        std::cout << "An operator was entered incorrectly.\n";
        break;
        //should resolve most incorrect operators
    }
}
int main() {
    char theSign{};
    int numberOne {};
    int numberTwo {};
    std::cout << "enter an integer: ";
    std::cin >> numberOne;
    
    if(std::cin.fail()){ //in case of an incorrect value input
        std::cout << "An incorrect value was input. Goodbye.\n";
    }
    else{
        std::cout << "enter another integer: ";
        std::cin >> numberTwo;
        
        if(std::cin.fail()){//you can never be too careful
        std::cout << "An incorrect value was input. Goodbye.\n";
        }
        
        else{//can have nested statements
            //if all goes right. It should ask for the operator.
            std::cout << "enter an operator. + is add, - is subtract, / is "
	        << "divide, * is multiply (*divisions with a decimal point "
	        << "will be truncated): ";
	        std::cin >> theSign;
	        
	        std::cout << "Calculating now...\n";
	        
	        //calls operations function
	        operations(theSign, numberOne, numberTwo);
        }
    }
	return 0;
}
