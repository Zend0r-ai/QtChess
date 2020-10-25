#pragma once
#include <QGraphicsRectItem>
#include <QBrush>
#include "chesspiece.h"
#include "main.h"
#include <QGraphicsSceneMouseEvent>

class ChessPiece;
class ChessBox : public QGraphicsRectItem
{
public:
    ChessBox(QGraphicsItem *parent=0);
    ~ChessBox();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setColor(QColor color);
    void movePiece(ChessPiece *piece);

    void resetOriginalColor();
    void setOriginalColor(QColor value);


    void checkForCheck();

    Side getPieceSide();
    void setPieceSide(Side color);

    bool getHasPiece();
    void setHasPiece(bool value,ChessPiece *piece = 0);

    int row;
    int col;

    ChessPiece * currentPiece;

private:
    QBrush brush;
    QColor originalColor;
    bool hasChessPiece;
    Side chessPieceColor;
};
