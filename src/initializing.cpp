// Contaning the function for initaling before the game starts.
#include "game.h"
#include <fstream>

using namespace std;

void NameSetting()
//The name setting of the initial interface 
{
    system("clear");
    fstream prefSet;
    prefSet.open(".preference", fstream::in | fstream::out | fstream::trunc);
    string userInput;
    cout << "========================================================" << endl;

    cout << "What's the name of Player 1? (no containing spaces)" << endl
         << ": ";
    cin >> userInput;
    prefSet << userInput << " ";

    cout << endl
         << "What's the name of Player 2? (no containing spaces)" << endl
         << ": ";
    cin >> userInput;
    prefSet << userInput << endl;

    cout << "========================================================" << endl;

    prefSet << winCountA << " " << winCountB << endl;
    prefSet.close();
    isGuest = 0; // Disable the Guest flag since the save is created.
}

bool showWelcome()
//welcome interface
{
    string userInput;
    if (isGuest == 1)
        cout << "========================================================" << endl
             << "Welcome to the Notakto, new comer." << endl
             << "Please change your name to save records." << endl
             << "========================================================" << endl;
    else
    {
        // Read the Players name.
        fstream prefFile(".preference", fstream::in);
        prefFile >> PlayerA >> PlayerB >> winCountA >> winCountB;
        cout << "========================================================" << endl;
        cout << "Welcome to the Notakto, " << PlayerA << " & " << PlayerB << "." << endl
             << "   Total battle times: " << winCountA + winCountB << "." << endl
             << "   Player " << PlayerA << " wins: " << winCountA << "." << endl
             << "   Player " << PlayerB << " wins: " << winCountB << "." << endl
             << "========================================================" << endl;
    }
    cout << " Select Command to Continue (PLAY / NAME / EXIT)" << endl
         << ": ";
    cin >> userInput;
    if (userInput == "PLAY")
    {
        cout << "========================================================" << endl;
        return 1;
    }
    else if (userInput == "NAME")
    {
        NameSetting();
        return 0;
    }
    else
        exit(0);
}

void getParameters()
// the number of boards that players want to play
{
    srand(time(NULL));
    int sizeB;
    cout << "Board (0 or 1-5): ";
    cin >> sizeB;
    if (sizeB >= 1 && sizeB <= 5)
    {
        sizeBoard = sizeB;
    }

    else if (sizeB == 0)
        sizeBoard = rand() % 4 + 1;
    else
        sizeBoard = -1;
}

void addWins(int Player)
//the winner of the game
{
    string dummy;
    fstream prefFile;
    if (Player == 1)
        winCountA++;
    else
        winCountB++;
    prefFile.open(".preference", fstream::in | fstream::out | fstream::trunc);

    prefFile << PlayerA << " " << PlayerB << endl
             << winCountA << " " << winCountB;
    prefFile.close();
}
