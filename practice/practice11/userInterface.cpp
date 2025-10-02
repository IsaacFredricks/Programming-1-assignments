#include <iostream>
#include "Circle.h"
#include "Circle.cpp"
#include <limits>

//forward declarations
int getInt(const std::string& prompt);
double getDouble(const std::string& prompt);

int main() {
    
    bool circleMade {false};
    
    while(true){
        Circle circ;
        std::cout << "\n=====Menu=====\n" << "1. Exit\n" << "2. Make Circle\n"
        << "3. Get Radius\n" << "4. Set Radius\n" 
        << "5. Get Max Radius\n" << "6. Set Max Radius\n" << "7. Get Area\n" 
        << "8. Get Perimeter\n" << "9. Scale The Radius\n";
        
        int i {getInt("Enter a choice: ")};
        
        if(i == 1){
            std::cout << "Bye.\n";
            break;//early return
        }
        
        else if(i == 2){
            circleMade = true;
            std::cout << "Do you want to set the radius now? y or n: ";
            char c {};
            std::cin >> c;
            
            if(c == 'y' || c == 'Y'){
                double rad {getDouble("Enter the radius: ")};
                circ.setRadius(rad);
                std::cout << "The circle has been made.\n";
            }
            
            else if(c == 'n' || c == 'N'){
                if(circ.getRadius() > 0){
                    circ.setRadius(0.0);
                    std::cout << "A 0 radius circle has been made.\n";
                }
                else{
                    std::cout << "A 0 radius circle has been made.\n";
                }
            }
            
            else{
                std::cout << "Invalid input. Choose this option again " 
                << " to try again.\n";
            }
        }
        
        else if(i == 3 && circleMade){
            std::cout << "The radius is " << circ.getRadius() << '\n';
        }
        
        else if(i == 4 && circleMade){
            double rad {getDouble("Enter the radius: ")};
            circ.setRadius(rad);
        }
        
        else if(i == 5 && circleMade){
            std::cout << "The max radius is " << circ.getMaxRadius() << '\n';
        }
        
        else if(i == 6 && circleMade){
            double maxRad {getDouble("Enter the max radius: ")};
            circ.setMaxRadius(maxRad);
        }
        
        else if(i == 7 && circleMade){
            std::cout << "The area is " << circ.area() << '\n';
        }
        
        else if(i == 8 && circleMade){
            std::cout << "The perimeter is " << circ.perimeter() << '\n';
        }
        
        else if(i == 9 && circleMade){
            double factor {getDouble("Enter the scale factor: ")};
            circ.scale(factor);
        }
        
        else{
            std::cout << "If you tried entering 3 through 9 without making a "
            << "circle, try making one!\n";
            std::cout << "Otherwise it's an invalid input. Try again.\n";
        }
    }
	return 0;
}

int getInt(const std::string& prompt){//reused from assignment 3
    
    int input;
    
    while (true){
        std::cout << prompt;
        std::cin >> input;
    
        if(std::cin.fail() || input < 0){
            std::cin.clear(); //clears the error
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //discards invalid input
        
             std::cout << "Inproper input. please try again.\n";
        }
        else{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
            //discards any extra input
            break;//exits loop
        }
    }
    
    return input;
}

//not required, but nice to have
double getDouble(const std::string& prompt){
    
    double result {};
    
    while (true){
        std::cout << prompt;
        std::cin >> result;
        
        if(std::cin.fail() || result < 0){
            std::cin.clear(); //clears the error
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //discards invalid input
        
           std::cout << "Inproper input. please try again.\n";
        }
        else{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return result;
            //discards any extra input
            break;//exits loop
        }
    }
}
