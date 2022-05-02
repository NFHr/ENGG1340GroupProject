#include <stdlib.h>
#include <fstream>
#include <time.h>
#include "game.h"

int sizeBoard;
string PlayerA, PlayerB;
char globalID = 'A';

int main()
{
    // Welcome Part
    fstream prefFile;
    prefFile.open(".preference");
    if (!prefFile)
    {
        showFirstTime();
        system("clear");
    }
    while (showWelcome() != 1)
        system("clear");
    prefFile.close();

    // Asking parameters of before initialzing
    cout << "Prefer board size before starting. (\"0\" for random)" << endl;
    getParameters();
    while (sizeBoard == -1)
    {
        cout << endl
             << "Wrong size, Please input again!" << endl;
        getParameters();
    }
    cout << "========================================================" << endl;

    // Initialze the Board
    Board *board = NULL;
    for (int i = 0; i < sizeBoard; i++)
    {
        addPiece(board);
    }

    // the Gaming Part
    int Player = 0;
    char moveID;
    int movePos;
    string command;
    while (1)
    {
        printBoard(board);
        command = judgeInput(moveID, movePos);
        if (command == "ADD")
        {
            cout << "Player" << specialSkill(Player);
        }

        else if (command == "GIVEUP")
        {
            cout << "Player" << ((Player + 1) % 2) + 1 << "wins";
            break;
        }
        else
        {
            Move(board, moveID, movePos);
            if (judgeWinner(board) == 1)
            {
                cout << "Player" << ((Player + 1) % 2) + 1 << "wins";
                addWins(((Player + 1) % 2) + 1);
                break;
            }
        }
        Player = (Player + 1) % 2;
    }
}