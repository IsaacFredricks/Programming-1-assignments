#include <iostream>
#include <limits>

struct Node{
  int data;
  Node* next;
};

class LinkedList{
    private://for instance variables
    Node* root;//head of linked list
    
    public://for functions
    
    //empty constructor
    LinkedList() : root(nullptr) {};

    //void functions
    void addNode(int value){
        Node* newNode = new Node{value, nullptr};
        
        if(root == nullptr){
            root = newNode;
        }
        
        else{
            Node* temp = root;
        
            while(temp->next != nullptr){
                temp = temp->next;
            }
                temp->next = newNode;
            }
    }
    
    void printList(){
        Node* current = root;
    
        while(current){
            //can also do while(current != nullptr) or while(current != 0)
            std::cout << current->data << " ";
            current = current->next;//goes to the next node
        }
    }
};

int getInt(const std::string& prompt);//forward declaration

int main() {
    LinkedList list;
    
    while(true){
        std::cout << "\n====Menu====\n1. Add an integer to the linked list\n"
	    << "2. Print entire linked list\n3. Exit the program\n============\n";
	
	    int choice = getInt("Enter a number 1-3 (inclusive): ");
	
	    if(choice == 1){
	        std::cout << "You chose to add an integer to the linked list.\n";
	        int num = getInt("Enter an integer: ");
	        list.addNode(num);
	        
	    }
	
	    else if(choice == 2){
	        std::cout << "You chose to print entire linked list: \n";
	        list.printList();
	        
	    }
	
    	else if(choice == 3){
    	    std::cout << "Exiting program. Goodbye.\n";
    	    break;
    	}
	    
	    else{
	        std::cout << "That was not one of the options.\n";
	    }
	
    }
	
	return 0;
}

int getInt(const std::string& prompt){//reused from assignment 4
    
    int input;
    
    while (true){
        std::cout << prompt;
        std::cin >> input;
    
        if(std::cin.fail() || input < 0){
            std::cin.clear(); //clears the error
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //discards invalid input
        
            std::cout << "Inproper input. please try again.\n";
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