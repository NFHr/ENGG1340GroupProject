// game.h
#ifndef GAMING_FUNCTION
#define GAMING_FUNCTION

#include <iostream>
#include <string>

using namespace std;

// Parameters of the Game
struct Piece
{
    char ID;
    bool piece[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
};

// A linked lists to handle the function of add/delete board during runtime
struct Board
{
    Piece p;
    Board *next;
};

extern int sizeBoard;
extern string PlayerA, PlayerB;
extern char globalID; // globalID is the ID of the tail Piece in the Board.

// Functions outside playing
bool showFirstTime();
bool showWelcome();
void NameSetting(int winsA, int winsB);
void getParameters();
void addWins(int P);

// Funcions during the game
string judgeInput(char &moveID, int &movePos, int PlayerNum, int specialMove);
bool judgeWinner(Board *board);
void specialSkill(int Player, int &specialMove, Board *board);

// functions to handle the linked list
void printBoard(Board *head);
void deletePiece(Board *head);
void addPiece(Board *head);
void Move(Board *Board, char moveID, int movePos);
int countLength(Board *head);

#endif