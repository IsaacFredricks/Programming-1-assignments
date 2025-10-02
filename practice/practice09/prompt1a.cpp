#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::vector<int> nums {};
    //looked at problem 2 of tutorial 9 to help with syntax
	std::cout << "Looking for numbers.txt..." << std::endl;
	
	std::ifstream finput{"numbers.txt"};//opens file if successful
	
	if(!finput.is_open()){
	    std::cerr << "Failed to open the file.\n";
	    return 1;
	}
	
	std::cout << "numbers.txt is found!" << std::endl;
	int num {};
	finput >> num;//stores first line of the txt file
	
    //modified from tuesday's code example
	while(true){
	    std::string line;
	    //get line accounts for whitespace, unlike >>
	    int lineRead {};
	    finput >> lineRead;
	    
	    bool boolean{std::getline(finput, line)};
	    
	    if(!boolean){
	        break;//does this if the line read was unsuccessful
	    }
	    
	    else if(lineRead == num){
	        //skips the first line
	        std::cout << "The size of the vector is " << num << '\n';
	    }
	    
	    else{
	        nums.push_back(lineRead);
	    }
	    //moves on to next line until there are no more lines to read
	    
	}
	finput.close();//flushes the buffer
	
	for(int i{0}; i < nums.size(); i++){
	    std::cout << nums.at(i) << '\n';
	}
	
	
	return 0;
}
