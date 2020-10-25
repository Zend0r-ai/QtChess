#include "chesspiece.h"
#include "game.h"
#include <QDebug>
#include "king.h"

extern Game *game;
ChessPiece::ChessPiece(Side m_side, QGraphicsItem *parent) : QGraphicsPixmapItem(parent),
                                                            firstMove(true), side(m_side), isPlaced(true)
{
}

void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(this == game->currentPiece){
        game->currentPiece->getCurrentBox()->resetOriginalColor();
        game->currentPiece->resetColorInDesk();
        game->currentPiece = NULL;
       return;
    }
    if(game->currentPiece && this->getSide() == game->currentPiece->getSide()){
        game->currentPiece->getCurrentBox()->resetOriginalColor();
        game->currentPiece->resetColorInDesk();
        game->currentPiece = this;
        game->currentPiece->getCurrentBox()->setColor(Qt::red);
        game->currentPiece->moveVariations();
        return;
    }
    if((!getIsPlaced() )|| ( (game->getTurn() != this->getSide()) && (!game->currentPiece)) )
        return;
    if(!game->currentPiece){
        game->currentPiece = this;
        game->currentPiece->getCurrentBox()->setColor(Qt::red);
        game->currentPiece->moveVariations();
    }
    else if(this->getSide() != game->currentPiece->getSide()){
        this->getCurrentBox()->mousePressEvent(event);
    }
}

void ChessPiece::setCurrentBox(ChessBox *box)
{

    currentBox = box;
}

ChessBox *ChessPiece::getCurrentBox()
{
    return currentBox;
}

Side ChessPiece::getSide()
{
    return side;
}

void ChessPiece::setSide(Side new_side)
{
    side = new_side;
}

bool ChessPiece::getIsPlaced()
{
    return isPlaced;
}

void ChessPiece::setIsPlaced(bool value)
{
    isPlaced = value;

}
QList<ChessBox *> ChessPiece::getMoveLocation()
{
    return moves_list;
}
void ChessPiece::resetColorInDesk()
{
    for(size_t i = 0, n = moves_list.size(); i < n;i++)
         moves_list[i]->resetOriginalColor();
}

void ChessPiece::setFirstMove(bool data) {
    firstMove = data;
}

bool ChessPiece::getFirstMove() const {
    return firstMove;
}
