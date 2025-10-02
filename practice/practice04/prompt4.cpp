#include <iostream>
int main() {
    //all the age group values
    int oldAgeGroup {65};
    int adultAgeGroup {20};
    int teenAgeGroup {13};
    int child {0};
    int tooBig {2147483647};
    int probablyLying {130};
    int age{};
    
	std::cout << "Enter your age:" << std::endl;
	std::cin >> age;
	
	if(std::cin.fail()){//just in case someone puts an inproper value
	    std::cout << "Really. That's not what I asked. Goodbye.\n";
	}
	else{
	    if(age >= probablyLying && age <= tooBig || age < child){ 
	        /*just in case someone puts a really big number for age
	        or a negative number*/
	        std::cout << "You are lying, aren't you?\n";
	    }
	    else if(age >= oldAgeGroup){
	        std::cout << "You are a senior.\n";
	    }
	    else if(age >= adultAgeGroup){
	        std::cout << "You are an adult.\n";
	    }
	    else if(age >= teenAgeGroup){
	        std::cout << "You are a teen.\n";
	    }
	    else{
	        std::cout << "You are a child.\n";
	    }
	}
	
	return 0;
}
