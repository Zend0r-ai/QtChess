#include "game.h"
#include "button.h"
#include <QPixmap>
//#include "king.h"
#include <QDebug>
#include <QImage>
#include <QGraphicsView>

Game::Game(QWidget *parent) : QGraphicsView(parent) {

    auto bg = QImage(":/images/background.png");

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,500,500);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(bg));
    item->setPos(width()/2-268, 51);
    addToScene(item);

    setMinimumSize(500,500);
    setScene(gameScene);
    currentPiece = NULL;
    setTurn(Side::WHITE);
}

void Game::drawChessBoard() {
    chess = new ChessBoard();
    chess->drawBoxes(width()/2-200, 50);
}

void Game::addToScene(QGraphicsItem *item) {
    gameScene->addItem(item);
}

void Game::removeFromScene(QGraphicsItem *item) {
    gameScene->removeItem(item);
}

Side Game::getTurn() {
    return turn;
}

void Game::setTurn(Side new_turn) {
    turn = new_turn;
}

void Game::changeTurn() {
    turn == Side::WHITE ? turn = Side::BLACK : turn = Side::WHITE;
}

void Game::startGame() {
    drawChessBoard();
    chess->addPiece();
}

