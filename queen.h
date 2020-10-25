#pragma once

#include "chesspiece.h"
#include "main.h"
class Queen:public ChessPiece
{
public:
    Queen(Side m_side, QGraphicsItem *parent = 0);
    void setImage();

    void moveVariations();

};

