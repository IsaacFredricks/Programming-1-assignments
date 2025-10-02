#include <iostream>
int notMain() {
    //oh no! main has left to go fishing
    
    //^bad comment example
	std::cout << "Hello, World!" << std::endl;
	return 0;
	
	/* doesn't compile and run
	
	gives 
	
	/usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/Scrt1.o: in function `_start':
    (.text+0x1b): undefined reference to `main'
    collect2: error: ld returned 1 exit status
    /bin/sh: 1: ./no_main: not found
    
    as an error
    */
}
