#include <iostream>
#include <vector>
//changed from struct
/*
class Cup {
    int id;
    int percentFull;
};
*/
class Cup {
private:
    int id;
    int percentFull;
public:
    Cup(int cupId) : id(cupId), percentFull(0) {}
    
    /*int getId() const {
        return id;
    }*/
    bool matchId(int searchId) const {
        return id == searchId;
    }
    
    void print() const{
        std::cout << "Cup ID: " << id << ", Percent Full: " << percentFull << "%" << std::endl;
    }
    
    void fill(){
        percentFull += 10;
        if (percentFull > 100) {
            percentFull = 100;
        }
    }
};
 
 
Cup& findCup(std::vector<Cup>& cups, int searchId) {
    for (Cup& cup : cups) {
        if (cup.matchId(searchId)) {
            return cup;
        }
    }
    return cups.at(0); //return the first cup if we couldn't find one
}
/*Cup newCup(int cupId) {
    Cup c;
    c.id = cupId;
    c.percentFull = 0;
    return c;
}
 
void fill(Cup& c) {
    c.percentFull += 10;
    if (c.percentFull > 100) {
        c.percentFull = 100;
    }
}
 
void print(const Cup& c) {
    std::cout << "Cup ID: " << c.id << ", Percent Full: " << c.percentFull << "%" << std::endl;
}*/
 
int main() {
    std::vector<Cup> cups = { Cup(1), Cup(2), Cup(3) };
    
    int searchId;
    std::cout << "Enter cup ID to find: ";
    std::cin >> searchId;
    
    Cup& foundCup = findCup(cups, searchId);
    foundCup.print();
    //Cup myCup(1);
    //myCup.percentFull = 200; bad
    //print(myCup); errors out
    //myCup.print();
    //myCup.fill();
    //print(myCup);
    //myCup.print();
    return 0;
}
