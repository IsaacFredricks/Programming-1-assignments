#include <iostream>
#include <string>

//enum of all the traffic light colors
enum class TrafficLight{Red, Yellow, Green};

//self explanetory name
void printTrafficLight(TrafficLight lights){ 
    switch (lights){
        case TrafficLight::Red: std::cout << "Stop\n"; break;
        
        case TrafficLight::Yellow: std::cout << "Slow Down\n"; break;
        
        case TrafficLight::Green: std::cout << "Go\n"; break;
        
        default: std::cout << "not a valid input\n"; break;
    }
}

int main() {
    int enteredNumber;//default init
	std::cout << "Enter a number 0, 1, or 2 (0 = Red, 1 = Yellow, 2 = Green): ";
	std::cin >> enteredNumber; //assings value
	
	/*if the input can't be parsed as an int, it auto init as 0.
	I don't want that to happen, so this if statement is there to catch that.
	My original plan was just to shift every index and input up by 1, but
	that creates a magic number (1), and it isn't good by coding
	convention standards and isn't easy to understand at first.
	*/
	if(std::cin.fail()){ 
	    std::cout << "Please follow directions. Bye, have a good day.\n";
	}
	else{
	//casts int to enum type. Can't std::cin enum by default
	TrafficLight light = static_cast<TrafficLight>(enteredNumber);
	printTrafficLight(light); //this function gets called
	}
	return 0;
}
//creator-Isaac Fredricks