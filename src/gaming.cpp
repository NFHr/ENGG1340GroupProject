#include "game.h"

//TO-DO 输入保护
//输入: 仍可操作的棋盘的编号(字母)(0-8)范围的数字
//特殊输入：输入"SKILL" 会返回 "ADD", 输入GIVEUP会返回 "GIVEUP"
//输出: "Player 'NumToName(PlayerNum)' (SKILL Remains: 'specialMove'): "
//如果是棋盘编号则修改

string judgeInput(char &moveID, int &movePos, int PlayerNum, int specialMove)
{
    string userInput;
    return "";
}

string NumToName(int PlayerNum){
    string Pikachu;
    if (PlayerNum == 0)
        return PlayerA;
    else
        return PlayerB;
}

void specialSkill(int PlayerNum, int &specialMove, Board *board)
{
    specialMove--;
    if (countLength(board) == sizeBoard)
        cout << "The Board is full! One chance is lost!";
    else
    {
        cout << "PLAYER " << NumToName(PlayerNum) << "  used SPECIAL MOVEMENT!!";
        addPiece(board);
    }
}


bool judgeDead(Board Piece)
{
    if (Piece.p.piece[0] == Piece.p.piece[1] && Piece.p.piece[1] == Piece.p.piece[2] && Piece.p.piece[0] == true) return true;
    if (Piece.p.piece[3] == Piece.p.piece[4] && Piece.p.piece[4] == Piece.p.piece[5] && Piece.p.piece[3] == true) return true;
    if (Piece.p.piece[6] == Piece.p.piece[7] && Piece.p.piece[7] == Piece.p.piece[8] && Piece.p.piece[6] == true) return true;
    if (Piece.p.piece[0] == Piece.p.piece[3] && Piece.p.piece[3] == Piece.p.piece[6] && Piece.p.piece[0] == true) return true;
    if (Piece.p.piece[1] == Piece.p.piece[4] && Piece.p.piece[4] == Piece.p.piece[7] && Piece.p.piece[1] == true) return true;
    if (Piece.p.piece[2] == Piece.p.piece[5] && Piece.p.piece[5] == Piece.p.piece[8] && Piece.p.piece[2] == true) return true;
    if (Piece.p.piece[0] == Piece.p.piece[4] && Piece.p.piece[4] == Piece.p.piece[8] && Piece.p.piece[0] == true) return true;
    if (Piece.p.piece[2] == Piece.p.piece[4] && Piece.p.piece[4] == Piece.p.piece[6] && Piece.p.piece[2] == true) return true;
    return false;
}
void Move(Board *&board, char moveID, int movePos)
{
    Board *moveNode = board;
    while (moveNode)
    {
        if (moveNode->p.ID == moveID)
        {
            moveNode->p.piece[movePos] = true;
            if (judgeDead(*moveNode))
            {
                deletePiece(board, moveID);
            }
            break;
        }
        moveNode = moveNode->next;
    }
}



bool judgeWinner(Board *board)
{
    return countLength(board) == 0;
}
