#include "game.h"

// append the piece backward to the board(linked list)
void addPiece() 
{
    Board *moveNode = board;
    Board *newPiece = new Board;
    newPiece->p.ID = globalID;
    newPiece->next = NULL;

    if (board == NULL)
        board = newPiece;
    else
    {
        while (moveNode->next != NULL) // go to the tail
            moveNode = moveNode->next;
        moveNode->next = newPiece;
    }
    globalID++;
}

//delete one piece in the board(linked list)
void deletePiece(char ID)
{
    int pos = findPiece(ID);
    Board *moveNode = board;
    if (pos == 0)
    {
        board = moveNode->next;
        delete moveNode;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++) // move to the node before the ID's node
            moveNode = moveNode->next;
        if (moveNode->next->next == NULL) // if the ID is tail
        {
            delete moveNode->next;
            moveNode->next = NULL;
        }

        else
        {
            Board *temp_next = moveNode->next->next;
            delete moveNode->next;
            moveNode->next = temp_next;
        }
    }
}

// return the position of one pieces in the board(linked list)
int findPiece(char aID)
{
    int count = 0;
    Board *moveNode = board;
    while (moveNode != NULL)
    {
        if (moveNode->p.ID == aID)
            return count;
        else
        {
            moveNode = moveNode->next;
            count++;
        }
    }
    return -1;
}

// return the length of the board
int countLength()
{
    Board *moveNode = board;
    int count = 0;
    while (moveNode != NULL)
    {
        count++;
        moveNode = moveNode->next;
    }
    return count;
}

//print the full board(linked list)
void printBoard()
{
    cout << "\033[1;1m";
    Board *cutNode = board;
    Board *moveNode = cutNode;
    while (moveNode)
    {
        printf("%-7c", moveNode->p.ID);
        moveNode = moveNode->next;
    }
    cout << endl;
    int count = 0;
    while (count < 9)
    {
        moveNode = cutNode;
        while (moveNode)
        {
            for (int i = count; i < count + 3; i++)
            {
                if (moveNode->p.piece[i])
                    cout << 'X' << " ";
                else
                    cout << i << " ";
            }
            cout << " ";
            moveNode = moveNode->next;
        }
        cout << endl;
        count += 3;
    }
    cout << "\033[0m";
}

