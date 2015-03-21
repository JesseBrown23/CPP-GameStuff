#include <iostream>
#include <stdlib.h>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int main()
{
    //Random generator for attack
    mt19937 randomGenerator(time(0));
    uniform_real_distribution<float> attack(0.0f, 1.0f);

    //Viking properties
    int numVikings;
    int startsVikings;
    float vikingsAttack = 0.6f;
    float vikingsHealth = 250.0f;
    float vikingsDamageDealt = 225.0f;
    float currentVHealth = vikingsHealth;

    //Dragon properties
    int numDragons;
    int startsDragons;
    float dragonsAttack = 0.3f;
    float dragonsHealth = 400.0f;
    float dragonsDamageDealt = 350.0f;
    float currentDHealth = dragonsHealth;

    //Number that is pulled from the generator
    float attackResult;

    //Sets vikings to go first
    char turn = 'V';

    //Prompting user to give amount of warriors/storing amount
    cout << "**** Vikings vs Dragons ****" << endl << endl;
    cout << "Enter number of Vikings: ";
    cin >> numVikings;
    startsVikings = numVikings;

    cout << "Enter number of Dragons: ";
    cin >> numDragons;
    startsDragons = numDragons;

    //Announces start of the battle
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

    cout << "**** Battle Ended ****" << endl;

    if(numVikings > 1){
        cout << "\n****Vikings won!****" << endl;
        cout << "There are " << numVikings << " Vikings left" << endl;
        cout << "Starting number of Dragons: " << startsDragons << endl << "Starting number of Vikings: " << startsVikings << endl;
    }else{
        cout << "\n****Dragons won!****" << endl;
        cout << "There are " << numDragons << " Dragons left" << endl;
        cout << "Starting number of Dragons: " << startsDragons << endl << "Starting number of Vikings: " << startsVikings << endl;
    }

    return 0;
}
