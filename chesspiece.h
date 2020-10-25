#pragma once

#include <QGraphicsPixmapItem>
#include "chessbox.h"
#include "main.h"
#include <QGraphicsSceneMouseEvent>

class ChessBox;
class ChessPiece:public QGraphicsPixmapItem
{
public:



    ChessPiece(Side m_side = Side::EMPTY, QGraphicsItem *parent = 0);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setCurrentBox(ChessBox *box);

    ChessBox *getCurrentBox() ;

    Side getSide() ;
    void setSide(Side new_side);
    virtual void setImage() = 0;

    bool getIsPlaced() ;
    void setIsPlaced(bool value);
    QList <ChessBox *> getMoveLocation();
    virtual void moveVariations() = 0;
    void resetColorInDesk();
    void setFirstMove(bool data);
    bool getFirstMove() const;

protected:
    bool firstMove;
    ChessBox *currentBox;
    Side side;
    bool isPlaced;
    QList <ChessBox *> moves_list;

};
