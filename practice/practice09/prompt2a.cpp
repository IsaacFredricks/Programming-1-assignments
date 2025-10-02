#include <iostream>
#include <fstream>

//link to lyrics source: https://www.99-bottles-of-beer.net/lyrics.html
void showFileContents(const std::string& filename) {
    std::ifstream fin(filename);
    
    if(!fin.is_open()){//just in case
	    std::cerr << "Failed to open the file.\n";
	}
	
	else{
	    std::cout << "CONTENTS OF " << filename << "\n=======================\n";
        std::string line;
        
        while (std::getline(fin, line)) {
            //getline() gets everything, including whitespace
            std::cout << line << std::endl;
        }
        
        std::cout << "=======================\n\n";
	}
}

int main() {
	std::string fileName {"beer.txt"};
	
	showFileContents(fileName);
	return 0;
}
