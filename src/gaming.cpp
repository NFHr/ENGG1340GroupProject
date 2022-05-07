#include "game.h"

// Judging the correctness of the input
// return the command flag for the driver part
string judgeInput(char &moveID, int &movePos, int PlayerNum)
{
    string userInput;
    while (1)
    {
        cout << "Player " << PlayerNum << " \"" << NumToName(PlayerNum) << "\" "
             << "(Power Remains: " << skills << "): ";
        cin >> userInput;
        if (userInput == "SKILL")
        {
            if (skills > 0)
            {
                return userInput;
            }
        }
        else if (userInput == "GIVUP")
            return userInput;
        else if (userInput[0] >= 'A' && userInput[0] <= 'Z' && userInput[1] >= '0' && userInput[1] <= '9')
        {
            if (findPiece(userInput[0]) != -1)
            {
                moveID = userInput[0];
                movePos = userInput[1] - '0';
                return "MOVE";
            }
        }
        cout << "\033[1;31m"
             << "Invalid Move!"
             << "\033[0m" << endl;
    }
    return "";
}

// return the true player name based on the opponent id.
string NumToName(int PlayerNum)
{
    if (PlayerNum == 1)
        return PlayerA;
    else
        return PlayerB;
}

// handle SPECIAL SKILL
void skill(int PlayerNum)
{
    skills--;
    if (countLength() == sizeBoard && sizeBoard != 1) // Rule: if the board is full and the default size is not 1
        cout << "\033[1;33m"
             << "Opponent Changed."
             << "\033[0m" << endl;
    else
    {
        cout << "\033[1;33m"
             << "New Piece Appended."
             << "\033[0m" << endl;
        addPiece();
        Move(globalID - 1, rand() % 9);
    }
}

// JUDGE whether the piece is dead
bool judgeDead(Board Piece)
{
    if (Piece.p.piece[0] == Piece.p.piece[1] && Piece.p.piece[1] == Piece.p.piece[2] && Piece.p.piece[0] == true)
        return true;
    if (Piece.p.piece[3] == Piece.p.piece[4] && Piece.p.piece[4] == Piece.p.piece[5] && Piece.p.piece[3] == true)
        return true;
    if (Piece.p.piece[6] == Piece.p.piece[7] && Piece.p.piece[7] == Piece.p.piece[8] && Piece.p.piece[6] == true)
        return true;
    if (Piece.p.piece[0] == Piece.p.piece[3] && Piece.p.piece[3] == Piece.p.piece[6] && Piece.p.piece[0] == true)
        return true;
    if (Piece.p.piece[1] == Piece.p.piece[4] && Piece.p.piece[4] == Piece.p.piece[7] && Piece.p.piece[1] == true)
        return true;
    if (Piece.p.piece[2] == Piece.p.piece[5] && Piece.p.piece[5] == Piece.p.piece[8] && Piece.p.piece[2] == true)
        return true;
    if (Piece.p.piece[0] == Piece.p.piece[4] && Piece.p.piece[4] == Piece.p.piece[8] && Piece.p.piece[0] == true)
        return true;
    if (Piece.p.piece[2] == Piece.p.piece[4] && Piece.p.piece[4] == Piece.p.piece[6] && Piece.p.piece[2] == true)
        return true;
    return false;
}

// move one chess in the piece
void Move(char moveID, int movePos)
{
    Board *moveNode = board;
    while (moveNode)
    {
        if (moveNode->p.ID == moveID)
        {
            moveNode->p.piece[movePos] = true;
            if (judgeDead(*moveNode)) // judge whether the piece is dead after one move
            {
                deletePiece(moveID);
            }
            break;
        }
        moveNode = moveNode->next;
    }
}
