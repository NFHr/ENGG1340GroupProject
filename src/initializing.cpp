// Contaning the function before/after the game.
#include "game.h"
#include <fstream>

using namespace std;

// The name setting of the initial interface
void NameSetting()
{
    system("clear");
    fstream prefSet;
    prefSet.open(".preference", fstream::in | fstream::out | fstream::trunc);
    string userInput;
    cout << "========================================================" << endl;

    cout << "\033[1;1m"
         << "What's the name of Player 1? (no containing spaces)" << endl
         << ": "
         << "\033[0m";
    cin >> userInput;
    prefSet << userInput << " ";

    cout << endl
         << "\033[1;1m"
         << "What's the name of Player 2? (no containing spaces)" << endl
         << ": "
         << "\033[0m";
    cin >> userInput;
    prefSet << userInput << endl;

    cout << "========================================================" << endl;

    prefSet << winCountA << " " << winCountB << endl;
    prefSet.close();
    isGuest = 0; // Disable the Guest flag since the save is created.
}

bool showWelcome()
// welcome interface
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
             << "\033[32m"
             << "   Total battle times: " << winCountA + winCountB << "." << endl
             << "   Player " << PlayerA << " wins: " << winCountA << "." << endl
             << "   Player " << PlayerB << " wins: " << winCountB << "." << endl
             << "\033[0m"
             << "========================================================" << endl;
    }
    cout << "\033[1;1m"
         << " Select Command to Continue (PLAY / NAME / EXIT)"
         << "\033[0m" << endl
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

// set the default parameter for generating the board
void getParameters()
{
    srand(time(NULL));
    int sizeB;
    cout << "Board (0 or 1-5): ";
    cin >> sizeB;
    if (sizeB >= 1 && sizeB <= 5)
        sizeBoard = sizeB;
    else if (sizeB == 0)
        sizeBoard = rand() % 4 + 1;
    else
        sizeBoard = -1;
}

// add the times of winner to the saving file
void addWins(int Player)
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
