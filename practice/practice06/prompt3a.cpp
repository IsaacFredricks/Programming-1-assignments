#include <iostream>
#include <cstdlib> //for rand() and srand() function
#include <time.h> //for time() function

//I wasn't sure how to do a random number, so I looked it up on google
//source: https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
int main() {
    int guess {};
    int range {100};//range of the random number
    
    //had error that rand() would get the same number. line below fixes it
    srand(time(0));
    //rand() is dependant on srand(), which sets starting point of making
    //a series of psuedo random integers. Making srand() dependant on time(0)
    
    
    //time(0) returns the time at 0 
    
    //random function call. without plus 1, the range of random is 0 to 99
    //now its 1 to 100
    int random {(rand() % range) + 1};
    //std::cout << random << '\n';//testing random number
    
    
    while(true){
        std::cout << "Guess the number. It's between 1 and 100 (inclusive): ";
        std::cin >> guess;
        
        if(std::cin.fail()){
            std::cout << "Inproper input. Try again.\n";
            continue; //goes to next iteration
        }
        
        if(guess == random){
            break;
        }
        
        else if(guess > random){
            std::cout << "Too high!\n";
        }
        
        else{
            std::cout << "Too low!\n";
        }
        
    }
    
    std::cout << "You guessed correctly!\n";
	return 0;
}
