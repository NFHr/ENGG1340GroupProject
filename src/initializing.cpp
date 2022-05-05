// Contaning the function for initaling before the game starts.
#include <fstream>
#include "game.h"

using namespace std;

void NameSetting(int winCountA, int winCountB)
{
    fstream prefSet;
    prefSet.open(".preference", fstream::in | fstream::out | fstream::trunc);
    string userInput;
    cout << "========================================================" << endl;

    cout << "What's the name of Player A? (no containing spaces)" << endl
         << ": ";
    cin >> userInput;
    prefSet << userInput << " ";

    cout << endl
         << "What's the name of Player B? (no containing spaces)" << endl
         << ": ";
    cin >> userInput;
    prefSet << userInput << endl;

    cout << "========================================================" << endl;

    prefSet << winCountA << " " << winCountB << endl;
    prefSet.close();
}

bool showFirstTime()
{
    // Welcome Message for the first time opening the game.
    string userInput;
    cout << "========================================================" << endl;
    cout << "Welcome to the Notakto, new comer!" << endl
         << "Coninue as a Guest? (y/n)" << endl
         << ": ";
    cin >> userInput;
    if (userInput == "y")
    {
        PlayerA = "GuestA";
        PlayerB = "GuestB";
        cout << "========================================================" << endl;
        return 1;
    }
    else if (userInput == "n")
    {
        NameSetting(0, 0);
        return 0;
    }
    else
        exit(0);
}

bool showWelcome()
{
    string userInput;
    int winCountA, winCountB;
    // Read the Players name.
    fstream prefFile(".preference", fstream::in);
    prefFile >> PlayerA >> PlayerB >> winCountA >> winCountB;
    cout << "========================================================" << endl;
    cout << "Welcome to the Notakto, " << PlayerA << " & " << PlayerB << "." << endl
         << "   Total battle times: " << winCountA + winCountB << "." << endl
         << "   Player " << PlayerA << " wins: " << winCountA << "." << endl
         << "   Player " << PlayerB << " wins: " << winCountB << "." << endl
         << "========================================================" << endl
         << " Continue without changing the player name? (y/n)" << endl
         << ": ";
    cin >> userInput;

    if (userInput == "y")
    {
        cout << "========================================================" << endl;
        return 1;
    }
    else if (userInput == "n")
    {
        NameSetting(winCountA, winCountB);
        return 0;
    }
    else
        exit(0);
}

void getParameters()
{
    srand(time(NULL));
    int sizeB;
    cout << "Board (0 or 1-6): ";
    cin >> sizeB;
    if (sizeB >= 1 && sizeB <= 6)
        sizeBoard = sizeB;
    else if (sizeB == 0)
        sizeBoard = rand() % 5 + 1;
    else
        sizeBoard = -1;
}

void addWins(int P){
    int winCountA, winCountB;
    // Read the Players name.
    fstream prefFile(".preference", fstream::in | fstream::out | fstream::trunc);
    prefFile >> PlayerA >> PlayerB >> winCountA >> winCountB;
    if (P == 0)
        winCountA++;
    else
        winCountB++;
    prefFile << PlayerA << " " << PlayerB << endl << winCountA << winCountB;
}
void getParameters()
{
    srand(time(NULL));
    int sizeB;
    cout << "Board (0 or 1-6): ";
    cin >> sizeB;
    if (sizeB >= 1 && sizeB <= 6)
        sizeBoard = sizeB;
    else if (sizeB == 0)
        sizeBoard = rand() % 5 + 1;
    else
        sizeBoard = -1;
}

void addWins(int P){
    int winCountA, winCountB;
    // Read the Players name.
    fstream prefFile(".preference", fstream::in | fstream::out | fstream::trunc);
    prefFile >> PlayerA >> PlayerB >> winCountA >> winCountB;
    if (P == 0)
        winCountA++;
    else
        winCountB++;
    prefFile << PlayerA << " " << PlayerB << endl << winCountA << winCountB;
}
