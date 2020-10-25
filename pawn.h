#pragma once

#include "chesspiece.h"
#include "main.h"

class Pawn:public ChessPiece
{
public:
    Pawn(Side m_side, QGraphicsItem *parent = 0);
    void setImage();
    void moveVariations();

 private:


};
