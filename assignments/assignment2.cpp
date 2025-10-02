#include <iostream>
#include <vector>
#include <limits>//for readInt() and readFloat()

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
    std::vector<Mission> missionLog;//haven't learned yet
};

void readInt(const std::string& prompt, int& result){
    
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
            //discards any extra input
            break;//exits loop
        }
    }
}

void readFloat(const std::string& prompt, float& result){
    
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
            //discards any extra input
            break;//exits loop
        }
    }
}

int main() {
    StarShip ship{};//makes starship accessable in main
    //add user input
    //input values directly to struct
    //make sure the inputs are valid. else, restart the program loop
    
    //ask general info

	readInt("Enter the Starship ID: ", ship.shipID);
	
    //std::cin.ignore(); //had a bug where i needed to \n another time
    //usually prevents any wierdness between std::cin & getline()
	std::cout << "Enter the Starship Name: ";
	getline(std::cin, ship.shipName);
	    
    readFloat("Enter the Daily Rate for operating the Starship: ", ship.dailyRate);
	
	readFloat("Enter the Fuel Capacity of the Starship: ", ship.fuelCapacity);
	    
    std::cout << '\n';
        	 
        	    
    //use push back method: ship.missionLog.push_back(Mission{});
    ship.missionLog.push_back(Mission{});
    ship.missionLog.push_back(Mission{});
    ship.missionLog.push_back(Mission{});
    //adds three missions to the vector
        	 
        	    
    for(int index = 0; index < ship.missionLog.size(); index++){
        	        
        //ask user for parameters each time
        	    
        //will only continue to next if everything is input correctly
        
        std::cout <<  "Enter hours spent for Mission "
        << (index + 1) << ": ";
        
        readFloat("", ship.missionLog.at(index).hoursSpent);
    
        std::cout << "Enter number of times refueled for Mission "
        << (index + 1) << ": ";
        readInt("", ship.missionLog.at(index).numRefuelings);
        	            

        std::cout << "Enter start startdate for Mission " 
        << (index + 1) << ": ";
        readInt("", ship.missionLog.at(index).missionStartStardate);
        	                

        //we want end date to be one more than the start date.
        ship.missionLog.at(index).missionEndStardate 
        = ship.missionLog.at(index).missionStartStardate + 1;
        	                
        std::cout << '\n';//adds extra line of space         
        //store mission log variables directly 
        }
        
        //print out results like the code example
        //\n in the front is an extra line of space
        std::cout << "\n===============REPORT===============\n";
        std::cout << "\nStarship ID: " << ship.shipID << '\n';
        std::cout << "Starship Name: " << ship.shipName << '\n';
        std::cout << "Daily Rate: " << ship.dailyRate << '\n';
        std::cout << "Fuel Capacity: " << ship.fuelCapacity << "\n\n";
        	 
        for(int i = 0; i < ship.missionLog.size(); i++){
        	 std::cout << "Mission " << (i + 1) << ": \n";
        	     
        	 //\t is for tab.
        	 std::cout << "\tHours Spent: " 
        	 << ship.missionLog.at(i).hoursSpent << '\n';
        	     
        	 std::cout << "\tRefuelings: " 
        	 << ship.missionLog.at(i).numRefuelings << '\n';
        	     
        	 std::cout << "\tStart Stardate: " 
        	 << ship.missionLog.at(i).missionStartStardate << '\n';
        	     
        	 std::cout << "\tEnd Stardate: " << ship.missionLog.at(i).missionEndStardate << "\n\n";
         }
	return 0;
}
