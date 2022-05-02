#include "game.h"


void addPiece(Board *head) // Append the piece backward
{
    Board *tail = head;
    Board *newPiece = new Board;
    newPiece->p.ID = globalID;
    newPiece->next = NULL;

    if (head == NULL)
    {
        head = newPiece;
    }
    else
    {
        while (tail->next != NULL) // go to the tail
            tail = tail->next;
        tail->next = newPiece;
    }
    globalID++;
}

void deletePiece(Board *current)
{
    Board *dead = current;
    current = current->next;
    delete dead;
}

Board *findPiece(Board *head, char aID)
{
    Board *current = head;
    while (current != NULL)
    {
        if (current->p.ID == aID)
            return current;
        else
            current = current->next;
    }
    return NULL;
}

int countLength(Board *head)
{
    Board *current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return 0;
}

void printBoard(Board *board)
{
}
