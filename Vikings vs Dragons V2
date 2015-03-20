#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

//Prototyping
int getVikings();
int getDragons();
void startBattle(int &numVikings, int &numDragons);
void printResults(int numVikings, int numDragons, int startsVikings, int startsDragons);

int main()
{
    //Viking properties
    int numVikings;
    int startsVikings;

    //Dragon properties
    int numDragons;
    int startsDragons;

    //Prompts game title-Might move this later who knows
    cout << "**** Vikings vs Dragons ****" << endl << endl;

    //setting the amount of vikings to inputted number from the fucntion getVikings
    numVikings = getVikings();
    //setting that to startsVikings to keep track of what was originally inputted
    startsVikings = numVikings;

    //Same as above but for dragons
    numDragons = getDragons();
    startsDragons = numDragons;

    //calls startBattle which has all the battle 'stuff' while passing how many of each
    startBattle(numVikings, numDragons);

    //prints results
    printResults(numVikings, numDragons, startsVikings, startsDragons);

    return 0;
}

int getVikings(){
    int numVikings;
    cout << "Enter number of Vikings: ";
    cin >> numVikings;
    return numVikings;
}


int getDragons(){
    int numDragons;
    cout << "Enter number of Dragons: ";
    cin >> numDragons;
    return numDragons;
}


void startBattle(int &numVikings, int &numDragons){
    //Random generator for attack
    static mt19937 randomGenerator(time(0));
    uniform_real_distribution<float> attack(0.0f, 1.0f);

    //Viking properties
    float vikingsAttack = 0.6f;
    float vikingsHealth = 250.0f;
    float vikingsDamageDealt = 225.0f;
    float currentVHealth = vikingsHealth;

    //Dragon properties
    float dragonsAttack = 0.3f;
    float dragonsHealth = 400.0f;
    float dragonsDamageDealt = 350.0f;
    float currentDHealth = dragonsHealth;

    //Number that is pulled from the generator
    float attackResult;

    //Sets vikings to go first
    char turn = 'V';

    cout << "\n**** Battle Beginning ****" << endl << endl;


    //Battle loop
    while((numDragons > 0) && (numVikings > 0)){
        //If vikings turn
        if(turn == 'V') {
            //Get number from random
            attackResult = attack(randomGenerator);
            //Was attack successful(in bounds of the attack)
            if(attackResult <= vikingsAttack){
                currentDHealth -= vikingsDamageDealt;
                cout << "Vikings hit succesfully!!" << endl;


                //if hit was successful, and dragon life went below
                //zero the dragon died so subtract a dragon
                if(currentDHealth <= 0){
                    numDragons--;
                    //reset health back to start
                    currentDHealth = dragonsHealth;
                }
            }
            //switch turn to dragons
            turn = 'D';
        }else{
            //same as above except backwards for dragons attacking
            attackResult = attack(randomGenerator);

            if(attackResult <= dragonsAttack) {
                currentVHealth -= dragonsDamageDealt;
                cout << "Dragons hit succesfully!!" << endl;


                if(currentVHealth <= 0){
                    numVikings--;
                    currentVHealth = vikingsHealth;
                }
            }
            //switch turn to vikings
            turn = 'V';
        }
    }
}


void printResults(int numVikings, int numDragons, int startsVikings, int startsDragons){
    cout << "**** Battle Ended ****" << endl;
    if(numVikings > 0){
        cout << "\n****Vikings won!****" << endl;
        cout << "There are " << numVikings << " Vikings left" << endl;
    }else{
        cout << "\n****Dragons won!****" << endl;
        cout << "There are " << numDragons << " Dragons left" << endl;
    }
    cout << "Starting number of Dragons: " << startsDragons << endl << "Starting number of Vikings: " << startsVikings << endl;
}
