#include <iostream>
#include <vector>
#include <limits>//for readInt() and readFloat()
#include <cstdlib> //for rand() and srand() function
#include <time.h> //for time() function
#include <ctime>//for getEpochTime()

//some conversion numbers for later
//also some numbers that never change
constexpr int secPerYr {31556926};
constexpr int hrPerYr {8760};
constexpr int minYear {2050};

//put structs here
struct Mission{
    float hoursSpent;
    int numRefuelings;
    int missionStartStardate;
    int missionEndStardate;
};

struct StarShip{
    int shipID;
    std::string shipName;
    float dailyRate;
    float fuelCapacity;
    std::vector<Mission> missionLog;
};

//for getting int prompts
int getInt(const std::string& prompt){
    
    int input;
    
    while (true){
        std::cout << prompt;
        std::cin >> input;
    
        if(std::cin.fail() || input < 0){
            std::cin.clear(); //clears the error
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //discards invalid input
        
             std::cout << "Inproper input. please try again. "
            << "Text should reappear for ship inputs except for mission inputs." 
            << " For that just type below for inputs and hit enter. "
            << "DO IT RIGHT THIS TIME.\n";
        }
        else{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
            //discards any extra input
            break;//exits loop
        }
    }
    
    return input;
}

//not required, but nice to have
float getFloat(const std::string& prompt){
    
    float result {};
    
    while (true){
        std::cout << prompt;
        std::cin >> result;
        
        if(std::cin.fail() || result < 0){
            std::cin.clear(); //clears the error
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //discards invalid input
        
           std::cout << "Inproper input. please try again. "
            << "Text should reappear for ship inputs except for mission inputs." 
            << " For that just type below for inputs and hit enter. "
            << "DO IT RIGHT THIS TIME.\n";
        }
        else{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return result;
            //discards any extra input
            break;//exits loop
        }
    }
}

//for string prompts
std::string getString(const std::string& prompt){
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

//returns time from 1970 in seconds.
int getEpochTime() {
    return static_cast<int>(std::time(nullptr));
}


StarShip& findStarship(int id, std::vector<StarShip>& starships){
    
    static StarShip blank{-1, "", 0, 0}; //the -1 is so it can be easily id'd
    //the user can't input -1, but I CAN
   for (StarShip& ship : starships) {//for each loop
        if (ship.shipID == id) {
            return ship;
            // Return the found StarShip. Have to convert it 
            //to stop binding conversion error
        }
    }

    return blank;
}


//forward declaration of functions
void endMission(StarShip& ship);
void refuel(StarShip& ship);
double calculateMissionCost(const StarShip& ship, int missionIndex);
void printMissionLog (const StarShip& ship);
bool isOngoing(StarShip& ship);

void startMission(StarShip& ship){
    
    //use push back method: ship.missionLog.push_back(Mission{});
    //adds missions to the vector

    //do an else if statement to see if another mission is still going on
    if(isOngoing(ship)){
        std::cout << "There's a mission still ongoing!\n";
        return;
    }
        //if mission log size > 0
        srand(time(0));
        int range {100000};
        int random {(rand() % range) + 1};
        if(ship.missionLog.size() == 0){
            std::cout << "Starting your first mission on this ship!\n";
        }
        
        else{
            std::cout << "Starting another mission\n";
        }
        
        ship.missionLog.push_back(Mission {});
        ship.missionLog.back().missionStartStardate = ((getEpochTime() - random) / secPerYr) + minYear;
        //do a rand() number thing to see if the mission started ok
    
        //rand() is dependant on srand(), which sets starting point of making
        //a series of psuedo random integers. Making srand() dependant on time(0)
        range = 100;
        int random2 {(rand() % range) + 1};
        
    
        if(random2 > 75){
            std::cout << "The mission started perfectly.\n";
        }
    
        else if(random2 > 50){
            std::cout << "The mission started out alright.\n";
        }
    
        else if(random2 > 25){
            std::cout << "The mission started below expectations." 
            << " You forgot to refuel earler.\n";
            refuel(ship);
        }
    
        else{
            refuel(ship);
            refuel(ship);
            refuel(ship);
            refuel(ship);
            refuel(ship);
            std::cout << "The mission started below horribly! After 5 TIMES " 
            << "refueling, it turns out there was a fuel leak and the ship blew up.\n";
            endMission(ship);
            
            std::cout << "You now owe $" << 
            (calculateMissionCost(ship, static_cast<int> (ship.missionLog.size()) - 1)) 
            << " in fees PLUS money to replace the ship. Nevermind on the "
            << "ship part, you have insurance. Mission ended.\n";
            
        }
}    

bool isOngoing(StarShip& ship){
    if(ship.missionLog.size() == 0){
        return false;
    }
    
    else if(ship.missionLog.back().missionEndStardate > 0 
    && ship.missionLog.back().missionStartStardate > 0
    && (ship.missionLog.back().missionEndStardate
    != ship.missionLog.back().missionStartStardate)){
        return false;
    }
    
    else if(ship.missionLog.back().missionEndStardate == 0 
    && ship.missionLog.back().missionStartStardate > 0){
        return true;
    }
    
    return true;
}

void endMission(StarShip& ship){//not finished
    srand(time(0));
    int range {5};
    int random {(rand() % range) + 1};
    
    if(ship.missionLog.size() == 0){
        std::cout << "There are no missions to end!\n";
    }
    
    else if(ship.missionLog.back().missionStartStardate == 0){
        std::cout << "Mission has not started yet\n";//just in case
    }
    
    else if(!(isOngoing(ship))){
        std::cout << "Mission has already ended\n";//just in case
    }
    else{
        ship.missionLog.back().missionEndStardate = 
        ship.missionLog.back().missionStartStardate + random;
        
        ship.missionLog.back().hoursSpent = 
        (ship.missionLog.back().missionEndStardate 
        - ship.missionLog.back().missionStartStardate) * hrPerYr;
        
        printMissionLog(ship);
    }
        	 
}


//returns the cost of the mission
double calculateMissionCost(const StarShip& ship, int missionIndex){
    
    double cost{}; 
    
    if(isOngoing){
        //zero because it's at least 1 year
        cost = cost = (double) (ship.dailyRate * (1) + 
        ship.missionLog.at(missionIndex).numRefuelings * ship.fuelCapacity * 5);
    }
    else{
        cost = (double) (ship.dailyRate * 
        (ship.missionLog.at(missionIndex).missionEndStardate 
        - ship.missionLog.at(missionIndex).missionStartStardate) 
        + ship.missionLog.at(missionIndex).numRefuelings
        * ship.fuelCapacity * 5);
    }
    
    return cost;
}

//total cost of all missions
double calculateTotalCost(const StarShip& ship){
    double totalCost {};
    
    for(int i {0}; i < ship.missionLog.size(); i++){
        totalCost += calculateMissionCost(ship, i);
    }
    
    return totalCost;
}

void refuel(StarShip& ship){
    
    if(!(isOngoing(ship))){//opposite if it's still going on
        std::cout << "The Mission has already ended.\n";
    }
    
    else {
        std::cout << "Refueling...\n";
        ++ship.missionLog.back().numRefuelings;
    }
}

void printMissionLog (const StarShip& ship){
    //I had a wierd bug where if the mission log was only 1, it wouldn't print
    
        for(int i = 0; i < ship.missionLog.size(); i++){
        	 std::cout << "Mission " << (i + 1) << ": \n";
        	     
        	 //\t is for tab.
        	 std::cout << "\tHours Spent: " 
        	 << ship.missionLog.at(i).hoursSpent << '\n';
        	     
        	 std::cout << "\tRefuelings: " 
        	 << ship.missionLog.at(i).numRefuelings << '\n';
        	     
        	 std::cout << "\tStart Stardate: " 
        	 << ship.missionLog.at(i).missionStartStardate << '\n';
        	     
        	 std::cout << "\tEnd Stardate: " 
        	 << ship.missionLog.at(i).missionEndStardate << "\n\n";
        	 
        	 std::cout << "\tMission Cost: $"
        	 << calculateMissionCost(ship, i) << '\n';
        }
    
    std::cout << "\tTotal Mission Cost: $" << calculateTotalCost(ship) << '\n';
}

//it is what it says on the tin
StarShip makeStarship(){
    //input values directly to struct
    //make sure the inputs are valid. else, restart the program loop
    
    //ask general info
    
    StarShip ship{};
    
	ship.shipID = getInt("Enter the Starship ID: ");
	
    //std::cin.ignore(); //had a bug where i needed to \n another time
    //usually prevents any wierdness between std::cin & getline()
	std::cout << "Enter the Starship Name: ";
	getline(std::cin, ship.shipName);
	    
    ship.dailyRate = getFloat("Enter the Daily Rate for operating the Starship: ");
	
	ship.fuelCapacity = getFloat("Enter the Fuel Capacity of the Starship: ");
	
	return ship;
}

void printFleet(std::vector<StarShip> fleet){
    if(fleet.size() == 0){
        std::cout << "There is no fleet to print silly goose.\n";
    }
    else{
        for(int i =0; i < fleet.size(); i++){
        std::cout << "\nStarship ID: " << fleet.at(i).shipID << '\n';
        std::cout << "Starship Name: " << fleet.at(i).shipName << '\n';
        std::cout << "Daily Rate: " << fleet.at(i).dailyRate << '\n';
        std::cout << "Fuel Capacity: " << fleet.at(i).fuelCapacity << "\n\n";
        }
    }
    
}

void printFleetNames(std::vector<StarShip>& ships){
    if(ships.size() == 1){
        std::cout << "You only have 1 ship!\n";
        std::cout << 0 << ". " << ships.at(0).shipName << '\n';
    }
    else{
        for(int i {0}; i < ships.size(); ++i){
            std::cout << i << ". " << ships.at(i).shipName << '\n';
        }
    }
}

//a bit redundant, but I got tired of doing the same if statement over and over
bool isEmpty(std::vector<StarShip>& ships){
    if(ships.size() == 0){
        return true;
    }
    return false;
}

int chooseIndex(std::vector<StarShip>& fleet){
    printFleetNames(fleet);
    while(true){
        int index = getInt("Choose a ship from above using the index: ");
        
        if(index > fleet.size()){
            std::cout << "Try again\n";
        }
        
        else{
            return index;
        }
    }
    
}


int main() {
    //initializes an empty starship vector
    std::vector<StarShip> fleet;
    
    //make a menu of what you want to do
    
    
    while(true){//will not exit the loop until the user selects 0
         std::cout << "====Menu====\n" << "\n0. Exit \n1. Make a Starship"
        << "\n2. Find Starship ID \n3. Start a Mission \n4. End Mission"
        << " \n5. Refuel \n6. Calculate Mission Cost \n7. Total Mission Cost"
        << "\n8. Print Mission Log \n9. Print Entire Fleet\n";
        
        std::cout << "\nEnter a number between 0 and 9 (inclusive): ";
        int choice = getInt("");
        
        //output changes based on the choice
        switch(choice){
            case 0:
                std::cout << "You chose to Exit.\n";
                std::cout << "Program Shutting Down. Have a Nice Day.\n";
                return 0;//early return
            case 1: 
                std::cout << "You chose to Make a Starship.\n";
                
                fleet.push_back(makeStarship());
                break;
            case 2:
                std::cout << "You chose to Find a Starship ID.\n";
                if(isEmpty(fleet)){
                    std::cout << "You have no Ships silly goose.\n";
                    break;
                }
                else{
                    int id = getInt("Enter the ID: ");
                    if(findStarship(id, fleet).shipID == -1){
                        std::cout << "ID not found\n";
                        break;
                    }
                    
                    std::cout << "ID found!\n";
                    //i forgot about returning the name lol
                    std::cout << findStarship(id, fleet).shipName << '\n';
                    break;
                }
               
            case 3:
                std::cout << "You chose to Start a Mission.\n";
                if(isEmpty(fleet)){
                    std::cout << "You need to make a ship first.\n";
                    break;
                }
                else if(fleet.size() == 1){
                    std::cout << "You only have one ship. That makes it easy.\n";
                    startMission(fleet.at(0));//first ship
                    break;
                }
                else{
                    int i = chooseIndex(fleet);
                    startMission(fleet.at(i));
                    break;
                }
            case 4:
                std::cout << "You chose to End Mission.\n";
                if(isEmpty(fleet)){
                    std::cout << "You need to make a ship first.\n";
                    break;
                }
                else if(fleet.size() == 1){
                    std::cout << "You only have one ship. That makes it easy.\n";
                    endMission(fleet.at(0));
                    break;
                }
                else{
                    int i2 = chooseIndex(fleet);
                    endMission(fleet.at(i2));
                    break;
                }
            case 5:
                std::cout << "You chose to Refuel.\n";
                if(isEmpty(fleet)){
                    std::cout << "You need a ship first\n";
                    break;
                }
                else{
                    int i3 = chooseIndex(fleet);
                    
                    if(fleet.at(i3).missionLog.size() == 0){
                        std::cout << "No missions in this ship!\n";
                        break;
                    }
                    else{
                        refuel(fleet.at(i3));
                        break;
                    }
                }
            case 6:
                std::cout << "You chose to Calculate Mission Cost.\n";
            
                if(isEmpty(fleet) || fleet.back().missionLog.size() == 0){
                    std::cout << "There are no ships in this fleet "
                    << "or there's no mission done on the ship.\n";
                    break;
                }
                
                else{
                    int i4 = chooseIndex(fleet);
                    if(isOngoing(fleet.at(i4))){
                        std::cout << "The mission has not ended yet. "
                        << "End the mission first before getting the cost.\n";
                        break;
                    }
                    std::cout << "The cost of the most recent mission is $" 
                    << calculateMissionCost(fleet.at(i4),
                    fleet.at(i4).missionLog.size() - 1) << '\n';
                    break;
                }
            case 7:
                if(isEmpty(fleet)){
                    std::cout << "You need to make a ship first.\n";
                    break;
                }
                
                else{
                    std::cout << "You chose to find Total Mission Cost.\n";
                    int i5 = chooseIndex(fleet);
                    std::cout << "The total mission cost is $" 
                    << calculateTotalCost(fleet.at(i5)) << '\n';
                    break;
                }
            case 8:
                std::cout << "You chose to Print Mission Log.\n";
                if(isEmpty(fleet)){
                    std::cout << "You need to make a ship first.\n";
                    break;
                }
                else{
                    int i6 = chooseIndex(fleet);
                    printMissionLog(fleet.at(i6));
                    break;
                }
            case 9:
                if(isEmpty(fleet)){
                    std::cout << "You need to make a ship first.\n";
                    break;
                }
                
                else{
                    std::cout << "You chose to Print Entire Fleet.\n";
                    printFleet(fleet);
                    break;
                }
            default://just in case
                std::cout << "How did you even get here? The getInt() was"
                << " supposed to stop you from making a wrong input!\n";
                break;
        }
        
    }
    
    std::cout << "Program Shutting Down. Have a Nice Day.\n";    
	return 0;
}
