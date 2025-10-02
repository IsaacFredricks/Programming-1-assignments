#include <iostream>

//it is what it says on the tin
double celsiusToFarenheit(double celsius){
    //I kept getting an int answer until I added a decimal point to these
    double farenheit {((9.0/5.0) * celsius) + 32.0};
    return farenheit;
}

int main() {
    double cels{};
	std::cout << "Enter a number in Celsius and I'll convert it: \n";
	
	std::cin >> cels;
	
	std::cout << cels << " in Farenheit is " << celsiusToFarenheit(cels)
	<< ".\n"; 
	//calls the celsiusToFarenheit function to convert it
	return 0;
}
