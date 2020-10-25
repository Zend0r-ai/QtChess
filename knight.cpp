#include "knight.h"
#include "game.h"
extern Game *game;

Knight::Knight(Side m_side,QGraphicsItem *parent):ChessPiece(m_side,parent)
{
    setImage();
}

void Knight::setImage()
{
    if(side == Side::WHITE)
        setPixmap(QPixmap(":/images/horse-white.png"));
    else
        setPixmap(QPixmap(":/images/horse-black.png"));
}

void Knight::moveVariations()
{
    int row = this->getCurrentBox()->row;
    int col = this->getCurrentBox()->col;
    int i ,j;
    Side team  = this->getSide();

    i = row - 2;
    j = col - 1;
    if(i >= 0 && j >= 0 && (game->desk[i][j]->getPieceSide() != team) )
        moves_list.append(game->desk[i][j]);
    i = row - 2;
    j = col + 1;
    if(i >= 0 && j <= 7 && (game->desk[i][j]->getPieceSide() != team) )
        moves_list.append(game->desk[i][j]);
    i = row + 2;
    j = col - 1;
    if(i <= 7 && j >= 0 && (game->desk[i][j]->getPieceSide() != team) )
        moves_list.append(game->desk[i][j]);
    i = row + 2;
    j = col + 1;
    if(i <= 7 && j <= 7 && (game->desk[i][j]->getPieceSide() != team) )
        moves_list.append(game->desk[i][j]);
    i = row - 1;
    j = col - 2;
    if(i >= 0 && j >= 0 && (game->desk[i][j]->getPieceSide() != team) )
        moves_list.append(game->desk[i][j]);
    i = row + 1;
    j = col - 2;
    if(i <= 7 && j >= 0 && (game->desk[i][j]->getPieceSide() != team) )
        moves_list.append(game->desk[i][j]);
    i = row - 1;
    j = col + 2;
    if(i >= 0 && j <= 7 && (game->desk[i][j]->getPieceSide() != team) )
        moves_list.append(game->desk[i][j]);
    i = row + 1;
    j = col +  2;
    if(i <= 7 && j <= 7 && (game->desk[i][j]->getPieceSide() != team) )
        moves_list.append(game->desk[i][j]);
}

