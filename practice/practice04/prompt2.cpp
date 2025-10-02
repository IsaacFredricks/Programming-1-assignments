#include <iostream>
#include <string> //here for the getline() and strings
#include <tuple> //for tuples

//is what it says on the tin
void printStudentTuple(int theID, std::string theName, float gradePoint){
    auto studentInfo = std::make_tuple(theID, theName, gradePoint);
    std::cout << "Name: " << theName << "\nID: " << theID << "\nGPA: "
    << gradePoint << '\n';
}

//this program makes a tuple of a students id, name and gpa
int main() {
    //this program does not store your personal info.
    //declares variables here
    int studentID {};
    std::string name {};
    float gpa;
    
	std::cout << "Enter your student id: ";
	std::cin >> studentID;
	
	if(std::cin.fail()){
	    std::cout << "That was an inproper input. Goodbye.\n";
	}
	else{
	std::cin.ignore();
	//prevents any wierdness when going from std::cin to getline()
	
	std::cout << "Enter your name: ";
	getline(std::cin, name);
	//use getline() for string
	
	std::cout << "Enter your GPA: ";
	std::cin >> gpa;
	if(std::cin.fail()){
	    std::cout << "That was an inproper input. Goodbye.\n";
	}
	else{
	    printStudentTuple(studentID, name, gpa); //calls printStudentTuple
	}
	}
	return 0;
}
//creator-Isaac Fredricks