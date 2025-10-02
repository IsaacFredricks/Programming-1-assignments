#include <iostream>
#include <cmath>  // For using std::sqrt and std::pow
 
// Define the Point class
class Point {
public:
    float x;
    float y;
    
    // Constructor to initialize a point
    Point(float xCoord, float yCoord) : x{xCoord}, y{yCoord} {}
};
 
// Function to calculate the distance between two points
float calcDistance(const Point* p1, const Point* p2) {
    // TODO: Implement the distance formula here using p1 and p2
    // Hint: Use the formula sqrt((x2 - x1)^2 + (y2 - y1)^2)
    float distance{sqrt(pow((p2->x - p1->x), 2.0f) + pow((p2->y - p1->y), 2.0f))};
    
    return distance;
}
 
int main() {
    // Step 1: Create two points with sample coordinates
    Point point1(3.0f, 4.0f);  // Example: Point at (3, 4)
    Point point2(7.0f, 1.0f);  // Example: Point at (7, 1)
    
    // Step 2: Call calcDistance using pointers to point1 and point2
    // TODO: Pass the addresses of point1 and point2 to calcDistance
    float distance = calcDistance(&point1, &point2);
 
    // Step 3: Print the calculated distance
    std::cout << "Distance between points: " << distance << std::endl; //Should be 5
 
    return 0;
}
