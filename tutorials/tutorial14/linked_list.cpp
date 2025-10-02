#include <iostream>

struct Node{
  int data;
  Node* next;
};

void addNode(Node* head, int value){
    Node* newNode = new Node{value, nullptr};
    Node* temp = head;
    
    while(temp->next != nullptr){
        temp = temp->next;
        
        //std::cout << temp->data << '\n';
    }
    
    temp->next = newNode;
}

void printList(Node* head){
    Node* current = head;
    
    while(current){//can also do while(current != nullptr) or while(current != 0)
        std::cout << current->data << " ";
        current = current->next;//goes to the next node
    }
}

int main() {
    
    Node nodeA;
    nodeA.data = 1;
    //std::cout << nodeA.data << '\n';
    
    Node nodeB;
    nodeB.data = 2;
    //std::cout << nodeB.data << '\n';
    
    nodeA.next = &nodeB; //links nodeA to nodeB

    Node nodeC;
    nodeC.data = 3;
    //std::cout << nodeC.data << '\n';
    
    addNode(&nodeA, 3);
    addNode(&nodeA, 4);
	
	printList(&nodeA);
	
	return 0;
}
