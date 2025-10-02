#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = {15, 23};
    nums.push_back(8);
    nums.push_back(19);
    
	std::cout << nums.at(0) << std::endl;
	std::cout << nums.at(1) << std::endl;
	std::cout << nums.at(2) << std::endl;
	std::cout << nums.at(3) << std::endl;
	
	
	nums.back() = 99;
	//std::cout << nums.at(2) << std::endl; //errors
	
	std::cout << nums.size() << std::endl;
	std::cout << nums.capacity() << std::endl;
	
	//std::cout << nums.at(-1) << std::endl;
	struct Mission {
    double hoursSpent;
    int numRefuelings;
    int missionStartStardate;
    int missionEndStardate;
};
 

	std::vector<Mission> missions;
 
    missions.push_back(Mission());
    missions.back().hoursSpent = 102.0;
    missions.back().numRefuelings = 2;
    missions.back().missionStartStardate = 20034;
    missions.back().missionEndStardate = 20037;
 
    missions.push_back({250.15, 5, 40013, 40020});
    
    std::cout << missions.at(0).numRefuelings << std::endl;
    
    std::cout << missions.at(1).missionStartStardate << std::endl;
    std::cout << missions.back().missionStartStardate << std::endl;
    
    missions.push_back(Mission());
    
    std::cout << missions.back().hoursSpent << '\n';
	return 0;
}
