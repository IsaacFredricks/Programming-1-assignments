#include <iostream>
enum class Color {RED, GREEN, BLUE};
//unlike my previous assumption, this does work since it's in the same scope as enumerators
int main() {
	//enum class Color {RED, GREEN, BLUE};
	Color myColor = Color::RED; //can access enum class Color
	std::cout << static_cast<int>(myColor) << std::endl;
	//std::cout << myColor << std::endl;
	//commented out to stop errors
	return 0;
}
