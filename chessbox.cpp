#include "chessbox.h"
#include "game.h"
#include <QDebug>
#include "king.h"

extern Game *game;
ChessBox::ChessBox(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setRect(0,0,50,50);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setHasPiece(false);
    setPieceSide(Side::EMPTY);
    currentPiece = NULL;
}

ChessBox::~ChessBox()
{
    delete this;
}

void ChessBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(currentPiece && game->currentPiece &&
            (currentPiece == game->currentPiece ||
             currentPiece->getSide() == game->currentPiece->getSide())){
        currentPiece->mousePressEvent(event);
        return;
    }

    if(game->currentPiece){
        if(this->getPieceSide() == game->currentPiece->getSide())
            return;
        QList <ChessBox *> movLoc = game->currentPiece->getMoveLocation();
        int check = 0;
        for(size_t i = 0, n = movLoc.size(); i < n;i++) {
            if(movLoc[i] == this) {
                check++;

            }
        }
        if(check == 0)
            return;
         game->currentPiece->resetColorInDesk();
         game->currentPiece->setFirstMove(false);
        if(this->getHasPiece()){
            this->currentPiece->setIsPlaced(false);
            this->currentPiece->setCurrentBox(NULL);
            King *g = dynamic_cast <King *>(this->currentPiece);
            if(g){
                game->close();
            }
            game->all_pieces_in_desk.removeAll(this->currentPiece);
            delete this->currentPiece;

        }
        game->currentPiece->getCurrentBox()->setHasPiece(false);
        game->currentPiece->getCurrentBox()->currentPiece = NULL;
        game->currentPiece->getCurrentBox()->resetOriginalColor();
//        King *g = dynamic_cast <King *>(game->currentPiece);
//        if(g && g->getCastlingRook() &&  g->getCastlingRook()->getCurrentBox()){
//                g->getCastlingRook()->getCurrentBox()->movePiece(g->getRookSpot());
//        }

        movePiece(game->currentPiece);

        game->currentPiece = NULL;
        game->changeTurn();
        checkForCheck();
    }
    else if(this->getHasPiece())
    {
        this->currentPiece->mousePressEvent(event);
    }
}

void ChessBox::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}

void ChessBox::movePiece(ChessPiece *piece)
{

    piece->setPos(x()+25- piece->pixmap().width()/2  ,y()+25-piece->pixmap().width()/2);
    piece->setCurrentBox(this);
    setHasPiece(true,piece);
    currentPiece = piece;


}

void ChessBox::resetOriginalColor()
{
        setColor(originalColor);
}



void ChessBox::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}

bool ChessBox::getHasPiece()
{
    return hasChessPiece;
}

void ChessBox::setHasPiece(bool value, ChessPiece *piece)
{
    hasChessPiece = value;
    if(value)
        setPieceSide(piece->getSide());
    else
        setPieceSide(Side::EMPTY);
}

void ChessBox::checkForCheck()
{
    QList <ChessPiece *> pList = game->all_pieces_in_desk;

    for(size_t i = 0,n=pList.size(); i < n; i++ ) {
        King * king = dynamic_cast<King *> (pList[i]);
        if(king){
            continue;
        }
        pList[i]->moveVariations();
        pList[i]->resetColorInDesk();
        QList <ChessBox *> bList = pList[i]->getMoveLocation();
        for(size_t j = 0,n = bList.size(); j < n; j ++) {
            King * king = dynamic_cast<King *> (bList[j]->currentPiece);
            if(king) {
                if(king->getSide() == pList[i]->getSide())
                    continue;
            }
        }
    }
}

Side ChessBox::getPieceSide()
{
    return chessPieceColor;
}

void ChessBox::setPieceSide(Side color)
{
    chessPieceColor = color;
}
