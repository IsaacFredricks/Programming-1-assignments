#include <iostream>

int getUserAge(){
    int age{};
    std::cin >> age;
    
    if(std::cin.fail() || age < 0){//in case of inproper input
        return -1;//the user can't input -1. So, this will tell if 
        //it's an inproper input
    }
    
    else{
        return age;
    }
}

int main() {
    //calling the function by itself does not output anything.
    std::cout << "Enter your age: ";
    int age {getUserAge()};
    if(age == -1){
        std::cout << "Inproper input. Restart to try again.\n";
    }
    
    else{
        std::cout << "Your age is " << age << '\n';
    }
	return 0;
}
