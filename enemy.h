#ifndef ENEMY_H
#define ENEMY_H

#include "definitions.h"
#include "inclusions.h"

#include "mainwindow.h"
#include "bullet.h"

class Enemy: public QWidget
{
    Q_OBJECT

//    EnemyId m_Id;
    static QPixmap * m_EnemyArray;

private:
    // start position in the field of window for Enemy object
    const int EnemyDefaultPositionX = (MainWindowSizeWidth - MARGIN) - 25,
              EnemyDefaultPositionY = (MainWindowSizeHeight - MENUHEIGHT) - 25;
    int EnemyRandomDirection;

    QPainter painterEnemyTank;

public:
    static int EnemyWidth, EnemyHeight; // mesure of Enemy object
    static int EnemyCurrentPositionX, EnemyCurrentPositionY; // position of the Enemy wich will be change
    static Direction EnemyDirection; // Enemy's tank direction

public:
    explicit Enemy(QWidget *parent = 0);
    ~Enemy();

    static void EnemyLoadBitmaps(); // load the pictures of tank in memory
    static void EnemyWidthHeightInit(); // init the width and height of the Enemy object

protected:
    void paintEvent(QPaintEvent * event); // procedur for drow the Enemy's tank
//    void EnemyDrow(QPainter &painter); // procedur for drow the Enemy's tank

private slots:
    void on_EnemyMove(); // automatic move the Enemy object
    void on_EnemyRandomDirection(); // randomly change the Enemy direction
    void on_EnemyShoot(); // create the Bullet object when Enemy is shoot
    void on_EnemyMove_triggered(); // trigger for Enemy move
    void on_EnemyDirectionChange_triggered(); // timer for Enemy direction change
    void on_EnemyShoot_trigger(); // timer for Enemy shooting delay
};

#endif // ENEMY_H
