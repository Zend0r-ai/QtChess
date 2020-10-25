#include "king.h"
#include "game.h"
#include "pawn.h"
#include <QDebug>

extern Game *game;
King::King(Side m_side,QGraphicsItem *parent) : ChessPiece(m_side, parent), is_chess(false)
{
    setImage();
}

void King::setImage()
{
    if(side == Side::WHITE)
        setPixmap(QPixmap(":/images/king-white.png"));
    else
        setPixmap(QPixmap(":/images/king-black.png"));
}

void King::moveVariations()
{

    moves_list.clear();
    int row = this->getCurrentBox()->row;
    int col = this->getCurrentBox()->col;
    Side team = this->getSide();

//    if(game->desk[row][col]->currentPiece->getFirstMove())
//    {
//        if(row == 0 &&
//                !game->desk[row][3]->currentPiece &&
//                !game->desk[row][2]->currentPiece &&
//                !game->desk[row][1]->currentPiece &&
//                game->desk[row][0]->currentPiece &&
//                game->desk[row][0]->currentPiece->getFirstMove()) {
//            castlingRook = game->desk[row][0]->currentPiece;
//            rookSpot = game->desk[row][2]->currentPiece;
//            moves_list.append(game->desk[row][2]);
//        }
//        if(row == 0 &&
//                !game->desk[row][5]->currentPiece &&
//                !game->desk[row][6]->currentPiece &&
//                game->desk[row][7]->currentPiece &&
//                game->desk[row][7]->currentPiece->getFirstMove()) {
//            castlingRook = game->desk[row][7]->currentPiece;
//            rookSpot = game->desk[row][5]->currentPiece;
//            moves_list.append(game->desk[row][6]);
//        }
//        if(row == 7 &&
//                !game->desk[row][3]->currentPiece &&
//                !game->desk[row][2]->currentPiece &&
//                !game->desk[row][1]->currentPiece &&
//                game->desk[row][0]->currentPiece &&
//                game->desk[row][0]->currentPiece->getFirstMove()) {
//            castlingRook = game->desk[row][0]->currentPiece;
//            rookSpot = game->desk[row][2]->currentPiece;
//            moves_list.append(game->desk[row][2]);
//        }
//        if(row == 7 &&
//                !game->desk[row][5]->currentPiece &&
//                !game->desk[row][6]->currentPiece &&
//                game->desk[row][7]->currentPiece &&
//                game->desk[row][7]->currentPiece->getFirstMove()) {
//            castlingRook = game->desk[row][7]->currentPiece;
//            rookSpot = game->desk[row][5]->currentPiece;
//            moves_list.append(game->desk[row][6]);
//        }
//    }
    if(col > 0 && row > 0 && !(game->desk[row-1][col-1]->getPieceSide() == team))
        moves_list.append(game->desk[row-1][col-1]);
    if(col < 7 && row > 0 && !(game->desk[row-1][col+1]->getPieceSide() == team))
        moves_list.append(game->desk[row-1][col+1]);
    if(row > 0 && !(game->desk[row-1][col]->getPieceSide() == team))
        moves_list.append(game->desk[row-1][col]);
    if(row < 7 && !(game->desk[row+1][col]->getPieceSide() == team))
        moves_list.append(game->desk[row+1][col]);
    if(col > 0 && !(game->desk[row][col-1]->getPieceSide() == team))
        moves_list.append(game->desk[row][col-1]);
    if(col < 7 && !(game->desk[row][col+1]->getPieceSide() == team))
        moves_list.append(game->desk[row][col+1]);
    if(col > 0 && row < 7  && !(game->desk[row+1][col-1]->getPieceSide() == team))
        moves_list.append(game->desk[row+1][col-1]);
    if(col < 7 && row < 7 && !(game->desk[row+1][col+1]->getPieceSide() == team))
        moves_list.append(game->desk[row+1][col+1]);
}

void King::setChess(bool data) {
    is_chess = data;
}

bool King::getChess() const {
    return is_chess;
}

ChessPiece *King::getCastlingRook() const
{
    return castlingRook;
}

ChessPiece *King::getRookSpot() const
{
    return rookSpot;
}

void King::unsetRook()
{
    delete castlingRook;
}

void King::unsetSpot()
{
    delete rookSpot;
}
