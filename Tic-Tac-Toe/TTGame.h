#ifndef TTGAME_H
#define TTGAME_H

using namespace std;

class TTGame
{
    public:
        //Constructor
        TTGame();
        //Game loop
        void playGame();
    private:
        //Gets user inputted coordinate
        int getXCoord();
        int getYCoord();
        //Making sure they can place there
        bool placeLetter(int x, int y, char currentPlayer);
        //Sees if there is any 3 in a rows
        bool checkForVictory(char currentPlayer);
        //Empties board
        void clearBoard();
        //Prints boards
        void printBoard();
        //Stores board state
        char board[3][3];
};

#endif
