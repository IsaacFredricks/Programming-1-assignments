#include <iostream>
#include <fstream>
#include <vector>
 
struct Point {
    int x, y;
};
 
//HELPER FUNCTION FOR NOW.  DON'T WORRY ABOUT ITS CONTENTS.
void showFileContents(const std::string& filename) {
    std::ifstream fin(filename);
    std::cout << "CONTENTS OF " << filename << "\n=======================\n";
    std::string line;
    while (std::getline(fin, line)) {
        std::cout << line << std::endl;
    }
    std::cout << "=======================\n\n";
}
 
 
void savePointsToFile(const std::string& filename, const std::vector<Point>& points) {
    std::ofstream fout(filename);
    fout << "vector size: " << points.size() << std::endl;//makes it easier to read
    for (const auto& point : points) {
        fout << point.x << " " << point.y << std::endl;
    }
}
 
std::vector<Point> loadPointsFromFile(const std::string& filename) {
    std::ifstream fin(filename);
    std::vector<Point> points;
    int size;
    fin >> size;
    for (int i = 0; i < size; ++i) {
        Point p;
        fin >> p.x >> p.y;
        points.push_back(p);
    }
    return points;
}
 
int main() {
    std::vector<Point> points = {{2, 3}, {4, 5}, {6, 7}};
 
    savePointsToFile("points.txt", points);
    showFileContents("points.txt");
    
    
    auto vec2 = loadPointsFromFile("points.txt");
    //vec2.back().y = 99;
    savePointsToFile("points.txt", vec2);
    showFileContents("points.txt");
    
    return 0;
}