#ifndef BULLET_H
#define BULLET_H

#include "definitions.h"
#include "inclusions.h"

#include "mainwindow.h"

class Bullet: public QWidget
{
    Q_OBJECT

private:
//    BulletId m_Id;
    static QPixmap * m_BulletArray;

    QPainter painterBullet;

public:
    static int BulletWidth, BulletHeight; // mesure of Bullet object
    int BulletCurrentPositionX, BulletCurrentPositionY; // position of the Bullet wich will be change
    Direction BulletDirection; // Bullet direction

public:
    Bullet(QWidget *parent = 0, int PositionX = 0, int PositionY = 0, Direction Direct = Down);
    ~Bullet();

private:
    void BulletLoadBitmaps(); // load the pictures of bullet in memory
    void BulletWidthHeightInit(); // init the width and height of the Bullet object

//    void BulletDrow(/*QPainter &painter*/); // procedure for drow the Bullet
//    void BulletDrow(QPainter &painter); // procedure for drow the Bullet

protected:
    void paintEvent(QPaintEvent * event); // painting the Bullet object

private slots:
    void on_BulletMove(); // trigger for Bullet fly until death
    void on_BulletMove_triggered(); // timer which restart the procedure of fly Bullet
};
#endif // BULLET_H
