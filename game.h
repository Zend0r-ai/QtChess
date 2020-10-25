#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>
#include <chessboard.h>
#include "chesspiece.h"
#include "main.h"

class Game:public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);

    void startGame();
    void drawChessBoard();

    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);


    Side getTurn();
    void setTurn(Side new_turn);
    void changeTurn();

    ChessBox *desk[8][8];
    ChessPiece *currentPiece;
    QList <ChessPiece *> all_pieces_in_desk;
private:
    QGraphicsScene *gameScene;
    Side turn;
    ChessBoard *chess;
    QList <QGraphicsItem *> listG;


};
