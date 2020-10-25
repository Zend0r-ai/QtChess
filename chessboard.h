#pragma once

#include <QGraphicsRectItem>
#include "chesspiece.h"
#include "main.h"

class ChessBoard
{
public:
    ChessBoard();

    void drawBoxes(int x, int y);

    void setUpWhite();
    void setUpBlack();

    void addPiece();
    void reset();
private:
    QList <ChessPiece *> white;
    QList <ChessPiece *> black;



};
