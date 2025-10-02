#include <iostream>
#include <vector>
#include <limits>//for cin errors

struct People{
    std::string name;
    int age;
};

int main() {
    std::vector<People> people(3);
    int i = 0; //index
    
    while(i < people.size()){
        std::cout << "Enter the name and age of person " << (i + 1) << ": ";
	    std::cin >> people.at(i).name >> people.at(i).age;
	    
	    if(std::cin.fail() || people.at(i).age < 0){
	        std::cin.clear(); //clears the error
	        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //discards invalid input
            
	        std::cout << "Inproper input. Please retype the names and ages for"
	        << " the people.\n";
	        
	        i = 0;//resets loop
	    }
	    else{
	        i++;
	    }
	    
    }
    
    //I wasn't sure how to do this simpler
    
    //basically it looks to see in each if/if else statement who is the oldest
    //and who is the youngest
    
    //these one's are if the 1st person is the oldest
    if(people.at(0).age > people.at(1).age 
    && people.at(0).age > people.at(2).age 
    && people.at(2).age < people.at(1).age){
        
        std::cout << people.at(0).name << " is " 
        << (people.at(0).age - people.at(1).age) << " year(s) older than "
        << people.at(1).name << '\n';
    }
    
    else if(people.at(0).age > people.at(1).age 
    && people.at(0).age > people.at(2).age 
    && people.at(2).age > people.at(1).age){
        
        std::cout << people.at(0).name << " is " 
        << (people.at(0).age - people.at(2).age) << " year(s) older than "
        << people.at(1).name << '\n';
    }
    
    else if(people.at(0).age > people.at(1).age 
    && people.at(0).age > people.at(2).age 
    && people.at(2).age == people.at(1).age){
        
        std::cout << people.at(0).name << " is " 
        << (people.at(0).age - people.at(2).age) << " year(s) older than "
        << people.at(1).name << " and " << people.at(2).name 
        << " because " << people.at(1).name << " and " << people.at(2).name 
        << " are of equal age." << '\n';
    }
    
    //these one's are if the 2nd person is the oldest
    else if(people.at(1).age > people.at(2).age 
    && people.at(1).age > people.at(0).age 
    && people.at(2).age > people.at(0).age){
        
        std::cout << people.at(1).name << " is " 
        << (people.at(1).age - people.at(0).age) << " year(s) older than "
        << people.at(2).name << '\n';
    }
    
    else if(people.at(1).age > people.at(2).age 
    && people.at(1).age > people.at(0).age 
    && people.at(2).age < people.at(0).age){
        
        std::cout << people.at(1).name << " is " 
        << (people.at(1).age - people.at(2).age) << " year(s) older than "
        << people.at(2).name << '\n';
    }
    
    else if(people.at(1).age > people.at(2).age 
    && people.at(1).age > people.at(0).age 
    && people.at(2).age == people.at(0).age){
        
        std::cout << people.at(1).name << " is " 
        << (people.at(1).age - people.at(2).age) << " year(s) older than "
        << people.at(0).name << " and " << people.at(2).name
        << " because " << people.at(0).name << " and " << people.at(2).name 
        << " are of equal age." << '\n';
    }
    
    //these one's are if the 3rd person is the oldest
    else if(people.at(2).age > people.at(1).age 
    && people.at(2).age > people.at(0).age 
    && (people.at(1).age > people.at(0).age)){
        
        std::cout << people.at(2).name << " is " 
        << (people.at(2).age - people.at(0).age) << " year(s) older than "
        << people.at(0).name << '\n';
    }
    
    else if(people.at(2).age > people.at(1).age 
    && people.at(2).age > people.at(0).age 
    && people.at(1).age < people.at(0).age){
        
        std::cout << people.at(2).name << " is " 
        << (people.at(2).age - people.at(1).age) << " year(s) older than "
        << people.at(1).name << '\n';
    }
    
    else if(people.at(2).age > people.at(1).age 
    && people.at(2).age > people.at(0).age 
    && people.at(1).age == people.at(0).age){
        
        std::cout << people.at(2).name << " is " 
        << (people.at(2).age - people.at(0).age) << " year(s) older than "
        << people.at(0).name << " and " << people.at(1).name
        << " because " << people.at(0).name << " and " << people.at(1).name 
        << " are of equal age." << '\n';
    }
    
    //if there are multiple biggest ages
    else if(people.at(0).age == people.at(1).age 
    && people.at(0).age > people.at(2).age){
        std::cout << people.at(0).name << " and " << people.at(1).name 
        << " are " << (people.at(0).age - people.at(2).age) 
        << " year(s) older than " << people.at(2).name << " since " 
        << people.at(0).name << " and " << people.at(1).name 
        << " are the same age.\n"; 
    }
    
    else if(people.at(0).age == people.at(2).age 
    && people.at(0).age > people.at(1).age){
        std::cout << people.at(0).name << " and " << people.at(2).name 
        << " are " << (people.at(0).age - people.at(1).age) 
        << " year(s) older than " << people.at(1).name << " since " 
        << people.at(0).name << " and " << people.at(2).name 
        << " are the same age.\n"; 
    }
    
    else if(people.at(1).age == people.at(2).age 
    && people.at(1).age > people.at(0).age){
        std::cout << people.at(1).name << " and " << people.at(2).name 
        << " are " << (people.at(1).age - people.at(0).age) 
        << " year(s) older than " << people.at(0).name << " since " 
        << people.at(1).name << " and " << people.at(2).name 
        << " are the same age.\n"; 
    }
    
    //if they are all even
    else{
        std::cout << "They are all of equal age.\n";
    }
	return 0;
}
