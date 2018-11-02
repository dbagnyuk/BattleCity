#include "player.h"

QPixmap * Player::m_PlayerArray; // create array for pictures of the player's tank

// variables for player attributes
int Player::PlayerWidth, Player::PlayerHeight;
int Player::PlayerCurrentPositionX, Player::PlayerCurrentPositionY;
Direction Player::PlayerDirection;

Player::Player(QWidget *parent): QWidget(parent), painterPlayerTank(this)
{
    // difinition for the first place of player
    PlayerCurrentPositionX = PlayerDefaultPositionX,
    PlayerCurrentPositionY = PlayerDefaultPositionY;
    PlayerDirection = Up;

    qDebug() << "--> default position --> " << PlayerDirection << ", " << PlayerCurrentPositionX << "/ " << PlayerCurrentPositionY;

    PlayerLoadBitmaps(); // load the pictures of tank in memory
    PlayerWidthHeightInit(); // init the width and height of the player object

    // focuding the player object
    setFocusPolicy(Qt::StrongFocus);
    setFocus();
    grabKeyboard(); // grab the keyboard press event for player object

    qDebug() << "--> PlayerTank object is created";
}

// load the pictures of tank in memory
void Player::PlayerLoadBitmaps()
{
    m_PlayerArray = new QPixmap[PlayerImagesCount];
    m_PlayerArray[Up]    = std::move(QPixmap("resources\\Player_Tank_Up.bmp"));
    m_PlayerArray[Right] = std::move(QPixmap("resources\\Player_Tank_Right.bmp"));
    m_PlayerArray[Down]  = std::move(QPixmap("resources\\Player_Tank_Down.bmp"));
    m_PlayerArray[Left]  = std::move(QPixmap("resources\\Player_Tank_Left.bmp"));

    qDebug() << "--> Player images is loaded";
}

// init the width and height of the player object
void Player::PlayerWidthHeightInit()
{
    // init the variables with the one of pictures of tank
    PlayerWidth = m_PlayerArray[Up].width();
    PlayerHeight = m_PlayerArray[Up].height();

    qDebug() << "--> Player width and hight is initialized";
}

// procedur for drow the player's tank
//void Player::PlayerDrow(QPainter &painter)
void Player::paintEvent(QPaintEvent * event)
{
//    QPainter painter(this);
    painterPlayerTank.begin(this);
    // paint the player tank object
    painterPlayerTank.drawPixmap(PlayerCurrentPositionX, PlayerCurrentPositionY, m_PlayerArray[PlayerDirection].width(), m_PlayerArray[PlayerDirection].height(), m_PlayerArray[PlayerDirection]);
    painterPlayerTank.end();
    this->update();

//    qDebug() << "--> Player is drowed --> " << PlayerDirection << ", " << PlayerCurrentPositionX << "/ " << PlayerCurrentPositionY;
}

// event for the key press grab
void Player::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Up:
        PlayerDirection = Up;
        if (PlayerCurrentPositionY > 0 + MENUHEIGHT)
            PlayerCurrentPositionY -= PLAYERSPEED;
        break;

    case Qt::Key_Right:
        PlayerDirection = Right;
        if (PlayerCurrentPositionX <= MainWindowSizeWidth - MARGIN - PlayerWidth)
            PlayerCurrentPositionX += PLAYERSPEED;
        break;

    case Qt::Key_Down:
        PlayerDirection = Down;
        if (PlayerCurrentPositionY <= MainWindowSizeHeight - MARGIN - PlayerHeight)
            PlayerCurrentPositionY += PLAYERSPEED;
        break;

    case Qt::Key_Left:
        PlayerDirection = Left;
        if (PlayerCurrentPositionX > 0 + MARGIN)
            PlayerCurrentPositionX -= PLAYERSPEED;
        break;

    case Qt::Key_Space:
        Bullet * bullet = new Bullet(0, PlayerCurrentPositionX, PlayerCurrentPositionY, PlayerDirection);
//        bullet->setVisible(true);
        bullet->show();

        qDebug() << "--> Space button pressed";
        break;
    }
    //    this->releaseKeyboard();

//    qDebug() << "--> arrow button pressed --> " << PlayerDirection << ", " << PlayerCurrentPositionX << "/ " << PlayerCurrentPositionY;
}

Player::~Player()
{
    qDebug() << "--> Player deleted";
}
