#include "game.h"

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
        cout << "Invalid Move!" << endl;
    }
    return "";
}

string NumToName(int PlayerNum)
{
    if (PlayerNum == 1)
        return PlayerA;
    else
        return PlayerB;
}

void skill(int PlayerNum)
{
    skills--;
    if (countLength() == sizeBoard && sizeBoard != 1)
        cout << "Opponent Changed." << endl;
    else
    {
        cout << "New Piece Appended." << endl;
        addPiece();
        Move(globalID - 1, rand() % 9);
    }
}

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

void Move(char moveID, int movePos)
{
    Board *moveNode = board;
    while (moveNode)
    {
        if (moveNode->p.ID == moveID)
        {
            moveNode->p.piece[movePos] = true;
            if (judgeDead(*moveNode))
            {
                deletePiece(moveID);
            }
            break;
        }
        moveNode = moveNode->next;
    }
}
