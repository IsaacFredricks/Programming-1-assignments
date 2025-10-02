#include <iostream>
#include <fstream>
#include <vector>
 
struct Point {
    int x, y;
};
 
void printPointVector(const std::vector<Point>& points) {
    for (const auto& point : points) {
        std::cout << "(" << point.x << ", " << point.y << ")\n";
    }
}
 
int main() {
    std::ifstream fin{"numbers.txt"};//file input. reads data from file
    
    if (!fin.is_open()) {
        std::cerr << "Failed to open the file.\n";
        return 1;
    }
    
    /*else{
        
        while(true){
            int num;
            fin >> num;
            std::cout << "number: " << num << std::endl;
        }
        
    }*/
    
    
    std::vector<Point> points;
    for (int i = 0; i < 4; ++i) {
        points.push_back(Point());
        fin >> points.back().x >> points.back().y;
    }
    printPointVector(points);
   /*
    int num;
    fin >> num;
    std::cout << "First number: " << num << std::endl;
    */
    return 0;
}