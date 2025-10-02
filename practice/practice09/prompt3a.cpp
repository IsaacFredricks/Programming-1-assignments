#include <iostream>
#include <fstream>
#include <filesystem>

//reusing the numbers.txt from earlier
void showFileContents(const std::string& filename) {
    std::ifstream fin{filename};
    
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

void sumNumbers(const std::string& fileName){
    std::ifstream fin(fileName);//It says not to ifstream multiple times
    //and make a global namespace, but I don't know how
    std::ofstream fout{"sum.txt"};
    
    if(!fout.is_open()){//just in case
	    std::cerr << "Failed to open the file.\n";
	}
	
	else{
	    //the first line is ignored since that is the number of numbers
	    int sum {};
	    std::string line {};
	    while (std::getline(fin, line)) {
            int num {};
            fin >> num;
            sum += num;
        }
        
        fout << sum;
        fin.close();
        fout.close();
	}
}

int main() {
    std::string fileName {"numbers.txt"};
    
    sumNumbers(fileName);
    showFileContents("sum.txt");
	return 0;
}
