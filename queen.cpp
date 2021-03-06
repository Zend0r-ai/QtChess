#include "queen.h"
#include "game.h"
extern Game *game;
Queen::Queen(Side m_side,QGraphicsItem *parent):ChessPiece(m_side,parent)
{
    setImage();
}

void Queen::setImage()
{
    if(side == Side::WHITE)
        setPixmap(QPixmap(":/images/queen-white.png"));
    else
        setPixmap(QPixmap(":/images/queen-black.png"));
}

void Queen::moveVariations()
{
    moves_list.clear();
    int row = this->getCurrentBox()->row;
    int col = this->getCurrentBox()->col;
    Side team = this->getSide();

    for(int i = row-1,j = col; i >= 0 ; i--) {
        if(game->desk[i][j]->getPieceSide() == team )
            break;
        else
            moves_list.append(game->desk[i][j]);
    }

    for(int i = row+1,j = col; i <= 7 ; i++) {
        if(game->desk[i][j]->getPieceSide() == team )
            break;
        else
            moves_list.append(game->desk[i][j]);
    }

    for(int i = row,j = col-1; j >= 0 ; j--) {
        if(game->desk[i][j]->getPieceSide() == team )
            break;
        else
            moves_list.append(game->desk[i][j]);
    }

    for(int i = row,j = col+1; j <= 7 ; j++) {
        if(game->desk[i][j]->getPieceSide() == team )
            break;
        else
            moves_list.append(game->desk[i][j]);
    }

    for(int i = row-1,j = col-1; i >= 0 && j >=0; i--,j--) {
        if(game->desk[i][j]->getPieceSide() == team )
            break;
        else
            moves_list.append(game->desk[i][j]);
    }

    for(int i = row-1,j = col+1; i >= 0 && j <= 7; i--,j++) {
        if(game->desk[i][j]->getPieceSide() == team )
            break;
        else
            moves_list.append(game->desk[i][j]);
    }

    for(int i = row+1,j = col+1; i <= 7 && j <= 7; i++,j++) {
        if(game->desk[i][j]->getPieceSide() == team )
            break;
        else
            moves_list.append(game->desk[i][j]);
    }

    for(int i = row+1,j = col-1; i <= 7 && j >= 0; i++,j--) {
        if(game->desk[i][j]->getPieceSide() == team )
            break;
        else
            moves_list.append(game->desk[i][j]);
    }
}
