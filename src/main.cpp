#include <stdlib.h>
#include <fstream>
#include "game.h" // global variables and functions definded here
#include<Windows.h>

int isGuest = 0;
int sizeBoard, skills = 0;
string PlayerA, PlayerB;
int winCountA, winCountB;
char globalID = 'A';
Board *board = NULL;

int main()
{
    //COLOR
    system("color E1");
    SetConsoleTitle(LPCWSTR(L"Notakto"))
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
    cout << "What's your prefered size of board? (\"0\" for random)" << endl;
    getParameters();
    while (sizeBoard == -1)
    {
        cout << endl
             << "Wrong size, Please input again!" << endl;
        getParameters();
    }
    cout << "========================================================" << endl;

    // Initialze the Game
    for (int i = 0; i < sizeBoard; i++)
    {
        addPiece();
    }
    while (skills == 0)
        skills = rand() % 3;

    // the Gaming Part
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
    cout << "Every piece in the board was dead." << endl
         << "========================================================" << endl
         << "Player" << PlayerNum % 2 + 1 << " " << NumToName(PlayerNum % 2 + 1) << " wins." << endl;
}
