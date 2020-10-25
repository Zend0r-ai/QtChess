#include "bishop.h"
#include <QDebug>
#include "game.h"
extern Game *game;

Bishop::Bishop(Side m_side, QGraphicsItem *parent):ChessPiece(m_side,parent)
{
    setImage();
}

void Bishop::setImage()
{
    if(side == Side::WHITE)
        setPixmap(QPixmap(":/images/bishop-white.png"));
    else
        setPixmap(QPixmap(":/images/bishop-black.png"));
}

void Bishop::moveVariations()
{
    moves_list.clear();
    int row = this->getCurrentBox()->row;
    int col = this->getCurrentBox()->col;
    Side team = this->getSide();

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
