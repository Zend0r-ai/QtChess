#pragma once

#include "chesspiece.h"
#include "main.h"

class Rook : public ChessPiece
{
public:
    Rook(Side m_side, QGraphicsItem *parent = 0);

    void setImage();
    void moveVariations();

};

