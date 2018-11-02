#include "bullet.h"

QPixmap * Bullet::m_BulletArray; // create array for pictures of the bullet
//QMainWindow * MainWindow;

// variables for Bullet attributes
int Bullet::BulletWidth, Bullet::BulletHeight;
//int Bullet::BulletCurrentPositionX, Bullet::BulletCurrentPositionY;
//Direction Bullet::BulletDirection;

Bullet::Bullet(QWidget *parent, int PositionX, int PositionY, Direction Direct):
               QWidget(parent), painterBullet(this), BulletCurrentPositionX(PositionX + 12), BulletCurrentPositionY(PositionY + 12), BulletDirection(Direct)
{
    // difinition for the first place of Bullet
//    BulletCurrentPositionX = Player::PlayerCurrentPositionX + 12,
//    BulletCurrentPositionY = Player::PlayerCurrentPositionY + 12;
//    BulletDirection = Player::PlayerDirection;

//    qDebug() << "--> bullet start position --> " << BulletDirection << ", " << BulletCurrentPositionX << "/ " << BulletCurrentPositionY;

    BulletLoadBitmaps(); // load the pictures of tank in memory
    BulletWidthHeightInit(); // init the width and height of the Bullet object

    on_BulletMove_triggered(); // start trigger for Bullet movement

    qDebug() << "--> bullet object is created";
}

// load the pictures of tank in memory
void Bullet::BulletLoadBitmaps()
{
    m_BulletArray = new QPixmap[BulletImagesCount];
    m_BulletArray[Up]    = std::move(QPixmap("resources\\Bullet_Up.bmp"));
    m_BulletArray[Right] = std::move(QPixmap("resources\\Bullet_Right.bmp"));
    m_BulletArray[Down]  = std::move(QPixmap("resources\\Bullet_Down.bmp"));
    m_BulletArray[Left]  = std::move(QPixmap("resources\\Bullet_Left.bmp"));

    qDebug() << "--> bullet images is loaded";
}

// init the width and height of the Bullet object
void Bullet::BulletWidthHeightInit()
{
    // init the variables with the one of pictures of tank
    BulletWidth = m_BulletArray[Up].width();
    BulletHeight = m_BulletArray[Up].height();

    qDebug() << "--> bullet width and hight is initialized";
}

// procedure for drow the Bullet's tank
//void Bullet::BulletDrow(/*QPainter &painter*/)
//void Bullet::BulletDrow(QPainter &painter)
void Bullet::paintEvent(QPaintEvent *event)
{
//    QPainter painter(this);
    painterBullet.begin(this);
    // paint the Bullet tank object
    painterBullet.drawPixmap(BulletCurrentPositionX, BulletCurrentPositionY, m_BulletArray[BulletDirection].width(), m_BulletArray[BulletDirection].height(), m_BulletArray[BulletDirection]);
    painterBullet.end();
    this->update();

//    qDebug() << "--> bullet is drowed --> " << BulletDirection << ", " << BulletCurrentPositionX << "/ " << BulletCurrentPositionY;
}

// timer for run movement of bullet
void Bullet::on_BulletMove_triggered()
{
    QTimer * timerBulletFly = new QTimer(this);
    connect(timerBulletFly, SIGNAL(timeout()), this, SLOT(on_BulletMove()));
    timerBulletFly->start(500);
}

//procedure for chenge the bullet coordinate
void Bullet::on_BulletMove()
{
    switch(BulletDirection)
    {
    case 0:
        if (BulletCurrentPositionY > 0 + MENUHEIGHT)
            BulletCurrentPositionY -= BULLETSPEED;
        else delete(this);
        break;

    case 1:
        if (BulletCurrentPositionX <= MainWindowSizeWidth - MARGIN - BulletWidth)
            BulletCurrentPositionX += BULLETSPEED;
        else delete(this);
        break;

    case 2:
        if (BulletCurrentPositionY <= MainWindowSizeHeight - MARGIN - BulletHeight)
            BulletCurrentPositionY += BULLETSPEED;
        else delete(this);
        break;

    case 3:
        if (BulletCurrentPositionX > 0 + MARGIN)
            BulletCurrentPositionX -= BULLETSPEED;
        else delete(this);
        break;

    case 4:
        break;
    }

//    qDebug() << "--> bullet start position --> " << BulletDirection << ", " << BulletCurrentPositionX << "/ " << BulletCurrentPositionY;
}

Bullet::~Bullet()
{
    qDebug() << "--> bullet deleted";
}
