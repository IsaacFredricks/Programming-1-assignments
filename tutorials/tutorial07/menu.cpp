#include <iostream>
#include <vector>
 //What would happen if the & was removed from the parameter of the feedCat, petCat, or groomCat functions (i.e., if the cats were not passed by reference)?
 //add & back to functions to have them work correctly
struct Cat {
    std::string name;
    int hunger;
    int vocalization;
};
 
void feedCat(Cat cat);
void petCat(Cat cat);
void displayCats(const std::vector<Cat>& cats);
 
void groomCat(Cat cat);
 
Cat& getCatRef(std::vector<Cat>& cats, int index) {
    return cats.at(index);
}
 
int main() {
    std::vector<Cat> cats = {{"Whiskers", 5, 10}, {"Fluffy", 3, 8}};
 
 
    while (true) {
        std::cout << "1. Feed a cat\n2. Pet a cat\n3. Groom the cat\n4. Display all cats\n0. Exit\n";
        int choice;
        std::cin >> choice;
 
        if (choice == 4) {
            displayCats(cats);
        } else if (choice!=0) {
            int catIndex = -1;
            std::cout << "Select the cat by index (0 for Whiskers, 1 for Fluffy): ";
            std::cin >> catIndex;
            Cat& cat=getCatRef(cats, catIndex);
 
 
            switch (choice) {
                case 1:
                    feedCat(cat);
                    break;
                case 2:
                    petCat(cat);
                    break;
                case 3:
                    groomCat(cat);
                    break;
                default:
                     std::cout << "Invalid choice.\n";
            }
          
        } else {
            break;
        } 
    }
   
    return 0;
}
 
void feedCat(Cat cat) {
    cat.hunger -= 1;
    std::cout << cat.name << " has been fed. Hunger: " << cat.hunger << "\n";
}
 
void petCat(Cat cat) {
    cat.vocalization += 1;
    std::cout << cat.name << " has been petted. Vocalization: " << cat.vocalization << "\n";
}
 
void displayCats(const std::vector<Cat>& cats) {
    for (int i = 0; i < cats.size(); i++) {
        Cat cat=cats.at(i);
        std::cout << "Cat " << i << ": " << cat.name << ", Hunger: " << cat.hunger << ", Vocalization: " << cat.vocalization << "\n";
    }
}

void groomCat(Cat cat){
    cat.hunger -= 1;
    cat.vocalization += 2;
    std::cout << "The cat has been brushed Hunger: " << cat.hunger << ", Vocalization: " << cat.vocalization << " \n";
}