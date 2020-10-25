#pragma once
#include "chesspiece.h"
#include "main.h"
class Knight:public ChessPiece
{
public:
    Knight(Side m_side, QGraphicsItem *parent = 0);
    void setImage();

    void moveVariations();

};
