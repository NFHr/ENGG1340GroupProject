#include "game.h"


void addPiece(Board *&head) // Append the piece backward
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

void deletePiece(Board *&head,char id)
{
    Board* curNode = NULL;
    if (head->p.ID == id)
    {
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Board* temp = head;
            head = head->next;
            delete temp;
        }
        return;
    }
    while (head)
    {
        if (head->p.ID == id)
        {
            Board* temp = head;
            curNode->next = head->next;
            delete temp;
            return;
        }
        curNode = head;
        head = head->next;
    }
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
    return count;
}

void printBoard(Board *board)
{
    Board* cutNode = board;
    Board* moveNode = cutNode;
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
                {
                    cout << 'X' << " ";
                }
                else
                {
                    cout << i << " ";
                }
            }
            cout << " ";
            moveNode = moveNode->next;
        }
        cout  << endl;
        count += 3;
    }
}
