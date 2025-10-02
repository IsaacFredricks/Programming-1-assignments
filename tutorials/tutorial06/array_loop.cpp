#include <iostream>
#include <vector>
 
int main() {
    std::vector<int> arr {10, 20, 30, 40, 50};
    //i got rid of the = in the vector.
    arr.push_back(60);
    for (int i = arr.size() - 1; i >= 0; --i) {
        std::cout << "Element at index " << i << " is: " << arr.at(i) << std::endl;
    }
    return 0;
}