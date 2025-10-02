#include <iostream>
#include <tuple>

int main() {
    
	auto tuple_name = std::make_tuple(18, "string example", 2024.5);
	std::cout << std::get<1>(tuple_name) << std::endl;
	std::get<1>(tuple_name) = "Isaac"; //changes the age
	std::cout << std::get<1>(tuple_name) << std::endl;
	
	auto car = std::make_tuple("Toyota", "Camry", 2020);
	std::string make = std::get<0>(car);
	int year = std::get<2>(car);
	std::cout << std::get<0>(car) << '\n';
	std::get<2>(car) = 2023; //changes car year in tuple car.
	
    auto [brand, model, theYear] = car; //linked to orignal variable
    //extracts multiple tuple variables at once
    
    std::cout << "Brand: " << brand << "\nModel: " << model 
    << "\nYear: " << theYear << '\n';
	return 0;
}
