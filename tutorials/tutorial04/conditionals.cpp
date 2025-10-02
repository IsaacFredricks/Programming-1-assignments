#include <iostream>
int main() {
	int day = 2;
	switch(day){
	    case 1: std::cout << "Monday\n"; break;
	    case 2: std::cout << "Tuesday\n"; break;
	    default: std::cout << "Other Day";
	}
	int x = 1;
	if(x > 5){
	    std::cout << "x is greater than 5" << std::endl;
	}
	else{
	    std::cout << "x is less than 5" << std::endl;
	}
	return 0;
}
