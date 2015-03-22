#include "TTGame.h"
#include <iostream>

//Constructor
TTGame::TTGame(){
}

void TTGame::playGame(){
    clearBoard();

    //Assigns x/o to the players
    char player1 = 'X';
    char player2 = 'O';

    //Starts with player1 (x)
    char currentPlayer = player1;

    //For a win/tie
    bool isDone = false;

    //storing entered coordinates
    int x, y;

    //keep track of turns for ties
    int turns = 0;

    //Inner game loop-keeps going until someone wins/ties
    while(isDone == false){
        //makes the board
        printBoard();
        //stores inputted coordinates
        x = getXCoord();
        y = getYCoord();


        if(placeLetter(x, y, currentPlayer) == false) {
            cout << "Coordinate is taken!" << endl;
        }else{
            turns ++; //keeping track of turns for ties
            if(checkForVictory(currentPlayer) == true){
                cout << "The game is over! Player " << currentPlayer << " won!" << endl;
                isDone = true;
            }else if(turns == 9) {
                cout << "It's a tie game :(" << endl << endl;
                isDone = true;
            }

            //Switching players
            if(currentPlayer == player1){
                currentPlayer = player2;
            }else{
                currentPlayer = player1;
            }
        }
    }
}


int TTGame::getXCoord(){
    bool isInputBad = true;
    int x;

    while(isInputBad == true){
    cout << "Enter X coordinate (Top number): ";
    cin >> x;
        if(x < 1 || x > 3){
            cout << "Invalid coordinate (1-3)" << endl;
        }else{
            isInputBad = false;
        }
    }
    return x -1;
}


int TTGame::getYCoord(){
    bool isInputBad = true;
    int y;

    while(isInputBad == true){
    cout << "Enter Y coordinate (Left number): ";
    cin >> y;
        if(y < 1 || y > 3){
            cout << "Invalid coordinate (1-3)" << endl;
        }else{
            isInputBad = false;
        }
    }
    return y -1;
}

bool TTGame::placeLetter(int x, int y, char currentPlayer){
    if(board[y][x] != ' '){
        return false;
    }
    board[y][x] = currentPlayer;
    return true;
}

bool TTGame::checkForVictory(char currentPlayer){
    //Check rows
    for(int i = 0; i < 3; i ++){
        if((board[i][0] == currentPlayer) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])){
            return true; //We won!
        }
    }
    //Check columns
    for(int i = 0; i < 3; i ++){
        if((board[0][i] == currentPlayer) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])){
            return true; //We won!
        }
    }
    //Check top left diagnol
    if((board[0][0] == currentPlayer) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])){
        return true; //We won!
    }
    //Check top right diagnol
    if((board[2][0] == currentPlayer) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])){
        return true; //We won!
    }
    return false; //Didn't win
}

void TTGame::clearBoard(){
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

void TTGame::printBoard(){
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~*******************************~" << endl;
    cout << "~*******************************~" << endl;
    cout << "~*******************************~" << endl;
    cout << "~*******************************~" << endl;
    cout << "~***********---------***********~" << endl;
    cout << "~***********||~|1_2_3||*********~\n";
    for(int i = 0; i < 3; i ++){
        cout << "~***********---------***********~" << endl;
        cout << "~***********|" << i + 1 << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|***********~" << endl;
    }
    cout << "~***********---------***********~" << endl;
    cout << "~*******************************~" << endl;
    cout << "~*******************************~" << endl;
    cout << "~*******************************~" << endl;
    cout << "~*******************************~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
