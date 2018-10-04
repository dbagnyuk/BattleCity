#ifndef PLAYER_H
#define PLAYER_H

#include "definitions.h"
#include "inclusions.h"

class Player: public QWidget
{
    PlayerId m_Id;
    static QPixmap * m_PlayerArray;

    const int PlayerDefaultPositionX = (800 - MARGIN) / 2 - 25, PlayerDefaultPositionY = (600 - MENUHEIGHT) / 2 - 25;

public:
    int PlayerCurrentPositionX = PlayerDefaultPositionX,
        PlayerCurrentPositionY = PlayerDefaultPositionY;
    Direction m_PlayerDirection = Up;


public:
    explicit Player();
    static void PlayerLoadBitmaps();
    static void PlayerWidthHeightInit();
    static int PlayerWidth, PlayerHeight;

    void PlayerDrow(QPainter &painter, Direction PlayerDirection, int PlayerPositionX, int PlayerPositionY);
    void keyPressEvent(QKeyEvent *event);
//    void paintEvent(QPaintEvent *event);
};

#endif // PLAYER_H
