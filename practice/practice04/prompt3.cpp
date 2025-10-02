#include <iostream>

/*this program asks for the width and the length of a rectangle, then it prints 
the area*/
struct Rectangle{
    //both float values
    float length;
    float width;
};

//using a function to calculate area so I can reuse code later
float rectangleArea(float len, float wid){
    float area {len * wid};
    return area;
}
int main() {
    Rectangle rect; //can init without values
	std::cout << "Enter the length of the rectangle: ";
	std::cin >> rect.length;
	
	std::cout << "Enter the width of the rectangle: ";
	std::cin >> rect.width;
	
	std::cout << "Calculating area...\n";
	std::cout << "The area of it is " << rectangleArea(rect.length,rect.width)
	<< '\n'; //I put it at a new line to not pass 80 characters
	return 0;
}
