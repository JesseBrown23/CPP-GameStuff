#include <iostream>
#include <string>

using namespace std;

//Global constant variables.
//so all functions can use, constant so they aren't changeable
//global constants are okay, although you should avoid globals when possible
const int inventoryNum = 4;
const int numItems = 4;
const int numPrices = 4;
const string shopItemsNames[numItems] = {"Boots", "Swords", "Helmets", "Kittens"};
const int shopItemsPrice[numPrices] = {10, 15, 25, 300};

//Prototyping functions
void printInventory(int playerInventory[inventoryNum]);
void printShop();
bool buyItems(int playerInventory[inventoryNum]);

int main()
{
    //To decide wether done buying or not
    bool isDone = false;

    //Stores player inventory in an array
    int playerInventory[inventoryNum] = {1, 0, 0, 1};

    //Welcome message to user
    cout << "**Welcome to the shop**" << endl;

    //Repeatedly prints shop until they are done
    while(isDone == false){
        printShop();
        cout << "************\n\n";
        printInventory(playerInventory);
        //returns true or false
        isDone = buyItems(playerInventory);
    }

    cout << "\n\n************\n\n";


    return 0;
}

//prints the players inventory x name from shop array
void printInventory(int playerInventory[inventoryNum]){
    cout << "Your inventory is: " << endl;
    for(int i =0; i < inventoryNum; i++){
        if(playerInventory[i] > 0){
            cout << playerInventory[i] << " x " << shopItemsNames[i] << endl;
        }
    }
}

//prints shops
void printShop(){
    //Loops arrays to print to screen
    for(int i = 0; i < numItems; i++){
        cout << i+ 1 << ". " << shopItemsNames[i] << " --- " << shopItemsPrice[i] << endl;
    }
}


bool buyItems(int playerInventory[inventoryNum]){
    int input;
    //Prompts user with a question
    cout << "What would you like to buy? (To quit enter -1) (Enter 1-" << numItems << "): ";
    cin >> input;

    //If they quit return true to change isDone
    if(input == -1){
        return true;
    }

    //make sure they give correct input while buying
    if(input < 1 || input > numItems){
        cout << "************\n" << "Try again!\n" << "************\n" << endl;
        return false;;
    }
    playerInventory[input - 1]++;
    return false;
}
