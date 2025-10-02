#include <iostream>
#include <vector>


//I had to look up what isosceles and what scalene triangles were because I
//forgot
int main() {
    std::vector<int> sides(3);
    
	std::cout << "Enter the lengths of 3 sides: ";
	std::cin >> sides.at(0) >> sides.at(1) >> sides.at(2);
	
	
	if(std::cin.fail()){
	    std::cout << "Inproper value(s) input. This is not a triangle. " 
	    << "Restart to try again\n";
	}
	
	else{
	    
	    if(sides.at(0) == sides.at(1) && sides.at(1) == sides.at(2) 
	    && sides.at(1) == sides.at(2)){
	        // equilateral-> all 3 sides are equal
	        std::cout << "This triangle is equilateral.\n";
	    }
	    
	    else if((sides.at(0) == sides.at(1) 
	    || sides.at(1) == sides.at(2) || sides.at(1) == sides.at(2) 
	    || sides.at(0) == sides.at(2)) && (sides.at(0) != sides.at(1) 
	    || sides.at(1) != sides.at(2) || sides.at(1) != sides.at(2) 
	    || sides.at(0) != sides.at(2))){
	        // isosceles-> 2 sides are equal and 1 isn't
            std::cout << "This triangle is isosceles.\n";
        }
        
        else if(sides.at(0) != sides.at(1) && sides.at(1) != sides.at(2) 
        && sides.at(1) != sides.at(2) && sides.at(0) != sides.at(2)){
            //scalene-> no sides are equal
            std::cout << "This triangle is scalene.\n";
        }
        
        else{
            std::cout << "That is not a triangle.\n";
        }
	}
	return 0;
}
