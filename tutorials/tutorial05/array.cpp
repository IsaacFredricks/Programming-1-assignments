#include <iostream>
#include <array>
int main() {
    std::array<int, 5> numbers = {4, 6};
	std::cout << numbers.at(0) << std::endl;
	std::cout << numbers.at(1) << std::endl;
	std::cout << numbers.at(2) << std::endl;
	std::cout << numbers.at(3) << std::endl;
	std::cout << numbers.at(4) << std::endl;
	
	numbers.at(4) = 99;
	
	//std::cout << numbers.at(-1) << std::endl;//commented out to stop erroring
	
	std::cout << numbers.size() << std::endl;
	
	struct Mission {
	    double hoursSpent;
	    int numRefuelings;
	    int MissionStartStardate;
	    int missionEndStardate;
	};
	
	std::array<Mission, 3> missions = {{
	    {120.5, 3, 4100, 41010},
	    {95.0, 2, 41011, 41012},
	    {200.75, 5, 41013, 41020},
	}};
	
	std::cout << missions.at(2).missionEndStardate << '\n';
	
	missions.at(1).numRefuelings = 4;
	return 0;
}
