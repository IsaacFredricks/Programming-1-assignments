#include <iostream>
#include <cmath> //for math functions like pow()

//calculates area of a circle using the radius by the user
//I wanted this to be a seperate function so I can reuse it for later
double circleArea(double rad){
    const double PI_CONSTANT {3.14159}; //immutable variable
    double area{PI_CONSTANT * pow(rad, 2.0)};
    return area;
}

int main() {
    double radius {};
	std::cout << "Enter a radius" << std::endl;
	
	std::cin >> radius;
	
	std::cout<< "The area of a circle is " << circleArea(radius) << '\n';
	
	return 0;
}
