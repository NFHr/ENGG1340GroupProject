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
extern bool showFirstTime();
extern bool showWelcome();
extern void NameSetting(int winsA, int winsB);
extern void getParameters();
extern void addWins(int P);

// Funcions during the game
string judgeInput(char &moveID, int &movePos);
extern bool judgeWinner(Board *board);
extern string specialSkill(int Player);

// functions to handle the linked list
extern void printBoard(Board *head);
extern void deletePiece(Board *head);
extern void addPiece(Board *head);
extern void Move(Board *Board, char moveID, int movePos);

#endif