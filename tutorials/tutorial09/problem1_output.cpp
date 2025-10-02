#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

//HELPER FUNCTION FOR NOW.  DON'T WORRY ABOUT ITS CONTENTS.
void listFilesInDirectory() {
    std::cout << "FILES IN YOUR DIRECTORY\n=======================\n";
    for (const auto& entry : std::filesystem::directory_iterator(".")) {
        std::cout << entry.path().filename() << std::endl;
    }
    std::cout << "=======================\n\n";
}
 
 
//HELPER FUNCTION FOR NOW.  DON'T WORRY ABOUT ITS CONTENTS.
void showFileContents(const std::string& filename) {
    std::ifstream fin{filename};
    std::cout << "CONTENTS OF " << filename << "\n=======================\n";
    std::string line;
    while (std::getline(fin, line)) {
        std::cout << line << std::endl;
    }
    std::cout << "=======================\n\n";
}

struct Names{
  std::string nameOne;
  std::string nameTwo;
};
 
int main() {
    Names nombres {};//i had trouble figuring out a variable name for a bit
    nombres.nameOne = "Bob";
    nombres.nameTwo = "Kevin";
    std::vector<char> vect {'a', 'b', 'c'};
    std::string filename = "hello.txt";
 
    listFilesInDirectory();
 
    std::ofstream fout{filename};//output file stream. writes data to file
    fout << "Hello, World!\n";
    fout << "Hello, World!\n";
    fout << "Hello, World!\n";
    fout << "Hello, World!\n";
    //fout << vect << '\n'; //errors out
    //fout << nombres << '\n';//errors out
    fout << nombres.nameOne << '\n';
    fout << nombres.nameTwo << '\n';
    
    for(int i {0}; i < vect.size(); i++){
        fout << vect.at(i) << '\n';
    }
    fout.close();
 
    //std::ofstream fout2{filename};
    std::ofstream fout2{filename, std::ofstream::app};//app here means append
    fout2 << "Another message!";
    fout2.close();

    listFilesInDirectory();
    showFileContents(filename);
    showFileContents(filename);
    showFileContents(filename);
    
    return 0;
}