#include <iostream>
int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
//two of the same name. the compiler can't tell them apart
int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
	
/*	double_main.cpp:7:5: error: redefinition of ‘int main()’
    7 | int main() {
      |     ^~~~
double_main.cpp:2:5: note: ‘int main()’ previously defined here
    2 | int main() {
      |     ^~~~
/bin/sh: 1: ./double_main: not found
*/
}