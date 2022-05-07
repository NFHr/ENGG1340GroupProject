#include <stdlib.h>
#include <fstream>
#include "game.h" // global variables and functions definded here

int isGuest = 0;
int sizeBoard, skills = 0;
string PlayerA, PlayerB;
int winCountA, winCountB;
char globalID = 'A';
Board *board = NULL;

int main()
{
    // Title
    cout << "\033]0;"
         << "Notakto - Welcome"
         << "\007";
    // Welcome Part
    fstream prefFile;
    prefFile.open(".preference");
    if (!prefFile)
    {
        isGuest = 1; // enable the Guest flag since the saving is not found
        PlayerA = "Guest";
        PlayerB = "Guest";
    }
    while (showWelcome() != 1)
        system("clear");
    prefFile.close();

    // Asking parameters of before initialzing
    cout << "\033[1;1m"
         << "What's your prefered size of board? (\"0\" for random)"
         << "\033[0m" << endl;
    getParameters();
    while (sizeBoard == -1)
    {
        cout << "\033[1;31m"
             << "Wrong size, Please input again!"
                "\033[0m"
             << endl;
        ;
        getParameters();
    }
    cout << "========================================================" << endl;

    // Initialze the Game
    cout << "\033]0;"
         << "Notakto - Preparing"
         << "\007";
    for (int i = 0; i < sizeBoard; i++)
    {
        addPiece();
    }
    while (skills == 0)
        skills = rand() % 3;

    // the Gaming Part
    cout << "\033]0;"
         << "Notakto - Gaming"
         << "\007";
    int PlayerNum = 0;
    string command;
    char moveID;
    int movePos;
    while (1)
    {
        printBoard();
        PlayerNum = (PlayerNum % 2) + 1;
        command = judgeInput(moveID, movePos, PlayerNum);
        if (command == "SKILL")
            skill(PlayerNum);
        else if (command == "GIVUP")
            break;
        else if (command == "MOVE")
        {
            Move(moveID, movePos);
            if (countLength() == 0)
            {
                if (isGuest == 1)
                    addWins(((PlayerNum + 1) % 2) + 1);
                break;
            }
        }
    }
    // the ending part
    cout << "\033[1;32m"
         << "Every piece in the board was dead."
         << "\033[0m" << endl
         << "========================================================" << endl
         << "\033[1;33m"
         << "Player" << PlayerNum % 2 + 1 << " " << NumToName(PlayerNum % 2 + 1) << " wins."
         << "\033[0m" << endl;
}
