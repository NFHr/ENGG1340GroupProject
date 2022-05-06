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

extern int isGuest;
extern int sizeBoard, skills;
extern string PlayerA, PlayerB;
extern int winCountA, winCountB;
extern char globalID; // globalID is the ID of the tail Piece in the Board.
extern Board *board;

// initializing.cpp
//  Functions outside playing
extern bool showWelcome();
extern void NameSetting(int winsA, int winsB);
extern void getParameters();
extern void addWins(int P);

// gaming.cpp
//  Funcions during the game
extern string judgeInput(char &moveID, int &movePos, int PlayerNum);
extern void skill(int Player);
extern bool judgeDead(Board Piece);
extern void Move(char moveID, int movePos);
extern string NumToName(int PlayerNum);

// boarding.cpp
//  Functions to handle the linked list
extern void printBoard();
extern void deletePiece(char ID);
extern void addPiece();
extern int countLength();
extern int findPiece(char aID);
#endif
