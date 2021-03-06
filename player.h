#ifndef PLAYER_H
#define PLAYER_H

#include "definitions.h"
#include "inclusions.h"

#include "mainwindow.h"
#include "bullet.h"

class Player: public QWidget
{
    Q_OBJECT

    PlayerId m_Id;
    static QPixmap * m_PlayerArray;

private:
    // start position in the field of window for player object
    const int PlayerDefaultPositionX = (MainWindowSizeWidth - MARGIN) / 2 - 25,
              PlayerDefaultPositionY = (MainWindowSizeHeight - MENUHEIGHT) / 2 - 25;

    QPainter painterPlayerTank;

public:
    static int PlayerWidth, PlayerHeight; // mesure of player object
    static int PlayerCurrentPositionX, PlayerCurrentPositionY; // position of the player wich will be change
    static Direction PlayerDirection; // player's tank direction


public:
    explicit Player(QWidget *parent = 0);
    ~Player();

    static void PlayerLoadBitmaps(); // load the pictures of tank in memory
    static void PlayerWidthHeightInit(); // init the width and height of the player object

protected:
    void paintEvent(QPaintEvent * event); // procedur for drow the player's tank
//    void PlayerDrow(QPainter &painter); // procedur for drow the player's tank
    void keyPressEvent(QKeyEvent *event); // event for the key press grab
};

#endif // PLAYER_H
