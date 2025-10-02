#include <iostream>
enum Color {RED, GREEN, BLUE};
enum TrafficLight {RED, YELLOW, GREEN}; //comment out to stop errors
enum Weekday {MONDAY, TUESDAY, WEDNESDAY};
int main() {
    Color myColor = RED;
    int color = RED;
    int MONDAY = 7; //shadowing enum value
    std::cout << MONDAY << '\n';
	std::cout << myColor << std::endl;
	return 0;
}
