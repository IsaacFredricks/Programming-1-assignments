#include <iostream>
struct Car {
    std::string make;
    int year;
};
int main() {
	Car myCar = {"Toyota", 2020};
	std::cout << myCar.make << '\n';
	myCar.make = "Honda";
	std::cout << myCar.make << '\n';
	return 0;
}
