#include "pawn.h"
#include "game.h"
#include <QDebug>
#include <typeinfo>
#include "king.h"
extern Game * game;
Pawn::Pawn(Side m_side,QGraphicsItem *parent):ChessPiece(m_side,parent)
{
    setImage();
    firstMove = true;
}

void Pawn::setImage()
{
    if(side == Side::WHITE)
        setPixmap(QPixmap(":/images/pawn-white.png"));
    else
        setPixmap(QPixmap(":/images/pawn-black.png"));
}

void Pawn::moveVariations(){
    moves_list.clear();
    int row = this->getCurrentBox()->row;
    int col = this->getCurrentBox()->col;
    if(this->getSide() == Side::WHITE)  {
        if(col > 0 && row > 0 && game->desk[row-1][col-1]->getPieceSide() == Side::BLACK)
            moves_list.append(game->desk[row-1][col-1]);
        if(col < 7 && row > 0 && game->desk[row-1][col+1]->getPieceSide() == Side::BLACK)
            moves_list.append(game->desk[row-1][col+1]);
        if(row>0 && (!game->desk[row-1][col]->getHasPiece())) {
            moves_list.append(game->desk[row-1][col]);
            if(firstMove && !game->desk[row-2][col]->getHasPiece())
                moves_list.append(game->desk[row-2][col]);
        }
    }
    else{
        if(col > 0 && row < 7 && game->desk[row+1][col-1]->getPieceSide() == Side::WHITE)
            moves_list.append(game->desk[row+1][col-1]);
        if(col < 7 && row <  7 && game->desk[row+1][col+1]->getPieceSide() == Side::WHITE)
            moves_list.append(game->desk[row+1][col+1]);
        if(row<7 && (!game->desk[row+1][col]->getHasPiece())) {
            moves_list.append(game->desk[row+1][col]);
            if(firstMove && !game->desk[row+2][col]->getHasPiece())
                moves_list.append(game->desk[row+2][col]);
        }
    }
}


