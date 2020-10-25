#pragma once

#include "chesspiece.h"
#include "main.h"

class Bishop:public ChessPiece
{
public:
    Bishop(Side m_side ,QGraphicsItem *parent = 0);
    void setImage();

    void moveVariations();

};
