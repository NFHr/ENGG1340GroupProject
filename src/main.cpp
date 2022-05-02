#include <stdlib.h>
#include <fstream>
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
    int PlayerNum = 0;
    string command;
    char moveID;
    int movePos;
    int specialMoves = rand() % 2 + 1;
    while (1)
    {
        printBoard(board);
        command = judgeInput(moveID, movePos, PlayerNum, specialMoves);
        if (command == "ADD")
        {
            specialSkill(PlayerNum, specialMoves, board);
            Move(board, globalID, rand() % 9);
        }
        else if (command == "GIVEUP")
            break;
        else
        {
            Move(board, moveID, movePos);
            if (judgeWinner(board) == 1)
            {
                addWins(((PlayerNum + 1) % 2) + 1);
                break;
            }
        }
        PlayerNum = (PlayerNum + 1) % 2;
    }
    cout << "Player" << ((PlayerNum + 1) % 2) + 1 << "wins";
}