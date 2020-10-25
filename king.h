#pragma once

#include "chesspiece.h"
#include "main.h"
class King:public ChessPiece
{
public:
    King(Side m_side, QGraphicsItem *parent = 0);
    void setImage();
    void findUnSafeLocation();
    void moveVariations();
    void setChess(bool data);
    bool getChess() const;
    ChessPiece *getCastlingRook() const;
    ChessPiece *getRookSpot() const;
    void unsetRook();
    void unsetSpot();
private:
    ChessPiece *castlingRook;
    ChessPiece *rookSpot;
    bool is_chess;
};

