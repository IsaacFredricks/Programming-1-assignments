#include <iostream>
#include <vector>

void isEvenNums(std::vector<int> vect1, std::vector<int> vect2){
    
    for(int i = 0; i < vect1.size(); i++){
        
        if(vect1.at(i) % 2 == 0){//checks if it's even
            vect2.push_back(vect1.at(i));

        }
        
    }
    

        
        std::cout << "You entered " << vect2.size() << " Even Numbers\n";
        
        if(vect2.size() == 0){
            std::cout << "There is no last or first even number because you "
            << "didn't enter any.\n";
        }
        
        else{
            std::cout << "The first even number is " << vect2.front() << '\n';
            std::cout << "The last even number is " << vect2.back() << '\n';
            }
    }

int main() {
    std::vector<int> allNums(4);
    std::vector<int> evenNums {}; 
    
	std::cout << "Enter 4 integers: ";
	
    std::cin >> allNums.at(0) >> allNums.at(1) >> allNums.at(2) 
    >> allNums.at(3);
    
    if(std::cin.fail()){
        std::cout << "Invalid input. Restart to try again.\n";
    }
    
    else{
        isEvenNums(allNums, evenNums);
    }
        
	return 0;
}
