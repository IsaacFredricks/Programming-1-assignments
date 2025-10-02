#include <iostream>
#include <random>
 
int main() {
    //original engine
    //std::default_random_engine engine(10);
    
    std::random_device seed;//makes the dice rolls change each run
    std::default_random_engine engine(seed());
    
    std::uniform_int_distribution<int> dist(1, 6);
 
    for (int i = 0; i < 8; ++i) {
        std::cout << "Roll: " << dist(engine) << std::endl;
    }
    
    
    std::normal_distribution<> ndist(10, 5);
    for (int i = 0; i < 8; ++i) {
        std::cout << "Normal: " << ndist(engine) << std::endl;
    }
    return 0;
}