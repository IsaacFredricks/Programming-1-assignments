#include <iostream>
#include <vector>


// Function to print the elements of a vector
void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
 
int main() {
    std::vector<int> nums = {12, 27, 35};
    printVector(nums);
    //do more here
    nums.reserve(10);
    printVector(nums);
    std::cout << nums.size() << std::endl;
    std::cout << nums.capacity() << std::endl;
    
    nums.shrink_to_fit();//does so here
    std::cout << nums.size() << std::endl;
    std::cout << nums.capacity() << std::endl;
    
    nums.assign(999, 5);
    printVector(nums);
    std::cout << nums.size() << std::endl;
    std::cout << nums.capacity() << std::endl;
    
    nums.shrink_to_fit();//doesn't change anything here
    std::cout << nums.size() << std::endl;
    std::cout << nums.capacity() << std::endl;
    

    std::cout << nums.empty() << std::endl;
    
    nums.clear();
    printVector(nums);
    std::cout << nums.size() << std::endl;
    std::cout << nums.capacity() << std::endl;
    
    std::cout << nums.empty() << std::endl;
    return 0;
}