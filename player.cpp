#include "mainwindow.h"
#include "player.h"

#include "inclusions.h"
#include "definitions.h"

QPixmap * Player::m_PlayerArray;
//QMainWindow * MainWindow;

int Player::PlayerWidth, Player::PlayerHeight;

Player::Player()
{
    qDebug() << "--> PlayerTank object is created";

    PlayerLoadBitmaps();
    PlayerWidthHeightInit();

    setFocusPolicy(Qt::StrongFocus);
    setFocus();
    grabKeyboard();
}

void Player::PlayerLoadBitmaps()
{
    qDebug() << "--> Player images is loaded";

    m_PlayerArray = new QPixmap[PlayerImagesCount];
    m_PlayerArray[Right] = std::move(QPixmap("resources\\Player_Tank_Right.bmp"));
    m_PlayerArray[Left]  = std::move(QPixmap("resources\\Player_Tank_Left.bmp"));
    m_PlayerArray[Down]  = std::move(QPixmap("resources\\Player_Tank_Down.bmp"));
    m_PlayerArray[Up]    = std::move(QPixmap("resources\\Player_Tank_Up.bmp"));
}

void Player::PlayerDrow(QPainter &painter, Direction PlayerDirection, int PlayerPositionX, int PlayerPositionY)
{
    qDebug() << "--> Player is drowed";

    painter.drawPixmap(PlayerPositionX, PlayerPositionY, m_PlayerArray[PlayerDirection].width(), m_PlayerArray[PlayerDirection].height(), m_PlayerArray[PlayerDirection]);
}

void Player::PlayerWidthHeightInit()
{
    qDebug() << "--> Player width and hight is initialized";

    PlayerWidth = m_PlayerArray[Up].width();
    PlayerHeight = m_PlayerArray[Up].height();
}

void Player::keyPressEvent(QKeyEvent * event)
{
//    qDebug() << "--> button pressed";

    switch(event->key())
    {
    case Qt::Key_Right:
        m_PlayerDirection = Right;
        if (PlayerCurrentPositionX <= /*MainWindow->size().width()*/800 - MARGIN - PLAYERSPEED - PlayerWidth)
            PlayerCurrentPositionX += PLAYERSPEED;
        qDebug() << "--> " << m_PlayerDirection << ", " << PlayerCurrentPositionX;
        break;

    case Qt::Key_Left:
        m_PlayerDirection = Left;
        if (PlayerCurrentPositionX > 0 + MARGIN)
            PlayerCurrentPositionX -= PLAYERSPEED;
        qDebug() << "--> " << m_PlayerDirection << ", " << PlayerCurrentPositionX;
        break;

    case Qt::Key_Down:
        m_PlayerDirection = Down;
        if (PlayerCurrentPositionY <= /*MainWindow->size().height()*/600 - MARGIN - PlayerWidth)
            PlayerCurrentPositionY += PLAYERSPEED;
        qDebug() << "--> " << m_PlayerDirection << ", " << PlayerCurrentPositionY;
        break;

    case Qt::Key_Up:
        m_PlayerDirection = Up;
        if (PlayerCurrentPositionY > 0 + MENUHEIGHT)
            PlayerCurrentPositionY -= PLAYERSPEED;
        qDebug() << "--> " << m_PlayerDirection << ", " << PlayerCurrentPositionY;
        break;

    case Qt::Key_Space:
//        Bullet * MyBullet = new Bullet();
        qDebug() << "--> Space";
        break;
    }
    //    this->releaseKeyboard();
}

//void Player::paintEvent(QPaintEvent * event)
//{
//    QPainter painter(this);
//    PlayerDrow(painter,m_PlayerDirection,PlayerCurrentPositionX,PlayerCurrentPositionY);
//}
