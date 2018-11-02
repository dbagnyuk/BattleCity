#include "enemy.h"

QPixmap * Enemy::m_EnemyArray; // create array for pictures of the Enemy's tank

// variables for Enemy attributes
int Enemy::EnemyWidth, Enemy::EnemyHeight;
int Enemy::EnemyCurrentPositionX, Enemy::EnemyCurrentPositionY;
Direction Enemy::EnemyDirection;

Enemy::Enemy(QWidget *parent): QWidget(parent), painterEnemyTank(this)
{
    // difinition for the first place of Enemy
    EnemyCurrentPositionX = EnemyDefaultPositionX,
    EnemyCurrentPositionY = EnemyDefaultPositionY;
    EnemyDirection = Up;

    qDebug() << "--> default position --> " << EnemyDirection << ", " << EnemyCurrentPositionX << "/ " << EnemyCurrentPositionY;

    EnemyLoadBitmaps(); // load the pictures of tank in memory
    EnemyWidthHeightInit(); // init the width and height of the Enemy object

    // focuding the Enemy object
//    setFocusPolicy(Qt::StrongFocus);
//    setFocus();
    on_EnemyMove_triggered(); // start trigger for Enemy movement
    on_EnemyDirectionChange_triggered(); // start trigger for Enemy direction randomly change
    on_EnemyShoot_trigger(); // start trigger for Enemy shoot

    qDebug() << "--> EnemyTank object is created";
}

// load the pictures of tank in memory
void Enemy::EnemyLoadBitmaps()
{
    m_EnemyArray = new QPixmap[EnemyImagesCount];
    m_EnemyArray[Up]    = std::move(QPixmap("resources\\Enemy_Tank_Up.bmp"));
    m_EnemyArray[Right] = std::move(QPixmap("resources\\Enemy_Tank_Right.bmp"));
    m_EnemyArray[Down]  = std::move(QPixmap("resources\\Enemy_Tank_Down.bmp"));
    m_EnemyArray[Left]  = std::move(QPixmap("resources\\Enemy_Tank_Left.bmp"));

    qDebug() << "--> Enemy images is loaded";
}

// init the width and height of the Enemy object
void Enemy::EnemyWidthHeightInit()
{
    // init the variables with the one of pictures of tank
    EnemyWidth = m_EnemyArray[Up].width();
    EnemyHeight = m_EnemyArray[Up].height();

    qDebug() << "--> Enemy width and hight is initialized";
}

// procedur for drow the Enemy's tank
//void Enemy::EnemyDrow(QPainter &painter)
void Enemy::paintEvent(QPaintEvent * event)
{
//    QPainter painter(this);
    painterEnemyTank.begin(this);
    // paint the Enemy tank object
    painterEnemyTank.drawPixmap(EnemyCurrentPositionX, EnemyCurrentPositionY, m_EnemyArray[EnemyDirection].width(), m_EnemyArray[EnemyDirection].height(), m_EnemyArray[EnemyDirection]);
    painterEnemyTank.end();
    this->update();

//    qDebug() << "--> Enemy is drowed --> " << EnemyDirection << ", " << EnemyCurrentPositionX << "/ " << EnemyCurrentPositionY;
}

// timer for run movement of Enemy
void Enemy::on_EnemyMove_triggered()
{
    QTimer * timerEnemyMove = new QTimer(this);
    connect(timerEnemyMove, SIGNAL(timeout()), this, SLOT(on_EnemyMove()));
    timerEnemyMove->start(100);
}

// timer for Enemy direction change
void Enemy::on_EnemyDirectionChange_triggered()
{
    QTimer * timerEnemyMove = new QTimer(this);
    connect(timerEnemyMove, SIGNAL(timeout()), this, SLOT(on_EnemyRandomDirection()));
    timerEnemyMove->start(EnemyDirectionChangeDelay);
}

// randomly change the Enemy direction
void Enemy::on_EnemyRandomDirection()
{
    srand((unsigned int)time(0));
    EnemyRandomDirection = rand () % 4;

    qDebug() << "--> Enemy random direction --> " << EnemyDirection;
}

// automatic move the Enemy object
void Enemy::on_EnemyMove()
{
    switch(EnemyRandomDirection)
    {
    case 0:
        EnemyDirection = Up;
        if (EnemyCurrentPositionY > 0 + MENUHEIGHT)
            EnemyCurrentPositionY -= ENEMYSPEED;
        else
            on_EnemyRandomDirection();
        break;

    case 1:
        EnemyDirection = Right;
        if (EnemyCurrentPositionX <= MainWindowSizeWidth - MARGIN - EnemyWidth)
            EnemyCurrentPositionX += ENEMYSPEED;
        else
            on_EnemyRandomDirection();
        break;

    case 2:
        EnemyDirection = Down;
        if (EnemyCurrentPositionY <= MainWindowSizeHeight - MARGIN - EnemyHeight)
            EnemyCurrentPositionY += ENEMYSPEED;
        else
            on_EnemyRandomDirection();
        break;

    case 3:
        EnemyDirection = Left;
        if (EnemyCurrentPositionX > 0 + MARGIN)
            EnemyCurrentPositionX -= ENEMYSPEED;
        else
            on_EnemyRandomDirection();
        break;
    }

//    qDebug() << "--> Enemy random direction --> " << EnemyDirection;
}

// timer for Enemy shooting delay
void Enemy::on_EnemyShoot_trigger()
{
    QTimer * timerEnemyShoot = new QTimer(this);
    connect(timerEnemyShoot, SIGNAL(timeout()), this, SLOT(on_EnemyShoot()));
    timerEnemyShoot->start(EnemyShootDelay);
}

// create the Bullet object when Enemy is shoot
void Enemy::on_EnemyShoot()
{

    Bullet * bullet = new Bullet(0, EnemyCurrentPositionX, EnemyCurrentPositionY, EnemyDirection);
//        bullet->setVisible(true);
    bullet->show();

    qDebug() << "--> Enemy is shooted";
}

Enemy::~Enemy()
{
    qDebug() << "--> Enemy deleted";
}
