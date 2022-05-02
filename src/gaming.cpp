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

void Move(Board *Board, char moveID, int movePos)
{
}


void judgeDead(Board Piece)
{
}

bool judgeWinner(Board *board)
{
    return 0;
}