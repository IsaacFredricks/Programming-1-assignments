#include <iostream>
#include <vector>
#include <limits>
 
class Rectangle {
public:
    Rectangle(int w, int h) : w(w), h(h) {}
 
    int area() const {
        return w * h;
    }
 
private:
    int w;
    int h;
};
 
Rectangle* findBiggestRectangle(std::vector<Rectangle*>& rects) {
    Rectangle* biggest = rects.at(0);
    for (auto rect : rects) {
        if (rect->area() > biggest->area()) {
            biggest = rect;
        }
    }
    return biggest;
}
 
int main() {
    std::vector<Rectangle*> rectangles;
    int choice;
 
    do {
        std::cout << "\nRectangle Manager\n";
        std::cout << "1. Add Rectangle\n";
        std::cout << "2. Find Biggest Rectangle\n";
        std::cout << "3. Clear Rectangles\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
 
        switch (choice) {
            case 1:
                int width, height;
                std::cout << "Enter width: ";
                std::cin >> width;
                std::cout << "Enter height: ";
                std::cin >> height;
                rectangles.push_back(new Rectangle(width, height));
                std::cout << "Rectangle added.\n";
                break;
            case 2:
                if (rectangles.empty()) {
                    std::cout << "No rectangles available.\n";
                } else {
                    Rectangle* biggest = findBiggestRectangle(rectangles);
                    std::cout << "Biggest rectangle area: " << biggest->area() << "\n";
                }