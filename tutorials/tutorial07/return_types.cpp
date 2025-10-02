#include <iostream>
#include <vector>
 
struct Cat {
    std::string name;
    int hunger;
};
 
Cat getCatRef(std::vector<Cat> cats, int index);
Cat getCatValue(std::vector<Cat> cats, int index); // Pass by value version
 
int main() {
    std::vector<Cat> cats = {{"Whiskers", 5}, {"Fluffy", 3}};
 
    Cat& refCat = getCatRef(cats, 0);
    refCat.hunger += 1;
    std::cout << "Hunger after modifying by reference: " << cats.at(0).hunger << "\n";
    //std::cout << "Hunger after modifying by reference: " << &refCat << "\n";
    Cat valueCat = getCatValue(cats, 1);
    valueCat.hunger += 1;
    std::cout << "Hunger after modifying by value: " << cats.at(1).hunger << "\n";
 
    return 0;
}
 
Cat getCatRef(std::vector<Cat> cats, int index) {
    return cats.at(index);
}
 
Cat getCatValue(std::vector<Cat> cats, int index) { // Pass by value
    return cats.at(index);
}