#include <iostream>
#include <cmath> //I remember you doing this last week.
int main() {
    /*Gives hypotnuse of two side lengths    
    
    Remember the pythagorean theorem: a squared + b squared = c squared
    */
    double sideOne {}; //we don't want to give these values just yet since we will be replacing them soon
    double sideTwo {}; //value init
	std::cout << "Please enter side 1 length: \n";
	
	std::cin >> sideOne;
	
	std::cout << "Please enter side 2 length: \n";
	
	std::cin >> sideTwo;
	
	/*I remembered you doing the power thing last week but I had to look up how to do a square root.
	Here's the link I used : https://www.scaler.com/topics/sqrt-in-cpp/
	
	It works by inputting the variable you want to use then it calculates the square root of it.
	
	In this case we are using it to find the hypotnuse (aka c).
	*/
	
	/*double hypotnuse(sqrt(pow(sideOne, 2) + pow(sideTwo, 2))); original
	way I did it. 
	*/
	
	double hypotnuse(hypot(sideOne, sideTwo));
	
	std::cout << "The hypotnuse rounded to the nearest hundred thousandth: "
	<< hypotnuse << '\n';
	
	return 0;
}