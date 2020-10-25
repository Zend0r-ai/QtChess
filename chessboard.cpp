#include "chessboard.h"
#include "chessbox.h"
#include "game.h"
#include "queen.h"
#include "rook.h"
#include "pawn.h"
#include "king.h"
#include "knight.h"
#include "bishop.h"
#include <QDebug>
extern Game *game;
ChessBoard::ChessBoard()
{
    setUpBlack();
    setUpWhite();
}
void ChessBoard::drawBoxes(int x,int y)
{
    int SHIFT = 50;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            ChessBox *box = new ChessBox();
            game->desk[i][j] = box;
            box->row = i;
            box->col = j;
            box->setPen(QColor(174, 87, 0));
            box->setPos(x+SHIFT*j,y+SHIFT*i);
            if((i+j)%2==0)
                box->setOriginalColor(QColor(255, 255, 255));
            else
                box->setOriginalColor(QColor(174, 87, 0));
            game->addToScene(box);
        }
    }
}



void ChessBoard::addPiece() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            ChessBox *box =game->desk[i][j];
            if(i < 2) {
                static int k;
                box->movePiece(black[k]);
                game->all_pieces_in_desk.append(black[k]);
                game->addToScene(black[k++]);
            }
            if(i > 5) {
                 static int h;
                box->movePiece(white[h]);
                game->all_pieces_in_desk.append(white[h]);
                game->addToScene(white[h++]);
            }
        }
    }
}

void ChessBoard::setUpWhite()
{
    ChessPiece *piece;
    for(int i = 0; i < 8; i++) {
        piece = new Pawn(Side::WHITE);
        white.append(piece);
    }
    piece = new Rook(Side::WHITE);
    white.append(piece);
    piece = new Knight(Side::WHITE);
    white.append(piece);
    piece = new Bishop(Side::WHITE);
    white.append(piece);
    piece = new Queen(Side::WHITE);
    white.append(piece);
    piece = new King(Side::WHITE);
    white.append(piece);
    piece = new Bishop(Side::WHITE);
    white.append(piece);
    piece = new Knight(Side::WHITE);
    white.append(piece);
    piece = new Rook(Side::WHITE);
    white.append(piece);
}

void ChessBoard::setUpBlack()
{
    ChessPiece *piece;
    piece = new Rook(Side::BLACK);
    black.append(piece);
    piece = new Knight(Side::BLACK);
    black.append(piece);
    piece = new Bishop(Side::BLACK);
    black.append(piece);
    piece = new Queen(Side::BLACK);
    black.append(piece);
    piece = new King(Side::BLACK);
    black.append(piece);
    piece = new Bishop(Side::BLACK);
    black.append(piece);
    piece = new Knight(Side::BLACK);
    black.append(piece);
    piece = new Rook(Side::BLACK);
    black.append(piece);
    for(int i = 0; i < 8; i++) {
        piece = new Pawn(Side::BLACK);
        black.append(piece);
    }
}
