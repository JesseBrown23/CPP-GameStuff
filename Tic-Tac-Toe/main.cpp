#include <iostream>
#include "TTGame.h"

using namespace std;

int main(){

    bool isDone = false;

    char input;

    TTGame game;

    //Loop to find out wether user wnats to play another round
    while(isDone == false){
        game.playGame();
        //Asks if theyw ould like to play another game/takes input
        cout << "Would you like to play another round? (Y/N)" << endl;
        cin >> input;

        //Figures out how they answered/if false program quits
        if(input == 'y' || input == 'Y'){
            isDone = false;
        }else{
            isDone = true;
        }
    }
    return 0;
}
