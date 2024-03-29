// game.h
#ifndef GAMING_FUNCTION
#define GAMING_FUNCTION

#include <iostream>
#include <string>

using namespace std;


struct Piece
{
    char ID;
    bool piece[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};  // the chess represents "1"
};

// A linked lists to handle the function of add/delete board during runtime
struct Board
{
    Piece p;
    Board *next;
};

// Global Parameters of the Game
extern int isGuest; //flag of determing whether the players are guests
extern int sizeBoard, skills;  //size of Board, remaining number of skills
extern string PlayerA, PlayerB; // name of players
extern int winCountA, winCountB; // count of winning number of players
extern char globalID; // the ID of the tail Piece in the Board.
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
